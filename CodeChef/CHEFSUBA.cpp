/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,k,p;
int input[100001],shiftedInput[100001],lastAnswer;
lli shiftArray(lli shift){
	for(int i(0);i<n;i++){
		shiftedInput[(i+shift)%n] = input[i];
	}
	lli answer(0),sum(0);
	for(int i(0);i<k;i++){
		input[i] = shiftedInput[i];
		sum+=input[i];
	}
	answer = max(sum,answer);
	for(int i(k);i<n;i++){
		input[i] = shiftedInput[i];
		sum+=input[i];
		sum-=input[i-k];
		answer = max(answer,sum);
	}
	lastAnswer = answer;
	return lastAnswer;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lastAnswer = -1;
	cin>>n>>k>>p;
	for(int i(0);i<n;i++){
		cin>>input[i];
	}
	lli countShift(0);
	string s;
	cin>>s;
	for(int i(0);i<p;i++){
		if(s[i] == '!'){
			countShift = (countShift+1)%n;
		}
		else{
			cout<<shiftArray(countShift)<<endl;
			countShift = 0;
		}
	}
	return 0;
}	
