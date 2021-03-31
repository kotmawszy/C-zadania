#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int a,b,x;
pair<int,int>* d;
bool* d2;
int lv=1;
int s;

void insertToVertex(int v, pair<int,int> x) {
	if(x.first==0 && x.second==0) return;
	if(d[v].first==0 && d[v].second==0) d[v]=x;
	else if(x.first == d[v].second+1) d[v].second=x.second;
	else d2[v]=0;
}

void push(int v) {
	if(d2[v]==0 && v<lv) {
		d2[2*v]=0;
		d2[2*v+1]=0;
	}
	if(d[v].first==0 && d[v].second==0) return;
	if(v>=lv) return;
	insertToVertex(2*v,d[v]);
	insertToVertex(2*v+1,d[v]);
	d[v]={0,0};
}

void insert(int a, int b, int v, int p, int q, int x) {
	push(v);
	if(q<a || p>b) return;
	if(p>=a && q<=b) {
		insertToVertex(v,{x,x});
		return;
	}
	int r = (p+q)/2;
	insert(a,b,2*v,p,r,x);
	insert(a,b,2*v+1,r+1,q,x);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>k;

	while(lv<n) lv*=2;
	d = new pair<int,int>[2*lv];
	d2 = new bool[2*lv];
	for(int i=0;i<2*lv;i++) d[i]={0,0},d2[i]=1;

	while(m--) {
		cin>>a>>b>>x;
		insert(a,b,1,1,lv,x);
	}

	for(int i=1;i<lv;i++) push(i);
	//for(int i=1;i<2*lv;i++) cout<<i<<": "<<d[i].first<<" "<<d[i].second<<"  "<<d2[i]<<"\n";
	//cout<<"\n\n";
	for(int i=0;i<n;i++) if(d[lv+i].first==1 && d[lv+i].second==k && d2[lv+i]) s++;
	cout<<s<<"\n";
}
