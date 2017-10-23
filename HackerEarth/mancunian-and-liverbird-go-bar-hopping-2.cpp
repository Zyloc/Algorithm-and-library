/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+2);
int direction[MAX],reversedDirection[MAX];
int orginalLeft[MAX],orginalRight[MAX],reversedLeft[MAX],reversedRight[MAX];
lli n,x,q;
void calculateAnsRightToLeft(){
    for(int i(n-2);i>=0;i--){
        if(direction[i]){
            orginalLeft[i]+=orginalLeft[i+1]+1;
        }
        if(reversedDirection[i]){
            reversedLeft[i]+= reversedLeft[i+1]+1;
        }
    }
}
void calculateAnsLeftToRight(){
    for(int i(1);i<n;i++){
        if(direction[i-1] == 0){
            orginalRight[i]+=orginalRight[i-1]+1;
        }
        if(reversedDirection[i-1] == 0){
            reversedRight[i]+=reversedRight[i-1]+1;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i(0);i<n-1;i++){
	    cin>>direction[i];
	    reversedDirection[i] = 1-direction[i];
	}
	calculateAnsLeftToRight();
	calculateAnsRightToLeft();
	lli countUpdate(0);
	cin>>q;
	while(q--){
	    char c;
	    cin>>c;
	    if(c=='U'){
	        countUpdate++;   
	    }
	    else{
	        cin>>x;
	        if(countUpdate&1){
	            cout<<reversedLeft[x-1]+reversedRight[x-1]+1<<endl;
	        }
	        else{
	            cout<<orginalLeft[x-1]+orginalRight[x-1]+1<<endl;
	        }
	    }
	}
	return 0;
}	