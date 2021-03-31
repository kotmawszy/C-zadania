#include <bits/stdc++.h>
using namespace std;

int n;
int* a;
int* tmp;
long long sum=0;

void connect(int p, int q) {
  int s = (p+q-1)/2+1;
  int i=p;
  int j=s;
  int k=0;
  while(i<s || j<q) {
    if(i>=s) {
      sum+=j-p-k;
      tmp[k++]=a[j++];
    } else if(j>=q) {
      tmp[k++]=a[i++];
    } else if(a[i]<a[j]) {
      tmp[k++]=a[i++];
    } else {
      tmp[k++]=a[j++];
        sum+=j-p-k;
    }
  }
  for(int i=0;i<k;i++) a[p+i]=tmp[i];
}

void mergesort(int p, int q) {
  if(p+1>=q) return;
  int s = (p+q-1)/2+1;
  mergesort(p,s);
  mergesort(s,q);
  connect(p,q);
}

int main() {
  cin>>n;
  a = new int[n];
  tmp = new int[n];
  for(int i=0;i<n;i++) cin>>a[i];
  mergesort(0,n);
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
