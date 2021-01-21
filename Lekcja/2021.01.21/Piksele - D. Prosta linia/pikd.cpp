#include <bits/stdc++.h>
using namespace std;

const int R = 200;
const int C = 320;

int mx;
int curr;
int arr[R+1][C+1];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) cin>>arr[i][j];

  for(int j=1;j<=C;j++) {
    for(int i=1;i<=R;i++) {
      if(i==1 || arr[i][j]!=arr[i-1][j]) curr=0;
      curr++;
      mx = max(mx,curr);
    }
  }
  cout<<mx;
}
