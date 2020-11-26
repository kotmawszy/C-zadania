#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;
int tab[1001][1001];
int x,y;
int s;
vector<int> e,f;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>a>>b>>c>>d;
  f.push_back(a);f.push_back(b);f.push_back(c);f.push_back(d);
  sort(f.begin(),f.end());
  cin>>y>>x;
  for(int i=0;i<y;i++) for(int j=0;j<x;j++) cin>>tab[i][j];

  for(int i=1;i<y;i++) for(int j=1;j<x;j++) {
    e.clear();
    e.push_back(tab[i-1][j-1]);
    e.push_back(tab[i-1][j]);
    e.push_back(tab[i][j-1]);
    e.push_back(tab[i][j]);
    sort(e.begin(),e.end());
    bool xd = 1;
    for(int j=0;j<4;j++) if(f[j]!=e[j]) xd=0;
    if(xd) s++;
  }
  cout<<s;
}
