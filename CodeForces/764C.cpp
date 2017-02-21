/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e5+1;
vector<lli> tree[MAX];
lli color[MAX];
bool visited[MAX];
lli dfs(lli vertex,lli parentColor){
	if(color[vertex]!=parentColor){
		return vertex;
	}
	visited[vertex] = true;
	for(auto x:tree[vertex]){
		if(!visited[x]){
			lli calVertex(dfs(x,parentColor));
			if(calVertex != -1){
				return calVertex;
			}
		}
	}
	return -1;
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,y;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	color[0] = 0;
	for(int i=1;i<=n;i++){
		cin>>color[i];
	}
	lli probableParent1(1),probableParent2(0);
	bool flag(false);
	visited[1] = true;
	for(auto x:tree[1]){
		lli getVertex(dfs(x,color[x]));
		if(getVertex!=-1){
			probableParent1 = getVertex;
			probableParent2 = x;
			flag = true;
			break;
		}
	}
	if(flag){
		memset(visited,false,sizeof visited);
		visited[probableParent1] = true;
		bool flag2(false);
		for(auto x:tree[probableParent1]){
			if(dfs(x,color[x])!= -1){
				flag2 = true;
				break;
			}
		}
		if(!flag2){
			cout<<"YES"<<endl;
			cout<<probableParent1<<endl;
			return 0;	
		}
		memset(visited,false,sizeof visited);
		visited[probableParent2] = true;
		for(auto x:tree[probableParent2]){
			if(dfs(x,color[x])!= -1){
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES"<<endl;
		cout<<probableParent2<<endl;
		return 0;
	}
	else{
		cout<<"YES"<<endl;
		cout<<1<<endl;		
	}
	return 0;
}