/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli unsigned long long int
using namespace std;
const int MAX(1e7+2);
lli x,k,m;
int phi[MAX];
lli fast_expo(lli base, lli expo,lli MODE){
	lli res(1);
	while(expo>0){
		if(expo&1){
			res=(res*base)%MODE;
		}
		base=(base*base)%MODE;
		expo/=2;
	}
	return res%MODE;
}

// Computes and prints totien of all numbers
// smaller than or equal to n.
bool IsPrime(long long int number){
 
    if (number == 2 || number == 3)
        return true;
 
    if (number % 2 == 0 || number % 3 == 0)
        return false;
 
    long long int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {
 
        if (number % (divisor - 1) == 0)
            return false;
 
        if (number % (divisor + 1) == 0)
            return false;
 
        divisor += 6;
 
    }
 
    return true;
 
}

void computeTotient(){
	// Create and initialize an array to store
	// phi or totient values
	int n = MAX;
	for (int i=1; i<=n; i++)
		phi[i] = i; // indicates not evaluated yet
					// and initializes for product
					// formula.

	// Compute other Phi values
	for (int p=2; p<=n; p++)
	{
		// If phi[p] is not computed already,
		// then number p is prime
		if (phi[p] == p)
		{
			// Phi of a prime number p is
			// always equal to p-1.
			phi[p] = p-1;

			// Update phi values of all
			// multiples of p
			for (int i = 2*p; i<=n; i += p)
			{
			// Add contribution of p to its
			// multiple i by multiplying with
			// (1 - 1/p)
			phi[i] = (phi[i]/p) * (p-1);
			}
		}
	}

	// Print precomputed phi values
}

lli magicBox(lli x,lli k,lli m){
	lli getPhi(phi[m]);
	if(getPhi == 1 or k == 0){
		return 1%m;
	}
	return fast_expo(x,magicBox(x,k-1,getPhi),m);
}
int main(){
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);	*/
	computeTotient();
	lli t;
	cin>>t;
	while(t--){
		//cin>>x>>k>>m;
		scanf("%lld %lld %lld",&x,&k,&m);
		printf("%lld\n", magicBox(x,k,m));
		//cout<<magicBox(x,k,m)<<endl;
	}
	return 0;
}

