#ifndef INCLUDED_PatriciaTrie_H
#define INCLUDED_PatriciaTrie_H

#include <inttypes.h>

#include <cassert>
#include <memory>
#include <queue>

template <typename K, typename V>
class PatriciaTrie;

template <typename K, typename V>
class PatriciaTrieNode {
 public:
  friend std::ostream& operator<<(std::ostream& os,
                                  const PatriciaTrieNode<K, V>& node) {
    if (node.key) {
      os << "(" << (*node.key) << ", ";
    } else {
      os << "(null, ";
    }
    return os << node.bitLength << ")";
  }

  friend class PatriciaTrie<K, V>;

  PatriciaTrieNode(std::shared_ptr<K> key,
                   uint bitLength,
                   std::shared_ptr<V> value = nullptr,
                   std::shared_ptr<PatriciaTrieNode<K, V>> left = nullptr,
                   std::shared_ptr<PatriciaTrieNode<K, V>> right = nullptr)
      : key(key)
      , bitLength(bitLength)
      , value(value)
      , left(left)
      , right(right){};

  ~PatriciaTrieNode(){};

  uint getFirstDifferentBit(const K& otherKey, uint checkLength) {
    return key->getFirstDifferentBit(otherKey, checkLength);
  }

 private:
  std::shared_ptr<K> key;  // prefix
  uint bitLength;
  std::shared_ptr<V> value;
  std::shared_ptr<PatriciaTrieNode<K, V>> left, right;
};

template <typename K, typename V>
class PatriciaTrie {
 public:
  PatriciaTrie() : root(nullptr), size(0){};

  ~PatriciaTrie(){};

  void levelOrderTraversal(std::ostream& os) {
    os << "PatriciaTrie size: " << size << std::endl;
    std::queue<std::shared_ptr<PatriciaTrieNode<K, V>>> q;
    if (root) q.push(root);
    int sz;
    while (sz = q.size()) {
      while (sz--) {
        auto cur = q.front();
        q.pop();
        os << (*cur) << ", ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      os << std::endl;
    }
  }

  /**
   * walk till first contains the index (node->bitLength >= index)
   * or if there's no such node contains index (node->bitLength < index)
   * root is not null
   */
  std::shared_ptr<PatriciaTrieNode<K, V>> walkTillIndex(std::shared_ptr<K> key,
                                                        uint index) {
    std::shared_ptr<PatriciaTrieNode<K, V>> node = root;
    while (node->bitLength < index) {
      if (key->getBit(node->bitLength)) {
        if (node->right == nullptr) break;
        node = node->right;
      } else {
        if (node->left == nullptr) break;
        node = node->left;
      }
    }
    return node;
  }

  /**
   * insert key (of length bitLength) into the trie, key is guaranteed not null
   */
  std::shared_ptr<PatriciaTrieNode<K, V>> insert(std::shared_ptr<K> key,
                                                 uint bitLength) {
    assert(key);
    ++size;
    if (!root) {
      root = std::make_shared<PatriciaTrieNode<K, V>>(key, bitLength);
      return root;
    }
    std::shared_ptr<PatriciaTrieNode<K, V>> node =
        walkTillIndex(key, bitLength);
    // key already exists!
    if (node->bitLength == bitLength && node->key && *(node->key) == *key) {
      --size;
      return node;
    }
    // 随便走到一个key非空的节点
    // while (!node->key && node->right) node = node->right;
    // 不可能有node->key为空，node->right也为空的，因为空的中间节点是splitNode
    while (!node->key) node = node->right;
    assert(node->key);
    uint checkLength = std::min(bitLength, node->bitLength);
    uint firstDifferentBit = node->getFirstDifferentBit(*key, checkLength);
    bool firstDifferentBitSet = node->key->getBit(firstDifferentBit);
    node = walkTillIndex(key, firstDifferentBit);
    // node->bitLength >= firstDifferentBit
    if (node->bitLength > firstDifferentBit) {  // need to split current node
      std::shared_ptr<PatriciaTrieNode<K, V>> old =
          std::make_shared<PatriciaTrieNode<K, V>>(
              node->key, node->bitLength, node->value, node->left, node->right);
      node->key = nullptr;
      node->bitLength = firstDifferentBit;
      node->value = nullptr;
      if (firstDifferentBitSet) {
        node->right = old;
      } else {
        node->left = old;
      }
    }
    // 找到原来一个splitNode，直接把当前的key赋值给它即可
    if (node->bitLength == bitLength) {
      node->key = key;
      return node;
    }
    std::shared_ptr<PatriciaTrieNode<K, V>> cur =
        std::make_shared<PatriciaTrieNode<K, V>>(key, bitLength);
    // firstDifferentBitSet 指的是另外一个孩子，所以这里是反着的
    return firstDifferentBitSet ? (node->left = cur) : (node->right = cur);
  }

  std::shared_ptr<PatriciaTrieNode<K, V>> lookup(const K& key, uint bitLength) {
    auto node = root;
    std::shared_ptr<PatriciaTrieNode<K, V>> stk[K::MAX_BITS];
    int i = 0;
    while (node && node->bitLength < bitLength) {
      if (node->key) {
        stk[i++] = node;
      }
      node = key.getBit(node->bitLength) ? node->right : node->left;
    }
    if (node && node->bitLength == bitLength && node->key) stk[i++] = node;
    while (i) {
      node = stk[--i];
      if (node->getFirstDifferentBit(key, node->bitLength) == node->bitLength) {
        return node;
      }
    }
    return nullptr;
  }

 private:
  std::shared_ptr<PatriciaTrieNode<K, V>> root;
  uint size;  // 树的大小 = 插入的key个数
};

#endif
