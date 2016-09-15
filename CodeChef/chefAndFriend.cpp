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
#define MAX 1003
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
class Graph{
	lli V;
	lli adj[MAX][MAX]; 
public:
	Graph(lli V);
	void BFS(lli n);
	bool BFSUtil(lli start,bool visited[],lli color[]);
	void deleteEdge(lli from,lli to);
};
Graph::Graph(lli V){
	this->V=V;
	loop(i,1,V-1){
		loop(j,1,V-1){
			if (i!=j)
				adj[i][j]=1;
			else
				adj[i][j] = 0;
		}
	}
}
void Graph::deleteEdge(lli from,lli to){
	adj[from][to] = 0;
}
bool Graph::BFSUtil(lli start,bool visited[],lli color[]){
	lli vertex(start);
	visited[vertex] = true;
	color[start] = 1;
	list<lli> q;
	q.push_back(vertex);
	//cout<<V<<endl;
	/*loop(i,1,V-1){
		loop(j,1,V-1){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}*/
	while(!q.empty()){
		vertex=q.front();
		q.pop_front();
		for(int it=0;it<V;it++){
			//cout<<vertex<<" "<<it<<" "<<adj[vertex][it]<<" "<<color[it]<<endl;
			if (adj[vertex][it] and color[it]==-1){
				//debug();
				//cout<<vertex<<" "<<it<<endl;
				color[it] = 1 - color[vertex];
				visited[it] = true;
				q.push_back(it);
			}
			else if(adj[vertex][it] and color[it]==color[vertex]){
				//cout<<vertex<<" "<<it<<" "<<color[vertex]<<endl;
				return false;
			}
		}
	}
	return true;	
}
void Graph::BFS(lli n){
	bool visited[V]={false};
	lli color[n];
	loop(i,1,n-1){
		color[i] = -1;
	}
	loop(i,1,V-1){
		if (!visited[i]){
			if (!BFSUtil(i,visited,color)){
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	zyloc(){
		lli m,n,x,y;
		cin>>n>>m;
		Graph g(n+1);
		loop(i,0,m-1){
			cin>>x>>y;
			g.deleteEdge(x,y);
			g.deleteEdge(y,x);
		}
		g.BFS(n+1);
	}
	return 0;
}	