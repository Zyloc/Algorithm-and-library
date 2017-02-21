/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const lli MOD = 1e9+7;
lli fast_expo(lli base, lli expo,lli MODE){
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
struct node{
	lli value,level;
	char parent;
	node(){
		value = 0;
		level = 1;
		parent = '-';
	}
};
int main(){
	lli n;
	cin>>n;
	lli input[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	node temp;
	temp.value = input[0];
	queue<node> q;
	q.push(temp);
	while(q.front().level < n){
		node temp1(q.front());
		while(q.front().level == temp1.level){
			node temp2,temp3;
			temp = q.front();
			//cout<<temp.level<<endl;
			// adding next value
			temp2.value = (temp.value + input[temp.level])%MOD;
			temp2.level = temp.level + 1 ;
			temp2.parent = '+';
			//cout<<temp2.value<<" ";
			// OR next value
			q.push(temp2);
			if(temp.parent == '+'){
				temp3.value = (temp.value - input[temp.level-1] + MOD + (input[temp.level-1]|input[temp.level])%MOD)%MOD;
			}
			else{
				temp3.value = (temp.value | input[temp.level])%MOD;
			}
			temp3.parent = '|';
			temp3.level = temp.level + 1;
			//cout<<temp3.value<<" ";
			q.push(temp3);
			q.pop();
		}
		//`cout<<endl;	
	}
	lli sum(0);
	while(!q.empty()){
		sum = (sum + q.front().value)%MOD;
		q.pop();
	}
	lli inverse,ans(sum);
	inverse = fast_expo(2,MOD-2,MOD);
	for(int i=0;i<n-1;i++){
		ans = (ans*inverse)%MOD;
	}
	//ans = ((sum%MOD)*(fast_expo(x,MOD-2,MOD)))%MOD;
	cout<<ans<<endl;
	return 0;
}