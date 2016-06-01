#include <iostream>
using namespace std;

int main() {
	
	// your code here
	unsigned long long int a;
	cin>>a;
	/*cout<<(a&&(a-1))<<endl;
	*/if ((a&(a-1))==0){
		cout<<"TAK";}
	else{
		cout<<"NIE";
	}	
	

	return 0;
}