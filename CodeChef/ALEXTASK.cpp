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
#define MAX 1000000000000000000
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli lcm(lli x,lli y){
	return (x*y)/__gcd(x,y);
}
int main(){
	zyloc(){
		lli n,x,ans(MAX);
		cin>>n;
		vi(v);
		loop(i,0,n-1){
			cin>>x;
			v.pb(x);
		}
		loop(i,0,n-2){
			lli localLcm(lcm(v[i],v[i+1]));
			loop(j,i+1,n-1){
				localLcm = min(localLcm,lcm(v[i],v[j]));
			}
			ans = min(ans,localLcm);
		}
		cout<<ans<<endl;
	}
	return 0;
}	