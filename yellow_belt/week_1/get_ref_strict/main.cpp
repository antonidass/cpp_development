#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <stdexcept>


using namespace std;

template <typename Key, typename Value> Value& GetRefStrict(map <Key, Value> &dict, Key key);


template <typename Key, typename Value>
Value& GetRefStrict(map <Key, Value> &dict, Key key)
{
    if (dict.find(key) == dict.end())
        throw runtime_error("lol");

    return dict.at(key);
}




// int main()
// {
//     map<int, string> m = {{0, "value"}};
//     string& item = GetRefStrict(m, 0);
//     item = "newvalue";
//     cout << m[0] << endl; // выведет newvalue

//     return 0;
// }