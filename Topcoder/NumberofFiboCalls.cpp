/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
class NumberofFiboCalls{
public:
	int ans[2];
	int* fiboCallsMade(int n){
		int pa[n+1][2];
		pa[0][0] = 1;
		pa[0][1] = 0;
		pa[1][1] = 1;
		pa[1][0] = 0;
		for(lli i=2;i<=n;i++){
			pa[i][0] = pa[i-1][0] + pa[i-2][0];
			pa[i][1] = pa[i-1][1] + pa[i-2][1];
		}
		ans[0] = pa[n][0];
		ans[1] = pa[n][1];
		return ans;
	}	
};
int main(){
	int ans[2];
	NumberofFiboCalls obj;
	lli n;
	cin>>n;
	ans = obj.fiboCallsMade(n);
	cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}