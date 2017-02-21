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
/*

asdfasfasdfasfsad
*/
int main(){
	lli n,ans(0),x,y,maxFound(0),lefte(0),righte(0),total(0);
	cin>>n;
	lli left[n+1],right[n];
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	loop(i,1,n){
		cin>>left[i]>>right[i];
		lefte += left[i];
		righte += right[i];
	}
	maxFound = abs(lefte-righte);
	total = maxFound;
	loop(i,1,n){
		if (abs(lefte-left[i]+right[i]-(righte-right[i]+left[i]))> maxFound){
			if (abs(lefte-left[i]+right[i]-(righte-right[i]+left[i]))>total){
				total = abs(lefte-left[i]+right[i]-(righte-right[i]+left[i]));
				ans = i;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}	