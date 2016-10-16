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
	lli n,x,y,x2,y2;
	cin>>n;
	vector<pair<lli,lli> > v;
	loop(i,0,n-1){
		cin>>x>>y;
		v.pb(mp(x,y));
		lli maxiDistance(0),z(0);
		if (i>0)
			loop(j,0,i-1){
				loop(k,j+1,i){
					z = (v[k].first-v[j].first)*(v[k].first-v[j].first)+(v[k].second-v[j].second)*(v[k].second-v[j].second);
					if (z>maxiDistance){
						x = v[k].first;
						y = v[k].second;
						x2 = v[j].first;
						y2 = v[j].second;
					}
					maxiDistance = max(z,maxiDistance);
				}
			}
		cout<<x<<" "<<y<<" "<<x2<<" "<<y2<<endl;	
		cout<<maxiDistance<<endl;;
	}
	return 0;
}	