// po siedzeniu nad tym ponad godzinę może dacie punkty

#include <bits/stdc++.h>
using namespace std;

int n,m,q;
int r0,c0,r1,c1;
int INF = numeric_limits<int>::max();
int c;

int** d;
int lv=1,lvv=1;


int getMin(int ra, int rb, int ca, int cb, int rv=1, int cv=1, int rp=1, int rq=lv, int cp=1, int cq=lvv) {
  if(rp>rb || rq<ra) return INF;
  if(rp>=ra && rq<=rb) {
        if(cp>cb || cq<ca) return INF;
        if(cp>=ca && cq<=cb) {
          return d[rv][cv];
        }
        int cs = (cp+cq)/2;
        return min(
          getMin(ra,rb,ca,cb,rv,2*cv,rp,rq,cp,cs),
          getMin(ra,rb,ca,cb,rv,2*cv+1,rp,rq,cs+1,cq)
        );
  }
  int rs = (rp+rq)/2;
  return min(
    getMin(ra,rb,ca,cb,2*rv,cv,rp,rs,cp,cq),
    getMin(ra,rb,ca,cb,2*rv+1,cv,rs+1,rq,cp,cq)
  );
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>q;

    while(lv<n) lv*=2;
    d = new int*[2*lv];
    while(lvv<m) lvv*=2;
    for(int i=1;i<2*lv;i++) d[i] = new int[2*lvv];

    for(int i=lv;i<lv+n;i++) {
      for(int j=lvv;j<lvv+m;j++) cin>>d[i][j];
      for(int j=lvv+m;j<2*lvv;j++) d[i][j]=INF;
      for(int j=lvv-1;j>0;j--) d[i][j]=min(d[i][2*j],d[i][2*j+1]);
    }
    for(int i=lv+n;i<2*lv;i++) for(int j=1;j<2*lvv;j++) d[i][j]=INF;
    for(int i=lv-1;i>0;i--) {
      for(int j=1;j<2*lvv;j++) d[i][j] = min(d[2*i][j],d[2*i+1][j]);
    }

    while(q--) {
      cin>>r0>>c0>>r1>>c1;
      cout<<getMin(r0,r1,c0,c1)<<"\n";
    }
}
