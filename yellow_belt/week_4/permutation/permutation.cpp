#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;




int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}



int main()
{
    int n;

    cin >> n;

    vector <int> nums(n);

    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    for (int i = 0; i < factorial(n); i++)
    {
        prev_permutation(nums.begin(), nums.end());
        for (auto x : nums)
        {
            cout << x << " ";
        }
        cout << endl;
    }




    return 0;
}