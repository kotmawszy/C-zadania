#include <bits/stdc++.h>
using namespace std;

int n;
long long* arr;
long long* ans;
long long* snp;
bool* dost;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	arr = new long long[n+1];
	ans = new long long[n+1];
	snp = new long long[n+1];
	dost = new bool[n+1];
	bool tylko12=1;
	int last1=0;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		if(arr[i]==1) last1=i;
		if(arr[i]>2) tylko12=0;
		dost[i]=1;
	}
	if(tylko12) {
		for(int i=1;i<=n;i++) {
			ans[i]=arr[i];
			if(i>1) ans[i]+=ans[i-1];
		}
		for(int i=1;i<=n;i++) {
			if(arr[i]==2 && i<last1) cout<<ans[i]-1<<" ";
			else cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return 0;
	}

	snp[n]=0;
	for(int i=n-1;i>0;i--) snp[i]=snp[i+1]+arr[i+1];

	long long curr = snp[1]+arr[1];

	for(int i=n;i>0;i--) {
		ans[i]=curr;
		int bestIndex;
		long long bestValue=0;
		for(int j=1;j<=n;j++) if(dost[j] && snp[j]<arr[j] && bestValue<arr[j]) {
			bestValue=arr[j];
			bestIndex=j;
		}
		curr-=bestValue;
		dost[bestIndex]=0;
		for(int j=bestIndex;j>0;j--) snp[j]-=bestValue;
	}

	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}


/*#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500003;
int n;
long long arr[MAXN];
long long ans[MAXN];

bool wziety[MAXN];
bool ssz[MAXN];
int lv=1;
long long suma[2*MAXN];
long long mx[2*MAXN];
bool mxdir[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	while(lv<n) lv*=2;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		wziety[i]=1;
	}

	for(int i=n;i>=1;i--) suma[lv+i-1]=arr[i];
	for(int i=lv-1;i>0;i--) suma[i]=suma[2*i]+suma[2*i+1];

	long long snp=0;
	for(int i=n;i>=1;i--) {
		ssz[i]=(arr[i]>snp);
		snp+=arr[i];
		if(ssz[i]) mx[lv+i-1]=arr[i];
	}
	for(int i=lv-1;i>0;i--) {
		if(mx[2*i]>mx[2*i+1]) mx[i]=mx[2*i], mxdir[i]=0;
		else mx[i]=mx[2*i+1], mxdir[i]=1;
	}

	for(int k=1;k<=2;k++) {
		for(int i=lv;i<lv+n;i++) cout<<suma[i]<<" "; cout<<"\n";
		for(int i=1;i<=n;i++) cout<<ssz[i]<<" "; cout<<"\n";

		int bestIndex = 1;
		while(bestIndex < lv) bestIndex=2*bestIndex+mxdir[bestIndex];
		bestIndex-=lv-1;
		cout<<"bestIndex: "<<bestIndex<<"\n";
	}
}
*/
