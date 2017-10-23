/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+1);
const int MOD(1e9+7);
int fact[MAX];
lli fast_expo(lli base, lli expo){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MODE;
		}
		base=(base*base)%MODE;
		expo/=2;
	}
	return res%MODE;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fact[0] = 1;
	for(int i=1;i<MAX;i++){
	    fact[i] = (i*fact[i-1])%MOD;
	}
	lli t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    map<char,lli> vowel,conso;
	    for(int i(0);i<s.length();i++){
	        if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
	            vowel[s[i]]++;
	        }
	        else{
	            conso[s[i]]++;
	        }
	    }
	    lli countVowel(0),countConso(0);
	    for(auto x:vowel){
	        countVowel+=x.second;
	    }
	    lli ans(fact[countVowel]);
	    for(auto x:vowel){
	        ans = (ans*fast_expo(MOD-2,fact[x.second]))%MOD;
	    }
	    for(auto x:conso){
	        countConso+=x.second;
	    }
	    ans = (ans*fact[countConso])%MOD;
	    for(auto x:conso){
	        ans = (ans*fast_expo(MOD-2,fact[x.second]))%MOD;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}