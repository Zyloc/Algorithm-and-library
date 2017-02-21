/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e3+1;
bool isPresent[MAX][MAX];
void topLeft(lli x,lli y,lli &ans,bool &check){
	if(x < 1 or x >=MAX or y < 1 or y >= MAX){
		return;
	}
	if(isPresent[x][y]){
		check = true;
		ans++;
	}
	topLeft(x-1,y-1,ans,check);
}
void topRight(lli x,lli y,lli &ans,bool &check){
	if(x < 1 or x >=MAX or y < 1 or y >= MAX){
		return;
	}
	if(isPresent[x][y]){
		check =true;
		ans++;
	}
	topRight(x-1,y+1,ans,check);
}
void bottomLeft(lli x,lli y,lli &ans,bool &check){
	if(x < 1 or x >=MAX or y < 1 or y >= MAX){
		return;
	}
	if(isPresent[x][y]){
		ans++;
		check = true;
	}
	bottomLeft(x+1,y-1,ans,check);
}
void bottomRight(lli x,lli y,lli &ans,bool &check){
	if(x < 1 or x >=MAX or y < 1 or y >= MAX){
		return;
	}
	if(isPresent[x][y]){
		check = true;
		ans++;
	}
	bottomRight(x+1,y+1,ans,check);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,y;
	cin>>n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v.push_back(make_pair(x,y));
		isPresent[x][y] = true;
	}
	lli ans(0),ans2(0);
	for(int i=0;i<v.size();i++){
		bool check(false);
		lli x(v[i].first),y(v[i].second);
		if(x >= 1){
			if(y >= 1 ){
				topLeft(x-1,y-1,ans,check);
			}
			if(y < MAX){
				topRight(x-1,y+1,ans,check);
			}	
		}
		if(x < MAX){
			if(y >= 1 ){
				bottomLeft(x+1,y-1,ans,check);
			}
			if(y < MAX){
				bottomRight(x+1,y+1,ans,check);
			}
		}
	}
	cout<<ans/2<<endl;
	return 0;
}