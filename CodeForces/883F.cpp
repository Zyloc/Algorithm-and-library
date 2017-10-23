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
	string s;
	cin>>n;
	set<string> input;
	for(int i(0);i<n;i++){
		cin>>s;
		string dummy;
		for(int j(0);j<s.length();j++){
			if(s[j] == 'u'){
				dummy+="oo";
			}
			else{
				dummy+=s[j];
			}
		}
		string finalString;
		for(int j(dummy.length()-1);j>=0;){
			if(dummy[j] == 'h'){
				bool flag(false);
				lli iterator(j-1);
				while(iterator >=0 and dummy[iterator]=='k'){
					iterator--;
					flag = true;
				}
				if(flag){
					j = iterator;
					finalString = 'h'+ finalString;
				}
				else{
					j--;
					finalString ='h'+ finalString;
				}
			}
			else{
				finalString= dummy[j] + finalString;;
				j--;
			}
		}
		input.insert(finalString);
	}
	cout<<input.size()<<endl;
	return 0;
}
