#include <bits/stdc++.h>
using namespace std;

// moja libka
template<class T>
class Stack {
    struct Node {
        T value;
        Node* next;
    };
    unsigned int length;
    Node* _top;
    Node* last;

  public:
    Stack();
    void push(T);
    void pop();
    T top();
    unsigned int size();
    bool empty();

    class iterator {
        Node* curr;
      public:
        iterator(const iterator&);
        iterator(Node*);
        T operator*();
        iterator& operator++();
        iterator operator++(int);
        bool operator!=(const iterator&);
        bool operator==(const iterator&);
    };

    iterator begin();
    iterator end();
};
template<class T>
Stack<T>::Stack() {
    length = 0;
    last = new Node();
    last -> next = NULL;
    _top = last;
}

template<typename T>
void Stack<T>::push(T _value) {
    Node* tmp = new Node();
    tmp -> value = _value;
    tmp -> next = _top;
    _top = tmp;
    length++;
}

template<typename T>
void Stack<T>::pop() {
    if(length == 0) return;
    Node* ptop = _top;
    _top = _top -> next;
    delete ptop;
    length--;
}

template<typename T>
T Stack<T>::top() {
    if(length == 0) return 0;
    return _top -> value;
}

template<typename T>
unsigned int Stack<T>::size() {
    return length;
}

template<typename T>
bool Stack<T>::empty() {
    return length == 0;
}

template<typename T>
Stack<T>::iterator::iterator(const iterator& other) {
    this->curr = other.curr;
}

template<typename T>
Stack<T>::iterator::iterator(Node* node) {
    curr = node;
}

template<typename T>
T Stack<T>::iterator::operator*() {
    return curr->value;
}

template<typename T>
typename Stack<T>::iterator& Stack<T>::iterator::operator++() {
    curr = curr -> next;
    return *this;
}

template<typename T>
typename Stack<T>::iterator Stack<T>::iterator::operator++(int) {
    iterator tmp = *this;
    curr = curr -> next;
    return tmp;
}

template<typename T>
bool Stack<T>::iterator::operator!=(const iterator& other) {
    return other.curr != this->curr;
}

template<typename T>
bool Stack<T>::iterator::operator==(const iterator& other) {
    return other.curr == this->curr;
}

template<typename T>
typename Stack<T>::iterator Stack<T>::begin() {
    return iterator(_top);
}

template<typename T>
typename Stack<T>::iterator Stack<T>::end() {
    return iterator(last);
}


int n,m,a,b;
vector<int>* g;
int* c;

bool d;

Stack<int> s;

void dfs(int v) {
  if(d) return;
  s.push(v);
  for(int u : g[v]) {
    if(c[u] == 0) {
      c[u] = 3-c[v];
      dfs(u);
    } else if(c[u] == c[v]) {
      if(d) return;
      cout<<"TAK";
      while(!s.empty()) {
        int x = s.top();
        s.pop();
        cout<<" "<<x;
        if(x == u) break;
      }
      while(!s.empty()) s.pop();
      cout<<"\n";
      d=1;
      return;
    }
  }
  s.pop();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int z;
  cin>>z;
  while(z--) {
    cin>>n>>m;
    g = new vector<int>[n+1];
    c = new int[n+1];
    for(int i=0;i<=n;i++) c[i]=0;
    while(m--) {
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    d=0;
    for(int i=1;i<=n;i++) if(c[i]==0) {
      c[i]=1;
      dfs(i);
    }
    if(!d) cout<<"NIE\n";
  }
}
