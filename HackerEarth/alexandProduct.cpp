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
		string s;
		lli a,b,mode(1),ans(1);
		cin>>s;
		cin>>a>>b;
		loop(i,1,a){
			mode = mode*10;
		}
		mode += b;
		//cout<<mode<<endl;
		for(lli i=0;i<s.length();){
			lli dummy(0);
			loop(j,0,((s[i]-'0')-1)){
				if (i+j<s.length())
					dummy = dummy*10+(s[i+j]-'0');
			} 
			//cout<<dummy<<endl;
			i += (s[i]-'0');
			ans = (ans%mode*dummy%mode)%mode;
		}
		cout<<ans<<endl;
	}
	return 0;
}	