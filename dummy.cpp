/*
 * Everyting happens for a reason . Hold tight everything is gonna ok :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6);
bool prime[MAX];
vector<lli> adj[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n>>x;
	for(int i(2);i<MAX;i++){
		if(!prime[i]){
			for(int j(i);j<MAX;j+=i){
				adj[j].push_back(i);
				prime[j] = true;
			}
		}
	}
	bool isSmith[MAX];
	memset(isSmith,false,sizeof isSmith);
	for(int i(4);i<5;i++){
		lli temp(0),tem2(i);
		while(tem2){
			temp+=tem2%10;
			tem2/=10;
		}
		lli temp3(0),temp5(0);
		for(int j(0);j<adj[i].size();j++){
			lli temp4(adj[i][j]);
			while(temp4){
				temp5+=temp4%10;
				temp4/=10;
			}
		}
		if(temp5 == temp){
			isSmith[i] = true;
		}
	}
	while(n--){
		if(isSmith[x]){
			n--;
		}
	}
	cout<<x<<endl;
	return 0;
}
