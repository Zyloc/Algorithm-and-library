/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,K,x;
	cin>>n>>K;
	lli cost[n+1];
	lli parent[n+1];
	for(int i(1);i<=n;i++){
	    cin>>cost[i];
	}
	parent[1] = 1;
	for(int i(2);i<=n;i++){
	   cin>>parent[i];
	}
	bool isParent[n+1][n+1];
	memset(isParent,false,sizeof isParent);
	for(int i(2);i<=n;i++){
	    lli vertex(i);
	    while(vertex != 1){
	        vertex = parent[vertex];
	        isParent[vertex][i] = true;
	    }
	}
	lli ans(0);
	for(int i(1);i<=n;i++){
	    for(int j(1);j<=n;j++){
	        for(int k(1);k<=n;k++){
	        	if(i==j or j==k or i==k){
	        		continue;
	        	}
	            if(isParent[i][j] and isParent[i][k] and cost[i]+cost[j]+cost[k] >= K){
	                ans++;
	            }
	       }   
	    }   
	}
	cout<<ans/2<<endl;
	return 0;
}	