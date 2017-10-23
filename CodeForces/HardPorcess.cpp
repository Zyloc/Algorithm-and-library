/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,k;
	cin>>n>>k;
	vector<lli> input,dummy;
	for(int i(0);i<n;i++){
		cin>>x;
		dummy.push_back(x);
		x = 1-x;
		if(i == 0){
			input.push_back(x);	
		}
		else{
			input.push_back(x+input[i-1]);
		}
	}
	lli ans(0),ansLeft(0),ansRight(-1);
	for(int i(0);i<n;i++){
		lli left(i),right(n-1),temp(-1),tempRight;
		while(left <= right){
			lli mid((left+right)/2);
			lli sub(0);
			if(i!=0){
				sub = input[i-1];
			}
			if(input[mid]-sub <= k){
				temp = mid-i+1;
				tempRight = mid;
				left = mid+1;
			}
			else{
				right = mid -1 ;
			}
		}
		if(temp > ans){
			ans = temp;
			ansLeft = i;
			ansRight = tempRight;
		}
	}
	cout<<ans<<endl;
	for(int i(ansLeft);i<=ansRight;i++){
		dummy[i]|=1;
	}
	for(auto x:dummy){
		cout<<x<<" ";
	}
	return 0;
}
