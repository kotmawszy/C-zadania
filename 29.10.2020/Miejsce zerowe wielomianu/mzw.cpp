#include <iostream>
#include <iomanip>
using namespace std;

double a,b,c,d,p,q;

double f(double x) {
  return a*x*x*x + b*x*x + c*x + d;
}
double df(double x) {
  return 3*a*x*x + 2*b*x + c;
}

int main() {
  cin>>a>>b>>c>>d>>p>>q;

  double g = (p+q)/2;
  for(int i=0;i<20;i++) {
    g = g-f(g)/df(g);
  }
  if(abs(f(g))<0.000001) {
    cout<<fixed<<setprecision(2)<<g;
    return 0;
  }

  g = p-10;
  for(int i=0;i<20;i++) {
    g = g-f(g)/df(g);
  }
  if(abs(f(g))<0.000001) {
    cout<<fixed<<setprecision(2)<<g;
    return 0;
  }

  g = q+10;
  for(int i=0;i<20;i++) {
    g = g-f(g)/df(g);
  }
  cout<<fixed<<setprecision(2)<<g;
}
