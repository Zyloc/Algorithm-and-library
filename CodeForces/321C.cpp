/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+5);
vector<lli> edge[MAX];
bool visited[MAX];
char ans[MAX];
bool bfsVisited[MAX];
char getNext(char c){
	if(c == 'Z'){
		return 'A';
	}
	return ++c;
}
pair<lli,lli> bfs(lli vertex,lli distance){
	memset(bfsVisited,0,sizeof bfsVisited);
	queue<pair<lli,lli> > q;
	q.push({0,vertex});
	bfsVisited[vertex] = true;
	pair<lli,lli> ans({0,vertex});
	while(!q.empty()){
		pair<lli,lli> processing(q.front());
		for(int i(0);i<edge[processing.second].size();i++){
			if(!bfsVisited[edge[processing.second][i]]){
				ans = max(ans,{processing.first+1,edge[processing.second][i]});
				bfsVisited[edge[processing.second][i]] =  true;
				if(processing.first+1 == distance){
					return {distance,edge[processing.second][i]};
				}
				q.push({processing.first+1,edge[processing.second][i]});
			}
		}
		q.pop();
	}
	return ans;
}
pair<lli,lli> getDiameter(){
	pair<lli,lli> u(bfs(1,INT_MAX));
	pair<lli,lli> v(bfs(u.second,INT_MAX));
	return v;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,y;
	cin>>n;
	for(int i(0);i<n-1;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	pair<lli,lli> diameter(getDiameter());
	lli start(bfs(diameter.second,(diameter.first+1)/2).second);
	queue<pair<lli,char> > q;
	q.push({start,'A'});
	visited[start] = true;
	ans[start] = 'A';
	while(!q.empty()){
		pair<lli,char> processing(q.front());
		for(int i(0);i<edge[processing.first].size();i++){
			if(!visited[edge[processing.first][i]]){
				visited[edge[processing.first][i]] = true;
				char next(getNext(processing.second));
				ans[edge[processing.first][i]] = next;
				q.push({edge[processing.first][i],next});
			}
		}
		q.pop();
	}
	for(int i(1);i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
