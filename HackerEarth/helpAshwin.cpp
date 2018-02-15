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
lli dijkstra(vector<edge> graph[],vector<lli> &minimumDistance,lli source){
	minimumDistance[source] = 0;
	set<pair<lli,lli> > activeVertices;
	activeVertices.insert(mp(0,source));
	while(!activeVertices.empty()){
		lli processing(activeVertices.begin()->second);
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
	cin>>t;
	while(t--){
		lli n,m,from,to,weight,source,k,shift(1e5+10);
		scanf("%lld %lld",&n,&m);
		vector<edge> graph[n+1];
		vector<lli> minimumDistance(n+1,INT_MAX);
		edge temp;
		loop(i,0,m-1){
			scanf("%lld %lld %lld",&to,&from,&weight);
			weight+=shift;
			temp.to = to;
			temp.weight = weight;
			graph[from].pb(temp);
			temp.to = from;
			graph[to].pb(temp);
		}
		cin>>source>>k;
		k+=shift;
		vector<lli> input;
		dijkstra(graph,minimumDistance,source);	
		loop(i,1,n){
			if (minimumDistance[i]==INT_MAX){
				printf("-1 ");
			}
			else if (i!=source){
				cout<<minimumDistance[i]-shift<<endl;
				input.push_back(minimumDistance[i]);
			}
		}
		sort(input.begin(),input.end());
		lli ans(1),sum(0);
		for(auto x:input){
			if(sum+x <= k){
				sum+=x;
				ans++;
			}
		}
		cout<<ans<<endl;
		printf("\n");	
	}
	return 0;
}	