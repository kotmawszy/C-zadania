#include <bits/stdc++.h>
using namespace std;

const long long P = 127;
const long long MOD = 2147483647;

//szybkie modulo przez liczę piewszą mersene'a
long long modulo(long long x) { // zwraca modulo z x przez MOD
  return (x&MOD) + (x>>31);
}

int n;
int a[500007]; // a[i] - czy w i-tym zapytaniu dopisywaliśmy literę z przodu (1) czy z tyłu (2)
char b; // pomocnicza do wczytywania
long long h[500007]; // hash sufiksu stringa s ( np dla s="abc", h = [ 'a'*p^2+'b'*p+'c' , 'a'*p+'c' , 'c' ] )
pair<int,int> subs[500007]; // subs[i] to taka para (p,q), że po wczytaniu i-tej linijki, cały string jest taki sam jak podciąg końcowego stringa s od p do q
string s; // końcowy string
int pfx[500007];
int power[500007]; // potęgi liczby P
list<char> l;

long long sub(int a, int b) { // zwraca hash dla podciągu [p,q]
  return modulo(h[a] + MOD - modulo(h[b+1]*power[b-a+1]));
}

bool daSie(int d, int r) { // zwraca czy dany
  if(r<d) return 1;
  return sub(subs[r].first,subs[r].second-d)==sub(subs[r].first+d,subs[r].second);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  power[0]=1;
  for(int i=1;i<500007;i++) power[i]=modulo(power[i-1]*P);

  cin>>n;
  h[0]=0;
  for(int i=1;i<=n;i++) {
    cin>>a[i]>>b;
    if(a[i]==1) l.push_back(b);
    else l.push_front(b);
  }
  for(list<char>::iterator i=l.begin();i!=l.end();i++) s+=*i;
  subs[n]={1,n};
  for(int i=n-1;i>0;i--) {
    subs[i]=subs[i+1];
    if(a[i+1]==2) subs[i].first++;
    else subs[i].second--;
  }
  for(int i=1;i<=n+1;i++) pfx[i]=0;

  h[n+1]=0;
  h[n]=s[n-1];
  for(int i=n-1;i>0;i--) h[i]=modulo(h[i+1]*P+s[i-1]);


  for(int i=1;i<=n;i++) {
    int p = 1;
    int q = n;
    while(p+1<q) {
      int r = (p+q)/2;
      if(daSie(i,r)) p=r;
      else q=r-1;
    }
    if(daSie(i,p+1)) p++;
    pfx[i]++;
    pfx[p+1]--;
  }
  int su=0;
  for(int i=1;i<=n;i++) cout<<(su+=pfx[i])<<"\n";
}
