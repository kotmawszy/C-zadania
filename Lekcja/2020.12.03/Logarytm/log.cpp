#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double abss(double x) {
  if(x<0) return -x;
  return x;
}

double logarytm(double a, double b) {
  double n=1;
  double logan=0;

  double m=a;
  double logam=1;
  while(m<=b) {
    m*=a;
    logam++;
  }

  while(abss(logan-logam)>=0.001){
    double k = sqrt(n*m);
    double logak = (logan+logam)/2;

    if(k>b) {
      m = k;
      logam = logak;
    } else {
      n = k;
      logan = logak;
    }
  }

  return logan;
}

int main() {
  double a,b;
  cin>>a>>b;
  cout<<fixed<<setprecision(2)<<logarytm(a,b);
  return 0;
}
