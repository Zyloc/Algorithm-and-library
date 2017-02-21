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
bool isPossible(char a,char b){
	if ((a=='P' and b=='P') or (a=='A' and b=='P') or (a=='P' and b=='A')){
		return true;
	}
	return false;
}
int main(){
	zyloc(){
		string s;
		cin>>s;
		if ((s.length()&(s.length()-1))!=0){
			cout<<"NO"<<endl;
		}
		else if(s.length()==1){
			cout<<"YES"<<endl;
		}
		else{
			bool flag(false);
			for(lli i=0;i<s.length()-1;i=i+2){
				if (!isPossible(s[i],s[i+1])){
					cout<<"NO"<<endl;
					flag = true;
					break;
				}
			}
			if (!flag){
				cout<<"YES"<<endl;
			}
		}
	}
	return 0;
}	