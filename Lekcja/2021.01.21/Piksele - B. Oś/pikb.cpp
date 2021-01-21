#include <bits/stdc++.h>
using namespace std;

const int R = 200;
const int C = 320;

int s;
int a;
int arr[C+1];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=1;i<=R;i++) {
    bool c=0;
    for(int j=1;j<=C;j++) {
      cin>>a;
      arr[j]=a;
      if(C-j+1<j && arr[C-j+1]!=a) c=1;
    }
    s+=c;
  }
  cout<<s;
}
