#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector < pair< unsigned long long int,unsigned long long int> > primeFactors;
void primeFactor(unsigned long long int n){
	while(n%2==0){
		//primeFactors.push_back();
		n/=2;
	}
	for (unsigned long long int i=3;i<sqrt(n);i=i+2){
		if (n%i==0){
			primeFactors.push_back(i);
			n/=int;
		}
	}
	if (n>2){
		primeFactor.push_back(n);
	}
}
int main(){
	int n;
	cin>>n;
	primeFactor(n);
}