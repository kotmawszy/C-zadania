#include <bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int>* p;
int* pocz;
int* kon;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>m>>n;

  p = new pair<int,int>[m+1];
  pocz = new int[m];
  kon = new int[m];

  for(int i=1;i<=m;i++) {
    cin>>p[i].first>>p[i].second;
    pocz[i-1]=p[i].first;
    kon[i-1]=p[i].second;
  }
  sort(pocz,pocz+m);
  sort(kon,kon+m);

  for(int i=1;i<=m;i++) {
    int a = m-(lower_bound(pocz,pocz+m,p[i].second+1)-pocz);
    int b = (upper_bound(kon,kon+m,p[i].first-1)-kon);
    cout<<m-a-b-1<<"\n";
  }
}
