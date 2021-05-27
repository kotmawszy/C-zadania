#include <bits/stdc++.h>
using namespace std;

int n;
int* a;
int c,d;
bool ok=0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  a = new int[2*n];
  for(int i=0;i<2*n;i++) cin>>a[i];
  sort(a,a+2*n);
  if(a[0]==a[2*n-1]) {
    cout<<a[0]<<" "<<a[0];
    return 0;
  }
  for(int i=0;i<2*n;i++) {
    if(a[i]==d) c++;
    else {
      if(c%2) {
        cout<<d<<" ";
        ok=1;
      }
      d=a[i];
      c=1;
    }
  }
  if(c%2) {
    cout<<d<<" ";
    ok=1;
  }
  if(!ok) cout<<"NIE";
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();

}
