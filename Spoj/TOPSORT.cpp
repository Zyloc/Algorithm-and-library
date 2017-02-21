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
vector<lli> edge[MAX];
bool cmp(lli x,lli y){
	return x>y;
}
void topographicalSort(lli start,bool visited[],stack<lli>&st){
	visited[start] = true;
	for(lli i=0;i<edge[start].size();i++){
		if (!visited[edge[start][i]]){
			topographicalSort(edge[start][i],visited,st);
		}
	}
	st.push(start);
}
bool isCyclicUtil(lli start,bool visited[],bool recStack[]){
	if(!visited[start]){
		visited[start] = true;
		recStack[start] = true;
		for(lli i=0;i<edge[start].size();i++){
			if (!visited[edge[start][i]] and isCyclicUtil(edge[start][i],visited,recStack)){
				return true;
			}
			else if(recStack[edge[start][i]]){
				return true;
			}
		}
	}
	recStack[start] = false;
	return false;
}
bool isCyclic(lli n){
	bool visited[n],recStack[n];
	memset(visited,false,sizeof(visited));
	memset(recStack,false,sizeof(recStack));	
	loop(i,1,n){
		if (!visited[i]){
			if(isCyclicUtil(i,visited,recStack)){
				return true;
			}
		}
	}
	return false;
}	
int main(){
	lli n,x,y,m;
	cin>>n>>m;
	loop(i,0,m-1){
		cin>>x>>y;
		edge[x].pb(y);
	}
	if(isCyclic(n+1)){
		cout<<"Sandro fails.";
		return 0;
	}
	loop(i,1,n){
		sort(edge[i].begin(),edge[i].end(),cmp);
	}
	bool visited[n+1];
	stack<lli> st;
	pool(i,n,1){
		if (!visited[i]){
			topographicalSort(i,visited,st);
		}
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}