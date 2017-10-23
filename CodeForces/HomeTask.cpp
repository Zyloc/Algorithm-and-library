/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
void print(vector<lli>& output){
	bool allZero(true);
	for(int i(0);i<output.size();i++){
		if(output[i]!=0){
			allZero = false;
			break;
		}
	}
	if(allZero){
		cout<<0;
		return ;
	}
	for(auto x:output){
		cout<<x;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<lli> input[3],in;
	lli totalSum(0);
	bool containsZero(false);
	for(int i(0);i<n;i++){
		cin>>x;
		totalSum+=x;
		if(x == 0){
			containsZero = true;
		}
		input[x%3].push_back(x);
		in.push_back(x);
	}
	if(!containsZero){
		cout<<-1;
		return 0;
	}
	sort(in.begin(),in.end(),greater<lli>());
	sort(input[0].begin(),input[0].end(),greater<lli>());
	sort(input[1].begin(),input[1].end(),greater<lli>());
	sort(input[2].begin(),input[2].end(),greater<lli>());
	if(totalSum%3 == 0){
		print(in);
		return 0;
	}
	if(totalSum%3 == 1){
		if(input[1].size() >= 1){
			input[1].pop_back();
		}
		else{
			input[2].pop_back();
			input[2].pop_back();
		}
		vector<lli> finalAnswer;
		for(int i(0);i<input[0].size();i++){
			finalAnswer.push_back(input[0][i]);
		}
		for(int i(0);i<input[1].size();i++){
			finalAnswer.push_back(input[1][i]);
		}
		for(int i(0);i<input[2].size();i++){
			finalAnswer.push_back(input[2][i]);
		}
		sort(finalAnswer.begin(),finalAnswer.end(),greater<lli>());
		print(finalAnswer);
		return 0;
	}
	if(input[2].size() >= 1){
		input[2].pop_back();
	}
	else{
		input[1].pop_back();
		input[1].pop_back();
	}
	vector<lli> finalAnswer;
	for(int i(0);i<input[0].size();i++){
		finalAnswer.push_back(input[0][i]);
	}
	for(int i(0);i<input[1].size();i++){
		finalAnswer.push_back(input[1][i]);
	}
	for(int i(0);i<input[2].size();i++){
		finalAnswer.push_back(input[2][i]);
	}
	sort(finalAnswer.begin(),finalAnswer.end(),greater<lli>());
	print(finalAnswer);
	return 0;
}
