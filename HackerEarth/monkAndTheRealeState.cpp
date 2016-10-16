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
lli cnt;
class Graph{
	lli V;
	list <lli> *adj;
	void DFSutil(lli vertex,bool visited[]);
public:
	Graph(lli V);
	void addEdge(lli from,lli to);
	void DFS(lli start);
};
Graph::Graph(lli V){
	this->V=V;
	adj = new list<lli>[V];
}
void Graph::addEdge(lli from,lli to){
	adj[from].pb(to);
}
void Graph::DFSutil(lli vertex,bool visited[]){
	visited[vertex] = true;
	//cout<<vertex<<" ";
	list<lli>::iterator it;
	for(it=adj[vertex].begin();it!=adj[vertex].end();++it){
		if (!visited[*it]){
			cnt++;
			DFSutil(*it,visited);
		}
	}
}
void Graph::DFS(lli n){
	lli vertex,ans(0);
	bool visited[V];
	memset(visited,false,sizeof(visited)/sizeof(bool));
	loop(i,0,n-1){
		if(!visited[i]){
			cnt=1;
			DFSutil(i,visited);
			ans +=  cnt;
		}
	}
	cout<<ans<<endl;
}
int main(){
	zyloc(){
		lli n,x,y,z(0);
		cin>>n;;
		Graph g(10000);
		loop(i,0,n-1){
			cin>>x>>y;
			x--,y--;
			g.addEdge(x,y);
			g.addEdge(y,x);
			z = max(x,max(y,z));
		}
		g.DFS(z);
	}	
	return 0;
}	