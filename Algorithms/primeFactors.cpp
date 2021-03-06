/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
bool prime[MAX];
vector<lli> primes;
void sieve()
{
	memset(prime, true, sizeof(prime));
	for (lli p=2; p<MAX; p++){
		if (prime[p] == true){
			primes.pb(p);
			for (lli i=p*2; i<MAX; i += p)
				prime[i] = false;
		}
	}
}
int main(){
	sieve();
	vi(noOfDivisors);
	loop(i,1,MAX-1){
		lli count(0),ans(1);
		loop(j,0,primes.size()-1){
			if (prime[j]*primes[j]*primes[j]>i){
				break;
			}
			count = 1;
			while(i%primes[j]==0){
				i/= primes[j];
				count++;
			}
			ans = ans*count;
		}
		if (prime[i]){
			ans = ans*2;
		}
		else if (sqrt(i)*sqrt(i)==n and prime[sqrt(i)]){
			ans = ans*3;
		}
		else if (i!=1){
			ans = ans*4;
		}
		noOfDivisors.pb(ans);
	}
	loop(i,1,20){
		cout<<noOfDivisors[i]<<" ";
	}
	return 0;
}	