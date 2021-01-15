#include <bits/stdc++.h>
using namespace std;

int n,m,z,a,b,c;
vector<int>* g;

//int score[5002][5002];

queue<int> q;
bool* vis;
int* d;
int bfs(int v, int f) {
  for(int i=0;i<2*n+2;i++) vis[i]=0, d[i]=-1;

  q.push(v);
  vis[v]=1;
  d[v]=0;

  while(!q.empty()) {
    int w = q.front();
    q.pop();
    if(w==f) {
      while(!q.empty()) q.pop();
      return d[w];
    }

    for(int u : g[w]) {
      if(vis[u]) continue;
      vis[u]=1;
      d[u]=d[w]+1;
      q.push(u);
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m>>z;
  g = new vector<int>[2*n+2];
  vis = new bool[2*n+2];
  d = new int[2*n+2];
  while(m--) {
    cin>>a>>b;
    g[2*a].push_back(2*b+1);
    g[2*b+1].push_back(2*a);

    g[2*a+1].push_back(2*b);
    g[2*b].push_back(2*a+1);
  }

  while(z--) {
    cin>>a>>b>>c;
    if(c%2==0) { // gdy parzysta ilość kroków
      int x = bfs(2*a,2*b);
      if(x == -1) { // jeżeli nie da się w parzystej liczbie kroków to w ogóle się nie da
        cout<<"NIE\n";
        continue;
      }
      cout<<(c>=x ? "TAK\n" : "NIE\n"); // tak tylko jeżeli więcej kroków niż minimalnie
    } else {
      int x = bfs(2*a,2*b+1);
      if(x == -1) { // jeżeli nie da się w nieparzystej liczbie kroków to w ogóle się nie da
        cout<<"NIE\n";
        continue;
      }
      cout<<(c>=x ? "TAK\n" : "NIE\n"); // tak tylko jeżeli więcej kroków niż minimalnie
    }
  }
}
