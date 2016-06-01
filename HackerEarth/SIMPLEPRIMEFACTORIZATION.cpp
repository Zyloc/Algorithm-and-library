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
map<lli,lli> mp;
void primeFactors(lli n)
{
	// Print the number of 2s that divide n
	mp.insert(make_pair(2,0));
	while (n%2 == 0)
	{
		mp[2]++;
		n = n/2;
	}
 
	// n must be odd at this point. So we can skip one element (Note i = i +2)
	for (lli i = 3; i <= sqrt(n); i = i+2)
	{
		// While i divides n, print i and divide n
		while (n%i == 0)
		{
			mp[i]++;
			n = n/i;
		}
	}
 
	// This condition is to handle the case whien n is a prime number
	// greater than 2
	if (n > 2)
		mp[n]++;
}
 
/* Driver program to test above function */
int main()
{
	map<lli,lli>::iterator it,it1;
	zyloc(){
		lli n;
		cin>>n;
		primeFactors(n);
		lli k=0;
		it=mp.begin();
		it++;	
		if (mp.size()==2 and it->first==n){
			if (it->first==n){
				cout<<"2^0";
			}
		}
		else {
			for(it=mp.begin();it!=mp.end();it++){
			cout<<it->first<<"^"<<it->second;
			k++;
			if (k<mp.size()){
				cout<<"*";
			}	
		}		
		}
		cout<<endl;
		mp.clear();
	}
	return 0;
}