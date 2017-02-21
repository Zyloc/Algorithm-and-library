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
		lli n,x;
		cin>>n;
		vi(v);
		vi(ans);
		loop(i,0,n-1){
			cin>>x;
			v.pb(x);
			ans.pb(0);
		}
		ans[0] = 1;
		stack<lli> st;
		loop(i,0,n-1){
			while(!st.empty() and v[st.top()]<=v[i]){
				st.pop();
			}
			if (st.empty()){
				ans[i] = i + 1;
			}
			else{
				ans[i] = i - st.top();
			}
			st.push(i);
		}
		loop(i,0,n-1){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}	