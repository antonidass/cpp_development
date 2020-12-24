#include <iostream>
#include <vector>
#include <map>

using namespace std;


template <typename T> T Sqr(T x);
template <typename T> vector <T> Sqr(vector <T> src);
template <typename First, typename Second> pair <First, Second> Sqr(pair <First, Second> src);
template <typename Key , typename Value>map <Key, Value> Sqr(map <Key, Value> dictionary);



template <typename T>
T Sqr(T x)
{
    return x * x;
}



template <typename T>
vector <T> Sqr(vector <T> src)
{
    for (auto &x : src)
        x = Sqr(x);

    return src;
}


template <typename First, typename Second>
pair <First, Second> Sqr(pair <First, Second> src)
{
    return make_pair(Sqr(src.first), Sqr(src.second));
}



template <typename Key , typename Value>
map <Key, Value> Sqr(map <Key, Value> dictionary)
{
    for (auto &x : dictionary)
        x.second = Sqr(x.second);

    return dictionary;
}



// int main(){
//     vector<int> v = {1, 2, 3};
//     cout << "vector:";
//     for (int x : Sqr(v)) {
//     cout << ' ' << x;
//     }
//     cout << endl;

//     map<int, pair<int, int>> map_of_pairs = {
//     {4, {2, 2}},
//     {7, {4, 3}}
//     };
//     cout << "map of pairs:" << endl;
//     for (const auto& x : Sqr(map_of_pairs)) {
//     cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
//     }
// }