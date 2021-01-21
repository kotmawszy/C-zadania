#include <bits/stdc++.h>
using namespace std;

const int R = 200;
const int C = 320;

int s;
int arr[R+1][C+1];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) cin>>arr[i][j];

  for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) {
    bool b=0;
    if(i>1 && abs(arr[i][j]-arr[i-1][j])>128) b=1;
    if(i<R && abs(arr[i][j]-arr[i+1][j])>128) b=1;
    if(j>1 && abs(arr[i][j]-arr[i][j-1])>128) b=1;
    if(j<C && abs(arr[i][j]-arr[i][j+1])>128) b=1;
    s+=b;
  }
  cout<<s;
}
