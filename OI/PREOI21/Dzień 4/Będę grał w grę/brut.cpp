#include <bits/stdc++.h>
using namespace std;

enum Chlop {K,P};

int n,m;
bool arr[303][303];
bool vis[303][303];
string in;
int t;
int s;

enum Chlop dfs(int r, int c, enum Chlop kto_wybiera) {
  vis[r][c]=1;
  int wk=0;
  int wp=0;
  enum Chlop win;
  if(arr[r+1][c] && !vis[r+1][c]) {
    win = dfs(r+1,c,(kto_wybiera==K ? P : K));
    if(win==P) wp++;
    else wk++;
  }
  if(arr[r-1][c] && !vis[r-1][c]) {
    win = dfs(r-1,c,(kto_wybiera==K ? P : K));
    if(win==P) wp++;
    else wk++;
  }
  if(arr[r][c+1] && !vis[r][c+1]) {
    win = dfs(r,c+1,(kto_wybiera==K ? P : K));
    if(win==P) wp++;
    else wk++;
  }
  if(arr[r][c-1] && !vis[r][c-1]) {
    win = dfs(r,c-1,(kto_wybiera==K ? P : K));
    if(win==P) wp++;
    else wk++;
  }
  enum Chlop kto_wygrywa;

  vis[r][c]=0;
  if(wp==0 && wk==0) kto_wygrywa = kto_wybiera==K ? P : K;
  else if(kto_wybiera==P) {
    if(wp>0) kto_wygrywa = P;
    else kto_wygrywa = K;
  } else {
    if(wk>0) kto_wygrywa = K;
    else kto_wygrywa = P;
  }
  return kto_wygrywa;
}

void printAns() {
  for(int si=1;si<=n;si++) {
    for(int sj=1;sj<=m;sj++) {
      if(!arr[si][sj]) continue;
      enum Chlop wygrany = dfs(si,sj,K);
      if(wygrany==P) {
        cout<<"Piotr\n";
        return;
      }
    }
  }
  cout<<"Krzysztof\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>t;
  while(t--) {
    cin>>n>>m;
    int s=0;
    for(int i=1;i<=n;i++) {
      cin>>in;
      for(int j=1;j<=m;j++) {
        arr[i][j] = (in[j-1] == '.');
        s+=(in[j-1]=='X');
        vis[i][j]=0;
      }
      arr[i][0]=arr[i][m+1]=0;
    }
    for(int i=0;i<=m+1;i++) arr[0][i]=arr[n+1][i]=0;

    if(s==0) {
      cout<<(n%2 && m%2 ? "Piotr" : "Krzysztof")<<"\n";
      continue;
    }

    if(s==n*m) {
      cout<<"Krzysztof\n";
      continue;
    }

    printAns();
  }
}
