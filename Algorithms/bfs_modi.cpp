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
struct edge{
	lli to;
	lli weight;
	lli level;
	edge(){
		level = 0;
	}
};
void bfs(vector<edge> v[],lli n,lli source){
	queue<edge> q;
	bool visited[n+1];
	memset(visited,false,sizeof(visited));
	edge temp;
	temp.to = source;
	q.push(temp);
	debug();
	cout<<source<<" ";
	while(!q.empty()){
		edge current(q.front());
		visited[current.to] = true;
		q.pop();
		for(auto ed : v[current.to]){
			if (!visited[ed.to]){
				cout<<ed.to<<" ";
				temp.to = ed.to;
				temp.level = ed.level+1;
				q.push(temp);
			}
		}	
		cout<<endl;
	}
}
int main(){
	lli n,m,from,to,weight,source;
	cin>>n>>m;
	vector<edge> v[n+1];
	edge temp;
	loop(i,0,m-1){
		cin>>from>>to;
		temp.to = to;
		temp.weight = 0;
		v[from].pb(temp);
	}
	bfs(v,n,source);
	return 0;
}	