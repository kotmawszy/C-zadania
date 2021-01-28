#include <bits/stdc++.h>
using namespace std;

int n;
float* x;
float* y;
float mv=numeric_limits<float>::max();
int mi;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  x = new float[n];
  y = new float[n];
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>y[i];

  for(int i=0;i<n;i++) {
    float z = x[i]/y[i];
    if(z<mv) mv=z,mi=i;
  }

  cout<<x[mi]<<" "<<y[mi]<<"\n";
}
