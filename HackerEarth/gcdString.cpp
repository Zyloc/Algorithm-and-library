/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1e9+7;
vector<lli> v;
lli magicBox(lli a,lli b){
	v.pb(a);
	if(a%b==0){
		return 0;
	}
	return magicBox(b,a%b);
}
lli toDecimal(string s){
	lli startPower(1),ans(0);
	for (lli i = s.length()-1; i >= 0; --i){
		ans = ans+startPower*(s[i]-'0');
		if(ans>MOD){
			ans-=MOD;
		}
		startPower *= 2;
		if(startPower > MOD){
			startPower-=MOD;
		}
	}
	return ans;
}
string finalString(string s,lli index){
	string newString;
	if(index == 0){
		if(v[index]>s.size()){
			for(lli i=0;i<(v[index]/s.size());i++){
				newString += s; 
			}
			for(lli i=0;i<v[index]%s.size();i++){
				newString+=s[i];
			}
			return newString;
		}
		else{
			for(lli i=0;i<v[index]%s.size();i++){
				newString+=s[i];
			}	
			return newString;	
		}	
	}
	if(v[index]>s.size()){
		for(lli i=0;i<(v[index]/s.size());i++){
			newString += s; 
		}
		for(lli i=0;i<v[index]%s.size();i++){
			newString+=s[i];
		}
		return finalString(newString,index-1);
	}
	else{
		for(lli i=0;i<v[index]%s.size();i++){
			newString+=s[i];
		}
		return finalString(newString,index-1);	
	}
}
int main(){	
	zyloc(){
		lli a,b;
		string s;
		cin>>a>>b;
		magicBox(a,b);
		lli index(v[v.size()-1]);
		s = '1';		
		for(lli i=0;i<index-1;i++){
			s+='0';
		}
		if(v.size() == 1){
			cout<<toDecimal(s)%MOD<<endl;
		}
		else{
			cout<<toDecimal(finalString(s,v.size()-2))%MOD<<endl;	
		}	
		v.clear();
	}
	return 0;
}	