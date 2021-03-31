#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
  return a.first*b.second<b.first*a.second;
}

int main() {
  int n;
  cin>>n;
  pair<int,int> a[n];
  for(int i=0;i<n;i++) cin>>a[i].first;
  for(int i=0;i<n;i++) cin>>a[i].second;

  sort(a,a+n,cmp);

  for(int i=0;i<n;i++) {
    cout<<a[i].first<<" "<<a[i].second<<"\n";
  }
}
