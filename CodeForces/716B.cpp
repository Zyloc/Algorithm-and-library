/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli check(lli noOfQ){
	if (noOfQ==0){
		return 0;
	}
	else{
		return noOfQ-1;
	}
}
int main(){
	string s;
	cin>>s;
	vector<char> ans;
	if (s.length()<26){
		cout<<-1;
	}
	else{
		map<char,lli> mp;
		lli noOfQ(0),start(0);
		bool flag(false);
		loop(i,0,25){
			mp[s[i]]++;
			if (s[i]=='?'){
				noOfQ++;
			}
		}
		if (mp.size()==26-check(noOfQ)){
			flag = true;
			loop(i,0,25){
				if (s[i]=='?'){
					for(char c='A';c<='Z';c++){
						if (mp.find(c)==mp.end()){
							mp[c]++;
							ans.pb(c);
							break;
						}
					}
				}
				else{
					ans.pb(s[i]);
				}
			}
		}
		else{
			/*for (auto it=mp.begin();it!=mp.end();it++)
						cout<<it->first<<" "<<it->second<<endl;
			debug();*/
			loop(i,1,s.length()-26){
				//cout<<mp.size()<<endl;
				if(mp[s[i-1]]==1){
					mp.erase(s[i-1]);
				}
				else {
					//debug();
					mp[s[i-1]]--;
				}
				if (s[i-1]=='?'){
					noOfQ-= 1;
				}
				mp[s[i+25]]++;
				if (s[i+25]=='?'){
					noOfQ+= 1;
				}
				//cout<<mp.size()<<endl;
				if (mp.size()==26-check(noOfQ)){
					//cout<<i<<" "<<noOfQ<<" "<<mp.size()<<endl;
					/*for (auto it=mp.begin();it!=mp.end();it++)
						cout<<it->first<<" "<<it->second<<endl;*/
					flag = true;
					start = i;
					loop(j,start,start+25){
						if (s[j]=='?'){
							//cout<<j<<endl;
							for(char c='A';c<='Z';c++){
								if (mp.find(c)==mp.end()){
									mp[c]++;
									ans.pb(c);
									break;
								}
							}
						}
						else{
							//cout<<s[j];
							ans.pb(s[j]);
						}
					}
					//cout<<start;
					break;
				}
			}
		}
		/*loop(j,start,start+25){
						
						cout<<ans[j];
		}*/
		if (!flag){
			cout<<-1<<endl;
		}
		else{
			loop(i,0,s.length()-1){
				if (i==start){
					loop(j,0,start+25){
						
						cout<<ans[j];
					}
					i+=25;
				}
				else{
					if (s[i]=='?'){
						s[i]='A';
					}
					cout<<s[i];
				}
			}
		}
	}
	return 0;
}	