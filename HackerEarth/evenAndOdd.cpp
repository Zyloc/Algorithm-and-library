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
#define MAX 100001
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli unsigned long long int 
#define debug() cout<<"######"<<endl 
vector<lli> graph[MAX];
vi(weight);
map<lli,lli> mp;
lli ans[MAX];	
lli n,x,y,q;
struct myNode{
	lli node,weight;
	myNode(){
		weight = 0;
	}
};
void dfs(lli start){
	for(auto ed : graph[start]){
		ans[ed] = ans[start]+weight[ed];
		dfs(ed);
	}
}
int main(){
	scanf("%lld",&n);
	loop(i,1,n-1){
		scanf("%lld %lld",&x,&y);
		graph[x].pb(y);
	}
	weight.pb(0);
	loop(i,1,n){
		scanf("%lld",&x);
		weight.pb(x);
	}
	ans[1]=weight[1];
	dfs((lli)1);
	loop(i,1,n){
		if (mp.find(ans[i])!=mp.end()){
			mp[ans[i]] = min(mp[ans[i]],i);
		}
		else{
			mp[ans[i]]=i;
		}
	}
	scanf("%lld",&q);
	loop(i,0,q-1){
		scanf("%lld",&x);
		if (mp.find(x)==mp.end()){
			printf("-1\n");
		}
		else{
			printf("%lld\n", mp[x]);
		}
	}
	return 0;
}	