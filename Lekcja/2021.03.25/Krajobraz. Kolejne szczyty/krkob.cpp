#include <bits/stdc++.h>
using namespace std;

void sort(pair<int,int>* tab, int n) {
  for(int j=0;j<n-1;j++) {
    for(int i=0;i<n-1;i++) {
      if(tab[i].first*tab[i+1].second>=tab[i+1].first*tab[i].second) swap(tab[i],tab[i+1]);
    }
  }
}

int main() {
  int n;
  cin>>n;
  pair<int,int> a[n];
  for(int i=0;i<n;i++) cin>>a[i].first;
  for(int i=0;i<n;i++) cin>>a[i].second;

  sort(a,n);

  for(int i=0;i<n;i++) {
    cout<<a[i].first<<" "<<a[i].second<<"\n";
  }
}
