#include <bits/stdc++.h>
using namespace std;

int n,sqrtn;
pair<int,int>* points;
unordered_map<long long,bool> s;
int a,b;
long long sum;
long long sec = 1000000000;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>n;
  sqrtn = sqrt(n);
  points = new pair<int,int>[n];
  for(int i=0;i<n;i++) {
    cin>>a>>b;
    s[a+b*sec]=1;
    points[i] = make_pair(a,b);
  }
  sort(points,points+n);

  for(int p=0,q=0;p<n;p=q) {
    while(points[p].first == points[q].first) q++;
    int x = points[p].first;
    if(q-p<=4*sqrtn) {
      for(int i=p;i<q;i++) {
        for(int j=i+1;j<q;j++) {
          int o = abs(points[i].second-points[j].second);
          int g = max(points[i].second,points[j].second);
          int d = min(points[i].second,points[j].second);
          if(s.find(x+o + g *sec)!=s.end() && s.find(x+o + d *sec)!=s.end()) sum++;
        }
      }
    } else {
      for(int i=0;i<n;i++) {
        if(points[i].first<=x) continue;
        int xp = points[i].first;
        int yp = points[i].second;
        int d = xp-x;
        if(s.find(xp-d + yp *sec)!=s.end() && s.find(xp + (yp-d) *sec)!=s.end() && s.find(xp-d + (yp-d) *sec)!=s.end()) sum++;
      }
    }
  }
  cout<<sum;
}
