#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol1170;
using namespace std;

/*takeaways
  - avoid O(n^2)
  - use the concept of binary search to calculate the number of
    words qualified for a lesser frequency
*/

vector<int> Solution::find(vector<string> &queries, vector<string> &words)
{
  auto result = vector<int>();
  auto freq = vector<int>();

  for (auto w : words)
    freq.push_back(f(w));

  /* order by the frequency of the smallest char from each word */
  sort(begin(freq), end(freq));

  for (auto q : queries)
  {
    auto qf = f(q);
    /* this is why we need it to be sorted */
    auto ub = upper_bound(begin(freq), end(freq), qf);
    /* everything from ub toward the end is not qualified
       as they are larger than qf
    */
    result.push_back(end(freq) - ub);
  }

  return result;
}
int Solution::f(string s)
{
  /* sort it so the smallest chars will appear at the front */
  sort(s.begin(), s.end());
  auto i = 0;
  for (; i < s.size() - 1; i++)
    if (s[i] != s[i + 1])
      break;

  return i + 1;
}
