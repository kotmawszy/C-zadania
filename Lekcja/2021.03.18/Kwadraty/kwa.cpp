#include <bits/stdc++.h>
using namespace std;

int n,m;
int tab[1003][1003];
bitset<1003> vis[1003];
int c;
int l;
stack<pair<int,int> > s;

int dfs(int ii, int jj) {
  int sum=0;
  s.push({ii,jj});
  while(!s.empty()) {
    int i=s.top().first;
    int j=s.top().second;
    s.pop();
    if(i<0||i>=n || j<0||j>=m) continue;
    if(vis[i][j]) continue;
    if(tab[i][j]!=c) continue;
    vis[i][j]=1;
    sum++;
    s.push({i+1,j});
    s.push({i-1,j});
    s.push({i,j+1});
    s.push({i,j-1});
  }
  return sum;
}

int main() {
  cin>>m>>n;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>tab[i][j];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j]) {
    l++;
    c = tab[i][j];
    if(dfs(i,j)<2) l--;
  }
  cout<<l<<"\n";
}
