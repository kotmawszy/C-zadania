#include <bits/stdc++.h>
using namespace std;

int n;;
int* arr;

void heapify(int n, int i) {
  int maxv = i;
  int l = 2*i+1;
  int r = 2*i+2;
  if(l<n && arr[l]>arr[maxv]) maxv = l;
  if(r<n && arr[r]>arr[maxv]) maxv = r;

  if(maxv==i) return;
  swap(arr[i], arr[maxv]);
  heapify(n, maxv);
}

void heapSort() {
  for(int i=n/2-1;i>=0;i--) heapify(n, i);
  for(int i=n-1;i>0;i--) {
    swap(arr[0], arr[i]);
    heapify(i, 0);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  arr = new int[n];
  for(int i=0;i<n;i++) cin>>arr[i];

  heapSort();

  for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
