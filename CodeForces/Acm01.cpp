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
	lli count_0(0),count_1(0);
	string s;
	cin>>s;
	double ans(0);
	lli size(s.length());
	loop(i,0,s.length()-1){
		if (s[i]=='0'){
			count_0++;
		}
	}
	//cout<<count_0<<endl;
	lli index_0(count_0-1),index_1(count_0);
	while(index_0>=0 and index_1<size){
		if (s[index_1]!='1'){
			while(s[index_0]=='0'){
				index_0--;
			}
			ans+= sqrt(index_1-index_0);
			cout<<index_1-index_0<<endl;
			index_0--;
		}
		index_1++;
	}
	printf("%.12f\n",ans );
	return 0;
}	