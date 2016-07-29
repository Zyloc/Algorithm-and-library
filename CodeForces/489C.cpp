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
using namespace std;
#define loop(i,start,end) for (int i=start;i<end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b) 
#define MOD 1000000000
#define PI  3.14159265358979323846
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int
char handi[101];
char max_handi[101];
int count1,count2;
void min_poss_number(int n,int sum){
	if (n==0){
		return  ; 
	}
	if (sum==0 and n!=0){
		handi[count1]=char(0);
		count1++;
		min_poss_number(n-1,0);
		return;
	}
	int start;
	start=(count1==0?1:0);
	loop(i,start,10){
		if ((sum-i)<=(n-1)*9){	
			handi[count1]=char(i);
			count1++;
			min_poss_number(n-1,sum-i);		
			return;
		}	
	}
}
void max_poss_number(int n,int sum){
	if (n==0){
		return; 
	}
	if (sum==0 and n!=0){
		max_handi[count2]=char(0);
		count2++;
		max_poss_number(n-1,0);
		return; 
	}
	pool(i,9,0){
		if ((sum-i)>=0){
			max_handi[count2]=char(i);
			count2++;
			max_poss_number(n-1,sum-i);
			return;
		}
	}
}
int main(){
	lli n,sum;
	cin>>n>>sum;
	if (sum==0 and n==1){
		cout<<"0 0";
		return 0;
	}
	else if (sum==0 and n!=1){
		cout<<"-1 -1";
		return 0;
	}
	if (sum<=9*n and sum>0){
		min_poss_number(n,sum);
		loop(i,0,n){
			cout<<int(handi[i]);
		}
		cout<<" ";
		max_poss_number(n,sum);
		loop(i,0,count2){
			cout<<int(max_handi[i]);
		}
		
	}
	else{
		cout<<"-1 -1";
	}	
return 0;
	
}