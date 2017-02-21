/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MaxRun = 1e7+1000;
const int MAX = 1e6;
bool hash[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,maxElement(0),counter(0);
	scanf("%lld",&n);
	lli v[MAX];
	for(int i=0;i<n;i++){
	    scanf("%lld",&v[i]);
	}
	lli totalRun(0);
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        for(int k=j+1;k<n;k++){
	        	if(!hash[v[i]+v[j]+v[k]]){
	        		counter++;
	        	}
	            hash[v[i]+v[j]+v[k]] = true;
	            if(totalRun > MaxRun){
	                break;
	            }
	            totalRun++;
	        }
	        if(totalRun > MaxRun){
	                break;
	        }
	    }
	    if(totalRun > MaxRun){
	        break;
	   }
	}
	cout<<counter<<endl;
	for(int i=3;i<MAX;i++){
		if(hash[i]){
			cout<<i<<" ";
		}
	}	    
	return 0;
}