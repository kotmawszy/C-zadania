#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n,q;
  cin>>n>>q;
  int* arr = new int[n];
  set<int> s;
  for(int i=0;i<n;i++) {
    cin>>arr[i];
    s.insert(arr[i]);
  }
  MergeSortTree<int> t(arr,n);

  vector<int> v;
  for(int i : s) v.push_back(i);

  int p=0;
  int q=v.size()-1;


  /*while(q--) {
    cin>>a>>b>>c;

  }*/
}
