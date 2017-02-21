/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n,m;
	cin>>n>>m;
	set<string> p,e;
	for(int i=0;i<n;i++){
		cin>>s;
		p.insert(s);
	}
	int index(1);
	for(int i=0;i<m;i++){
		cin>>s;
		if(p.find(s)!=p.end()){
			p.erase(s);
			index++;
		}
		else{
			e.insert(s);
		}
	}
	if(index%2){
		if(p.size()>e.size()){
			cout<<"YES";
		}
		else if(e.size()>p.size()){
			cout<<"NO";
		}
		else{
			cout<<(p.size()%2?"YES":"NO");
		}
	}
	else{
		if(p.size()>e.size()){
			cout<<"YES";
		}
		else if(e.size()>p.size()){
			cout<<"NO";
		}
		else{
			cout<<(p.size()%2?"NO":"YES");
		}
	}
	return 0;
}