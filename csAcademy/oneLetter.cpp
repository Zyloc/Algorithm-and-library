/*
 * I felt , I felled and I failed :(
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
	vector<char> input;
	for(int i(0);i<n;i++){
	  string s;
	  cin>>s;
	  char smallest('z');
	  for(auto x:s){
	      if(smallest > x){
	          smallest = x;
	      }
	  }
	  input.push_back(smallest);
	}
	sort(input.begin(),input.end());
	for(auto x:input){
	    cout<<x;
	}
	return 0;
}
