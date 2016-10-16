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
	lli n;
	cin>>n;
	string s;
	cin>>s;
	map<char,lli> mp;
	loop(i,0,s.length()-1){
		mp[s[i]]++;
	}
	lli ans(INT_MAX);
	ans = min(ans,mp['h']/2);
	ans = min(ans,mp['a']/2);
	ans = min(ans,min(mp['c'],mp['k']));
	ans = min(ans,min(mp['e']/2,mp['r']/2));
	ans = min(ans,mp['t']);
	cout<<ans<<endl;
	return 0;
}	