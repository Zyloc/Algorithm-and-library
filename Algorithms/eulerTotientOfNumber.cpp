/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli phi(lli n){ 
	lli result = n; // Initialize result as n
	for (int p=2; p*p<=n; ++p){
		if (n % p == 0){
			while (n % p == 0)
				n /= p;
			result -= result / p;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<phi(11)<<endl;
	return 0;
}	
