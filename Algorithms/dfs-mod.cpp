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
	lli vertex;
	list<lli> *adj;
	void DFSutil(lli start,bool* visited);
public:
	Graph(lli vertex);
	void addEdge(lli from,lli to);
	void DFS();
};
Graph::Graph(lli vertex){
	this->vertex=vertex;
	adj = new list<lli>[vertex];
}
void Graph::addEdge(lli from,lli to){
	adj[from].pb(to);
}
void Graph::DFSutil(lli start,bool* visited){
	/*visited[start]=true;
	cout<<start<<" ";
	list<lli>::iterator it;
	for(it=adj[start].begin();it!=adj[start].end();++it){
		if (!visited[*it]){
			DFSutil(*it,visited);
		}
	}*/
	list<lli>::iterator it;
	stack<lli> st;
	st.push(start);
	while(!st.empty()){
		lli top=st.top();
		cout<<top<<" ";
		st.pop();
		visited[top]=true;
		for (it=adj[top].begin();it!=adj[top].end();it++){
			if (!visited[*it]){
				st.push(*it);
			}
		}
	}	
}
void Graph::DFS(){
	bool* visited=new bool[this->vertex];
	loop(i,0,this->vertex-1){
		visited[i]=false;
	}
	loop(i,0,vertex-1){
		if (!visited[i]){
			DFSutil(i,visited);
			break;	
		}
	}
}
int main(){
	lli n,parent,from,to;
	cin>>n;
	Graph g(n);
	loop(i,1,n){
		/*cin>>parent;
		if (parent!=-1){
			g.addEdge(parent-1,i-1);
		}*/
			cin>>from>>to;
			g.addEdge(from,to);
	}
	g.DFS();	
    return 0;
}	