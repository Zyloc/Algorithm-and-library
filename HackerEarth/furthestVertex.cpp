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
lli ans;
void dfs(vector<lli> graph[],bool visited[],lli start,lli level){
	visited[start]=true;
	if(graph[start].size()>0){
		for(auto x:graph[start]){
			if(!visited[x]){
				level++;
				ans = max(ans,level);
				dfs(graph,visited,x,level);
			}
		}	
	}
	
}
int main(){
	lli n,q,x,y;
	cin>>n>>q;
	vector<lli> graph[n+1];
	bool visited[n+1];
	memset(visited,false,sizeof visited);
	while(q--){	
		cin>>x;
		if (x==1){
			cin>>x>>y;
			graph[x].pb(y);
			graph[y].pb(x);
		}
		else{
			cin>>x;
			dfs(graph,visited,x,0);
			cout<<ans<<endl;
			ans = 0;
			memset(visited,false,sizeof visited);
		}
	}
	return 0;
}	