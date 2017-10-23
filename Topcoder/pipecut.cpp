/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class PipeCuts{
public:
	double probability(vector <int> weldLocations, int L){
		lli total(0),takes(0);
		sort(weldLocations.begin(),weldLocations.end());
		for(int i=0;i<weldLocations.size();i++){
			for(int j=i;j<weldLocations.size();j++){
				total++;
				if(weldLocations[i] >= L or weldLocations[j]-weldLocations[i] >= L or 100-weldLocations[j] >= L){
					takes++;
				}
			}
		}
		return takes/total;
	}
};
	