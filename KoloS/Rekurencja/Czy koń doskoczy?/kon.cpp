#include <bits/stdc++.h>
using namespace std;

bool tab[1007][1007];
bool v[1007][1007];
int xk,yk,xw,yw;
bool done = false;
int n;

void f(int x, int y) {
	if(v[x][y]==1) return;
	v[x][y]=1;
	if(x<0 || x>=n || y<0 || y>=n) return;
	if(x==xw && y==yw) {
		done=1;
		return;
	}
	if(tab[x][y]==0) return;
	f(x-1,y+2);
	f(x+1,y+2);
	f(x+2,y+1);
	f(x+2,y-1);
	f(x+1,y-2);
	f(x-1,y-2);
	f(x-2,y-1);
	f(x-2,y+1);
}

int main() {
	string s;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>s;
		for(int j=0;j<n;j++) {
			tab[i][j] = (s[j]!='x');
			if(s[j]=='k') xk=i,yk=j;
			if(s[j]=='w') xw=i,yw=j;
		}
	}
	f(xk,yk);
	cout<<(done ? "TAK" : "NIE");
}
