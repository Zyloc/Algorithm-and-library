/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
string goodString,patternString,queryString;
set<char> hashedGoodString;
int patternLeftIndex,patterRightIndex,queryLeftIndex,queryRightIndex;
int matchLeft(){
	while(patternLeftIndex < patternString.size() and queryLeftIndex < queryString.size()){
		if(patternString[patternLeftIndex] == '*'){
			return patternLeftIndex-1;
		}
		if(patternString[patternLeftIndex] == queryString[queryLeftIndex]){
			patternLeftIndex++,queryLeftIndex++;
		}
		else if(patternString[patternLeftIndex] == '?' and hashedGoodString.find(queryString[queryLeftIndex])!= hashedGoodString.end()){
			patternLeftIndex++,queryLeftIndex++;
		}
		else{
			return patternLeftIndex-1;
		}
	}
	return patternLeftIndex-1;
}
int matchRight(){
	patterRightIndex
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>goodString>>patternString;
	for(auto x:goodString){
		hashedGoodString.insert(x);
	}
	int  q;
	cin>>q;
	while(q--){
		cin>>queryString;
		int maxMatchingLeftIndex(matchLeft()),maxMatchingRightIndex(matchRight());
	}
	return 0;
}
