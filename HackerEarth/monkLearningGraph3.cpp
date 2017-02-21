/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
struct dataType{
	int node,value;
};
class cmp{
public:
	bool operator()(dataType lhs,dataType rhs){
		return lhs.value > rhs.value;
	}
};
vector<int> graph[MAX];
priority_queue<dataType,vector<dataType>,cmp> pq[MAX];
vector<int> value;
void bfs(int n,int k){
	bool visited[n+1];
	memset(visited,false,sizeof visited);
	queue<int> q;
	q.push(1);
	dataType temp;
	while(!q.empty()){
		int processing(q.front());
		visited[processing] = true;
		q.pop();
		for(auto x : graph[processing]){
			if(!visited[x]){
				if(pq[processing].size() < k){
					temp.node =  x;
					temp.value = value[x];
					pq[processing].push(temp);
				}
				else{
					temp  = pq[processing].top();
					if(value[x] > temp.value){
						pq[processing].pop();
						temp.node =  x;
						temp.value = value[x];
						pq[processing].push(temp);
					}
				}
				if(pq[x].size() < k){
					temp.node =  processing;
					temp.value = value[processing];
					pq[x].push(temp);
				}
				else{
					temp = pq[x].top();
					if(value[processing] > temp.value){
						temp.node =  processing;
						temp.value = value[processing];
						pq[x].pop();
						pq[x].push(temp);
					}	
				}
				q.push(x);
			}
		}
	}
}
int main(){
	int n,m,k,x,y;
	cin>>n>>m>>k;
	value.push_back(0);
	for(int i=0;i<n;i++){
		cin>>x;
		value.push_back(x);
	}
	for(int i=0;i<m;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(n,k);
	for(int i=1;i<=n;i++){
		if(pq[i].size() < k){
			cout<<-1<<endl;
		}
		else{
			cout<<pq[i].top().node<<endl;
		}
	}
	return 0;
}