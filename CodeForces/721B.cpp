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
	lli n,k,x;
	cin>>n>>k;
	string s;
	vi(v);
	loop(i,0,n-1){
		cin>>s;
		v.pb(s.length());
	}
	cin>>s;
	sort(v.begin(),v.end());
	lli mini(lower_bound(v.begin(),v.end(),s.length())-v.begin()),maxi(upper_bound(v.begin(),v.end(),s.length())-v.begin());
	cout<<(mini/k)*5+mini+1<<" "<<((maxi-1)/k)*5+maxi<<endl;
	return 0;
}	