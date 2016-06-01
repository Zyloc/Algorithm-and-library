#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define MOD 1000000007
lli total_multiple(lli x,lli y,lli n){
	if (x%n!=0 and y%n!=0){
		return (y/n-x/n);
	}
	else {
		if (x/n!=0)
			return (y/n-x/n+1);
		else
			return (y/n-x/n);
	}
}
int main(){
	lli p1,p2;
	cin>>p1>>p2;
	lli test;
	cin>>test;
	lli number1,number2;
	loop(i,test){
		cin>>number1>>number2;
		lli no_of_multiple_n1,no_of_multiple_n2,no_of_multiple_both;
		no_of_multiple_n1 = total_multiple(number1,number2,p1);
		no_of_multiple_n2 = total_multiple(number1,number2,p2);
		no_of_multiple_both = total_multiple(number1,number2,p1*p2);
		double result = float((no_of_multiple_n1+no_of_multiple_n2-no_of_multiple_both))/float((number2-number1+1));
		//cout<<setprecision(6)<<result<<endl;
		printf("%.6f \n",result);
	}	
	return 0;
}