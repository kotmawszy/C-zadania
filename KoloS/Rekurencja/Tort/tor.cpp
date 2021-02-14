#include <bits/stdc++.h>
using namespace std;

long long a,b,k,n;
long long* x;
long long* y;
long long* xx;
long long* yy;

long long f(long long s) {
  long long sum=0;
  long long j=n;
  for(int i=0;i<=n;i++) {
    while(j>=0 && x[i]*y[j]>=s) j--;
    sum+=n-j;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>a>>b>>n>>k;
  x = new long long[n+1];
  y = new long long[n+1];
  xx = new long long[n+2];
  yy = new long long[n+2];
  for(int i=1;i<=n;i++) cin>>xx[i];
  for(int i=1;i<=n;i++) cin>>yy[i];
  xx[0]=yy[0]=0;
  xx[n+1]=a;
  yy[n+1]=b;
  for(int i=0;i<=n;i++) x[i]=xx[i+1]-xx[i], y[i]=yy[i+1]-yy[i];
  sort(x,x+n+1);
  sort(y,y+n+1);

  long long p=1;
  long long q=a*b;
  while(p<q) {
    long long s=(p+q+1)/2;
    if(f(s)>=k) p=s;
    else q=s-1;
  }
  cout<<p;
}
