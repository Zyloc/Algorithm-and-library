/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e5+1;
struct edge{
    lli to,number;
};
vector<edge> graph[MAX];
lli disappears[MAX],timeToReach[MAX];
lli n,m,k,from,to,tme,edgeNumber;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	edge temp;
	for(int i=1;i<=m;i++){
	    disappears[i] = INT_MAX;
	    timeToReach[i] = -1;
	    cin>>from>>to;
	    temp.to = to;
	    temp.number = i;
	    graph[from].push_back(temp);
	    temp.to = from;
	    graph[to].push_back(temp);
	}
	for(int i=0;i<k;i++){
	    cin>>tme>>edgeNumber;
	    disappears[edgeNumber] = tme;
	}
	timeToReach[1] = 0;
	queue<edge> q;
	temp.to = 1;
	temp.number = 0;
	q.push(temp);
	while(!q.empty()){
		if(q.front().to == n){
			cout<<timeToReach[n];
			return 0;
		}
		for(auto x:graph[q.front().to]){
			if(timeToReach[x.to] == -1 and timeToReach[q.front().to] < disappears[x.number]){
				timeToReach[x.to] = timeToReach[q.front().to]+1;
				q.push(x);
			}
		}
		q.pop();
	}
	cout<<ans[n];
	return 0;
}