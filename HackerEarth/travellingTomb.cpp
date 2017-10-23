/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+1);
lli n,m,k,size;
bool visited[MAX];
vector<pair<lli,lli> > graph[MAX];
void dfs(lli vertex){
	visited[vertex] = true;
	size++;
	for(auto x:graph[vertex]){
		if(!visited[x.second]){
			dfs(x.second);
		}
	}
}
void modifiedDfs(lli vertex,lli value){
	visited[vertex] = true;
	size++;
	for(auto x:graph[vertex]){
		if(!visited[x.second] and ((x.first&value) == x.first)){
			 modifiedDfs(x.second,value);
		}
	}	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y,l;
	cin>>n>>m>>k;
	vector<lli> costOfToken;
	lli ans(0);
	for(int i(0);i<k;i++){
		cin>>x;
		ans|= (1LL<<i);
		costOfToken.push_back(x);
	}
	for(int i(0);i<m;i++){
	    cin>>x>>y>>l;
	    x--,y--;
	    lli dummyMask(0),tokenNumber;
		for(int i(0);i<l;i++){
			cin>>tokenNumber;
			tokenNumber--;
			dummyMask |= (1LL<<tokenNumber);
		}
		graph[x].push_back({dummyMask,y});
	    graph[y].push_back({dummyMask,x});
	}
	dfs(0);
	if(size != n){
		cout<<-1<<endl;
		return 0;
	}
	lli totalCost(0);
	for(int i(k-1);i>=0;i--){
		size = 0;
		memset(visited,false,sizeof visited);
		modifiedDfs(0,ans^(1LL<<i));
		if(size != n){
			ans|= (1LL<<i);
			totalCost+=costOfToken[i];
		}
		else{
			ans ^= (1LL<<i);
		}
	}
	cout<<totalCost<<endl;
	return 0;
}	