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
lli indexOFTshirt(string s){
	if (s=="S"){
		return 0;
	}
	else if (s=="M"){
		return 1;
	}
	else if(s=="L"){
		return 2;
	}
	else if (s=="XL"){
		return 3;
	}
	else if (s=="XXL"){
		return 4;
	}
	else if (s=="XXXL"){
		return 5;
	}
} 
int main(){
	vi(v);
	lli x,n;
	loop(i,0,5){
		cin>>x;
		v.pb(x);
	}
	cin>>n;
	string s;
	vector<string> ans;
	loop(i,0,n-1){
		cin>>s;
		bool comma(false);
		loop(i,0,s.length()-1){
			if (s[i]==','){
				comma = true;
				break;
			}
		}
		if (comma){
			string s1,s2;
			lli index(0);
			loop(i,0,s.length()-1){
				if (s[i]!=','){
					s1+=s[i];
				}
				else{
					index = i;
					break;
				}
			}
			loop(i,index+1,s.length()-1){
				s2+=s[i];
			}
			if (max(v[indexOFTshirt(s1)],v[indexOFTshirt(s2)])>0){
				if(v[indexOFTshirt(s1)]>v[indexOFTshirt(s2)]){
					ans[i]=s1;
					v[indexOFTshirt(s1)]--;
				}
				else{
					ans[i] = s2;
					v[indexOFTshirt(s2)]--;
				}
			}
			else{
				cout<<"NO";
				return 0;
			}
		}
		else{
			if (v[indexOFTshirt(s)]>0){
				ans[i]=s;
				v[indexOFTshirt(s)]--;
			}
			else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	loop(i,0,n-1){
		cout<<ans[i]<<endl;
	}
	return 0;
}	