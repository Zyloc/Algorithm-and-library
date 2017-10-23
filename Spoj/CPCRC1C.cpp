/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
string processing;
lli magicBox(lli index,bool flag,lli sum){
	lli totalSum(0);
	if(index == processing.size()){
		return sum;
	}
	lli limit(9);
	if(flag){
		for(int i(0);i<=limit;i++){
			totalSum += magicBox(index+1,true,sum+i);
		}
	}
	else{
		limit = (processing[index]-'0');
		for(int i(0);i<limit;i++){
			totalSum+=magicBox(index+1,true,sum+i);
		}
		totalSum+=magicBox(index+1,false,sum+limit);
	}
	return totalSum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli inA,inB;
	while(true){
		cin>>inA>>inB;
		if(inA == -1 and inB == -1){
			break;
		}
		lli ans(0);
		processing = to_string(inB);
		ans = magicBox(0,false,0);
		if(inA!=0){
			processing = to_string(inA-1);
			ans -= magicBox(0,false,0);	
		}
		cout<<ans<<endl;
	}
	return 0;
}
