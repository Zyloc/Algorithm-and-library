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
#include <queue>  
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
	lli noOfVertex;
	list <lli> *adj;
public:
	Graph(lli noOfVertex);
	void addEdge(lli from,lli to);
	void bfs(lli start);
};

Graph::Graph(lli noOfVertex){
	this->noOfVertex = noOfVertex;
	adj = new list<lli>[noOfVertex];
}

void Graph::addEdge(lli from,lli to){
	adj[from].push_back(to);
}

void Graph::bfs(lli start){
	bool *visited = new bool[noOfVertex];
	loop(i,0,noOfVertex-1){
		visited[i] = false; 
	}
	queue<lli> q;
	visited[start] =  true;
	q.push(start);
	list<lli>::iterator it;
	while(!q.empty()){
		start = q.front();
		cout<<start<<" ";
		q.pop();
		for (it = adj[start].begin();it!=adj[start].end();it++){
			if (!visited[*it]){
				visited[*it] =  true;
				q.push(*it);
				break;
			}
		}
	}

}
int main(){
	Graph g(4);
    g.bfs(2);
    return 0;
}	