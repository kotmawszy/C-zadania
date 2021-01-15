#include <bits/stdc++.h>
using namespace std;

int n,q,x,y,lv=1;
int d[3000000];
string a,b;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>a>>b>>q;
  while(lv<n) lv*=2;
  for(int i=0;i<n;i++) d[lv+i] = (a[i]==b[i] ? 0 : (a[i]>b[i] ? 1 : 2));
  for(int i=lv-1;i>0;i--) d[i] = (d[2*i]==0 ? d[2*i+1] : d[2*i]);

  while(q--) {
    cin>>x>>y;
    swap(a[x],b[y]);
    d[lv+x] = (a[x]==b[x] ? 0 : (a[x]>b[x] ? 1 : 2));
    d[lv+y] = (a[y]==b[y] ? 0 : (a[y]>b[y] ? 1 : 2));
    x+=lv;
    y+=lv;
    for(x/=2;x;x/=2) d[x] = (d[2*x]==0 ? d[2*x+1] : d[2*x]);
    for(y/=2;y;y/=2) d[y] = (d[2*y]==0 ? d[2*y+1] : d[2*y]);
    //for(int i=1;i<2*lv;i++) cout<<d[i]<<" ";
    cout<<d[1]<<"\n";
  }
}
