/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(4e5+2);
lli A[MAX];
int n,k;

bool check(lli mid){
	int start =0;
	int end = 0;
	while(end<n){
       if(A[end]-A[start]<=mid){
       	 end++;
       }else{
       	  if(end- start<k){ return false; }
       	  else{ start =  end; }
       }
	}

	if(end- start>=k){
		return true;
	}

	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	cin>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}

	sort(A,A+n);
	lli low = 0,high= 1e9+10;
	lli ans = high;
	while(low<=high){
		lli mid = (low+high)/2;
		if(check(mid)){
			ans = min(ans, mid);
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
    cout<<ans;
	return 0;
}
