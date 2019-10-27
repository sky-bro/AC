#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    friend ostream &operator<<(ostream &os, const Node &node)
    {
        os << node.data;
        return os;
    }

    Node(int dt, Node *nxt) : data(dt), next(nxt) {}

    void print(const Node *pnode) const
    {
        if (pnode == nullptr)
            ;
        pnode = this;
        while (pnode)
        {
            cout << (*pnode);
            pnode = pnode->next;
        }
    }
};

Node *init_list(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    Node *root = new Node(arr[0], nullptr);
    Node *p = root;
    for (int i = 1; i < n; ++i)
    {
        p->next = new Node(arr[i], nullptr);
        p = p->next;
    }
    return root;
}

void free_list(Node *node)
{
    Node *p = node;
    while (!p)
    {
        node = p->next;
        delete p;
        p = node;
    }
}

Node *reverse(Node *start, Node *end)
{
    if (start == end)
        return start;
    Node *tmp = start->next->next;
    // p指向逆序后的链表头
    Node *p = start->next;
    p->next = start;
    start->next = nullptr;

    // 下一个插到表头的元素
    Node *tmp2;
    while (tmp != end)
    {
        tmp2 = tmp->next;
        tmp->next = p;
        p = tmp;
        tmp = tmp2;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3};
    Node *pn = init_list(a, 3);
    pn->print(nullptr);
    cout << endl;
    pn = reverse(pn, nullptr);
    pn->print(nullptr);
    cout << endl;

    free_list(pn);

    return 0;
}
