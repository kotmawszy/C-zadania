#include <bits/stdc++.h>
using namespace std;

int n,m;
int* s;
int* dp;
int* tab;
int a;
int z;
priority_queue<pair<int,int> > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

  cin>>z;
  while(z--) {
    cin>>n>>m;
    while(!q.empty()) q.pop();
    s = new int[n+1];
    dp = new int[n+1];
    tab = new int[n+1];
    s[0]=0;
    for(int i=1;i<=n;i++) cin>>tab[i];
    for(int i=1;i<=n;i++) {
      s[i]=s[i-1]+tab[n-i+1];
    }

    dp[0]=0;
    q.push({0,0});
    for(int i=1;i<=n;i++) {
      while(!q.empty() && s[i]-q.top().second>m) q.pop();
      dp[i]=s[i]+q.top().first;
      q.push({-dp[i],s[i]});
    }
    cout<<dp[n]<<"\n";
  }
}
