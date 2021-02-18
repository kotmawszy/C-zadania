#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,char> >* g;
vector<int>* nrk;
map<string,bool> ans;
int a,b;
char c;
bool* vis;
bool* vis2;
bool* ds;

bool f(int v, string s) {
	//cout<<"v: "<<v<<"\n";
	if(s.size()==0) return true;
	vis2[v]=1;
	bool dss=0;
	for(int i=0;i<g[v].size();i++) {
		pair<int,char> u = g[v][i];
		int j = nrk[v][i];
		if(!vis2[u.first] && s[0]==u.second) {
			if(f(u.first,s.substr(1,s.size()-1))) {
				ds[j]=1;
				dss=1;
				//cout<<"da sie z "<<v<<" do "<<u.first<<"\n";
			}
		}
	}
	return dss;
}

bool daSie(string s) {
	for(int i=1;i<n;i++) ds[i]=0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) vis2[j]=0;
		f(i,s);
		//cout<<"po wywolaniu f "<<i<<"\n";
		//for(int j=1;j<n;j++) if(ds[j]) cout<<j<<" "; cout<<"\n";
	}
	for(int j=1;j<n;j++) if(!ds[j]) return false;
	return true;
}
void sciezka(int v, string s) {
	vis[v]=1;
	if(ans.find(s)==ans.end()) {
		//cout<<s<<"\n";
		ans[s]=daSie(s);
		//cout<<s<<": "<<ans[s]<<"\n";
		//return;
	}
	for(pair<int,char> u : g[v]) if(!vis[u.first]) {
		sciezka(u.first,s+u.second);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	g = new vector<pair<int,char> >[n+1];
	nrk = new vector<int>[n+1];
	vis = new bool[n+1];
	vis2 = new bool[n+1];
	ds = new bool[n+1];
	for(int i=1;i<n;i++) {
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
		nrk[a].push_back(i);
		nrk[b].push_back(i);
	}

	for(int j=1;j<=n;j++) {
		for(int i=1;i<=n;i++) vis[i]=0;
		sciezka(j,"");
	}

	long long s=0;
	for(auto i : ans) if(i.second) s++;
	cout<<s<<"\n";
	for(auto i : ans) {
		if(i.second) cout<<i.first<<"\n";
	}
}
