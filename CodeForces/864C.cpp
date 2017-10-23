/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli a,b,f,k;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b>>f>>k;
	lli journeryCounter(0),timesFueld(0),currentFuel(b-f);
	int goingRight(1);
	lli ans(-1);
	while(journeryCounter <= k and currentFuel >= 0){
		//cout<<goingRight<<" "<<journeryCounter<<" "<<currentFuel<<" "<<timesFueld<<endl;
		if(journeryCounter == k-1){
			if(goingRight){
				if(currentFuel < (a-f)){
					currentFuel = b-(a-f);
					timesFueld++;
					journeryCounter++;
				}
				else{
					currentFuel-=(a-f);	
					journeryCounter++;
				}
			}
			else{
				if(currentFuel < (f-1)){
					currentFuel = b-(f-1);
					timesFueld++;
					journeryCounter++;
				}
				else{
					currentFuel -= (f-1);
					journeryCounter++; 
				}
			}
		}
		else{
			if(goingRight){
				if(currentFuel < 2*(a-f) and b>=2*(a-f)){
					currentFuel = b-2*(a-f);
					timesFueld++;
					journeryCounter++;
				}
				else if(b < 2*(a-f)){
					timesFueld = INT_MAX;
					journeryCounter = INT_MAX;
				}
				else{
					currentFuel -= 2*(a-f);
					journeryCounter++;
				}
			}
			else{
				if(currentFuel < 2*(f-1) and b >= 2*(f-1)){
					currentFuel  = b-2*(f-1);
					timesFueld++;
					journeryCounter++;
				}
				else if(b < 2*(f-1)){
					timesFueld = INT_MAX;
					journeryCounter = INT_MAX;
				}
				else{
					currentFuel -= 2*(f-1);
					journeryCounter++;
				}
			}
		}
		goingRight = 1-goingRight;
	}
	if(timesFueld ==INT_MAX){
		cout<<-1;
	}
	else{
		cout<<timesFueld<<endl;
	}
	return 0;
}
