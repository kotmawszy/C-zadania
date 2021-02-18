#include <bits/stdc++.h>
using namespace std;

long long nwd(long long a, long long b) {
  if(a<b) swap(a,b);
  while(b) swap(a%=b,b);
  return a;
}

struct Liczba {
	long long p,q;
	void skroc() {
		long long d = nwd(p,q);
		p/=d;
		q/=d;
	}
	Liczba(long long p) : p(p), q(1) {}
	Liczba(long long p, long long q) : p(p), q(q) {
		skroc();
	}
	Liczba operator+(const Liczba& b) {
		return Liczba(p*b.q+b.p*q,q*b.q);
	}
	void divide(long long x) {
		q*=x;
		skroc();
	}
	void multiply(long long x) {
		p*=x;
		skroc();
	}
	Liczba getDivide(long long x) {
		Liczba l(p,q);
		l.divide(x);
		return l;
	}
	void print() {
		cout<<p<<"/"<<q<<" ";
	}
};

bool operator<(const pair<Liczba,Liczba>& a, const pair<Liczba,Liczba>& b) {
	if(a.first.p==b.first.p && a.first.q==b.first.q) return a.second.p * b.second.q < b.second.p * a.second.q;
	return a.first.p * b.first.q > b.first.p * a.first.q;
}

int n,X,z;
pair<int,int>* arr;
int* arrforbs;
int* in;
vector<vector<pair<Liczba,Liczba> > > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>X>>z;
	arr = new pair<int,int>[n-1];
	arrforbs = new int[n-1];
	in = new int[n];
	for(int i=0;i<n;i++) cin>>in[i];
	for(int i=1;i<n;i++) arr[i-1].first=in[i]-in[i-1], arr[i-1].second=i;
	sort(arr,arr+n-1);
	for(int i=0;i<n-1;i++) arrforbs[i]=arr[i].first;

	Liczba l(arr[n-2].first);
	int prevIleTakich=0;
	for(int i=1;;i++) {
		v.push_back(vector<pair<Liczba,Liczba> >());
		//cout<<"krok "<<i<<": \n";
		l.divide(2);
		//cout<<l.p<<"/"<<l.q<<"\n";
		int iletakich = arrforbs+n-upper_bound(arrforbs,arrforbs+n-1,l.p/l.q)-1;
		//if(iletakich<0) iletakich=0;
		//cout<<iletakich<<"\n";
		for(int j=n-iletakich-1;j<n-prevIleTakich-1;j++) v[v.size()-1].push_back(make_pair(Liczba(arrforbs[j]),Liczba(in[arr[j].second-1])));
		if(v.size()>=2) for(int j=0;j<v[v.size()-2].size();j++) {
			v[v.size()-1].push_back(make_pair(
				v[v.size()-2][j].first.getDivide(2),
				v[v.size()-2][j].second
			));
			v[v.size()-1].push_back(make_pair(
				v[v.size()-2][j].first.getDivide(2),
				v[v.size()-2][j].second+v[v.size()-2][j].first.getDivide(2)
			));
		}
		prevIleTakich=iletakich;
		//for(int j=0;j<n-1;j++) if(arr[j].first>l.p/l.q) cout<<arr[j].first<<","<<arr[j].second<<" ";
		//cout<<"\n";
		bool xd=0;
		for(int j=0;j<v[v.size()-1].size();j++) if(v[v.size()-1][j].first.p>v[v.size()-1][j].first.q) xd=1;
		if(xd==0) break;
	}
	for(int i=0;i<v.size();i++) sort(v[i].begin(),v[i].end());

	for(int i=0;i<v.size();i++) {
		cout<<i<<": ";
		for(int j=0;j<v[i].size();j++) {
			v[i][j].first.print();
			v[i][j].second.print();
			cout<<"   ";
		}
		cout<<"\n";
	}
	vector<int> poziom;
	poziom.push_back(0);
	for(int i=0;i<v.size();i++) poziom.push_back(v[i].size()+(poziom.size()==0 ? : poziom[poziom.size()-1]));
	//for(int i : poziom) cout<<i<<" "; cout<<"\n\n";
	int a;
	for(int i=0;i<z;i++) {
		cin>>a;
		int ktorypoziom = upper_bound(poziom.begin(),poziom.end(),a-1)-poziom.begin();
		if(ktorypoziom>=poziom.size()) {
			//a-=v[v.size()-1].size();
			int taliczba = v[v.size()-1].size();
			int ilerazydzielic=0;
			int todzielenie=taliczba;
			while(a>todzielenie) {
				a-=todzielenie;
				todzielenie*=2;
				ilerazydzielic++;
			}
			int jd = todzielenie/taliczba;
			//cout<<a<<" "<<ilerazydzielic<<" "<<(a-1)/jd<<" "<<(a-1)%jd<<"\n";
			Liczba wynik = v[v.size()-1][(a-1)/jd].second;
			Liczba dzielnik = v[v.size()-1][(a-1)/jd].first;
			for(int j=0;j<=ilerazydzielic;j++) dzielnik.divide(2);
			//wynik.print();
			dzielnik.multiply(2*((a-1)%jd)+1);
			//dzielnik.print();
			wynik = wynik + dzielnik;
			wynik.print();
			cout<<"\n";
			continue;
		}
		int ktorynapoziomie = a-poziom[ktorypoziom-1];
		//cout<<ktorypoziom<<" "<<ktorynapoziomie<<"\n";
		Liczba wynik = v[ktorypoziom-1][(ktorynapoziomie-1)].second;
		Liczba dodaj = v[ktorypoziom-1][(ktorynapoziomie-1)].first;
		dodaj.divide(2);
		wynik = wynik + dodaj;
		//cout<<"\n";
		wynik.print();
		cout<<"\n";
	}
}
