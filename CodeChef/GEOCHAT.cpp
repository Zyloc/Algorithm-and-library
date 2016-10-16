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
#define shift 1000000000
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl

int main(){
	lli z,n,x,y,x2,y2,leftMost(0),rightMost(0);
	cin>>n;
	map<lli,pair<lli,lli> >mp;
	loop(i,0,n-1){
		cin>>x>>y;
		x+= shift;
		y+= shift;
		z  = shift*x + y;
		mp[z] = mp(x,y);
		if (i==0){
			leftMost = z;
			rightMost = z;
		}
		else{
			leftMost = min(leftMost,z);
			rightMost = max(rightMost,z);
		}
		x = mp[leftMost].first;
		y = mp[leftMost].second;
		x2 = mp[rightMost].first;
		y2 = mp[rightMost].second;
		cout<<x-shift<<" "<<y-shift<<" "<<x2-shift<<" "<<y2-shift<<endl;
		cout<<(x2-x)*(x2-x)+(y2-y)*(y2-y)<<endl;
	}
	return 0;
}	