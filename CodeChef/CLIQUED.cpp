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
};
bool check;
lli n,m,from,to,weight,source,k,x;
lli dijkstra(vector<edge> graph[],vector<lli> &minimumDistance,lli source){
	minimumDistance[source] = 0;
	set<pair<lli,lli> > activeVertices;
	activeVertices.insert(mp(0,source));
	if(source <= k){
		for(int i(1);i<=k;i++){
			edge temp;
			temp.to = i;
			temp.weight = x;
			graph[source].push_back(temp);
			temp.to = source;
			graph[i].push_back(temp); 
		}
		check = true;
	}
	while(!activeVertices.empty()){
		lli processing(activeVertices.begin()->second);
		if(!check and processing <= k){
			for(int i(1);i<=k;i++){
				edge temp;
				temp.to = i;
				temp.weight = x;
				graph[processing].push_back(temp);
				temp.to = processing;
				graph[i].push_back(temp); 
			}
			check = true;
		}
		activeVertices.erase(activeVertices.begin());
		if (graph[processing].size()>0){
			loop(i,0,graph[processing].size()-1){
				if (minimumDistance[graph[processing][i].to] > minimumDistance[processing] + graph[processing][i].weight){
					activeVertices.erase(mp(minimumDistance[graph[processing][i].to],graph[processing][i].to));
					minimumDistance[graph[processing][i].to] = minimumDistance[processing] + graph[processing][i].weight;
					activeVertices.insert(mp(minimumDistance[graph[processing][i].to],graph[processing][i].to));
				}
			}
		}	
	}
	return 0;
}
int main(){
	lli t;
	scanf("%lld",&t);
	while(t--){
		check = false;
		scanf("%lld %lld %lld %lld %lld",&n,&k,&x,&m,&source);
		vector<edge> graph[n+1];
		vector<lli> minimumDistance(n+1,1e18);
		edge temp;
		loop(i,0,m-1){
			scanf("%lld %lld %lld",&to,&from,&weight);
			temp.to = to;
			temp.weight = weight;
			graph[from].pb(temp);
			temp.to = from;
			graph[to].pb(temp);
		}
		dijkstra(graph,minimumDistance,source);	
		loop(i,1,n){
			cout<<minimumDistance[i]<<" ";
		}
		printf("\n");
	}
	return 0;
}	