#include <bits/stdc++.h>
using namespace std;

int n,k;
bool arr[1000003];
int mi = numeric_limits<int>::max();

int main() {
  ios_base::sync_with_stdio(0);

  cin>>n>>k;
  for(int i=0;i<n;i++) cin>>arr[i];

  int p=0;
  while(arr[p]==1) p++;
  int q=p;
  int il=0;
  for(;il<k && q<n;q++) if(arr[q]==0) il++;
  if(il!=k) {
    cout<<"NIE";
    return 0;
  }
  q--;
  while(q<n) {
    mi = min(mi, q-p+1-k);
    p++;
    while(arr[p]==1) p++;
    q++;
    while(arr[q]==1) {
      q++;
      if(q>=n) break;
    }
  }
  cout<<mi;
}
