/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <bits/stdc++.h>  
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
string convertTobinary(lli x){
	string s;
	while(x>0){
		if (x%2){
			s+='1';
		}
		else{
			s+='0';
		}
		x/= 2;
	}
	lli size(s.length()-1);
	loop(i,size,30){
		s+='0';
	}
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	zyloc(){
		lli n,x,maxi(0);
		cin>>n;
		vector<pair<bool,bool> > ans(32);
		loop(i,0,n-1){
			cin>>x;
			string s(convertTobinary(x));
			pool(j,31,0){
				if (s[j]=='0'){
					ans[j].first = true;
				}
				else{
					ans[j].second = true;
				}
			}
		}
		lli index(-1),count_0(0);
		loop(j,0,31){
			if(ans[j].second){
				index = j;
				break;
			}		
		}
		pool(i,31,index){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
		pool(i,31,0){
			if (ans[i].first){
				count_0++;
				index = i;
			}	
		}
		cout<<count_0<<endl;
	}	
	return 0;
}	