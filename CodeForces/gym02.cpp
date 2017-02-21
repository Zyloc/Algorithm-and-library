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
		lli n,x,braveBeart(0),maxSoldier(0);
		cin>>n;
		vi(mens);
		vi(horses);
		loop(i,0,n-1){
			cin>>x;
			if (i==0){
				braveBeart = x;
			}
			else{
				maxSoldier = max(maxSoldier,x);
			}
		}
		loop(i,0,n-1){
			cin>>x;
			horses.pb(x);
		}
		sort(horses.begin(),horses.end());
		if (horses[n-1]*braveBeart > horses[0]*maxSoldier){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}	