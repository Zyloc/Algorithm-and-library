/*
 * Richie Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli dp[13][2][9];
lli magicBox(lli index,bool flag,lli modSoFar,string number,string temp){
	if(index == number.size()){
		cout<<temp<<" "<<modSoFar<<endl;
		return modSoFar == 0;
	}
	if(dp[index][flag][modSoFar]!=-1){
		return dp[index][flag][modSoFar];
	}
	lli ans(0);
	if(flag){
		for(int i(0);i<number[index]-'0';i++){
			if(i == 0){
				ans+=magicBox(index+1,false,modSoFar,number,temp+"0");	
			}
			else{
				ans+=magicBox(index+1,false,(modSoFar+int(pow(i,i))%i)%i,number,temp+to_string(i));	
			}
		}
		if(number[index] == '0'){
			ans+=magicBox(index+1,true,modSoFar,number,temp+"0");	
		}
		else{
			ans+=magicBox(index+1,true,(modSoFar+int(pow(number[index]-'0',number[index]-'0'))%(number[index]-'0'))%(number[index]-'0'),number,temp+number[index]);
		}
	}
	else{
		for(int i(0);i<=9;i++){
			if(i == 0){
				ans+=magicBox(index+1,false,modSoFar,number,temp+"0");	
			}
			else{
				ans+=magicBox(index+1,false,(modSoFar+int(pow(i,i))%i)%i,number,temp+to_string(i));	
			}
		}
	}
	dp[index][flag][modSoFar] = ans;
	return ans;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli l,r;
		cin>>l>>r;
		memset(dp,-1,sizeof dp);
		lli a(magicBox(0,true,0,to_string(r),""));
		memset(dp,-1,sizeof dp);
		//lli b(magicBox(0,true,0,to_string(l-1),""));
		//cout<<a-b<<endl;
	}
	return 0;
}
