#include <bits/stdc++.h>
using namespace std;

int n,m;
int a,b;
vector<int>* g;
bool ans=0;

void f(vector<int> v) {
	int s=v.size()-1;
	int dz=0;
	for(int i=1;i<=s;i++) if(v[i]==0) {dz=i;break;}
	if(dz==0) {
		cout<<"TAK\n";
		int aaa[s+1];
		for(int i=1;i<=s;i++)  aaa[v[i]]=i;
		for(int i=1;i<=s;i++) cout<<aaa[i]<<" "; cout<<"\n";
		ans=1;
		return;
	}
	bool dost[s+1];
	for(int i=1;i<=s;i++) dost[i]=1;
	for(int i=1;i<=s;i++) if(v[i]) dost[v[i]]=0;
	for(int i=1;i<=s;i++) if(dost[i]) {
		int iw = g[i].size();
		int il = 0;
		for(int j=0;j<g[i].size();j++) {
			if(!dost[g[i][j]] && g[i][j]!=2) il++;
		}
		if(2*il!=iw) continue;
		v[dz]=i;
		f(v);
		if(ans) return;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	g = new vector<int>[n+1];
	for(int i=0;i<m;i++) {
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> v;
	v.resize(n+1);
	v[0]=0;
	v[1]=1;
	v[n]=2;
	for(int i=2;i<n;i++) v[i]=0;
	f(v);
	if(ans==0) cout<<"NIE\n";
}
