/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli r,g,b;
	cin>>r>>g>>b;
	lli ans(0);
	for(int i=0;i<3;i++){
		if(min(r,min(g,b)) - i >= 0){
			ans = max(ans,(r-i)/3+(g-i)/3+(b-i)/3+i);	
		}
	}
	cout<<ans;
	return 0;
}