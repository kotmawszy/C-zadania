#include <bits/stdc++.h>
using namespace std;

int n;
long long x,a,b;
long long* arr;
long long* mx;
long long* pref;
long long p;
long long shift;
int d;
int s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>x>>a>>b;
  arr = new long long[n+1];
  pref = new long long[n+1];
  pref[0]=x;
  for(int i=1;i<=n;i++) {
    cin>>arr[i];
    pref[i]=pref[i-1]+arr[i];
    if(pref[i]>b) {cout<<"-1";return 0;}
  }

  mx = new long long[n+1];
  mx[n]=pref[n];
  for(int i=n-1;i>0;i--) mx[i]=max(mx[i+1],pref[i]);

  for(int i=1;i<=n;i++) {
      if (x+arr[i]<a) {
          long long y = min(b-mx[i]-p, b-x);
          x+=y;
          if (x+arr[i]<a) {
              cout << "-1";
              return 0;
          }
          s++;
          p+=y;
      }
      x+=arr[i];
  }
  cout<<s;
}
