#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
const int maxm = 1000;
const int maxq = 10000;
const int maxa = 1000000000;

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand()%(maxn-1)+1;
    int m = rand()%(maxm-1)+1;
    int q = rand()%(maxq-1)+1;
    cout<<n<<" "<<m<<" "<<q<<"\n";
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) cout<<(rand()%(maxa-1)+1)<<" ";
      cout<<"\n";
    }
    while(q--) {
      int r1 = rand()%n+1;
      int r2 = rand()%n+1;
      int c1 = rand()%m+1;
      int c2 = rand()%m+1;
      cout<<min(r1,r2)<<" "<<min(c1,c2)<<" "<<max(r1,r2)<<" "<<max(c1,c2)<<"\n";
    }
}
