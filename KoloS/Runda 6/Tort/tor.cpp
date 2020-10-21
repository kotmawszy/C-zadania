#include <bits/stdc++.h>
using namespace std;

long long s,fo;
int a,b,n,k,c;
int* x;
int* y;

int f(int q) {
  int s = 0;
  int j = n;
  for(int i=0;i<=n;i++) {
    while(x[j]*y[i]>q) j--;
    s+=j+1;
  }
  return s;
}

int main() {
  cin>>a>>b>>n>>k;
  x = new int[n+1];
  y = new int[n+1];
  int prev = 0;
  for(int i=0;i<n;i++) {
    cin>>c;
    x[i] = c - prev;
    prev = c;
    if(i+1 == n) x[n] = a-c;
  }
  prev = 0;
  for(int i=0;i<n;i++) {
    cin>>c;
    y[i] = c - prev;
    prev = c;
    if(i+1 == n) y[n] = b-c;
  }

  sort(x,x+n+1);
  sort(y,y+n+1);

  long long p = x[0]*x[1];
  long long q = x[n]*y[n];
  long long tf = (n+1)*(n+1)-k+1;
  //cout<<tf<<"\n";
  while(p<q) {
    s = (p+q)/2;
    fo = f(s);
    //cout<<"dla "<<s<<" "<<fo<<" p "<<p<<" q "<<q<<"\n";
    if(fo==tf) {
      cout<<s;
      return 0;
    }
    if(fo>tf) {
      q = s;
    }
    else {
      p = s+1;
    }
  }
  //cout<<"dla "<<s<<" "<<fo<<" p "<<p<<" q "<<q<<"\n";
  //cout<<tf<<" "<<q<<" "<<f(q)<<" "<<f(q-1)<<" ";
  //while(f(q)>tf) q--;
  cout<<q;

  delete[] x,y;
}
