/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
class BitStrings{
public:
	int maxStrings(vector <string> list, int numZeroes, int numOnes){
		vector<int> countZero,countOne;
		for(int i=0;i<list.size();i++){
			countOne.push_back(0);
			countZero.push_back(0);
			for(int j=0;j<list[i].length();j++){
				if(list[i][j]=='0'){
					countZero[i]++;
				}
				else{
					countOne[i]++;
				}
			}
		}
		int ans(0);
		for(int i=0;i<(2<<list.size());i++){
			int copyZeros(numZeroes),copyOnes(numOnes),countString(0);
			for(int j=0;j<list.size();j++){
				if(i&(1LL<<j)){
					if(copyZeros >= countZero[j] and copyOnes>= countOne[j]){
						countString++;
						copyZeros -=countZero[j];
						copyOnes -= countOne[j];
					}
				}	
			}
			ans = max(ans,countString);
			
		}
		return ans;	
	}
};
