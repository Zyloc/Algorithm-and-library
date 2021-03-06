/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	int input[n];
	for(int i(0);i<n;i++){
		cin>>input[i];
	}
	sort(input,input+n);
	int left(2),right(n-1),ans(-1);
	cin>>x;
	while(left <= right){
		int mid((left+right)/2);
		if(input[mid] <= x){
			right = mid - 1;
			ans = mid;
		}
		else{
			left = mid + 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}	