#include <vector>
#include <iostream>
#include <algorithm>
//#include <climits>
//#include <cstring>
using namespace std;

/*/* O(n^2) DP solution */
/*int main() {
  int n;
  cin >> n;
  if (n <= 0)
    return 0;
  vector<int> count(n, 1);
  vector<int> array(n);
  if (!(cin >> array[0]))
    return 0;
  int max_len = 1;
  int i, j;
  for (i = 1; i < n; i++) {
    if (!(cin >> array[i]))
      break;
    for (j = 0; j < i; j++) {
      if (array[i] > array[j] && count[j] + 1 > count[i])
	     count[i] = count[j] + 1;
    }
    if (count[i] > max_len)
      max_len = count[i];
  }
  cout << max_len << endl;
  return 0;
}*/

/* average case O(nlogk) solution */
int main() {
  long int n,x;
  std::vector<int> a;
  cin>>n;
  for(int i=0;i<n;i++){
  	cin>>x;
  	a.push_back(x);
  }
  vector<int> subseq;
  int i, tmp;
  for (i = 0; i < a.size(); i++) {
    tmp = lower_bound(subseq.begin(), subseq.end(), a[i]) - subseq.begin();
    if (tmp >= subseq.size())
      subseq.push_back(a[i]);
    else
      subseq[tmp] = a[i];
  }
  return subseq.size();
}