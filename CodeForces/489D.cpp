/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 3001;
vector<int> graph[MAX];
lli n,m,x,y;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		graph[x].push_back(y);
	}
	lli ans(0);
	for(int i=1;i<=n;i++){
		lli firstNode(i);
		for(int j=0;j<graph[firstNode].size();j++){
			lli secondNode(graph[firstNode][j]);
			lli count(0);
			for(int k=0;k<graph[secondNode].size();k++){
				lli thirdNode(graph[secondNode][k]);
				if(firstNode != thirdNode){
					count++;	
				}
			}
			ans+= count*(count-1)/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}