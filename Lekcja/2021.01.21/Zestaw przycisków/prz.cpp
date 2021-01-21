#include <bits/stdc++.h>
using namespace std;

int n,k;
int* arr;
int a;
int maxv;
int tomax;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>k>>n;
    arr = new int[k+1];
    for(int i=1;i<=k;i++) arr[i]=0;
    while(n--) {
        cin>>a;
        if(a==k+1) {
          tomax=maxv;
        } else {
          arr[a]=max(arr[a],tomax);
          arr[a]++;
          maxv = max(maxv, arr[a]);
        }
    }
    for(int i=1;i<=k;i++) cout<<max(tomax,arr[i])<<" ";
}
