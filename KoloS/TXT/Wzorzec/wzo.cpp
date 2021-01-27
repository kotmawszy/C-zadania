#include <bits/stdc++.h>
using namespace std;

string a,b;
int n,m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>a>>b;
  n = a.size();
  m = b.size();

  int j=0;
  for(int i=0;i<n;i++) {
    if(a[i]==b[j]) j++;
    if(j==m) break;
  }
  cout<<(j==m ? "TAK" : "NIE");
}
