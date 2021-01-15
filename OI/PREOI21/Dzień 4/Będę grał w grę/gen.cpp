#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int x = atoi(argv[1]);
  cout<<"1 4 5\n";
  for(int i=0;i<20;i++) {
    cout<<(x&1 ? "." : "X");
    x>>=1;
    if(i%5==4) cout<<"\n";
  }
}
