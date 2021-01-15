#include <bits/stdc++.h>
#include "ckuclib.h"
using namespace std;

int n,e;
const int MAXE = 22;
const int INF = 1000000000;

struct Frame {
  int k;
  int _jedno[MAXE];
  int _dwa[MAXE];
  int _polowa[MAXE];
  Frame* polowaFrame;

  Frame() {
    k=1;
    for(int i=0;i<MAXE;i++) {
      _jedno[i] = jedno(1);
      _dwa[i] = 0;
      _polowa[i] = INF;
    }
    polowaFrame = NULL;
  }

  void next() {
    k++;

    if(k==2) polowaFrame = new Frame();
    if(k%2) polowaFrame -> next();

    for(int i=0;i<MAXE;i++) {
      _polowa[i] = _dwa[i];
      _dwa[i] = _jedno[i];
      _jedno[i] = min({
        jedno(k) + _dwa[min(e+1,MAXE-1)],
        dwa(k) + _polowa[e],
        e>0 ? polowa(k) + polowaFrame->_jedno[e-1] : INF
      });
    }
  }

  void next(int x) {
    for(int i=0;i<x;i++) next();
  }
};

int main() {
  n = dajn();
  e = daje();

  Frame f;
  f.next(n-1);
  odpowiedz(f._jedno[min(e,MAXE-1)]);
}
