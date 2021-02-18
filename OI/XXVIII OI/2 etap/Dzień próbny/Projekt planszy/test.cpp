#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[2][100];
string s;

int main() {
  cin>>n;
  if(n>100) {
    cout<<"za duza plansza!\n";
    return 0;
  }
  for(int i=0;i<n;i++) {
    cin>>s;
    for(int j=0;j<n;j++) {
      arr[i%2][j]=(i==0 && j==0);
      if(s[j]=='#') continue;
      if(i) arr[i%2][j]+=arr[1-i%2][j];
      if(j) arr[i%2][j]+=arr[i%2][j-1];
    }
  }
  cout<<arr[1-n%2][n-1]<<"\n";
}
