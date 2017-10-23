/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(500+5);
int ones[MAX][MAX];
lli calculateOnes(lli i,lli j,lli size){
    return ones[i+size-1][j+size-1]-ones[i+size-1][j-1]-ones[i-1][j+size-1];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,x;
	cin>>n>>m;
	for(int i(1);i<=n;i++){
	    for(int j(1);j<=m;j++){
	        cin>>x;
	        ones[i][j] = ones[i][j-1]+ones[i-1][j]-ones[i-1][j-1]+(x==1);
	    }   
	}
	lli answer(ones[n][m]);
	for(int size(1);size <= min(n,m);size++){
	    for(int i(1);i+size-1<=n;i++){
    	    for(int j(1);j+size-1<=m;j++){
    	       answer = max(answer,ones[n][m]+size*size-2*calculateOnes(i,j,size));
    	    }   
	    }
	}
	cout<<answer<<endl;
	return 0;
}	