/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX_EDGES = 1e5+1;
vector<int> tree[MAX_EDGES];
int value[MAX_EDGES];
bool visited[MAX_EDGES];
int ans;
void dfs(int processing,int final,int v,int counter){
	visited[processing] = true;
	if(ans!=0){
		return;
	}
	if(processing == final){
		if(__gcd(value[processing],v) == 1){
			ans = counter+1;
		}
		else{
			ans  = counter;
		}
		return ;
	}
	for(auto x:tree[processing]){
		if(!visited[x]){
			if(__gcd(value[processing],value[x]) == 1){
				dfs(x,final,v,counter+1);
			}
			else{
				dfs(x,final,v,counter);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,q,x,y;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>value[i];
	}
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	for(int i=0;i<q;i++){
		lli type;
		cin>>type;
		if(type){
			int v;
			cin>>x>>y>>v;
			ans = 0;
			memset(visited,false,sizeof visited);
			if(__gcd(value[x],v) == 1){
				dfs(x,y,v,1);	
			}
			else{
				dfs(x,y,v,0);
			}
			cout<<ans<<endl;
		}
		else{
			cin>>x;
			cin>>value[x];
		}
	}
	return 0;
}