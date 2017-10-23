/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e3+5);
lli n,columnNumber,index;
string s;
vector<char> ans;
vector<lli> adj[MAX],dummy,tree(MAX);
void magicBox(lli stringIndex,lli treeIndex){
	lli leftValue(dummy[stringIndex+1]);
	lli leftBoundry(stringIndex+1);
	lli rightBoundry(adj[leftValue-1][lower_bound(adj[leftValue-1].begin(),adj[leftValue-1].end(),dummy[stringIndex+1]-1)-adj[leftValue].begin()]);
	tree[treeIndex] = stringIndex;
	lli leftLeftBoundry(stringIndex+2);
	lli leftRightBoundry(stringIndex+2);
	if(s[stringIndex+2]!='.'){
		lli leftleftValue(dummy[stringIndex+3]);
		leftRightBoundry = adj[leftleftValue-1][lower_bound(adj[leftleftValue-1].begin(),adj[leftleftValue-1].end(),dummy[stringIndex+3]-1)-adj[leftleftValue].begin()];
		magicBox(stringIndex)
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		index = 0;
		cin>>columnNumber;
		cin>>s;
		lli last(0);
		for(int i(0);i<s.length();i++){
			if(s[i] == '('){
				last++;
				adj[last].push_back(i);
			}
			if(s[i] == ')'){
				last--;
				adj[last].push_back(i);
			}
			dummy.push_back(last);
		}
		magicBox(0,0);
	}
	return 0;
}
