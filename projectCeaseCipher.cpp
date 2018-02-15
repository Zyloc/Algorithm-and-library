/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const string key = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int MOD(key.size());
map<lli,lli> indexToChar;
map<char,lli> charToIndex;

void init(){
	for(int i(0);i<key.size();i++){
		charToIndex[key[i]] = i;
		indexToChar[i] = key[i];
	}
}

string encrypt(string message,lli key){
	string ans;
	for(auto x:message){
		ans += indexToChar[(charToIndex[x]+key)%MOD];
	}
	return ans;
}

string decrypt(string message,lli key){
	string ans;
	for(auto x:message){
		ans += indexToChar[(charToIndex[x]-key+MOD)%MOD];
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	lli shift(103%MOD);
	string message("032VyT61pTdGFG");
	cout<<encrypt(message,shift)<<" "<<decrypt(message,shift)<<endl;
	return 0;
}
