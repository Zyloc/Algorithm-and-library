/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int MOD(1e9+7);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli a(0), b(1),steps(1),n;
	cin>>n;
	while(steps!=n){
		steps++;
		lli c(b%MOD);
		b = (a+b)%MOD;
		a = c;
	}
	cout<<b<<endl;
	return 0;
}
/*
911435502
*/