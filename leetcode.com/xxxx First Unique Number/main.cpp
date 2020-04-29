#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
// how to define this inside FirstUnique class, I get error?
struct Node {
    int num;
    Node* next;
    Node* prev;
    Node(int _num, Node* _prev=nullptr, Node *_next=nullptr): num(_num), next(_next), prev(_prev) {}
    void delete_cur() {
        prev->next = next;
        if (next) next->prev = prev;
        delete this;
    }
};

class FirstUnique {
private:
    unordered_set<int> non_uniq;
    unordered_map<int, Node*> uniq;
    Node* head;
    Node* tail;
    
public:
    FirstUnique(vector<int>& nums) {
        head = tail = new Node(0);
        for (int num: nums) add(num);
    }
    
    void delete_list(Node *hd) {
        if (!hd) return;
        delete_list(hd->next);
        delete hd;
    }
    
    ~FirstUnique() {
        delete_list(head);
    }
    
    int showFirstUnique() {
        return head->next ? head->next->num : -1;
    }
    
    void add(int num) {
        if (non_uniq.count(num)) return;
        auto it = uniq.find(num);
        if (it != uniq.end()) {
            Node* cur = it->second;
            if (tail == cur) tail = tail->prev;
            cur->delete_cur();
            uniq.erase(it);
            non_uniq.insert(num);
        } else {
            Node *cur = new Node(num, tail);
            tail->next = cur;
            tail = cur;
            uniq.emplace(num, cur);
        }
    }
};

int main(int argc, char const *argv[])
{
  vector<int> nums;
  int n, num;
  cin>>n;
  for (int i = 0; i < n; ++i) {
    cin>>num;
    nums.push_back(num);
  }
  FirstUnique fu(nums);

  string op;
  while (cin>>op) {
    if (op[0] == 'a') {
      cin>>num;
      fu.add(num);
    } else {
      cout<<fu.showFirstUnique()<<endl;
    }
  }
  return 0;
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
