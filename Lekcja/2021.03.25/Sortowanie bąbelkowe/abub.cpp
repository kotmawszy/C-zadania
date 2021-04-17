#include <cstdio>

int n;
int tab[100000];
char c;

int main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    c='0';
    do {
      c = getchar_unlocked();
    } while(c<'0' || c>'9');
    do {
      tab[i]*=10;
      tab[i]+=c-'0';
      c = getchar_unlocked();
    } while(c>='0' && c<='9');
  }

  for(int j=0;j<n-1;j++) {
    for(int i=0;i<n-1-j;i++) {
      if(tab[i]>tab[i+1]) {
        int r=tab[i];
        tab[i]=tab[i+1];
        tab[i+1]=r;
      }
    }
  }

  for(int i=0;i<n;i++) printf("%d ",tab[i]);
}
