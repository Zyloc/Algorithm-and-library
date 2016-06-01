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
lli noCow,noStalls;
vi(v);

lli placement(lli ans){
	lli cowPlaced = 1,lastPlacedPos = v[0];
	loop(i,1,noStalls-1){
		if (v[i]-lastPlacedPos>=ans){
			lastPlacedPos = v[i];
			cowPlaced++;
			if (cowPlaced==noCow){
				return 1;
			}
			
		}
	} 
	return 0;
}

/*
	function to find the largest minimum
*/
lli binSearch(){
	lli start = 0, end = v[noStalls-1],mid;
	while(start<end){
		mid =(end+start) / 2;
		//cout<<start<<" "<<end<<" "<<mid<<endl;
		//cout<<mid<<" "<<placement(mid)<<endl;
		if (placement(mid)){
			start = mid + 1;
		}
		else{
			end = mid;
		}
	}
	return start-1;
}
int main(){
	zyloc(){
		lli x;
		cin>>noStalls>>noCow;
		loop(i,1,noStalls){
			cin>>x;
			v.pb(x);
		}
		sort(v.begin(),v.end());
		//debug();
		cout<<binSearch()<<endl;	
		v.clear();
	}	
    return 0;
}	