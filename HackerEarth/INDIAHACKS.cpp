/* My First Template  
   :P
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
ll power(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
vector<ll>x;
int prime[1000002];
void sieve()
{
	int i,j;
	for(i = 2; i <= 1000000; i++) {
		if(!prime[i]) {
			for(j = 2; j*i <= 1000000; j++) {
				prime[i*j] = 1;
			}
			x.push_back(i);
		}
	}
}
int main()
{
	sieve();
	int t;
	ll n;
	scanf("%d",&t);
	while(t--) {
		scanf("%Ld",&n);
		int i,l = x.size();
		map<ll,int>mp;
		for(i = 0; i < l && x[i]*x[i] <= n; i++) {
			int c = 0;
			while(n%x[i] == 0) {
				n /= x[i];
				c++;
			}
			if(c) {
				mp[x[i]] = c;
			}
		}
		if(n > 1) {
			mp[n] = 1;
		}
		ll ans = 1;
		for(auto it = mp.begin(); it != mp.end(); it++) {
			ans = ans*(it->second+1);
		}
		ans--;
		printf("%Ld\n",ans);
	}
	return 0;
}