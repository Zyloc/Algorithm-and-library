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
#define MAX 100000
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli n,x,r(-1);
	cin>>n;
	loop(i,0,n-1){
		cin>>x;
		while(x%2==0){
			x/=2;
		}
		while(x%3==0){
			x/= 3;
		}
		if (i and r!=x){
			cout<<"NO";
			return 0;
		}
		r = x;
	}
	cout<<"YES"<<endl;
	return 0;
}	