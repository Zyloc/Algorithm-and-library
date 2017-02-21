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
#define lli unsigned long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli l,r,k,current(1);
	cin>>l>>r>>k;
	vi(v);
	while(current<=r){
		if (current>=l and current<=r){
			v.pb(current);
		}
		current = current*k;
	}
	bool flag(false);
	if (v.size()>1){
		loop(i,0,v.size()-1){
			if (v[i]>=l and v[i]<=r){
				cout<<v[i]<<" ";
				flag =true;
			}
		}
	}
	if (!flag){
		cout<<"-1"<<endl;
	}	
	return 0;
}	