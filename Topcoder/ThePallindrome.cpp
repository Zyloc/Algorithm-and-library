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
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug cout<<"######"<<endl 
const int MAX = 1000002;
const double PI = 3.14159265358979323846;
class ThePalindrome{
public:
	lli isPallindrome(string s,lli end){
		lli i(0),j(end);
		while(i<j){
			if(s[i]!=s[j]){
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
	int find(string s){
		string dummy,dummy2;
		dummy = s;
		reverse(dummy.begin(),dummy.end());
		dummy2 = s+dummy;
		for(lli i=dummy.length()-1;i<dummy2.length();i++){
			if(isPallindrome(dummy2,i)){
				return i;
			}
		}
		return 0;
	}
};
int main(){
	string s;
	cin>>s;
	ThePalindrome obj;
	cout<<obj.find(s);
	return 0;
}
