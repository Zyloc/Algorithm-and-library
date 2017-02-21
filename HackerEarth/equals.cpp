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
	zyloc(){
		lli ans(0),x(0);
		vi(v);
		string s;
		cin>>s;
		loop(i,0,s.length()-1){
			if (s[i]=='='){
				v.pb(ans);
				ans = 0;
			}
			else if(s[i]!='+'){
				ans += s[i]-'0'; 
			}
		}
		v.pb(ans);
		if (v.size() == 1){
			cout<<v[0];
		}
		else{
			loop(i,0,v.size()-2){
				cout<<v[i]<<'=';	
			}
			cout<<v[v.size()-1];
		}
		cout<<endl;
	}
	return 0;
}	