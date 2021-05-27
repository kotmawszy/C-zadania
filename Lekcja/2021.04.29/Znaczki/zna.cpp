#include <bits/stdc++.h>
using namespace std;

int n,m;
int a,b;
set<int> s;
int su;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;

	for(int i=0;i<n;i++) {
    cin>>a;
    s.insert(a);
  }
  for(int i=0;i<m;i++) {
    cin>>b;
    if(s.find(b)==s.end()) su++;
  }
  cout<<su<<"\n";
}
