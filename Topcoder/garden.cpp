/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
const int MOD(1e9+7);
string forbidden;

lli magicBox(char last,map<char,int> count){

}
class ColorfulGardenHard{
public:
	int count(String garden, String forbid){
		forbidden  = forbid;
		for(char c('a');c<='z';c++){
			mp[c] = count(garden.begin(),garden.end(),c);
		}
		magicBox('*',mp);
	}
};

