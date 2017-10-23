/*
 * Keep breathing :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MOD(1e9+7);
lli fast_expo(lli base, lli expo,lli MODE){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MODE;
		}
		base=(base*base)%MODE;
		expo/=2;
	}
	return res%MODE;
}
lli lcm(lli a,lli b){
	if(b == 0){
		return a;
	}
	return (a%MOD*b%MOD)*fast_expo(__gcd(a,b),MOD-2,MOD);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		bool visited[n+1];
		int input[n+1];
		memset(visited,false,sizeof visited);
		for(int i(1);i<=n;i++){
			cin>>input[i];
		}
		lli ans(1);
		for(int i(1);i<=n;i++){
			lli lenght(0),start(i);
			while(!visited[start]){
				visited[start] = true;
				lenght++;
				start = input[start];
			}
			ans = lcm(ans,lenght);
		}
		cout<<ans<<endl;
	}
	return 0;
}
