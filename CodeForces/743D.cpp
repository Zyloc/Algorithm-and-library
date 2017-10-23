
/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(2e5+5);
vector<lli> edge[MAX];
bool visited[MAX];
lli gift[MAX];
lli bestSum[MAX],totalSum[MAX];
lli ans;
lli dfs1(lli vertex){
	visited[vertex] = true;
	totalSum[vertex] = gift[vertex];
	bestSum[vertex] = -1e18;
	for(auto x:edge[vertex]){
		if(!visited[x]){
			totalSum[vertex] += dfs1(x);
			bestSum[vertex] = max(bestSum[vertex],bestSum[x]);
		}
	}
	//cout<<vertex<<" ";
	bestSum[vertex] = max(bestSum[vertex],totalSum[vertex]);
	//cout<<totalSum[vertex]<<" "<<bestSum[vertex]<<endl;
	return totalSum[vertex];
}

void dfs2(lli vertex,lli bestInRemainingSubTree){
	visited[vertex] = true;
	vector<pair<lli,lli> > dummy;
	//cout<<vertex<<" "<<bestInRemainingSubTree<<endl;
	if(bestInRemainingSubTree != -1e18){
		ans = max(ans,bestInRemainingSubTree+bestSum[vertex]);	
	}
	for(auto x:edge[vertex]){
		if(!visited[x]){
			dummy.push_back({bestSum[x],x});	
		}
		sort(dummy.rbegin(),dummy.rend());
		if(dummy.size() >= 3){
			dummy.pop_back();
		}
	}
	dummy.push_back({-1e18,-1});
	for(auto x:edge[vertex]){
		if(!visited[x]){
			if(x == dummy[0].second){
				dfs2(x,max(bestInRemainingSubTree,dummy[1].first));
			}
			else{
				dfs2(x,max(bestInRemainingSubTree,dummy[0].first));
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,y;
	cin>>n;	
	for(int i(1);i<=n;i++){
		cin>>gift[i];
	}
	for(int i(0);i<n-1;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs1(1);
	memset(visited,false,sizeof visited);
	ans = -1e18;
	dfs2(1,-1e18);
	cout<<(ans == -1e18?"Impossible":to_string(ans))<<endl;
	return 0;
}