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
lli lcm(lli x,lli y){
	return x*y/__gcd(x,y);
}
int main(){
	lli n;
	cin>>n;
	if (n==1){
		cout<<1;
		return 0;
	}
	else if (n==2){
		cout<<2;
		return 0;
	}
	else if(n==3){
		cout<<6;
		return 0;
	}
	else{
		lli ans(0);
		lli z(max((lli)1,n-50));
		loop(i,z,n){
			loop(j,i,n){
				loop(k,j,n){
					ans = max(ans,lcm(i,lcm(j,k)));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}	