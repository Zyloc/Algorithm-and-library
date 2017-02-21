/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
int main(){	
	lli n;
	cin>>n;
	lli ordinate[n+1],height[n+1],ans(0);
	lli last(INT_MIN);
	for(lli i=0;i<n;i++){
		cin>>ordinate[i]>>height[i];
	}
	ordinate[n] = INT_MAX;
	for(lli i=0;i<n;i++){
		if(last < ordinate[i]-height[i]){
			ans++;
			last =  ordinate[i];
		}
		else if(ordinate[i]+height[i] < ordinate[i+1]){
			ans++;
			last = ordinate[i]+height[i]; 
		}
		else{
			last = ordinate[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}