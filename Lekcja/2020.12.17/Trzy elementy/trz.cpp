#include <bits/stdc++.h>
using namespace std;

int n;
int arr[502];
int il,mx;

int main() {
  ios_base::sync_with_stdio(0);

  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  sort(arr,arr+n);
  for(int i=0;i<n;i++) {
    if(i==0 || arr[i-1]!=arr[i]) il=1;
    else il++;
    mx = max(mx, il);
  }
  cout<<(mx>=3 ? "TAK" : "NIE");
}
