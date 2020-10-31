#include <iostream>
#include <iomanip>
// nie ma tu nic więcej
using namespace std;

int n;

float f(float x) {
  return x*x-n;
}
float df(float x) {
  return 2*x;
}

int main() {
  cin>>n;
  float g = 1;
  for(int i=0;i<20;i++) {
    g = g-f(g)/df(g);
  }
  cout<<fixed<<setprecision(2)<<g;
}
