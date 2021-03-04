#include <iostream>
#include <queue>
#include <stack>

using namespace std;

namespace AVL
{
    template<typename KT, typename VT> // key type, value type
    struct Node
    {
        KT key;
        VT val;
        Node *left, *right;
        int height;
        Node(const KT &_key, const VT &_val, Node *_left = nullptr, Node *_right = nullptr, int _height = 0)
            : key(_key), val(_val), left(_left), right(_right), height(_height) {}
        void freeme() {
            if (left) left->freeme();
            if (right) right->freeme();
            delete this;
        }
    };

    template<typename KT, typename VT>
    ostream& operator<<(ostream &os, const Node<KT, VT> &node) {
        return os << "(" << node.key << ", " << node.val << ", " << node.height << ")";
    }

    template<typename KT, typename VT> // key type, value type
    class Tree
    {
    public:
        Node<KT, VT> *root;
        Tree();
        ~Tree();
        Node<KT, VT>* find(const KT& key);
        pair<bool, Node<KT, VT>*> insert(const KT &key, const VT &val);
        bool remove(const KT &key);
        int getHeight();

    private:
        void rotateLeft(Node<KT, VT>* &node);
        void rotateRight(Node<KT, VT>* &node); 
        void rotate(Node<KT, VT>* &node);
        void updateHeight(Node<KT, VT>* node);
        pair<bool, Node<KT, VT>*> insert(const KT &key, const VT &val, Node<KT, VT>* &node);
        int getHeight(Node<KT, VT>* node);
        bool remove(const KT &key, Node<KT, VT>* &node);
    };
    
    template<typename KT, typename VT>
    Tree<KT, VT>::Tree(): root(nullptr) {}
    
    template<typename KT, typename VT>
    Tree<KT, VT>::~Tree() {
        if (root) root->freeme();
    }

    template<typename KT, typename VT>
    Node<KT, VT>* Tree<KT, VT>::find(const KT& key) {
        Node<KT, VT>* p = root;
        while (p && p->key != key) {
            if (p->key < key) p = p->right;
            else p = p->left;
        }
        return p;
    }

    /**
     * @returns make_pair(is new key, pointer to the inserted node)
     */
    template<typename KT, typename VT>
    pair<bool, Node<KT, VT>*> Tree<KT, VT>::insert(const KT &key, const VT &val) {
        return insert(key, val, root);
    }

    template<typename KT, typename VT>
    pair<bool, Node<KT, VT>*> Tree<KT, VT>::insert(const KT &key, const VT &val, Node<KT, VT>* &node) {
        if (!node) return make_pair(true, node = new Node(key, val));
        pair<bool, Node<KT, VT>*> pp(false, node);
        if (node->key == key) node->val = val;
        else if (node->key < key) pp = insert(key, val, node->right);
        else pp = insert(key, val, node->left);
        if (pp.first) rotate(node);
        return pp;
    }

    template<typename KT, typename VT>
    bool Tree<KT, VT>::remove(const KT &key) {
        return remove(key, root);
    }

    template<typename KT, typename VT>
    bool Tree<KT, VT>::remove(const KT &key, Node<KT, VT>* &node) {
        if (!node) return false;
        bool found = true;
        if (node->key > key) {
            if (found = remove(key, node->left)) rotate(node);
        } else if(node->key < key) {
            if (found = remove(key, node->right)) rotate(node);
        } else if (node->left && node->right) {
            Node<KT, VT>* p = node->right;
            while (p->left) p = p->left;
            node->key = p->key;
            node->val = p->val;
            remove(node->key, node->right);
            rotate(node);
        } else {
            Node<KT, VT>* tmp = node->left ? node->left : node->right;
            delete node;
            node = tmp;
        }
        return found;
    }

    template<typename KT, typename VT>
    inline int Tree<KT, VT>::getHeight() {
        return getHeight(root);
    }

    template<typename KT, typename VT>
    inline int Tree<KT, VT>::getHeight(Node<KT, VT>* node) {
        return node ? node->height : -1;
    }

    /**
     * RR type
     */
    template<typename KT, typename VT>
    void Tree<KT, VT>::rotateLeft(Node<KT, VT>* &node) {
        Node<KT, VT> *p = node->right;
        node->right = p->left;
        p->left = node;
        updateHeight(node);
        updateHeight(p);
        node = p;
    }

    /**
     * LL type
     */
    template<typename KT, typename VT>
    void Tree<KT, VT>::rotateRight(Node<KT, VT>* &node) {
        Node<KT, VT> *p = node->left;
        node->left = p->right;
        p->right = node;
        updateHeight(node);
        updateHeight(p);
        node = p;
    }

    template<typename KT, typename VT>
    void Tree<KT, VT>::rotate(Node<KT, VT>* &node) {
        if (!node) return;
        int lh = getHeight(node->left), rh = getHeight(node->right);
        if (lh == rh + 2) {
            int llh = getHeight(node->left->left), lrh = getHeight(node->left->right);
            if (llh < lrh) { // LR
                rotateLeft(node->left);
            }
            rotateRight(node); // LL
        } else if (lh == rh - 2) {
            int rlh = getHeight(node->right->left), rrh = getHeight(node->right->right);
            if (rlh > rrh) { // RL
                rotateRight(node->right);
            }
            rotateLeft(node); // RR
        } else updateHeight(node);
    }

    template<typename KT, typename VT>
    inline void Tree<KT, VT>::updateHeight(Node<KT, VT>* node) {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

} // namespace AVL

template<typename KT, typename VT>
void bfs(AVL::Node<KT, VT> *p) {
    queue<AVL::Node<KT, VT>*> q;
    q.push(p);
    while (!q.empty()) {
        for (int sz = q.size(); sz; --sz) {
            p = q.front(); q.pop();
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
            cout << *p << " ";
        }
        cout << endl;
    }
}

template<typename KT, typename VT>
void dfs(AVL::Node<KT, VT> *p) {
    stack<AVL::Node<KT, VT>*> stk;
    stk.push(p);
    while (!stk.empty()) {
        p = stk.top(); stk.pop();
        cout << *p << " ";
        if (p->right) stk.push(p->right);
        if (p->left) stk.push(p->left);
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    AVL::Tree<int, int> tree;
    tree.insert(1, 1);
    tree.insert(2, 1);
    tree.insert(3, 1);
    tree.insert(4, 1);
    tree.insert(5, 1);
    tree.insert(6, 1);
    tree.insert(7, 1);
    tree.insert(8, 1);
    tree.insert(9, 1);
    bfs(tree.root);
    cout << "-------------------------\n";
    dfs(tree.root);
    cout << "=========================\n";
    tree.remove(3);
    tree.remove(5);
    tree.remove(9);
    tree.remove(8);
    tree.remove(2);
    tree.remove(1);
    bfs(tree.root);
    cout << "-------------------------\n";
    dfs(tree.root);
    return 0;
}
