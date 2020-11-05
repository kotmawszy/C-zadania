#include <bits/stdc++.h>
using namespace std;

double a,b,p,q;

double f(double x) {
  return a*x*x*x+b*x*x;
}

double step = 0.001;
int main() {
  cin>>a>>b>>p>>q;
  double s = 0;
  for(double i=p;i<q;i+=step) {
    s+=sqrt( (f(i+step)-f(i))*(f(i+step)-f(i)) + step*step );
  }
  cout<<fixed<<setprecision(3)<<s;
}
