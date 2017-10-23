// C++ program to compute Totient function for
// all numbers smaller than or equal to n.
#include<iostream>
using namespace std;
const int MAX (1e7+1);
int phi[MAX];
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

// Driver program to test above function
int main()
{
	computeTotient();
	cout<<phi[10]<<" "<<phi[47];
	return 0;
}
