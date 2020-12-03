#include <iostream>
using namespace std;

int g(int x) {
  int s=0;
  for(int i=1;i*i<=x;i++) {
    if(x%i) continue;
    s++;
    if(i*i!=x) s++;
  }
  return s-1;
}
int f(int a, int b) {
  return (g(a)>g(b) ? g(a) : g(b));
}

int main() {
  int a,b;
  cin>>a>>b;
  cout<<f(a,b);
  return 0;
}
