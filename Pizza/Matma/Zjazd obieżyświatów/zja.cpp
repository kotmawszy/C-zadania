#include <bits/stdc++.h>
using namespace std;

const int maxN = 250;
const int maxPOW = 58;
int n,m,k;
bitset<maxN> matrix[maxPOW+1][maxN];
long long pot[maxPOW+1];
int* start;
int a,b;
bitset<maxN> curr[maxN];
bitset<maxN> _next[maxN];

bool check() {
  for(int i=0;i<n;i++) {
    bool dasie=1;
    for(int j=0;j<k;j++) if(_next[start[j]-1][i]==0) dasie=0;
    if(dasie) return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;
  start=new int[k];
  for(int i=0;i<k;i++) cin>>start[i];
  while(m--) {
    cin>>a>>b;
    matrix[1][a-1][b-1]=1;
  }
  pot[1]=1;
  for(int p=2;p<=maxPOW;p++) {
    pot[p]=2*pot[p-1];
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        for(int k=0;k<n;k++) {
          if(matrix[p-1][i][k]&matrix[p-1][k][j]) {
            matrix[p][i][j]=1;
            break;
          }
        }
      }
    }
  }
  for(int i=0;i<n;i++) curr[i][i]=1;
  long long suma=0;
  for(int p=maxPOW;p>=1;p--) {
  //for(int p=0;p<5;p++) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        for(int k=0;k<n;k++) {
          _next[i][j]=0;
          if(curr[i][k]&matrix[p][k][j]) {
            _next[i][j]=1;
            break;
          }
        }
      }
    }
    if(!check()) {
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
          curr[i][j]=_next[i][j];
        }
      }
      suma+=pot[p];
    }
  }
  suma++;
  if(suma==288230376151711744) cout<<"NIE\n";
  else cout<<"TAK\n"<<suma<<"\n";
}
