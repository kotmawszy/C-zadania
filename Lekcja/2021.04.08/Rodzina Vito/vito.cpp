#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];

  sort(arr,arr+n);

  int x=arr[n/2];
  long long s=0,s2=0;
  for(int i=0;i<n;i++) s+=abs(arr[i]-x);
  if(n<=1) {cout<<s<<"\n"; return 0;}

  x = arr[n/2-1];
  for(int i=0;i<n;i++) s2+=abs(arr[i]-x);
  cout<<min(s,s2)<<"\n";
}
