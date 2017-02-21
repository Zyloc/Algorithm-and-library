/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
map<string,set<lli> > mp;
lli notFound(string s){
	map<string,set<lli> >::iterator it;
	it = mp.find(s);
	lli start(-1);
	for(auto  it2=(it->second).begin();it2!=(it->second).end();it2++){
		if(*it2 != start){
			return start;
		}
		start++;
	}
	return start;
}
int main(){
	
	string s,s1;
	zyloc(){
		cin>>s;
		lli index(s.length()-1);
		pool(i,s.length()-1,0){
			if (!(s[i]-'0'>=0 and s[i]-'0'<=9)){
				index = i;
				break;
			}
		}
		string name(s.substr(0,index+1));
		if(mp.find(name)!=mp.end()){
			lli id(notFound(name));
			cout<<name<<id<<endl;
			mp[name].insert(id);
		}
		else{
			cout<<name<<endl;
			mp[name].insert({-1});
		}
	}
	return 0;
}	