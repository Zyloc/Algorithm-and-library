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
	lli a,b;
	cin>>a>>b;
	vi(v);
	v.pb(b);
	while(b>a){
		
		if (b%2==0){
			v.pb(b/2);
			b/= 2;
		}
		else if((b-1)%10==0){
			v.pb((b-1)/10);
			b = (b-1)/10;
		} 
		else{
			cout<<"NO";
			return 0;
		}
	}
	if (b==a){
		cout<<"YES"<<endl;
		cout<<v.size()<<endl;
		pool(i,v.size()-1,0){
			cout<<v[i]<<" ";
		}
	}
	else {
		cout<<"NO";
	}
	return 0;
}	