/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,ans(0);
	cin>>n>>m;
	for(int i=1;i<5;i++){
		if(n >= i and m+i >= 5){
			lli maxTermN((n-i)/5),maxTermM((m-5+i)/5);
			if((n-i)%5 == 0){
				maxTermN++;
			}
			if((m-5+i)%5 == 0){
				maxTermM++;
			}
			ans += maxTermN*maxTermM;
		}
	}
	cout<<ans<<endl;
	return 0;
}