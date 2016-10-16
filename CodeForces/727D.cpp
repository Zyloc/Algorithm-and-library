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
	else if (s=="L"){
		return 2;
	}
	else if (s=="XL"){
		return 3;
	}
	else if(s=="XXL") {
		return 4;
	}
	else if (s=="XXXL"){
		return 5;
	}
	else {
		return -1;
	}
} 
int main(){
	lli v[6];
	loop(i,0,5){
		cin>>v[i];
	}
	lli n,x;
	cin>>n;
	vector<string> ans;
	string s1,s2,s3;
	loop(i,0,n-1){
		cin>>s1;
		bool comma(false);
		lli index(0);
		loop(j,0,s1.size()-1){
			if (s1[j]==','){
				index = j;
				break;
			}
		}
		if (comma){
			loop(j,0,index-1){
				s2+=s1[j];
			}
			loop(j,index+1,s1.size()-1){
				s3+=s1[j];
			}
			if (max(v[indexOFTshirt(s2)],v[indexOFTshirt(s3)])>0){
				if (v[indexOFTshirt(s2)]>v[indexOFTshirt(s3)]){
					ans.pb(s2);
					v[indexOFTshirt(s2)]--;
				}
				else{
					ans.pb(s3);
					v[indexOFTshirt(s3)]--;
				}
			}
			else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else{
			if (v[indexOFTshirt(s1)]>0){
				ans.pb(s1);
				v[indexOFTshirt(s1)]--;
			}
			else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		cout<<"YES"<<endl;
		loop(i,0,n-1){
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}	