/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+10);
lli n,q;
int BIT[26][MAX];
void update(int value,int which,int index){
	while(index <= n){
		BIT[which][index] += value;
		index += (index & -index);
	}
}
lli query(int which,int index){
	int ans(0);
	while(index){
		ans+= BIT[which][index];
		index -= (index & -index);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli type,l,r;
	char c;
	string s;
	cin>>n>>q>>s;
	for(int i(0);i<n;i++){
		update(1,s[i]-'a',i+1);
	}
	for(int i(0);i<q;i++){
		cin>>type;
		if(type == 2){
			cin>>l>>r;
			lli countOdd(0),count(0);
			for(int j(0);j<26;j++){
				count = query(j,r)-query(j,l-1);
				if(count&1){
					countOdd++;
				}
			}
			if(countOdd <= 1){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}	
		else{
			cin>>l>>c;
			update(-1,s[l-1]-'a',l);
			update(1,c-'a',l);
			s[l-1]=c;
		}
	}
	return 0;
}	