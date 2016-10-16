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
#define MAX 10000050
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
bool prime[MAX];
void sieve()
{
	memset(prime, true, sizeof(prime));
	prime[1]=false;
	for (int p=2; p*p<MAX; p++)
	{
		if (prime[p] == true){
			for (int i=p*2; i<MAX; i += p)
				prime[i] = false;
		}
	}
}
int main(){
	sieve();
	zyloc(){
		lli x,n,k,ans(0),cnt(0);
		cin>>n>>k;
		loop(i,0,n-1){
			cin>>x;
			if (prime[x]){
				cnt++;
				if (cnt==k){
					cnt=0;
					ans+= x;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}	