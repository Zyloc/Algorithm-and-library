/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct dataType{
	lli saveTime,burnTime,points,index;
};
vector<dataType> input;
lli n;
lli dp[10001][101];
lli points[101],burnTime[101],takeTime[101];
bool cmp(dataType first,dataType second){
	if(first.burnTime < second.burnTime){
		return true;
	}
	return first.index<second.index;
}
lli magicBox(lli index,lli time){
	if(index == n){
		return 0;
	}
	if(time > 10001){
		return 0;
	}
	if(dp[time][index]!=-1){
		return dp[time][index];
	}
	lli ans(0);
	if(time + input[index].saveTime < input[index].burnTime){
		lli temp(magicBox(index+1,time+input[index].saveTime));
		ans = max(ans,input[index].points+temp);
	}
	ans = max(ans,magicBox(index+1,time));
	return dp[time][index]=ans;
}
vector<lli> dummy;
void printAns(lli index,lli time,lli score){
	if(index == n){
		if(score > 0){
			dummy.push_back(n-1);
		}
		return ;
	}
	if(time+input[index].saveTime < 10001 and dp[time+input[index].saveTime][index+1] +input[index].points == score){
		dummy.push_back(index);
		printAns(index+1,time+input[index].saveTime,score-input[index].points);
	}
	else{
		printAns(index+1,time,score);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,-1,sizeof dp);
	cin>>n;
	dataType temp;
	for(int i(0);i<n;i++){
		cin>>takeTime[i]>>burnTime[i]>>points[i];
		temp.saveTime = takeTime[i];
		temp.burnTime = burnTime[i];
		temp.points = points[i];
		temp.index = i;
		input.push_back(temp);
	}
	sort(input.begin(),input.end(),cmp);
	lli temp2(magicBox(0,0));
	cout<<temp2<<endl;

	printAns(0,0,temp2);
	cout<<dummy.size()<<endl;
	for(auto x:dummy){
		cout<<input[x].index+1<<" ";
	}
	return 0;
}
