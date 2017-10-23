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
	lli input[n],ans(0);
	double logMultiplication(0);
	for(int i(0);i<n;i++){
		cin>>input[i];
		ans = max(ans,input[i]);
		logMultiplication+= log(input[i]);
	}
	ans++;
	lli start(1),end(ans);
	while(start <= end){
		lli mid((start+end)/2);
		if(logMultiplication < (n*1.0)*log(mid)){
			ans = min(ans,mid);
			end = mid - 1;
		}
		else{
			start = mid +1 ;
		}
	} 
	cout<<ans<<endl;
	return 0;
}	