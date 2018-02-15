/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli input[3][6];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<lli> input[3];
	for(int i(0);i<n;i++){
		for(int j(0);j<6;j++){
			cin>>x;
			input[i].push_back(x);
		}
	}
	lli answer(1);
	while(answer < 1000){
		vector<lli> numberArray;
		lli temp(answer);
		while(temp){
			numberArray.push_back(temp%10);
			temp/=10;
		}
		reverse(numberArray.begin(),numberArray.end());
		bool globalFlag(false);
		if(numberArray.size() == 1){
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end()){
				globalFlag = true;
			}
			if(find(input[1].begin(),input[1].end(),numberArray[0])!=input[1].end()){
				globalFlag = true;
			}
			if(find(input[2].begin(),input[2].end(),numberArray[0])!=input[2].end()){
				globalFlag = true;
			}
		}
		if(numberArray.size() == 2){
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end() and find(input[1].begin(),input[1].end(),numberArray[1])!=input[1].end()){
				globalFlag = true;
			}
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end() and find(input[2].begin(),input[2].end(),numberArray[1])!=input[2].end()){
				globalFlag = true;
			}
			if(find(input[1].begin(),input[1].end(),numberArray[0])!=input[1].end() and find(input[2].begin(),input[2].end(),numberArray[1])!=input[2].end()){
				globalFlag = true;
			}
			if(find(input[1].begin(),input[1].end(),numberArray[0])!=input[1].end() and find(input[0].begin(),input[0].end(),numberArray[1])!=input[0].end()){
				globalFlag = true;
			}
			if(find(input[2].begin(),input[2].end(),numberArray[0])!=input[2].end() and find(input[0].begin(),input[0].end(),numberArray[1])!=input[0].end()){
				globalFlag = true;
			}
			if(find(input[2].begin(),input[2].end(),numberArray[0])!=input[2].end() and find(input[1].begin(),input[1].end(),numberArray[1])!=input[1].end()){
				globalFlag = true;
			}
		}
		if(numberArray.size() == 3){
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end() and find(input[1].begin(),input[1].end(),numberArray[1])!=input[1].end() and find(input[2].begin(),input[2].end(),numberArray[2])!=input[2].end() ){
				globalFlag = true;
			}
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end() and find(input[2].begin(),input[2].end(),numberArray[2])!=input[2].end() and find(input[1].begin(),input[1].end(),numberArray[1])!=input[1].end()){
				globalFlag = true;
			}
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end() and find(input[2].begin(),input[2].end(),numberArray[2])!=input[2].end() and find(input[1].begin(),input[1].end(),numberArray[1])!=input[1].end()){
				globalFlag = true;
			}
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end() and find(input[2].begin(),input[2].end(),numberArray[2])!=input[2].end() and find(input[1].begin(),input[1].end(),numberArray[1])!=input[1].end()){
				globalFlag = true;
			}
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end() and find(input[2].begin(),input[2].end(),numberArray[2])!=input[2].end() and find(input[1].begin(),input[1].end(),numberArray[1])!=input[1].end()){
				globalFlag = true;
			}
			if(find(input[0].begin(),input[0].end(),numberArray[0])!=input[0].end() and find(input[2].begin(),input[2].end(),numberArray[2])!=input[2].end() and find(input[1].begin(),input[1].end(),numberArray[1])!=input[1].end()){
				globalFlag = true;
			}
		}
		if(globalFlag){
			answer++;
		}
		else{
			cout<<answer-1<<endl;
			return 0;
		}
	}
	cout<<999<<endl;
	return 0;
}
