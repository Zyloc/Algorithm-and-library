/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
bool dummy[1001][26];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m;
	cin>>n;
	string reveled,s;
	cin>>reveled;
	cin>>m;
	lli maskReveled(0);
	vector<string> input;
	for(int i(0);i<reveled.size();i++){
		if(reveled[i]!='*'){
			maskReveled|= (1LL<<(reveled[i]-'a'));	
		}
	}
	for(int i(0);i<m;i++){
		cin>>s;
		bool check(false);
		for(int j(0);j<s.length();j++){
			if(reveled[j] != s[j] and reveled[j]!='*'){
				check = true;
				break;
			}
			if(reveled[j] == '*' and maskReveled&(1<<(s[j]-'a'))){
				check = true;
				break;
			}
		}
		if(!check){
			input.push_back(s);
		}
	}
	for(int i(0);i<input.size();i++){
		for(int j(0);j<input[i].size();j++){
			dummy[i][input[i][j]-'a'] = true;
		}
	}
	lli count(0);
	for(int i(0);i<26;i++){
		if(maskReveled & (1<<i)){
			continue;
		}
		bool temp(true);
		for(int j(0);j<input.size();j++){
			if(!dummy[j][i]){
				temp = false;
			}
		}
		if(temp){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
