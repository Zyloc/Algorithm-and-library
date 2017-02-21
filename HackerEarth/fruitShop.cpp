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
int main(){
	vector<pair<lli,lli> > v;
	lli x,y,z,ans(0);
	cin>>x>>y>>z;
	v.pb(mp(x,0));
	v.pb(mp(y,0));
	v.pb(mp(z,0));
	cin>>x>>y>>z;
	v[0].second = x;
	v[1].second = y;
	v[2].second = z;
	cin>>x;
	sort(v.begin(),v.end());
	loop(i,0,2){
		if (x>0){
			ans += min(x/v[i].first,v[i].second);
			if (x/v[i].first >= v[i].second){
				x -= v[i].first * v[i].second;
			}
			else{
				x = 0;
			}
		}
	}
	cout<<ans;
	return 0;
}	