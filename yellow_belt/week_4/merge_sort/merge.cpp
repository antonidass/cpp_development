#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin < 2)
        return;

    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    
    auto range_mid = elements.begin() + (range_end - range_begin) / 2;

    MergeSort(elements.begin(), range_mid);
    MergeSort(range_mid, elements.end());

    merge(elements.begin(), range_mid, range_mid, elements.end(), range_begin);    

    
}








int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
