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
	lli n,start(0),end(0),ans(0);
	cin>>n;
	string s;
	cin>>s;
	vi(v);
	loop(i,0,s.length()-1){
		if (s[i]=='W'){
			if (end-start>0){
				v.pb(end-start);
				ans++;
			}	
			start = i;
			end = i;
		}
		else{
			end++;
		}
	}
	if (start!=end){
		ans++;
		v.pb(end-start);
	}
	cout<<ans<<endl;
    if (v.size()>=1)
	loop(i,0,v.size()-1){
		cout<<v[i]<<" ";
	}
	return 0;
}	