#include <bits/stdc++.h>
using namespace std;

int n,m;
long long* a;
long long* b;
long long* aSorted;
long long* noDigitsInRow; // ilość cyfr w danym wierszu
long long* prefndir;
int q;
long long c;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>m>>n;
  a = new long long[n];
  aSorted = new long long[n];
  b = new long long[m];
  noDigitsInRow = new long long[m];
  prefndir = new long long[m];
  for(int i=0;i<m;i++) cin>>b[i];
  for(int i=0;i<n;i++) {
    cin>>a[i];
    aSorted[i]=a[i];
  }
  sort(aSorted,aSorted+n);

  for(int i=0;i<m;i++) { // i - aktualny przetwarzany wiersz
    long long power = 1;
    noDigitsInRow[i]=0;
    for(int j=0;j<=18;j++) { // j - ilo cyfrowych liczb sukamy
      long long p = (power-1)/b[i]+1;
      long long q = (10*power-1)/b[i];
      if(q<0) q = numeric_limits<long long>::max();
      power*=10;
      noDigitsInRow[i] += distance(lower_bound(aSorted,aSorted+n,p),upper_bound(aSorted,aSorted+n,q))*(j+1);
    }
    prefndir[i] = noDigitsInRow[i];
    if(i>0) prefndir[i]+=prefndir[i-1];
  }
  cin>>q;
  while(q--) {
    cin>>c;
    int row = lower_bound(prefndir,prefndir+m,c)-prefndir;
    if(row>=m) {
      cout<<"x";
      continue;
    }
    int whichInRow = c-(row==0 ? 0 : prefndir[row-1]);
    int cWhichInRow = 0;
    int col;
    int noDigitsBefore = 0;
    for(col=0;cWhichInRow<whichInRow;col++) {
      int noDigits=1;
      long long cp = b[row]*a[col];
      while(cp/=10) noDigits++;
      cWhichInRow+=noDigits;
      noDigitsBefore += noDigits;
    }
    col--;
    long long cp = b[row]*a[col];
    for(int i=0;i<noDigitsBefore-whichInRow;i++) cp/=10;
    cout<<cp%10;
  }
}
