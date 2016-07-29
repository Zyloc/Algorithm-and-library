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

void printNo(lli no[]){
	lli flag(0);
	loop(i,1,9){
		if (no[i]>0){
			flag = 1;
			break;
		}
	}
	if(flag){
		pool(i,9,0){
			if (no[i]>0){
				loop(j,0,no[i]-1){
					cout<<i;
				}
			}
		}
	}
	else{
		cout<<0;
	}	
	cout<<endl;
} 

void printNo(lli no[],lli no1){
	lli flag(0);
	no[no1]--;
	loop(i,1,9){
		if (no[i]>0){
			flag = 1;
			break;
		}
	}
	if (flag){
		pool(i,9,0){
			if (no[i]>0){
				loop(j,0,no[i]-1){
					cout<<i;
				}	
			}
				
		}	
	}
	else{
		cout<<"0";
	}	
	cout<<endl;
}
void printNo(lli no[],lli no1,lli no2){
	lli flag(0);
	no[no1]--;
	no[no2]--;
	loop(i,1,9){
		if (no[i]>0){
			flag = 1;
			break;
		}
	}
	if (flag){
		pool(i,9,0){
			if (no[i]>0){
				loop(j,0,no[i]-1){
					cout<<i;
				}
			}	
		}
	}
	else{
		cout<<"0";
	}	
	cout<<endl;
}

int main(){
		zyloc(){
		lli n,no[10]={0},x,sumi(0),flag(0);
		cin>>n;
		loop(i,0,n-1){
			cin>>x;
			no[x]++;
			sumi += x;
		}
		if (no[0]>0){
			if (sumi%3==0){
				printNo(no);
				flag=1;
				//cout<<"0";
			}
			else {
				loop(i,1,9){
					if (no[i]>0 and (sumi-i)%3==0){
						printNo(no,i);
						flag = 1;
						//cout<<"1";
						break;
					}
				}
				if (flag==0){
					loop(i,1,9){
						loop(j,1,9){
							if (i==j and no[i]>=2 and (sumi-2*i)%3==0){
								printNo(no,i,i);
								flag = 1;
								//cout<<"2";
								break;
							}
							else if (no[i]>0 and no[j]>0 and (sumi-i-j)%3==0 and i!=j){
								printNo(no,i,j);
								flag = 1;
								//cout<<3;
								break;
							}
						}
						if (flag){
							break;
						}
					}
				}	
			}
				
		}
		if(flag==0){
			cout<<"-1"<<endl;
		}
	}
    return 0;
}	