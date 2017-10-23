#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int FindCount(int arr[],int length){
	int ans(0);
	for(int i(0);i<length;i++){
		if(arr[i]&1 and i&1){
			ans++;
		}
		if(!(arr[i]&1) and !(i&1)){
			ans++;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[] = {12,3,14,56};
	cout<<FindCount(arr,4);
	return 0;
}
