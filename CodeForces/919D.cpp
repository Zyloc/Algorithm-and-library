/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(3e5+1);
vector<lli> edge[MAX],oppositeEdge[MAX];
lli dp[MAX][26];
lli n,m,a,b;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	string s;
	cin>>s;
	lli inDegree[n+1];
	lli dp[n+1][26];
	memset(inDegree,0,sizeof inDegree);
	memset(dp,0,sizeof dp);
	for(int i(0);i<m;i++){
		cin>>a>>b;
		edge[a].push_back(b);
		oppositeEdge[b].push_back(a);
		inDegree[b]++;
	}
	queue<lli> q;
	vector<lli> topographicalSort;
	lli count(0);
	for(int i(1);i<=n;i++){
		if(inDegree[i] == 0){
			q.push(i);
			count++;
		}
	}
	while(!q.empty()){
		lli processing(q.front());
		topographicalSort.push_back(processing);
		q.pop();
		for(auto x:edge[processing]){
			inDegree[x]--;
			if(inDegree[x] == 0){
				count++;
				q.push(x);
			}
		}
	}
	if(count != n){
		cout<<-1<<endl;
		return 0;
	}
	lli ans(0);
	for(auto y:topographicalSort){
		dp[y][s[y-1]-'a']++;
		for(auto x:oppositeEdge[y]){
			for(int i(0);i<26;i++){
				dp[x][i]+=dp[y][i];
			}
		}
	}
	for(int i(0);i<=n;i++){
		for(int j(0);j<26;j++){
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
