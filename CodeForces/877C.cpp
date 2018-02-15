/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	vector<lli> oddFirst,evenFirst;
	for(int i(1);i<=n;i+=2){
		oddFirst.push_back(i);
	}
	for(int i(2);i<=n;i+=2){
		oddFirst.push_back(i);
	}
	for(int i(1);i<=n;i+=2){
		oddFirst.push_back(i);
	}
	for(int i(2);i<=n;i+=2){
		evenFirst.push_back(i);
	}
	for(int i(1);i<=n;i+=2){
		evenFirst.push_back(i);
	}
	for(int i(2);i<=n;i+=2){
		evenFirst.push_back(i);
	}
	cout<<min(oddFirst.size(),evenFirst.size())<<endl;
	if(oddFirst.size() < evenFirst.size()){
		for(auto x:oddFirst){
			cout<<x<<" ";
		}
	}
	else{
		for(auto x:evenFirst){
			cout<<x<<" ";
		}
	}
	return 0;
}
