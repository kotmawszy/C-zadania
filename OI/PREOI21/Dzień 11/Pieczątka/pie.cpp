#include <bits/stdc++.h>
using namespace std;

int n,m;
bool tab[503][503];
string in;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

  cin>>n>>m;
  for(int i=1;i<=n;i++) {
    cin>>in;
    for(int j=1;j<=m;j++) tab[i][j]=(in[j-1]=='#');
  }

  for(int ip=1;ip<=n;ip++) {
    for(int ik=ip;ik<=n;ik++) {
      for(int jp=1;jp<=m;jp++) {
        for(int jk=jp;jk<=m;jk++) {
          for(int iu=1;iu<=n;iu++) {
            for(int ju=1;ju<=m;ju++) {
              for(int is=1;is<=n;is++) {
                for(int js=1;js<=m;js++) {
                  
                }
              }
            }
          }
        }
      }
    }
  }
}
