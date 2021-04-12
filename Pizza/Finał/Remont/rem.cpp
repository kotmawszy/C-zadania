#include <bits/stdc++.h>
using namespace std;

int t,n,m;
vector<int>* g;
vector<int>* gt;
int a,b,c,d;
vector<int> tsort;
bool* vis;
bool* value;
int* component;
int currentComponent;
int* tab;

void dfs1(int v) {
	if(vis[v]) return;
	vis[v]=1;
	for(int u : g[v]) dfs1(u);
	tsort.push_back(v);
}
void dfs2(int v) {
	if(component[v]) return;
	component[v]=currentComponent;
	for(int u : gt[v]) dfs2(u);
}

void addAlternative(int a, bool b, int c, bool d) {
  g[(2*a-1)^b].push_back((2*c-2)^d);
  g[(2*c-1)^d].push_back((2*a-2)^b);
  gt[(2*c-2)^d].push_back((2*a-1)^b);
  gt[(2*a-2)^b].push_back((2*c-1)^d);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

  cin>>t;
  while(t--) {
  	cin>>n>>m;

  	g = new vector<int>[4*n];
  	gt = new vector<int>[4*n];
  	vis = new bool[4*n];
  	value = new bool[2*n];
  	component = new int[4*n];
    tab = new int[n+1];
    currentComponent=0;
    tsort.clear();

    for(int i=1;i<=n;i++) cin>>tab[i];

    addAlternative(1,0,1,0);
    addAlternative(n-1,0,n-1,0);

    for(int i=1;i<n-1;i++) addAlternative(i,0,i+1,0);

    for(int i=1;i<n-1;i++) {
      for(int j=i+1;j<n;j++) {
        if(tab[j]==tab[i] && tab[j+1]==tab[i+1]) {
          //cout<<"z "<<i<<" do "<<j<<"\n";
          addAlternative(i,1,j,1);
        }
      }
    }

  	for(int i=0;i<4*n;i++) vis[i]=component[i]=0;
  	for(int i=0;i<4*n;i++) if(!vis[i]) dfs1(i);
  	for(int i=4*n-1;i>=0;i--) if(!component[tsort[i]]) {
  		++currentComponent;
  		dfs2(tsort[i]);
  	}

    /*for(int i=0;i<4*n;i++) {
      cout<<i<<": ";
      for(int j : g[i]) cout<<j<<" ";
      cout<<"\n";
    }*/

    bool ok=1;
  	for(int i=0;i<4*n;i+=2) {
  		if(component[i]==component[i+1]) {
  			if(ok) cout<<"NIE\n";
        ok=0;
  		}
  		value[i/2]=component[i]<component[i+1];
  	}
  	if(ok) cout<<"TAK\n";
  }
}
