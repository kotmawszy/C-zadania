#include <bits/stdc++.h>
using namespace std;

int a,b;
int n,q; // ilość dołków, ilość zapytań
int s; // długość przedziału
int* arr;
int* p; // do którego przedziału należy dołek
pair<int,int>* k; // nr pierwszego elementu na który skoczymy poza przedziałem, w ilu skokach

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>q;
  arr = new int[n];
  p = new int[n];
  k = new pair<int,int>[n];
  for(int i=0;i<n;i++) cin>>arr[i];

  s = sqrt(n);
  int j = 0;
  for(int i=0;i<n;i++) {
    if(i%s==0) j++;
    p[i]=j;
  }
  for(int i=n-1;i>=0;i--) {
    int jump = i+arr[i];
    if(jump>=n) k[i] = make_pair(n,1);
    else if(p[i] == p[jump]) { // jeżeli skacze do tego samego przedziału
      k[i] = make_pair(k[jump].first, k[jump].second+1);
    } else { // gdy do innego przedziału
      k[i] = make_pair(jump, 1);
    }
  }

  while(q--) {
    cin>>a;
    if(a==0) {
      cin>>a>>b;
      a--;
      arr[a]=b;
      int seg=p[a];
      for(int i=a;p[i]==seg && i>=0;i--) {
        int jump = i+arr[i];
        if(jump>=n) k[i] = make_pair(n,1);
        else if(p[i] == p[jump]) { // jeżeli skacze do tego samego przedziału
          k[i] = make_pair(k[jump].first, k[jump].second+1);
        } else { // gdy do innego przedziału
          k[i] = make_pair(jump, 1);
        }
      }
    } else if(a==1) {
      cin>>a;
      int s=0;
      int last;
      for(a--;;) {
        if(p[k[a].first]==j || k[a].first==n) break;
        last=a;
        s+=k[a].second;
        a=k[a].first;
      }
      while(a!=n) {
        last=a;
        s++;
        a=min(a+arr[a],n);
      }
      cout<<last+1<<" "<<s<<"\n";
    }
  }
}
