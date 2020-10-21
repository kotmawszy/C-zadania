#include <bits/stdc++.h>
using namespace std;

int n;
int tab[1007][1007];
bool v[1007][1007];
int ox,oy;

bool isBomba(int x, int y) {
	if(x<0 || x>=n || y<0 || y>=n) return false;
	return tab[x][y]==-1;
}
int countBomba(int x, int y) {
	int il=0;
	for(int i=-1;i<=1;i++) {
		for(int j=-1;j<=1;j++) {
			if(i!=0 || j!=0) {
				il+=isBomba(x+i,y+j);
			}
		}
	}
	return il;
}
void f(int x, int y) {
	if(x<0 || x>=n || y<0 || y>=n) return;
	if(v[x][y]) return;
	v[x][y]=1;
	if(tab[x][y]!=0) return;
	for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if(i!=0 || j!=0) f(x+i,y+j);
}

int main() {
	string s;
	cin>>n;
	for(int y=0;y<n;y++) {
		cin>>s;
		for(int x=0;x<n;x++) {
			tab[x][y]=(s[x]=='#' ? -1 : 0);
		}
	}
	cin>>ox>>oy;
	--ox,--oy;
	if(isBomba(ox,oy)) {
		cout<<"BUM!";
		return 0;
	}

	for(int y=0;y<n;y++) {
		for(int x=0;x<n;x++) {
			if(tab[x][y]!=-1) tab[x][y]+=countBomba(x,y);
		}
	}
	f(ox,oy);

	for(int y=0;y<n;y++) {
		for(int x=0;x<n;x++) {
			if(!v[x][y]) cout<<".";
			else if(tab[x][y]==0) cout<<"x";
			else cout<<tab[x][y];
		}
		cout<<"\n";
	}
}
