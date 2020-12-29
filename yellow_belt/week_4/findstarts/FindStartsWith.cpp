#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;




// template <typename RandomIt>
// pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
// {
//     char new_prefix = static_cast<char>(prefix + 1);

//     string pref(1, prefix);
//     string pref_new(1, new_prefix);

//     auto new_begin = lower_bound(range_begin, range_end, pref);
//     auto new_end = lower_bound(range_begin, range_end, pref_new);



//     return make_pair(new_begin, new_end);
// }




template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix)
{
    auto new_begin = lower_bound(range_begin, range_end, prefix);

    string new_prefix = prefix;
    new_prefix[new_prefix.size() - 1] = static_cast<char>(prefix[prefix.size() - 1] + 1);


    auto new_end = lower_bound(range_begin, range_end, new_prefix);

    return make_pair(new_begin, new_end);
}
    


int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}