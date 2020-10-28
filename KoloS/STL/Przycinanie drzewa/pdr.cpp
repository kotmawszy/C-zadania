#include <bits/stdc++.h>
using namespace std;

bool* arr;
int h,m,a,n;

int f(int x) {
  if(x>n || arr[x]) return 0;
  return f(2*x)+f(2*x+1)+1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>h>>m;
  n = (1<<h)-1;
  arr = new bool[n+1];
  for(int i=1;i<=n;i++) arr[i]=0;

  while(m--) {
    cin>>a;
    arr[a]=1;
  }
  cout<<f(1);
}
