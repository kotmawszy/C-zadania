#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>* g;
int a,b;
int s;
int p,q;
int* vis;
bool found,ok;
stack<int> st;

void dfs(int v) {
	if(vis[v]) return;
	vis[v]=1;
	int iw=0;
	for(int u : g[v]) if(u<=q && u>=p) {dfs(u);iw++;}
	if(iw!=2) ok=0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	g = new vector<int>[n+1];
	vis = new int[n+1];

	while(m--) {
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++) sort(g[i].begin(), g[i].end());


	for(p=1;p<=n;p++) {
		for(q=p+1;q<=n;q++) {
			for(int i=1;i<=n;i++) vis[i]=0;
			ok=1;
			dfs(p);
			for(int i=p;i<=q;i++) if(!vis[i]) ok=0;
			if(ok) s++;
		}
	}
	cout<<s<<"\n";
}
