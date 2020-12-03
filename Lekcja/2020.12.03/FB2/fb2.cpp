//fajny szereg tylora generalnie
#include <iostream>
#include <iomanip>
using namespace std;

double abs(double x) {
  if(x<0) return -x;
  return x;
}

long long factorial(int x) {
  long long s = 1;
  for(int i=2;i<=x;i++) s*=i;
  return s;
}

double pow(double x, int y) {
  double s=1;
  while(y--) s*=x;
  return s;
}

double sin(double x) {
  double s,prevs;
  s = 0;
  for(int n=0;;n++) {
    prevs = (n==0 ? 100 : s);
    double y = (n%2 ? -1 : 1) * pow(x,2*n+1) / factorial(2*n+1);
    s += y;
    if(abs(s-prevs)<0.00005) break;
  }
  if(s<0 && s>-0.0001) return 0;
  return s;
}

int main() {
  double x;
  cin>>x;
  cout<<fixed<<setprecision(4)<<sin(x);
}
