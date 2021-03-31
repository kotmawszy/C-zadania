#include <bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int>* surowce;
int x,k;
int a,lasta;
bool* zliczone;
set<int>* g;
vector<int> t;
bool* vis;

void dfs(int v) {
	if(vis[v]) return;
	vis[v]=1;
	for(int u : g[v]) dfs(u);
	t.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	surowce = new pair<int,int>[n+1];
	g = new set<int>[n+1];
	vis = new bool[n+1];
	for(int i=1;i<=n;i++) cin>>surowce[i].first>>surowce[i].second;

	cin>>m;
	zliczone = new bool[n+1];
	while(m--) {
		for(int i=1;i<=n;i++) zliczone[i]=0;
		cin>>x>>k;
		if(k==0) continue;
		cin>>lasta;
		zliczone[lasta]=1;
		for(int i=1;i<k;i++) {
			cin>>a;
			zliczone[a]=1;
			g[a].insert(lasta);
			lasta=a;
		}
		for(int i=1;i<=n;i++) if(!zliczone[i] && surowce[i].first<=x && surowce[i].second>=x) g[i].insert(lasta);
	}

	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);

	for(int i : t) cout<<i<<" ";
}
