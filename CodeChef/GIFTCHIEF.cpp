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
struct indexes{
	lli start;
	lli end;
};
int main(){
	zyloc(){
		string s,f;
		cin>>s>>f;
		vector<indexes> v;
		indexes temp;
		for(lli i=0;i<=s.length()-f.length();i++){
			if (s.substr(i,f.length())==f){
				temp.start = i;
				temp.end = i+f.length();
				v.pb(temp);
			}
		}
		for(lli i=0;i<v.size();i++){
			cout<<v[i].start<<" "<<v[i].end<<" ";
		}
		cout<<endl;
	}
	return 0;
}	