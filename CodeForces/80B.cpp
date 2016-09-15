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
	string s;
	cin>>s;
	double hour,minute;
	hour = (s[0]-'0')*10+(s[1]-'0');
	minute = (s[3]-'0')*10+(s[4]-'0');
	double hoursRotation(0),minuteRotation(0);
	if (hour>=12){
		hour -= 12;
	}
	//cout<<hour;
	hoursRotation = hour*30;
	minuteRotation = (minute/60)*360;
	hoursRotation += minute/2;
	cout<<hoursRotation<<" "<<minuteRotation<<endl;
	return 0;
}	