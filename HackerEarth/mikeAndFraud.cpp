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
#define lli unsigned long long int 
#define debug() cout<<"######"<<endl 
#define MAXSQRT 31623

int main(){
	lli n,k,x,ans(0);
	scanf("%lld %lld",&n,&k);
	vi(v);
	v.pb(0);
	loop(i,1,n){
		scanf("%lld",&x);
		v.pb(x);
	}
	lli index(1),mul(v[1]);
	loop(i,1,n){
		if(index < i){
			mul*=v[i];
			index = i;
		}
		while(mul%k!=0){
			index++;
			mul = mul*v[index];
		}
		if(mul%k == 0){
			ans += (n-index+1);
		}
		mul/=v[i];
	}
	printf("%lld ", ans);
	return 0;
}	