#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;



// string make_arithmetic(int x, int n)
// {
//     string op, val;

//     string ans(n, '(');

//     for (int i = 0; i < to_string(x).size(); i++)
//     {
//         ans.push_back(to_string(x)[i]);
//     }

//     // cout << ans << "\n\n";


//     for (int i = 0; i < n; i++)
//     {
//         cin >> op >> val;
        
//         ans.push_back(')');
//         ans.push_back(' ');
//         ans.push_back(op[0]);
//         ans.push_back(' ');
        
//         for (int j = 0; j < val.size(); j++)
//             ans.push_back(val[j]);        

//         // cout << ans << "\n\n";
//     }

//     return ans;
// }



string make_modified_arithmetic(int x, int n)
{
    string op, val;
    string ans;

    for (int i = 0; i < to_string(x).size(); i++)
        ans.push_back(to_string(x)[i]);


    if (n == 0)
    {
        return ans;
    }

    
    int count_bracket = 0;
    string prev_op;

    // cout << ans << "\n\n";

    cin >> prev_op >> val;

    ans.push_back(' ');
    ans.push_back(prev_op[0]);
    ans.push_back(' ');

    for (int j = 0; j < val.size(); j++)
            ans.push_back(val[j]); 

    map <string, int> op_values;

    op_values.insert({"+", 1});
    op_values.insert({"-", 1});
    op_values.insert({"*", 2});
    op_values.insert({"/", 2});

    int k = 0;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> op >> val;
        
        if (op_values[op] > op_values[prev_op])
        {
            ans.push_back(')');
            k++;
        }

        ans.push_back(' ');
        ans.push_back(op[0]);
        ans.push_back(' ');
        
        for (int j = 0; j < val.size(); j++)
            ans.push_back(val[j]);        

        // cout << ans << "\n\n";

        prev_op = op;
    }

    string new_ans(k, '(');
    
    for (int i = 0; i < ans.size(); i++)
    {
        new_ans.push_back(ans[i]);
    }

    return new_ans;
}



int main()
{
    int x, n;
    cin >> x >> n;

    cout << make_modified_arithmetic(x, n) << endl;



}