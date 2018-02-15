/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli  int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,a,b;
	cin>>n>>a>>b;
	if(a > b){
		swap(a,b);
	}
	for(int i(0);i*a<=n;i++){
		lli remaining(n-a*i);
		if(remaining%b == 0){
			lli firstBox(i),secondBox(remaining/b);
			lli position(1);
			lli iterator(1);
			for(int i(1);i<=firstBox;i++){
				vector<lli> temp,temp2;
				for(int j(0);j<a;j++){
					temp.push_back(iterator++);
					temp2.push_back(0);
				}
				for(int j(0);j<a;j++){
					temp2[(j+1)%a] = temp[j];
				}
				for(auto x:temp2){cout<<x<<" ";}
			}
			for(int i(1);i<=secondBox;i++){
					vector<lli> temp,temp2;
					for(int j(0);j<b;j++){
						temp.push_back(iterator++);
						temp2.push_back(0);
					}
					for(int j(0);j<b;j++){
						temp2[(j+1)%b] = temp[j];
					}
					for(auto x:temp2){cout<<x<<" ";}
				}
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
