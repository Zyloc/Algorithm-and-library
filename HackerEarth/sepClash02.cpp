/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h>
#include <list>  
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
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
lli maxH;
class Graph{
	lli V;
	list <lli> *adj;
	void DFSutil(lli vertex,bool visited[],lli maxH);
	vector<pair<lli,lli> > v;
	vector<lli> copyV;
public:
	Graph(lli V);
	void addEdge(lli from,lli to);
	lli DFS(lli end);
	lli DFSutil(lli vertex,bool visited[]);
	void insertHeight(lli x,lli pos);
};
Graph::Graph(lli V){
	this->V=V;
	adj = new list<lli>[V];
}
void Graph::addEdge(lli from,lli to){
	adj[from].pb(to);
}
void Graph::insertHeight(lli x,lli pos){
	v.pb(mp(x,pos));
	copyV.pb(x);
}
lli Graph::DFSutil(lli vertex,bool visited[]){
	if (visited[vertex]){
		return 0;
	}
	visited[vertex] = true;
	maxH = max(maxH,copyV[vertex-1]);
	list<lli>::iterator it;
	for(it=adj[vertex].begin();it!=adj[vertex].end();++it){
		if (!visited[*it]){ 
			DFSutil(*it,visited);
		}
	}
	return maxH;
}
lli Graph::DFS(lli end){
	lli vertex;
	bool visited[V];
	memset(visited,false,sizeof(visited)/sizeof(bool));
	sort(v.begin(),v.end());
	/*loop(i,0,end){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}*/
	/*loop(i,1,V-1){
		cout<<i<<" ";	
		list<lli>::iterator it;
		for(it=adj[i].begin();it!=adj[i].end();++it){
			cout<<*it<<" ";
		}
		cout<<endl;
	}	*/
	lli ans(INT_MIN);
	//debug();
	loop(i,0,end-1){
		if (!visited[v[i].second]){
			maxH = 0;
			lli x(DFSutil(v[i].second,visited));
			//cout<<v[i].second<<" "<<x<<endl;
			ans = max(ans,x-v[i].first);
		}
	}
	delete[] adj;
	return ans;
} 
int main(){
	zyloc(){
		lli n,m,a,b,x;
		cin>>n>>m;
		vector<pair<lli,lli> > v;
		Graph g(n+1);
		//g.insertHeight(0,0);
		loop(i,0,n-1){
			cin>>x;
			g.insertHeight(x,i+1);
		}
		loop(i,0,m-1){
			cin>>a>>b;
			g.addEdge(a,b);
		}
		cout<<g.DFS(n)<<endl;
	}
	return 0;
}	