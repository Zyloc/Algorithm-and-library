/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
class PalindromicSubstringsDiv2{
public:
	int count(String[] S1, String[] S2){
		string a,b,s;
		a = accumulate(s1.begin(),s1.end());
		b = accumulate(s2.begin(),s2.end());
		s = a + b;
		lli ans(0);
		for(lli center=0;center<s.length();center++){
			for(lli odd=0;odd<2;odd++){
				lli left(center),right(center+1);
				if(odd){
					left = center - 1 ;
					ans++;
				}
				while((left>=0 and right<s.length())){
					if(s[left]==s[right]){
						ans++;
					}
					else{
						break;
					}
					left--;
					right++;
				}
			}
		}
		return ans;
	}
};
