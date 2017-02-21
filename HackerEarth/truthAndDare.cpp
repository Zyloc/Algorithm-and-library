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
	zyloc(){
		lli n,k,p;
		cin>>n>>k>>p;
		if (p&1){
			if ((p-1+k)%n == 0){
				cout<<n<<" "<<"dare"<<endl;
			}
			else{
				cout<<(p-1+k)%n<<" "<<"dare"<<endl;
			}
		}
		else{
			if ((p-1+k)%n == 0){
				cout<<n<<" "<<"truth"<<endl;
			}
			else{
				cout<<(p-1+k	)%n<<" "<<"truth"<<endl;
			}	
		}
	}
	return 0;
}	