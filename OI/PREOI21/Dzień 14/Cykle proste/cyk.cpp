#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int> >* g;
pair<int,int>* e;
int a,b;
int* deg; // stopień danego wierzchołka (krawędzie tylko do wierzchołków w danym przedziale)
pair<int,int>* einterval;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;

	g = new vector<pair<int,int> >[n+1];
	e = new pair<int,int>[m+1];
	deg = new int[n+1];
	einterval = new int[m+1];
	for(int i=1;i<=n;i++) {
		deg[i]=0;
	}

	for(int i=1;i<=m;i++) {
		cin>>a>>b;
		g[a].push_back({b,i});
		g[b].push_back({a,i});
		e[i] = {a,b};
	}

	int zle=0; // ile wierzchołków w przedziale ma
	int p=1; // początek gąsiennicy
	for(int q=1;q<=n;q++) { // koniec gasiennicy
		// dodanie q wierzchołka do przedziału
		for(pair<int,int> u : g[q]) if(p <= u.first && u.first <= q) {
			// dla każdego sąsiada należącego do przedziału
			deg[q]++;
			deg[u.first]++;
			if(deg[q]==3) zle++;
			if(deg[u.first]==3) zle++;
			einterval[u.second].first = q;
		}
		// usunięcie krawędzi z początku gąsiennicy
		while(zle) {
			for(pair<int,int> u : g[p]) if(p <= u.first && u.first <= q) {
				// dla każdego sąsiada należącego do przedziału
				if(deg[q]==3) zle--;
				if(deg[u.first]==3) zle--;
				deg[p]--;
				deg[u.first]--;
				einterval[u.second].second = p;
			}
			p++;
		}
	}
	while(p<=n) {
		for(pair<int,int> u : g[p]) if(p <= u.first && u.first <= q) {
			// dla każdego sąsiada należącego do przedziału
			deg[p]--;
			deg[u.first]--;
			einterval[u.second].second = p;
		}
		p++;
	}
}
