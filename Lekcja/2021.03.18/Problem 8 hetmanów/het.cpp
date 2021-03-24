#include <bits/stdc++.h>
using namespace std;

int tab[16][16];
int n;
int s;
bool wiersz[16];
bool skosPrawy[32];
bool skosLewy[32];

void ustaw(int w, int k) {
  wiersz[w]=1;
  skosPrawy[k-w+n]=1;
  skosLewy[k+w-1]=1;
}
void zdejmij(int w, int k) {
  wiersz[w]=0;
  skosPrawy[k-w+n]=0;
  skosLewy[k+w-1]=0;
}
bool sprawdz(int w, int k) {
  return wiersz[w]==0 && skosPrawy[k-w+n]==0 && skosLewy[k+w-1]==0;
}

void f(int k) {
  for(int w=1;w<=n;w++) {
    if(sprawdz(w,k)) {
      ustaw(w,k);
      if(k<n) f(k+1);
      else s++;
      zdejmij(w,k);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n;
  f(1);
  cout<<s;
}
