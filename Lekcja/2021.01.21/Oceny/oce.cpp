#include <bits/stdc++.h>
using namespace std;

int arr[7];
int n,a;

int main() {
    cin>>n;
    while(n--) {
      cin>>a;
      arr[a]++;
    }
    for(int i=1;i<=6;i++) cout<<arr[i]<<" ";
}
