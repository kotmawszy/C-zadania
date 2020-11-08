#include <bits/stdc++.h>
using namespace std;

string pr,in;
vector<int> g[30];
bool vis[30];
string v;

void dfs(int w) {
  vis[w]=1;
  for(int u : g[w]) {
    if(vis[u]==0) dfs(u);
  }
  v+=(char)(w+'A');
}

int main() {
  for(int i=0;i<30;i++) vis[i]=1;
  while(1) {
    pr = in;
    cin>>in;

    for(int j=0;j<in.size();j++) vis[in[j]-'A']=0;

    if(pr.size()==0) continue;
    if(in=="#") break;

    int i=0;
    while(pr[i]==in[i]) {
      i++;
      if(i>=pr.size()) break;
    }
    if(i<pr.size()) g[pr[i]-'A'].push_back(in[i]-'A');
  }
  for(int i=0;i<30;i++) if(!vis[i]) dfs(i);

  reverse(v.begin(),v.end());
  cout<<v;
}
