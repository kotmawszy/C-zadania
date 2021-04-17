#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
  int c = (a.first*a.first+a.second*a.second) - (b.first*b.first+b.second*b.second);
  if(c==0) return a<b;
  return c>0;
}

int main() {
  int n;
  cin>>n;
  pair<int,int> a[n];
  for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
  sort(a,a+n,cmp);
  for(int i=0;i<n;i++) cout<<a[i].first<<" "<<a[i].second<<"\n";
}
