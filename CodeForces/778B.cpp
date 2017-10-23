/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,k;
vector<int> arrayN;
lli fast_expo(lli base, lli expo){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base);
		}
		base=(base*base);
		expo/=2;
	}
	return res;
}

lli check(vector<int>&setBits){
	if(setBits.size() < 1){
		return INT_MAX;
	}
	lli formedN(0);
	for(int i=0;i<setBits.size();i++){
		formedN = formedN*10+arrayN[setBits[i]];
	}
	if(formedN % fast_expo(10,k) == 0){
		if(formedN == 0){
			return arrayN.size()-1;
		}
		return arrayN.size()-setBits.size();
	}
	else{
		return INT_MAX;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	lli copyN(n),length(0);
	while(copyN){
		arrayN.push_back(copyN%10);
		copyN = copyN/10;
		length++;
	}
	if(n == 0){
		cout<<0<<endl;
		return 0;
	}
	reverse(arrayN.begin(),arrayN.end());
	lli answer(INT_MAX);
	for(int i=0;i<(1<<length);i++){
		vector<int> setBits;
		for(int j=0;j<length;j++){
			if(i&(1<<j)){
				setBits.push_back(j);
			}
		}
		if(setBits.size() > 0){
			answer = min(answer,check(setBits));	
		}
	}
	cout<<answer<<endl;
	return 0;
}
