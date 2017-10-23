/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
class BirthdayOdds{
public:
	int minPeople(int minOdds, int daysInYear){
		double minOd = double((100-minOdds)/100);
		double ans(1.0), people(1);
		while(ans > minOd){
			ans = (daysInYear-people)/daysInYear;
			people++;
		}
		return people;
	}
};
