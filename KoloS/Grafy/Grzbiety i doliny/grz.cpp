#include<bits/stdc++.h>
using namespace std;

struct Point {
	short x,y;
	Point(short x, short y) : x(x), y(y) {}
};

short n;
int tab[1003][1003];
bitset<1003> vis[1003];
int dz;
int g,d;
vector<Point> v;

bool operator<(const Point &a, const Point &b) {
	return tab[a.y][a.x] > tab[b.y][b.x];
}

stack<Point> s;
void dfs(int xx, int yy, bool zn) {
	s.push(Point(xx,yy));
	Point p(0,0);
	int x,y;
	while(!s.empty()) {
		p=s.top();
		s.pop();
		x=p.x;
		y=p.y;
		if(vis[y][x]) continue;
		vis[y][x]=1;
		dz--;
		for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if((i!=0 || j!=0) && y+i>=0 && x+j>=0 && y+i<n && x+j<n && (zn ? tab[y+i][x+j]<=tab[y][x] : tab[y+i][x+j]>=tab[y][x]) && vis[y+i][x+j]==0) s.push(Point(x+j, y+i));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int y=0;y<n;y++) {
		for(int x=0;x<n;x++) {
			cin>>tab[y][x];
			vis[y][x]=0;
			v.push_back(Point(x,y));
		}
	}

	sort(v.begin(), v.end());
	dz = n*n;

	for(int i=0;dz>0;i++) if(!vis[v[i].y][v[i].x]) {
		dfs(v[i].x, v[i].y, 1);
		g++;
	}

	dz = n*n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) vis[i][j]=0;

	for(int i=v.size()-1;dz>0;i--) if(!vis[v[i].y][v[i].x]) {
		dfs(v[i].x, v[i].y, 0);
		d++;
	}
	cout<<g<<" "<<d;
}
