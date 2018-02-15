/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,m;
const int MAX(1e2+3);
vector<lli> graph[MAX];
bool visited[MAX],isCyclic[MAX];
lli globalCounter,nodeCount;
lli dfs(lli processing,lli parent){
	visited[processing] = true;
	nodeCount++;
	lli idx(-1),temp(-1);
	for(auto x:graph[processing]){
		if(x == parent){
			continue;
		}
		if(visited[x] and !isCyclic[x]){
			idx = x;
			globalCounter++;
		}
		else if(!isCyclic[x]){
			temp = max(temp,dfs(x,processing));
		}
	}
	if(temp != -1 or idx!=-1 ){
		isCyclic[processing] = true;
	}
	//cout<<processing<<" "<<-1<<endl;
	if(temp == processing){
		return -1;
	}
	//cout<<processing<<" "<<max(idx,temp)<<endl;
	return max(idx,temp);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y;
	cin>>n>>m;
	for(int i(0);i<m;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1,-1);
	//cout<<globalCounter<<" "<<nodeCount<<endl;
	if(globalCounter > 1 or nodeCount!=n){
		cout<<"NO";
		return 0;
	}
	lli totalCyclicNode(0);
	for(int i(1);i<=n;i++){
		if(isCyclic[i]){
			totalCyclicNode++;
		}
	}
	if(totalCyclicNode >= 3){
		cout<<"FHTAGN!"<<endl;
	}
	else{
		cout<<"NO";
	}
	return 0;
}
