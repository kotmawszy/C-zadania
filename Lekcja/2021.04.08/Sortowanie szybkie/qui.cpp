#include <bits/stdc++.h>
using namespace std;

int* partition(int* begin, int* end) {
		int* randd = rand()%(end-begin)+begin;
		int t = *(end-1);
		*(end-1)=*randd;
		*randd = t;
    int pivot=*(end-1);
    int* j=begin;
    for(int* i=begin;i<end-1;i++) if(*i<=pivot) {
      t=*i;
      *i=*j;
    	*j=t;
      j++;
    }
    t=*(end-1);
    *(end-1)=*j;
    *j=t;
     return j;
 }
 void quick_sort(int* begin, int* end) {
    if(begin>=end-1) return;
    int* i=partition(begin,end);
    quick_sort(begin,i);
    quick_sort(i+1,end);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	srand(time(NULL));
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	quick_sort(arr,arr+n);
	for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"\n";
}
