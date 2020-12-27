#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;





vector<string> SplitIntoWords(const string& s)
{
    vector <string> split;

    auto left = find(s.begin(), s.end(), ' ');
    split.push_back({s.begin(), left});

    auto right = find(left + 1, s.end(), ' ');

    while (left != s.end())
    {
        left++;
        split.push_back({left, right});
        left = right;
        right = find(right + 1, s.end(), ' ');
    }
    
    return split;
}







// int main() {
//   string s = "C Cpp Java Python";

//   vector<string> words = SplitIntoWords(s);
//   cout << words.size() << " ";
//   for (auto it = begin(words); it != end(words); ++it) {
//     if (it != begin(words)) {
//       cout << "/";
//     }
//     cout << *it;
//   }
//   cout << endl;
  
//   return 0;
// }