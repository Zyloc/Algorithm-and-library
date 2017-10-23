/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	lli ans[n+2];
	memset(ans,0,sizeof ans);
	ans[1] = 1;
	for(int i=2;i<=n+1;i++){
		if(ans[i] == 0){
			ans[i] = 1;
			for(int j=2;i*j<=n+1;j++){
				ans[j*i] = 2;
			}
		}
	}
	if(n <= 2){
		cout<<1<<endl;
	}
	else{
		cout<<2<<endl;
	}
	for(int i=2;i<=n+1;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}