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
	lli q,n,x,global_diff(INT_MAX);
	cin>>q>>n;
	vector<vector<lli> > v(n);
	vector<lli> ans;
	loop(i,0,n-1){
		lli mini(INT_MAX),maxi(INT_MIN);
		loop(j,0,q-1){
			cin>>x;
			v[i].pb(x);
			mini = min(mini,x);
			maxi = max(maxi,x);
		}
		lli diff(maxi-mini);
		if (diff < global_diff){
			global_diff = diff;
			ans.clear();
			ans.pb(i);
			//cout<<i<<endl;
		}
		else if (diff == global_diff){
			ans.pb(i);
			//debug();
			//cout<<i<<endl;;
		}
	}
	//cout<<ans.size();
	/*loop(i,0,ans.size()-1){
		cout<<ans[i]<<" ";
	}*/
	lli min_ans(INT_MAX),answer;
	loop(i,0,ans.size()-1){
		lli maxi(INT_MIN);
		loop(j,0,q-1){
			maxi = max(maxi,v[ans[i]][j]);
		}
		//cout<<maxi<<endl;
		if (maxi < min_ans){
			//cout<<ans[i]<<endl;
			answer = ans[i];
			min_ans = maxi;
		}
	}
	cout<<answer+1<<endl;
	return 0;
}	