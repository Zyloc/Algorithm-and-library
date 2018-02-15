/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+1);
vector<lli> preCompute[MAX],input[MAX];
bool prime[MAX];
lli ans;
void magicBox(){
	for(int i(2);i<MAX;i++){
		if(!prime[i]){
			for(int j(i);j<MAX;j+=i){
				prime[j] = true;
				preCompute[j].push_back(i);			
			}	
		}
		
	}
}
bool isSafe(){
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	magicBox();
	lli n,x;
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		input[i] = preCompute[x];
	}
	for(int i(0);i<n;i++){
		for(int j(0);j<input[i].size();j++){
			vector<lli> temp;
			lli totalSum(0);
			temp.push_back(j);
			for(int k(i+1);k<n;k++){
				for(int l(0);l<input[j].size();l++){
					if(input[k][l] == input[i][j]){
						temp.push_back(k+1);
						totalSum+=(k+1);
						input[k].erase(input[k].begin()+l);
					}
				}
			}
			for(int i(0);i<temp.size()-1;i++){
				totalSum-=temp[i];
				if(isSafe()){
					ans+= temp[i]*((temp.size()-i-1)*n-totalSum+(temp.size()-i-1));
				}
				else{
					cout<<-1;
					return 0;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
