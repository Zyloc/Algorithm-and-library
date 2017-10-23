/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	int  length,processed(0),ans(0);
	cin>>length;
	cin.ignore();
	getline(cin,input);
	int index(0);
	while(index < input.size()){
		int iterator(0),counter(0);
		while(index < input.size() and input[index]!=' '){
			if(input[index] >= 'A' and input[index] <= 'Z'){
				counter++;
			}
			index++;
		}
		ans = max(ans,counter);
		index++;
	}
	cout<<ans;
	return 0;
}
