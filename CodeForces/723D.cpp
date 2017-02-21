/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 51;
lli n,m,k;
string s[MAX],dummy[MAX];
bool isLake(lli x,lli y){
	if(dummy[x][y] == '.'){
		return true;
	}
	return false;
}
void dfs(lli x,lli y,lli &sizeOfLake){
	dummy[x][y] = '*';
	if(isLake(x-1,y)){
		sizeOfLake++;
		dfs(x-1,y,sizeOfLake);
	}
	if(isLake(x+1,y)){
		sizeOfLake++;
		dfs(x+1,y,sizeOfLake);
	}
	if(isLake(x,y-1)){
		sizeOfLake++;
		dfs(x,y-1,sizeOfLake);
	}
	if(isLake(x,y+1)){
		sizeOfLake++;
		dfs(x,y+1,sizeOfLake);
	}
}
void fillDummy(lli x,lli y){
	dummy[x][y] = '*';
	//upside
	if(x!=0){
		if(dummy[x-1][y] == '.'){
			fillDummy(x-1,y);
		}
	}
	//right side
	if(y!=m-1){
		if(dummy[x][y+1] == '.'){
			fillDummy(x,y+1);
		}
	}
	//left size 
	if(y!=0){
		if(dummy[x][y-1] == '.'){
			fillDummy(x,y-1);
		}
	}
	// down side
	if(x!=n-1){
		if(dummy[x+1][y] == '.'){
			fillDummy(x+1,y);
		}
	}
}
void fill(lli x,lli y){
	s[x][y] = '*';
	//upside
	if(s!=0){
		if(s[x-1][y] == '.'){
			fill(x-1,y);
		}
	}
	//right side
	if(y!=m-1){
		if(s[x][y+1] == '.'){
			fill(x,y+1);
		}
	}
	//left size 
	if(y!=0){
		if(s[x][y-1] == '.'){
			fill(x,y-1);
		}
	}
	// down side
	if(x!=n-1){
		if(s[x+1][y] == '.'){
			fill(x+1,y);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>s[i];
		dummy[i] = s[i];
	}
	for(int i=0;i<n;i++){
		if(dummy[i][0] == '.'){
			fillDummy(i,0);	
		}
		if(dummy[i][m-1] == '.'){
			fillDummy(i,m-1);	
		}
	}
	for(int j=0;j<m;j++){
		if(dummy[0][j] == '.'){
			fillDummy(0,j);	
		}
		if(dummy[n-1][j] == '.'){
			fillDummy(n-1,j);	
		}
	}
	vector<pair<lli,pair<lli,lli> > > lakes;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(isLake(i,j)){
				lli sizeOfLake(1);
				dfs(i,j,sizeOfLake);
				lakes.push_back(make_pair(sizeOfLake,make_pair(i,j)));
			}
		}
	}
	sort(lakes.begin(),lakes.end());
	lli ans(0);
	for(int i=0;i<lakes.size()-k;i++){
		ans+=lakes[i].first;
		fill(lakes[i].second.first,lakes[i].second.second);
	}
	cout<<ans<<endl;;
	for(auto x:s){
		cout<<x<<endl;
	}	
	return 0;
}