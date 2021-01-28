#include <bits/stdc++.h>
using namespace std;

int n;
int* x;
int* y;
int m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  x = new int[n];
  y = new int[n];
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>y[i];

  for(int i=1;i<n;i++) {
    if(x[i] * y[m] < x[m] * y[i]) m = i;
  }

  cout<<x[m]<<" "<<y[m]<<"\n";
}
