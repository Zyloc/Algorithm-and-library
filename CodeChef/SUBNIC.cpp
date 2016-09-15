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
#define MAX 100005
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli sum[MAX]={0};
	sum[1] = 1;
	sum[0] = 1;
	loop(i,2,MAX-1){
		sum[i] =(i*(i+1))/2; 
		//sum[i] += sum[i-1];
	}
	/*loop(i,0,5){
		cout<<sum[i]<<endl;
	}*/
	zyloc(){
		lli n,x;
		cin>>n;
		vi(v);
		loop(i,0,n-1){
			cin>>x;
			v.pb(x);
		}
		lli ans(0),start(1),end(1);
		loop(i,1,n-1){
			if (v[i]>=v[i-1]){
				end++;
			}
			else{
				ans += (sum[end-start+1]);
				end = i;
				start = i;
			}
		}
		//cout<<end-start<<endl;
		ans += (sum[end-start+1]);
		cout<<ans<<endl;
	}
	return 0;
}	