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
    


    auto range_mid1 = elements.begin() + (range_end - range_begin) / 3;
    auto range_mid2 = elements.begin() + 2 * (range_end - range_begin) / 3;


    MergeSort(elements.begin(), range_mid1);
    MergeSort(range_mid1, range_mid2);
    MergeSort(range_mid2, elements.end());


    vector<typename RandomIt::value_type> temp;

    merge(elements.begin(), range_mid1, range_mid1, range_mid2, back_inserter(temp));

    merge(temp.begin(), temp.end(), range_mid2, elements.end(), range_begin);    

    
}
















int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}