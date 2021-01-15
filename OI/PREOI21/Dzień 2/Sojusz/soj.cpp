#include <bits/stdc++.h>
using namespace std;

int n,a,c,q;
int arr[100007];
int* s;
map<int,bool> m[2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  s = new int[n];
  m[0][0]=1;
  for(int i=0;i<n;i++) {
    cin>>a>>c;
    int maxs=0;
    for(int j=1;j<=a;j++) {
      cin>>arr[j];
      arr[j]+=arr[j-1];
      for(int k=0;k<j;k++) {
        if((arr[j]-arr[k])%c) continue;
        maxs=max(maxs,arr[j]-arr[k]);
      }
    }
    m[1-i%2].clear();
    for(map<int,bool>::iterator it=m[i%2].begin();it!=m[i%2].end();it++) {
      m[1-i%2][it->first]=1;
      m[1-i%2][(it->first)^maxs]=1;
    }
  }

  cin>>q;
  while(q--) {
    cin>>a;
    cout<<(m[n%2].find(a)==m[n%2].end() ? "NIE" : "TAK")<<"\n";
  }
}
