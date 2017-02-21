/*
 * Team :- VAS, NIT Silchar
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
int main(){
	zyloc(){
		lli n,x,count_zero(0),count_one(0),count_minusOne(0),other(0);
		cin>>n;
		vi(v);
		set<lli> st;
		map<lli,lli> mp;
		loop(i,0,n-1){
			cin>>x;
			if (x==0){
				count_zero++;
			}
			else if (x==1){
				count_one++;
			}
			else if (x==-1){
				count_minusOne++;
			}
			else{
				mp[x]++;
				st.insert(x);
				other++;

			}
		}
		if (n==1){
			cout<<"no"<<endl;
		}
		else if (st.size()==0){
			if (count_minusOne>0){
				if (count_minusOne==1){
					cout<<"yes"<<endl;
				}
				else if (count_minusOne>1){
					if (count_one==0){
						cout<<"no"<<endl;
					}
					else {
						cout<<"yes"<<endl;
					}
				}
			}
			else{
				cout<<"yes"<<endl;
			}
		}
		else{
			set<lli>::iterator it;
			it = st.begin();
			if(count_minusOne>0){
				cout<<"no"<<endl;
			}
			else if (st.size()==1 and mp[*it]==1){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}
	}
	return 0;
}	