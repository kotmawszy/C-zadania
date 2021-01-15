#include <bits/stdc++.h>
using namespace std;

int r,c,m;
bitset<503> mapa[503];
string op;
string in;
bitset<503> b[503];
bitset<503> bn[503];

void printMapa() {
  for(int i=1;i<=r;i++) {
    for(int j=1;j<=c;j++) cout<<b[i][j];
    cout<<"\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>r>>c>>m;
  for(int i=1;i<=r;i++) {
    cin>>in;
    for(int j=0;j<c;j++) mapa[i][j+1]=(in[j]=='.');
  }
  cin>>op;

  for(int i=1;i<=r;i++) b[i]=mapa[i];

  for(int i=0;i<m;i++) {
    for(int j=1;j<=r;j++) bn[j]=0;

    if(op[i]=='E' || op[i]=='?') {
      for(int j=1;j<=r;j++) bn[j]|=(b[j]<<1);
    }
    if(op[i]=='W' || op[i]=='?') {
      for(int j=1;j<=r;j++) bn[j]|=(b[j]>>1);
    }
    if(op[i]=='N' || op[i]=='?') {
      for(int j=2;j<=r;j++) bn[j-1]|=b[j];
    }
    if(op[i]=='S' || op[i]=='?') {
      for(int j=1;j<r;j++) bn[j+1]|=b[j];
    }

    for(int j=1;j<=r;j++) b[j]=bn[j]&mapa[j];
  }
  int s=0;
  for(int i=1;i<=r;i++) {
    for(int j=1;j<=c;j++) {
      if(b[i][j]) s++;
    }
  }
  cout<<s;
}
