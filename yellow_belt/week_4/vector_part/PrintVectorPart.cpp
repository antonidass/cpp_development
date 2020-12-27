#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




void PrintVectorPart(const vector<int> &numbers)
{
    if (numbers.empty())
        return;

    auto result = find_if(numbers.begin(), numbers.end(), [](const int &num){return num < 0;});

    if (result == numbers.end())
    {
        auto i = numbers.end();
        i--;
        
        while (i != numbers.begin())
        {
            cout << *i << " ";
            i--;
        }
        cout << *i << " ";

        return;
    }


    while (result != numbers.begin())
    {
        result--;
        cout << *result << " ";
    }
}






int main() {
  PrintVectorPart({3});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
