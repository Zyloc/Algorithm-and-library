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
lli fast_expo(lli base, lli expo){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MOD;
		}
		base=(base*base)%MOD;
		expo/=2;
	}
	return res%MOD;
}
int main(){
	string s;
	cin>>s;
	lli a;
	if(s.length()>1)
		a = 10*(s[s.length()-2]-'0')+(s[s.length()-1]-'0');
	else
		a = (s[0]-'0');
	//cout<<a<<endl;
	a = a%4;
	lli ans(0);
	loop(i,1,4){
		ans+=fast_expo(i,a)%5;
	}
	cout<<ans%5<<endl;
	return 0;
}	