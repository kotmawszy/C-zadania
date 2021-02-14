#include <bits/stdc++.h>
#include "dlulib.h"
using namespace std;

map<int,int> m;
int spr(int x) {
  if(m.find(x)==m.end()) m[x]=sprawdz(x);
  return m[x];
}

int main() {
  int n = daj_n();

  if(spr(1)>spr(n)) {
    // góra dół góra
    int p = 1;
    int q = n;
    while(q-p>0) {
      int s = (p+q)/2;
      if(spr(s)>spr(s+1)) { // malejące
        q=s;
      } else { // rośnie
        if(spr(s)<spr(1)) { // ostatnie rosnące
          q=s-1;
        } else { // pierwsze rosnące
          p=s+1;
        }
      }
    }
    odpowiedz(spr(p));
  } else {
    // dół góra dół
    int p = 1;
    int q = n;
    while(q-p>0) {
      int s = (p+q)/2;
      if(spr(s)>spr(s+1)) { // malejące
        if(spr(s)<spr(1)) { // pierwsze malejące
          p=s+1;
        } else { // ostatnie malejące
          q=s;
        }
      } else { // rośnie
        p=s+1;
      }
    }
    odpowiedz(spr(p));
  }
}
