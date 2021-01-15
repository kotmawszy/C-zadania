#include <bits/stdc++.h>
using namespace std;

int n,m,q;
int** d;
int*** pref;
int** arr;
int lv=1;
const int INF = numeric_limits<int>::max();
int r0,c0,r1,c1;
int maxv;

int getMin(int row, int a, int b, int v=1, int p=1, int q=lv) {
  if(p>b || q<a) return INF;
  if(p>=a && q<=b) return d[row][v];
  int s = (p+q)/2;
  return min(
    getMin(row,a,b,2*v,p,s),
    getMin(row,a,b,2*v+1,s+1,q)
  );
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>q;

    arr = new int*[n+1];
    for(int i=1;i<=n;i++) {
      arr[i] = new int[m+1];
      for(int j=1;j<=m;j++) {
        cin>>arr[i][j];
        maxv = max(maxv,arr[i][j]);
      }
    }

    // PODZADANIE 2
    if(maxv<=10) {
      pref = new int**[maxv+1];
      for(int v=1;v<=maxv;v++) {
        pref[v] = new int*[n+1];
        for(int i=0;i<=n;i++) {
          pref[v][i] = new int[m+1];
          for(int j=0;j<=m;j++) pref[v][i][j]=0;
        }
      }

      for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
          pref[ arr[i][j] ][i][j]=1;
        }
      }

      for(int v=1;v<=maxv;v++) {
        for(int i=1;i<=n;i++) {
          for(int j=1;j<=m;j++) {
            pref[v][i][j]+=pref[v][i-1][j]+pref[v][i][j-1]-pref[v][i-1][j-1];
          }
        }
      }

      while(q--) {
        cin>>r0>>c0>>r1>>c1;
        for(int v=1;v<=maxv;v++) {
          if(pref[v][r1][c1]-pref[v][r1][c0-1]-pref[v][r0-1][c1]+pref[v][r0-1][c0-1]>0) {
            cout<<v<<"\n";
            break;
          }
        }
      }

      return 0;
    }

    // PODZADANIE 1 i 3
    d = new int*[n+1];
    while(lv<m) lv*=2;
    for(int i=1;i<=n;i++) {
      d[i] = new int[2*lv];
      for(int j=0;j<m;j++) d[i][lv+j]=arr[i][j+1];
      for(int j=m;j<lv;j++) d[i][lv+j]=INF;
      for(int v=lv-1;v>0;v--) {
        d[i][v]=min(d[i][2*v],d[i][2*v+1]);
      }
    }

    while(q--) {
      cin>>r0>>c0>>r1>>c1;
      int minnn=numeric_limits<int>::max();
      for(int i=r0;i<=r1;i++)
        minnn=min(minnn, getMin(i,c0,c1));
      cout<<minnn<<"\n";
    }
}


int*** arr;
int main() {
  arr = new int**[n];
  for(int i=0;i<n;i++) {
    arr[i] = new int*[m];
    for(int j=0;j<m;j++) {
      arr[i][j] = new int[k];
    }
  }
}
