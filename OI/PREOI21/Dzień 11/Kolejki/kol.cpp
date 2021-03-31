#include <bits/stdc++.h>
using namespace std;

int n,m;
bool d;

vector<int> p;
int* nopops;
vector<int> numbers;
int* jumpdist;
vector<int*> jp;

char t;
int x,k,l;

void insert(int k, int x) {
	int nnew = numbers.size();
	numbers.push_back(x);
	if(p[k]==k) p.push_back(nnew);
	else p.push_back(p[k]);
	p[k]=nnew;
	jumpdist[k]++;
	jp.push_back(new int[22]);
	jp[nnew][0]=p[nnew];
	for(int j=1;j<=m;j++) jp[nnew][j]=jp[jp[nnew][j-1]][j-1];
	jp[k][0]=p[k];
	for(int j=1;j<=m;j++) jp[k][j]=jp[jp[k][j-1]][j-1];
}
int get(int k) {
	int v=k;
	//for(int i=0;i<jumpdist[k];i++) v=p[v];
	int jd = jumpdist[k];
	for(int i=0;jd;i++) {
		if(jd%2) v=jp[v][i];
		jd/=2;
	}
	jumpdist[k]--;
	return numbers[v];
}
void copy(int k, int l) {
	if(p[l]==l) {
		p[k]=k;
		jp[k][0]=p[k];
		for(int j=1;j<=m;j++) jp[k][j]=jp[jp[k][j-1]][j-1];
		jumpdist[k]=0;
		return;
	}
	p[k]=p[l];
	jumpdist[k]=jumpdist[l];
	jp[k][0]=p[k];
	for(int j=1;j<=m;j++) jp[k][j]=jp[jp[k][j-1]][j-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

  cin>>n>>m>>d;
  int a=0;
	nopops = new int[m+1];
	jumpdist = new int[m+1];
	numbers.resize(m+1);
	p.push_back(0);
	jp.push_back(new int[1]);
	for(int i=1;i<=m;i++) {
		p.push_back(i);
		nopops[i]=0;
		jumpdist[i]=0;
		jp.push_back(new int[22]);
		for(int j=0;j<22;j++) jp[i][j]=i;
	}
  while(n--) {
	/*for(int i=0;i<jp.size();i++) {
		cout<<i<<":";
		for(int j=0;j<5;j++) cout<<" "<<jp[i][j];
		cout<<"\n";
	}
	cout<<"\n\n";*/
    cin>>t;
    if(t=='U') {
      cin>>x>>k;
      if(d) x^=a, k^=a;
			insert(k,x);
    } else if(t=='Z') {
      cin>>k;
      if(d) k^=a;
      a=get(k);
      cout<<a<<"\n";
    } else if(t=='I') {
      cin>>k>>l;
      if(d) k^=a, l^=a;
			copy(k,l);
    }
  }
	for(int i=0;i<jp.size();i++) {
		cout<<i<<":";
		for(int j=0;j<5;j++) cout<<" "<<jp[i][j];
		cout<<"\n";
	}
}
