#include <iostream>
using namespace std;

int n,k;
int* tab;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k;
  tab = new int[n];
  for(int i=0;i<n;i++) cin>>tab[i];
  sort(tab,tab+n);

  long long s=0;
  for(int i=0;i<n;i++) {
    int x = k/tab[i];
    if(tab[i]>0) s+=tab+n-upper_bound(tab,tab+n,x);
    else s+=lower_bound(tab,tab+n,x)-tab;
    if((long long)tab[i]*tab[i]>k) s--;
  }
  cout<<s/2<<"\n";
}
