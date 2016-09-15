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
#define lli  long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli l1,r1,l2,r2,k,ans(0);
	cin>>l1>>r1>>l2>>r2>>k;
	lli from(max(l1,l2)),to(min(r1,r2));
	if (r2<l1 or l2>r1){
		cout<<0;
		//debug();
	}
	else{
		ans =  to - from + 1;
		if (k>=from and k<=to){
			ans--;
		}
		cout<<ans;
	}
	return 0;
}	