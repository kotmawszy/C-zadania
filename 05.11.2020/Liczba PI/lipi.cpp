#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(time(NULL));
  int n = 1000000;
  float p = n;
  int w = 0;
  for(int i=0;i<n;i++) {
    float x = (rand()%1000)/1000.0;
    float y = (rand()%1000)/1000.0;
    if(x*x+y*y<=1) w++;
  }
  cout<<fixed<<setprecision(2)<<4*w/p;
}
