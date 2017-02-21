/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,k,ans(0);
		cin>>n>>k;
		if(k > n){
			lli linear(k-n);
			ans = linear*n-(linear*(linear-1))/2;
			linear += 1;
			if(linear <= n){
				lli oddOrEven(k-2*linear+1);
				if(oddOrEven%2){
					ans+= (oddOrEven/2)*(oddOrEven/2);
				}
				else{
					ans += ((oddOrEven/2)*(oddOrEven/2+1));
				}
			}
		}
		else{
			n = min(n,k);
			if((n-1)%2){
				ans+= ((n+1)/2)*((n+1)/2);
			}
			else{
				ans+= (n-1)*n;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}