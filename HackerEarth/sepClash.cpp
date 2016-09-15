/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h>
#include <list>  
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
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
int main(){
	zyloc(){
		string s;
		lli n,k;
		char c('z');
		cin>>n>>k;
		cin>>s;
		vi(v);
		loop(i,0,s.length()-1){
			if (s[i]<c){
				c = s[i];
			}
		}
		if (k==1){
			loop(i,0,n-1){
				if (s[i]==c){
					v.pb(i);
				}
			}
		}
		if (k>=2){
			cout<<c<<endl;
		}
		else{
			string ans;
			loop(i,0,n-1){
				ans+='z';
			}
			if (c==s[0] or c==s[n-1]){
				cout<<c<<endl;
			}
			else{
				loop(i,0,v.size()-1){
					//cout<<v[i]<<endl;
					string dummy(s.substr(v[i],s.length()-v[i]));
					if (dummy<ans){
						ans = dummy;
					}
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}	