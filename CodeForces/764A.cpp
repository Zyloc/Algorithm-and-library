/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,z;
	cin>>n>>m>>z;
	cout<<z/((n*m)/__gcd(n,m))<<endl;
	return 0;
}