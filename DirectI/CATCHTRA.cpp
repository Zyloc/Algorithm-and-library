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
		double ve,vy,l,T;
		cin>>ve>>vy>>l>>T;
		cout<<setprecision(10);
		cout<<min(1.0,(l/ve-l/(ve+vy))/T)<<endl;
	}
	return 0;
}
