/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(4e5+2);
map<char,lli> freq;
lli single,committed,ans;
vector<string> finalAnswer;
vector<char> oddChars,evenChars;
lli n;

void makePallindrome(lli length){
	for(int i(0);i<n/length;i++){
		string tempString(length,'x');
		if(oddChars.size() > 0){
			tempString[length/2] = oddChars.back();
			if(freq[oddChars.back()] > 1) {
				evenChars.push_back(oddChars.back());
			}
			freq[oddChars.back()]--;
			oddChars.pop_back();
		}
		else{
			tempString[length/2]  = evenChars.back();
			freq[evenChars.back()]--;
			oddChars.push_back(evenChars.back());
			evenChars.pop_back();
		}
		lli maxIter(1);
		while(length/2+maxIter < length){
			if(evenChars.size() > 0){
				tempString[length/2+maxIter] = evenChars.back();
				tempString[length/2-maxIter] = evenChars.back();
				freq[evenChars.back()]-=2;
				if(freq[evenChars.back()] == 0){
					evenChars.pop_back();
				}	
			}
			else{
				for(int j(0);j<oddChars.size();j++){
					if(freq[oddChars[j]] >= 2){
						tempString[length/2+maxIter] = oddChars[j];
						tempString[length/2-maxIter] = oddChars[j];
						freq[oddChars[j]]-=2;
						if(freq[oddChars[j]] == 0){
							oddChars.erase(oddChars.begin()+j);
						}	
					}		
				}
					
			}
			maxIter++;
		}
		finalAnswer.push_back(tempString);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,a;
	cin>>n;
	cin>>s;
	for(auto x:s){
		freq[x]++;
	}	
	lli countOdd(0);
	for(auto x:freq){
		countOdd += x.second&1;
			if(x.second&1){
			oddChars.push_back(x.first);
		}
		else{
			evenChars.push_back(x.first);
		}
	}
	if(countOdd <= 1){
		cout<<1<<endl;
		if(s.length()&1){
			makePallindrome(n);	
			cout<<finalAnswer[0]<<endl;
		}
		else{
			string tempString(n,'x');
			for(int i(0);i<n/2;i++){
				tempString[n-i-1]= evenChars.back();
				tempString[i] = evenChars.back();
				freq[evenChars.back()]-=2;
				if(freq[evenChars.back()] == 0){
					evenChars.pop_back();
				}
			}
			cout<<tempString<<endl;
		}
		return 0;
	}
	single  =countOdd;
	committed = (n-single)/2;
	ans = 1;
	for (lli size(countOdd);size<=n;size++){
		if(n%size == 0 ){
			lli length(n/size);
			if(length&1 and (length/2)*size <= committed){
				makePallindrome(n/size);
				break;
			}
		}
	}
	cout<<finalAnswer.size()<<endl;
	for(auto x:finalAnswer){
		cout<<x<<" ";
	}
	return 0;
}