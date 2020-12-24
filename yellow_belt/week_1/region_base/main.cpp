#include <iostream>
#include <vector>
#include <string.h>
#include <tuple>
#include <map>


using namespace std;



// enum class Lang {
//   DE, FR, IT
// };


// struct Region {
//   string std_name;
//   string parent_std_name;
//   map<Lang, string> names;
//   int64_t population;
// };


bool operator== (const Region &first, const Region &second)
{
    return tie(first.parent_std_name, first.population, first.std_name, first.names) == tie(second.parent_std_name, second.population, second.std_name, second.names);
}


int FindMaxRepetitionCount(const vector<Region>& regions)
{
    int max_count = 0;
    int k = 0;

    for (int i = 0; i < regions.size() - 1; i++)
    {
        k = 0;
        for (int j = i; j < regions.size(); j++)
        {
            if (regions[i] == regions[j])
                k++;
        }   

        if (k > max_count)
            max_count = k;
    }

    return max_count;
}





// int main() {
//   cout << FindMaxRepetitionCount({
//       {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       },
//   }) << endl;
  
//   cout << FindMaxRepetitionCount({
//       {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Toulouse",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           31
//       },
//   }) << endl;
  
//   return 0;
// }
