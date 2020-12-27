#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// enum class Gender {
//   FEMALE,
//   MALE
// };



// struct Person {
//   int age;  // возраст
//   Gender gender;  // пол
//   bool is_employed;  // имеет ли работу
// };


// template <typename InputIt>
// int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
//   if (range_begin == range_end) {
//     return 0;
//   }
//   vector<typename InputIt::value_type> range_copy(range_begin, range_end);
//   auto middle = begin(range_copy) + range_copy.size() / 2;
//   nth_element(
//       begin(range_copy), middle, end(range_copy),
//       [](const Person& lhs, const Person& rhs) {
//         return lhs.age < rhs.age;
//       }
//   );
//   return middle->age;
// }









void PrintStats(vector<Person> persons)
{
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;

    cout << "Median age for females = " << ComputeMedianAge(persons.begin(),
    partition(persons.begin(), persons.end(), [](Person pers){ return pers.gender == Gender::FEMALE; } )) << endl;

    cout << "Median age for males = " << ComputeMedianAge(persons.begin(),
    partition(persons.begin(), persons.end(), [](Person pers){ return pers.gender == Gender::MALE; } )) << endl;

    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(),
    partition(persons.begin(), persons.end(), [](Person pers){ return pers.gender == Gender::FEMALE && pers.is_employed; } )) << endl;


    cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(),
    partition(persons.begin(), persons.end(), [](Person pers){ return pers.gender == Gender::FEMALE && !pers.is_employed; } )) << endl;


    cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(),
    partition(persons.begin(), persons.end(), [](Person pers){ return pers.gender == Gender::MALE && pers.is_employed; } )) << endl;


    cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(),
    partition(persons.begin(), persons.end(), [](Person pers){ return pers.gender == Gender::MALE && !pers.is_employed; } )) << endl;
}


// template <typename InputIt>
// int ComputeMedianAge(InputIt range_begin, InputIt range_end);








// void PrintStats(vector<Person> persons);

// int main() {
//   vector<Person> persons = {
//       {31, Gender::MALE, false},
//       {40, Gender::FEMALE, true},
//       {24, Gender::MALE, true},
//       {20, Gender::FEMALE, true},
//       {80, Gender::FEMALE, false},
//       {78, Gender::MALE, false},
//       {10, Gender::FEMALE, false},
//       {55, Gender::MALE, true},
//   };
//   PrintStats(persons);
//   return 0;
// }
