/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,totalSize,x,y;
double lastAnswer;
pair<lli,lli> magicBox(vector<lli> breakTime, vector<lli> speed){
    vector<lli> prefixSumOfSize;
    for(int i(0);i<breakTime.size();i++){
	    if(i!=0){
	        prefixSumOfSize.push_back(prefixSumOfSize[i-1]+(breakTime[i]-breakTime[i-1])*speed[i-1]);
	    }
	    else{
	        prefixSumOfSize.push_back(0);
	    }
	}
	speed.push_back(1e18);
	prefixSumOfSize.push_back(1e18);
	double ans(1e18);
	lli numeratorAns,denomenatorAns,maxStartTime(1e6);
	for(int i(0);i<min(maxStartTime,x);i++){
	    int breakTimeIndex(lower_bound(breakTime.begin(),breakTime.end(),i)-breakTime.begin());
	    lli extraDownload(0),leftDownloadTime(0);
	    if(breakTime[breakTimeIndex] != i){
	        leftDownloadTime = breakTime[breakTimeIndex]-i;
	        lli downloadSpeed(speed[breakTimeIndex-1]);
	        extraDownload = downloadSpeed*leftDownloadTime;
	    }
	    int index(lower_bound(prefixSumOfSize.begin(),prefixSumOfSize.end(),prefixSumOfSize[breakTimeIndex]+totalSize-extraDownload)-prefixSumOfSize.begin());
	    lli remainingPart;
	    lli numerator;
	    lli denomenator;
	    if(i == 0){
            remainingPart = totalSize - prefixSumOfSize[index-1];
        }
        else{
            remainingPart = totalSize - prefixSumOfSize[index-1]+ prefixSumOfSize[breakTimeIndex]-extraDownload;
        }
        lli totalTime(breakTime[index-1] - breakTime[breakTimeIndex] );
        numerator = speed[index-1]*totalTime+remainingPart+leftDownloadTime*speed[index-1];
        denomenator = speed[index-1];
        lli gcd(__gcd(numerator,denomenator));
        numerator/= gcd;
        denomenator/= gcd;
	    if((numerator*1.0)/(denomenator*1.0) < ans){
	        numeratorAns = numerator;
	        denomenatorAns = denomenator;
	        ans = (numerator*1.0)/(denomenator*1.0);
	    }
	}
	if((totalSize*1.0)/(speed[n-1]*1.0) < ans){
	    lli g(__gcd(totalSize,speed[n-1]));
	    numeratorAns = totalSize/g;
	    denomenatorAns = speed[n-1]/g;
	}
	lastAnswer = numeratorAns/denomenatorAns;
	pair<lli,lli> answerInPair;
	answerInPair = {numeratorAns,denomenatorAns};
	return answerInPair;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>totalSize;
	vector<lli> breakTime,speed;
	for(int i(0);i<n;i++){
	    cin>>x>>y;
	    breakTime.push_back(x);
	    speed.push_back(y);
	}
	pair<lli,lli> answer(magicBox(breakTime,speed));
	double dummy(lastAnswer);
	double finalTime((totalSize*1.0)/y);
	int finalTimeInt(ceil(finalTime));
	breakTime.push_back(finalTime);
	reverse(speed.begin(),speed.end());
	speed.push_back(0);
	
	for(int i(0);i<breakTime.size();i++){
	    breakTime[i] = finalTimeInt - breakTime[i];
	}
	reverse(breakTime.begin(),breakTime.end());
	pair<lli,lli> currentAnswer(magicBox(breakTime,speed));
	/*for(int i(0);i<breakTime.size();i++){
		cout<<breakTime[i]<<" "<<speed[i]<<endl;
	}
	*/if (lastAnswer < dummy ){
	    cout<<currentAnswer.first<<"/"<<currentAnswer.second<<endl;
	}
	else{
	    cout<<answer.first<<"/"<<answer.second<<endl;
	}
	return 0;
}