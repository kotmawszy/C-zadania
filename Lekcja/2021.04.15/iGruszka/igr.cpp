#include <bits/stdc++.h>
using namespace std;

int s,k,n;
int* tab;
long long best = 0;
long long minSoFar = LONG_LONG_MAX;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>s>>k>>n;
  tab = new int[n];
  for(int i=0;i<n;i++) {
    cin>>tab[i];
    tab[i]-=k;
  }
  sort(tab,tab+n,greater<int>());

  for(int i=0;i<min(n,s);i++) {
    minSoFar = min(minSoFar, (long long)tab[i]);
    best = max(best, minSoFar*(i+1));
  }
  cout<<best<<"\n";
}
