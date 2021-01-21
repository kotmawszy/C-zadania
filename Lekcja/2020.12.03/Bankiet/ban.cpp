#include <bits/stdc++.h>
using namespace std;

int n,s;
int tab[30001];

int main() {
  cin>>n;
  for(int i=1;i<=n;i++) cin>>tab[i];
  for(int i=1;i<=n;i++) {
    int k=i;
    if(tab[k]!=0) s++;
    while(tab[k]!=0) {
      int tmp = k;
      k = tab[k];
      tab[tmp]=0;
    }
  }
  cout<<s;
}
