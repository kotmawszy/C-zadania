#include <bits/stdc++.h>
using namespace std;

int t,n;
vector<pair<pair<int,int>,int> >* gi;
int a,b,c;
int* subtreeSize;
vector<int>* g;
int* cost;
int* parent;
int* top;
int* normalToTree;
int* treeToNormal;
int currId;
int* jumpPointer[20];
int* depth;
int lv;
int* d;
int* edgeToVertex;

void rootDFS(int v) {
  subtreeSize[v]=1;
  depth[v]=depth[parent[v]]+1;
  for(auto u : gi[v]) {
    if(u.first.first==parent[v]) continue;
    parent[u.first.first]=v;
    cost[u.first.first]=u.first.second;
    edgeToVertex[u.second]=u.first.first;
    int last=g[v].size();
    g[v].push_back(u.first.first);
    rootDFS(u.first.first);
    subtreeSize[v]+=subtreeSize[u.first.first];
    if(subtreeSize[u.first.first]>subtreeSize[g[v][0]])
      swap(g[v][last],g[v][0]);
  }
}

int lca(int a, int b) {
  if(depth[b]>depth[a]) swap(a,b);
  for(int i=19;i>=0;i--) {
    if(depth[jumpPointer[i][a]]>=depth[b]) a = jumpPointer[i][a];
  }
  if(a==b) return a;
  for(int i=19;i>=0;i--) {
    if(jumpPointer[i][a]!=jumpPointer[i][b]) {
      a=jumpPointer[i][a];
      b=jumpPointer[i][b];
    }
  }
  return parent[a];
}

int query(int a, int b, int v, int p, int q) {
  if(a>b) return 0;
  if(q<a || p>b) return 0;
  if(p>=a && q<=b) return d[v];
  int s = (p+q)/2;
  return max( query(a,b,2*v,p,s), query(a,b,2*v+1,s+1,q) );
}

int update(int p, int x) {
  p = lv-1+normalToTree[p];
  d[p]=x;
  while(p/=2) {
    d[p] = max(d[2*p],d[2*p+1]);
  }
}

int query(int a, int b) {
  int ans=0;
  int c = lca(a,b);
  while(top[a]!=top[c]) {
    //cout<<normalToTree[top[a]]<<"a "<<normalToTree[a]<<"\n";
    ans = max(ans, query(normalToTree[top[a]],normalToTree[a],1,1,lv));
    a = top[a];
    if(parent[a]==c) break;
    else a = parent[a];
  }
  if(top[a]==top[c]) ans = max(ans, query(normalToTree[c]+1,normalToTree[a],1,1,lv));
  //cout<<normalToTree[c]+1<<"b "<<normalToTree[a]<<"\n";

  while(top[b]!=top[c]) {
    ans = max(ans, query(normalToTree[top[b]],normalToTree[b],1,1,lv));
    //cout<<normalToTree[top[b]]<<"c "<<normalToTree[b]<<"\n";
    b = top[b];
    if(parent[b]==c) break;
    else b = parent[b];
  }
  if(top[a]==top[c]) ans = max(ans, query(normalToTree[c]+1,normalToTree[b],1,1,lv));
  //cout<<normalToTree[c]+1<<"d "<<normalToTree[b]<<"\n";
  return ans;
}

void hldDFS(int v, int x=1) {
  normalToTree[v]=++currId;
  treeToNormal[currId]=v;
  top[v]=x;
  for(int u : g[v]) {
    hldDFS(u, u==g[v][0] ? x : u);
  }
}

int main() {
  cin>>t;
  while(t--) {
    cin>>n;

    gi = new vector<pair<pair<int,int>,int> >[n+1];
    subtreeSize = new int[n+1];
    cost = new int[n+1];
    parent = new int[n+1];
    g = new vector<int>[n+1];
    top  = new int[n+1];
    normalToTree = new int[n+1];
    treeToNormal = new int[n+1];
    depth = new int[n+1];
    edgeToVertex = new int[n];

    for(int i=1;i<n;i++) {
      cin>>a>>b>>c;
      gi[a].push_back(make_pair(make_pair(b,c),i));
      gi[b].push_back(make_pair(make_pair(a,c),i));
    }
    parent[1]=1;
    depth[1]=1;
    rootDFS(1);
    hldDFS(1);
    for(lv=1;lv<n;lv*=2);
    d = new int[2*lv];
    for(int i=1;i<=n;i++) d[lv+normalToTree[i]-1]=cost[i];
    for(int i=n;i<lv;i++) d[lv+i]=0;
    for(int i=lv-1;i>0;i--) d[i]=max(d[2*i],d[2*i+1]);

    for(int i=0;i<20;i++) jumpPointer[i] = new int[n+1];
    for(int i=1;i<=n;i++) jumpPointer[0][i]=parent[i];
    for(int i=1;i<20;i++) for(int j=1;j<=n;j++) jumpPointer[i][j]=jumpPointer[i-1][jumpPointer[i-1][j]];

    string op;
    do {
      cin>>op;
      if(op=="QUERY") {
        cin>>a>>b;
        cout<<query(a,b)<<"\n";
      }
      else if(op=="CHANGE") {
        cin>>a>>b;
        update(edgeToVertex[a],b);
      }
    } while(op!="DONE");
  }
}
