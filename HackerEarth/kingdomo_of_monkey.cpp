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
lli localAns;
class Graph{
	lli V;
	list <lli> *adj;
	lli DFSutil(vector<lli> &v,lli vertex,bool visited[],lli memo[]);
public:
	Graph(lli V);
	void addEdge(lli from,lli to);
	lli DFS(vector<lli> &v,lli start,lli upto);
};
Graph::Graph(lli V){
	this->V=V;
	adj = new list<lli>[V];
}
void Graph::addEdge(lli from,lli to){
	adj[from].pb(to);
}
lli Graph::DFSutil(vector<lli> &v,lli vertex,bool visited[],lli memo[]){
	visited[vertex] = true;
	list<lli>::iterator it;
	for(it=adj[vertex].begin();it!=adj[vertex].end();it++){
		if (!visited[*it]){
			memo[*it] = DFSutil(v,*it,visited,memo);
			return v[*it]+memo[*it];
		}
		return memo[*it];
	}

}
lli Graph::DFS(vector<lli> &v,lli start,lli upto){
	lli vertex,ans(0);
	lli memo[upto+1];
	memset(memo,0
		,sizeof(memo)/sizeof(lli));
	bool visited[V];
	memset(visited,false,sizeof(visited)/sizeof(bool));
	loop(i,0,upto){
		if (!visited[i]){
			DFSutil(v,i,visited,memo);
			memo[i] = localAns+v[i];
			ans = max(ans,localAns+v[i]);
			localAns = 0;
		}		
	}
	return ans;
}
int main(){
	zyloc(){
		lli n,m,x,y;
		cin>>n>>m;
		Graph g(n);
		loop(i,0,m-1){
			cin>>x>>y;
			x--,y--;
			g.addEdge(x,y);
		}
		vi(v);
		loop(i,0,n-1){
			cin>>x;
			v.pb(x);
		}
		cout<<g.DFS(v,0,n-1)<<endl;

	}	
	return 0;
}	