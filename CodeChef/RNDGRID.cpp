/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli int
using namespace std;
const int MAX(1e3+1);
lli length,n;
string route,path[MAX],reversedRoute;
int ans[MAX][MAX];
bool visited[MAX][MAX];
void magicBox(lli i,lli j,lli currentPosition,lli maxLength){
	if(currentPosition == 0){
		ans[i][j] = maxLength;
		return ;
	}
	if(reversedRoute[currentPosition] == 'D'){
		if(i+1!=n and path[i+1][j]!='#'){
			magicBox(i+1,j,currentPosition-1,maxLength);
		}
	}
	if(reversedRoute[currentPosition] == 'U'){
		if(i-1!=0 and path[i-1][j]!='#'){
			magicBox(i-1,j,currentPosition-1,maxLength);
		}	
	}
	if(reversedRoute[currentPosition] == 'R'){
		if(j+1!=n and path[i][j+1]!='#'){
			magicBox(i,j+1,currentPosition-1,maxLength);
		}
	}
	if(reversedRoute[currentPosition] == 'L'){
		if(j-1!=0 and path[i][j-1]!='#'){
			magicBox(i,j-1,currentPosition-1,maxLength);
		}
	}
}
void check(lli i,lli j){
	for(int i(0);i<length;i++){
		if(reversedRoute[i] == 'R'){
			if(j!=n-1 and path[i][j+1]!='#'){
				magicBox(i,j+1,length,length+1);
			}
		}
		else if(reversedRoute[i] == 'D'){
			if(i!=n-1 and path[i+1][j]!='#'){
				magicBox(i+1,j,length,length+1);
			}	
		}
		else if(reversedRoute[i] == 'U'){
			if(j!=0 and path[i][j-1]!='#'){
				magicBox(i,j-1,length,length+1);
			}
		}
		else{
			if(j!=0 and path[i][j-1]!='#'){
				magicBox(i,j-1,length,length+1);
			}
		}
	}
}
int main(){
	lli t;
	cin>>t;
	while(t--){
		memset(ans,-1,sizeof ans);
		cin>>length>>n>>route;
		for(auto x:route){
			if(x == 'R'){
				reversedRoute+='L';
			}
			if(x == 'L'){
				reversedRoute+='R';
			}
			if(x == 'D'){
				reversedRoute+='U';
			}
			if(x == 'U'){
				reversedRoute+='D';
			}
		}
		for(int i(0);i<n;i++){
			cin>>path[i];
		}
		for(int i(0);i<n;i++){
			for(int j(0);j<n;j++){
				if(path[i][j] == '#'){
					check(i,j);
				}
			}
		}
		lli answer(0);
		for(int i(0);i<n;i++){
			for(int j(0);j<n;j++){
				cout<<ans[i][j]<<" ";;
			}
			cout<<endl;
		}
		cout<<answer<<endl;
	}
	return 0;
}	