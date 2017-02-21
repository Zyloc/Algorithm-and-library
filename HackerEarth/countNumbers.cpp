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
int main(){
	lli n,q,x,ans(0),y;
	cin>>n>>q;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	lli upto((1LL<<n)-1);
	loop(i,0,q-1){
		cin>>x>>y;
		loop(i,1,upto){
			lli count(0),start(x-1),end(y);
			loop(j,0,n-1){
				if ((i&(1ll<<j))){
					count++;
					start /= v[j];
					end /= v[j];
				}
			}
			if (count%2){
				ans += (end-start);
			}
			else{
				ans -= (end-start);
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}	