/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli lowerCase[51],specialCharacter[51],numeric[51];
bool isNumberic(char c){
	if(c-'0' >=0 and c-'0'<=9){
		return true;
	}
	return false;
}
bool isSpecial(char c){
	if(c == '#' or c=='*' or c=='&'){
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m;
	cin>>n>>m;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
		int distanceOfNumeric(INT_MAX),distanceOfSpecialCharacter(INT_MAX),distanceOfLowerCase(INT_MAX);
		if(isNumberic(s[i][0])){
				distanceOfNumeric = 0;
			}
			else if(isSpecial(s[i][0])){
				distanceOfSpecialCharacter = 0;
			}
			else{
				distanceOfLowerCase = 0;
		}
		for(int j=1;j<s[i].length();j++){
			if(isNumberic(s[i][j])){
				distanceOfNumeric = min(distanceOfNumeric,min(j,(int)s[i].length()-j));
			}
			else if(isSpecial(s[i][j])){
				distanceOfSpecialCharacter = min(distanceOfSpecialCharacter,min(j,(int)s[i].length()-j));
			}
			else{
				distanceOfLowerCase =  min(distanceOfLowerCase,min(j,(int)s[i].length()-j));
			}
		}
		lowerCase[i] = distanceOfLowerCase;
		specialCharacter[i] = distanceOfSpecialCharacter;
		numeric[i] = distanceOfNumeric;
	}
	lli answer(INT_MAX);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(i!=j and i!=k and j!=k){
					answer = min(answer,lowerCase[i]+specialCharacter[j]+numeric[k]);
				}
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}