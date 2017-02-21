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
#define MAX 50000
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
vector<lli> graph[MAX];
lli bfs(lli start,lli level[],lli n,lli levelOfJohn){
	queue<pair<lli,lli> > q;
	q.push(mp(0,1));
	bool visited[n];
	memset(visited,false,sizeof(visited)/sizeof(bool));
	while(!q.empty()){
		pair<lli,lli> current;
		current.first = q.front().first;
		current.second = q.front().second;
		visited[current.first] = true;
		for (lli i=0;i<graph[current.first].size();i++){
			if (!visited[graph[current.first][i]]){
				q.push(mp(graph[current.first][i],current.second+1));
				visited[graph[current.first][i]] = true;
				level[current.second+1]++;
			}
		}
		q.pop();
	}
	lli ans(0);
	loop(i,1,levelOfJohn-1){
		ans += level[i];
	}
	return ans; 
}
int main(){
	lli n,x,y,levelOfJohn;
	cin>>n;
	loop(i,0,n-2){
		cin>>x>>y;
		x--,y--;
		graph[x].pb(y);
		graph[y].pb(x);

	}
	cin>>levelOfJohn;
	lli level[n+2];
	memset(level,0,sizeof(level)/sizeof(lli));
	loop(i,0,n+1){
		level[i] = 0;
	}
	level[1]++;
	cout<<bfs(0,level,n,levelOfJohn);
	return 0;
}	