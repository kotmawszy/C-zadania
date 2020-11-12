#include <bits/stdc++.h>
using namespace std;

float k;
float w[15] = {500, 200, 100, 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
int s[15];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>k;
  while(k>=0.001) {
    for(int i=0;i<15;i++) {
      if(w[i]<=k) {
        k-=w[i];
        s[i]++;
        break;
      }
    }
  }
  for(int i=0;i<15;i++) {
    if(s[i]) {
      cout<<fixed<<setprecision(2)<<w[i];
      cout<<" "<<s[i]<<"\n";
    }
  }
}
