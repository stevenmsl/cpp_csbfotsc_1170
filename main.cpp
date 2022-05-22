#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1170;

/*
Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1,
f("zaaaz") = 3 so f("cbd") < f("zaaaz")
*/

tuple<vector<string>, vector<string>, vector<int>>
testFixture1()
{
  auto queries = vector<string>{"cbd"};
  auto words = vector<string>{"zaaaz"};
  auto output = vector<int>{1};
  return make_tuple(queries, words, output);
}

/*
Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa").
On the second query both f("aaa") and f("aaaa") are both > f("cc").
*/

tuple<vector<string>, vector<string>, vector<int>>
testFixture2()
{
  auto queries = vector<string>{"bbb", "cc"};
  auto words = vector<string>{"a", "aa", "aaa", "aaaa"};
  auto output = vector<int>{1, 2};
  return make_tuple(queries, words, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}