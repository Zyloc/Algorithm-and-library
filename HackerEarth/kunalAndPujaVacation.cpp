/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <lli> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli unsigned long long int 
#define debug() cout<<"######"<<endl 
lli a,b,c,k;
lli rankOfNumber(lli n){
	return n/a+n/b+n/c-n/(c*b)-n/(a*b)-n/(a*c)+n/(a+b+c);
}
int main(){
	zyloc(){
		cin>>a>>b>>c>>k;
		lli low(0),high(16), mid;
		while(low < high ){
			mid = low + (high - low)/2;
			if(rankOfNumber(mid) >= k ){
				high = mid;
			}
			else{
				low = mid + 1;
			}
			cout<<mid<<endl;
		}
		cout<<low<<endl;
	}	
	return 0;
}	