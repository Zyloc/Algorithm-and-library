/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
class TheAirTripDivTwo{
public:
	int find(vector <int> flights, int fuel){
		int ans(0),index(0);
		while(fuel){
			fuel-=flights[index];
			index++;
		}
		return index-1;
	}
};
