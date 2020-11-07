#include <bits/stdc++.h>
using namespace std;

int pfx[1003][1003];
int tab[1003][1003];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x_size,y_size,q,x1,y1,x2,y2;
  cin>>x_size>>y_size>>q;
  int s=x_size*y_size;
  while(q--) {
    cin>>x1>>y1>>x2>>y2;
    pfx[x2][y2]++;
    pfx[x2][y1]--;
    pfx[x1][y2]--;
    pfx[x1][y1]++;
  }

  for(int y=0;y<y_size;y++) {
    for(int x=0;x<x_size;x++) {
      tab[x+1][y+1]=tab[x][y+1]+tab[x+1][y]-tab[x][y]+pfx[x][y];
    }
  }

  for(int y=y_size-1;y>=0;y--) {
    for(int x=0;x<x_size;x++) {
      if(tab[x+1][y+1]) s--;
    }
  }
  cout<<s;
}
