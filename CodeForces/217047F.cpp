/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,m;
const int MAX(50);
vector<lli> graph[MAX],answer[MAX];
bool visited[MAX],considered[MAX];
vector<lli> temp;
void dfs(lli processing){
	visited[processing] = true;
	temp.push_back(processing);
	for(auto x:graph[processing]){
		if(!visited[x]){
			dfs(x);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,x,y;
	cin>>n>>m;
	for(int i(0);i<m;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	lli answerIterator(0);
	for(int i(1);i<=n;i++){
		if(!visited[i]){
			dfs(i);
			if(temp.size() > 3){
				cout<<-1;
				return 0;
			}
			if(temp.size() >= 2){
				for(auto x:temp){
					considered[x] = true;
					answer[answerIterator].push_back(x);
				}
				answerIterator++;	
			}
			temp.clear();
		}
	}
	for(int i(0);i<answerIterator;i++){
		if(answer[i].size() == 2){
			for(int j(1);j<=n;j++){
				if(!considered[j]){
					considered[j] = true;
					answer[i].push_back(j);
					break;
				}
			}
		}
	}
	vector<lli> check;
	for(int i(1);i<=n;i++){
		if(!considered[i]){
			check.push_back(i);
		}
	}
	while(!check.empty()){
		answer[answerIterator].push_back(check.back());
		check.pop_back();
		answer[answerIterator].push_back(check.back());
		check.pop_back();
		answer[answerIterator].push_back(check.back());
		check.pop_back();
		answerIterator++;
	}
	for(int i(0);i<answerIterator;i++){
		if(answer[i].size()!=3){
			cout<<-1;
			return 0;
		}
	}
	for(int i(0);i<answerIterator;i++){
		for(auto x:answer[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}

	return 0;
}
