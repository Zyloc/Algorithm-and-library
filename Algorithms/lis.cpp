/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli length;
vector<lli> tail;
lli ceilIndex(lli start,lli end,lli key){
	while(end-start > 1){
		lli mid(start+(end-start)/2);
		if(tail[mid] >= key){
			end = mid;
		}
		else{
			start = mid+1;
		}
		return end;
	}
}
void longestIncreasingSubSequence(vector<lli> &input){
	if(input.size() == 0){
		return;
	}
	tail.push_back(input[0]);
	lli length(1);
	for(int i=1;i<input.size();i++){
		if(tail[0] > input[i]){
			tail[0] = input[i];
		}
		else if(tail[length] < input[i]){
			tail.push_back(input[i]);
			length++;
		}
		else{
			tail[ceilIndex(-1,length-1,input[i])] =  input[i];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<lli> input;
	for(int i=0;i<n;i++){
		cin>>x;
		input.push_back(x);
	}
	longestIncreasingSubSequence(input);
	cout<<tail.size();
	return 0;
}