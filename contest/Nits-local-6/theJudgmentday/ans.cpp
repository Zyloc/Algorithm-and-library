#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int lk;
	cin>>lk;
	while(lk--){
		int limit,a,b,ans,j,i,four,temp,c,d,t;
		int x[1000],y[1000];
		scanf("%d",&limit);
		for (a=0;a<limit;a++){
			scanf("%d",&x[a]);
		}
		for (c=1;c<=limit-1;c++){
			d=c;
			while(d>0&&x[d]<x[d-1]){
				t = x[d];
				x[d]= x[d-1];
				x[d-1]=t;
				d--;
			}
		}
		for(c=limit-1,d=0;c>=0;c--,d++){
			y[d]=x[c];
		}
		for(c=0;c<limit;c++){
			x[c]=y[c];
		}
		j = limit-1;
		ans = 0;
		i = 0;
		while (i<=j){
			ans++;
			four = 4-x[i];
			while (x[j]<=four && j>=i){
				four = four-x[j];
				j--;
			}
			i++;
		}
		printf ("%d\n",ans);
	}	
	return 0;
	
}