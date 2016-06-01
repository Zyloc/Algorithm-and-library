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
class Graph{
	int V;
	list<lli> *adj; 
public:
	Graph(lli V);
	void addEdge(lli from,lli to);
	void BFS(lli start);
};
Graph::Graph(lli V){
	this->V=V;
	adj = new list<lli>[V];
}
void Graph::addEdge(lli from,lli to){
	adj[from].pb(to);
}
void Graph::BFS(lli start){
	lli vertex;
	bool visited[V];
	memset(visited,false,sizeof(visited)/sizeof(bool));
	list<lli> q;
	vertex=start;
	q.push_back(vertex);
	visited[vertex]=true;
	list<lli>::iterator it;
	while(!q.empty()){
		vertex=q.front();
		q.pop_front();
		cout<<vertex<<" ";
		for(it=adj[vertex].begin();it!=adj[vertex].end();++it){
			if (!visited[*it]){
				visited[*it]=true;
				q.push_back(*it);
			}
		}
	}
}
int main(){
	//Graph* g = new Graph(4);
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);	
    return 0;
}	