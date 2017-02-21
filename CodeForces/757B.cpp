/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int MAX = 1e5+1;
	int hash[MAX]={0};
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>hash[i];
	}
	int ans(0);
	for(int i=2;i*i<MAX;i++){
		int count(0);
		for(int j=0;j<n;j++){
			bool flag(false);
			while(hash[j]%i==0 and hash[j]!=1){
				hash[j]/=i;
				flag = true;
			}
			if(flag){
				count++;
			}	
		}
		ans = max(count,ans);
				
	}
	cout<<max(ans,1)<<endl;
	return 0;
}

