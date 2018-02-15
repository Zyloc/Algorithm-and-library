/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+2);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	string s;
	cin>>s;
	int input[26] = {0};
	for(int i(0);i<26;i++){
	    cin>>input[i];
	}
	int hash[MAX] = {0};
	lli start(0),length(0),ansStart(-1);
	for(int i(0);i<n;i++){
	    hash[s[i]-'a']++;
	    bool check(true);
	    for(int j(0);j<26;j++){
	        if(hash[j] > input[j]){
	            check = false;
	        }
	    }
	    if(check){
	        if(i-start+1 > length){
	            length = i-start+1;
	            ansStart = start;
	        }
	    }
	    else{
	        while(start <= i){
	            bool check(true);
	            hash[s[start]-'a']--;
	            for(int j(0);j<26;j++){
	                if(hash[j] > input[j]){
	             		check = false;
	                }
	            }
	            start++;
	            if(check){
	                break;
	            }
	        }
	    }
	}
	if(ansStart == -1){
		cout<<"No";
		return 0;
	}
	cout<<ansStart+1<<" "<<ansStart+length<<endl;
	return 0;
}
