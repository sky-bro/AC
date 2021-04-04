#include <bits/stdc++.h>
using namespace std;

template<typename X>
class m_auto_ptr {
private:
    X* _p;
public:
    explicit m_auto_ptr(X* p): _p(p) {}
    m_auto_ptr(m_auto_ptr& other): _p(other._p) { other._p = nullptr; }
    ~m_auto_ptr() { delete _p; }
    m_auto_ptr<X>& operator=(m_auto_ptr<X>& other) {
        if (this != &other) { // no need to assign if same object
            // delete _p;
            // _p = other._p;
            // other._p = nullptr;
            reset(other.release());
        }
        return *this;
    }
    X& operator*() const { return *_p; }
    X* operator->() const { return _p; }
    X* get() const { return _p; }
    X* release() {
        X* p = _p;
        _p = nullptr;
        return p;
    }
    void reset(X* p = nullptr) {
        if (p != _p) {
            delete _p;
            _p = p;
        }
    }
};

struct Node {
    int x, y;
    Node(int x, int y): x(x), y(y) {}
};

int main(int argc, char const *argv[])
{
    m_auto_ptr<int> p(new int);
    *p = 3;
    cout << *p << endl;
    m_auto_ptr<Node> p2(new Node(1, 2));
    cout << p2->x << endl;
    cout << (*p2).y << endl;
    p.reset(new int(4));
    cout << *p << endl;
    return 0;
}

