/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli  int
using namespace std;
const int MAX(1e5+3);
bool isTriangle(lli a,lli b,lli c){
	if(a >= b+c or b >= a+c or c >= a+b){
		return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,count(0);
	cin>>n;
	set<pair<lli,pair<lli,lli> > >st;
	for(int i(1);i<=n;i++){
		for(int j(1);j<=n;j++){
			if(i^j!=0 and isTriangle(i,j,i^j) and (i^j) <= n){
				int input[3] = {0};
				input[0] = i;
				input[1] = j;
				input[2] = i^j;
				sort(input,input+3);
				int size(st.size());
				st.insert({input[0],{input[1],input[2]}});
			}
		}	
	}
	cout<<st.size()<<endl;
	return 0;
}