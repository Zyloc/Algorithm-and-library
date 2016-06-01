/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <iomanip>
#include <set>
using namespace std;
#define loop(i,start,end) for (int i=start;i<end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
 
int main(){
	lli t,n,a,b,c;
	cin>>t;
	loop(i,0,t){
		cin>>n;
		map<float,float > mp;
		set<pair<float,float> > st;
		map<float,float >::iterator it,it2;
		loop(j,0,n){
			cin>>a>>b>>c;
			it=mp.find(-float(a)/float(b));
			if (it!=mp.end()){
				it->second+=1;
			}
			else{
				mp.insert(make_pair(-float(a)/float(b),1));
				}
			if (b!=0)	
				st.insert(make_pair(-float(a)/float(b),-float(c)/float(b)));
			else{
				st.insert(make_pair(-MOD,-MOD));
			}	
				
		}
		int max=0;
		float inter;
		for (it2=mp.begin();it2!=mp.end();it2++){
			if (it2->second>max){
				max=it2->second;
				inter=it2->first;
			}
		}
		set<pair<float,float> >::iterator it5;
		int count1=0;
		for(it5=st.begin();it5!=st.end();it5++){
		//	cout<<(it5->first)<<endl;
			if (it5->first==inter){
				count1++;
			}
		}
		cout<<count1<<endl;
	}
    return 0;
}
Language: C++