#include <bits/stdc++.h>
using namespace std;

int n;
int* arr;
int* ans;
int pfx[1000007];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
  cin>>n;
  arr = new int[n];
  ans = new int[n];
  for(int i=0;i<n;i++) {
    cin>>arr[i];
    pfx[arr[i]]++;
  }
  for(int i=1;i<1000007;i++) pfx[i]+=pfx[i-1];

  for(int i=1000006;i>0;i--) pfx[i]=pfx[i-1];
  pfx[0]=0;
  for(int i=0;i<n;i++) ans[pfx[arr[i]]++]=arr[i];
  for(int i=0;i<n;i++)cout<<ans[i]<<" "; cout<<"\n";
}
