#include <bits/stdc++.h>
using namespace std;

float integral(float x) {
  return pow(x,3)/100.0-pow(x,2)/400.0+x;
}

int main() {
  float x;
  cin>>x;
  cout<<fixed<<setprecision(2)<<integral(x);
}
