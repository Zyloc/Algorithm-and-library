/*
 * Richie Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	double m,ans(1e18),a,b;
	cin>>n>>m;
	for(int i(0);i<n;i++){
		cin>>a>>b;
		ans = min(ans,(a/b)*m);
	}
	printf("%.12lf \n",ans);
	return 0;
}
