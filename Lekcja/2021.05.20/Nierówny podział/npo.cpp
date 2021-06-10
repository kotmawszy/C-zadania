#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  long long n,s=0;
  cin>>n;
  long long tab[n];
  for(int i=0;i<n;i++) {
    cin>>tab[i];
    s+=tab[i];
  }
  sort(tab,tab+n,greater<long long>());
  for(long long i=0,x=0;i<n;i++) {
    x+=tab[i];
    if(2*x>s) {
      cout<<i+1<<"\n";
      return 0;
    }
  }
  cout<<n<<"\n";
}
