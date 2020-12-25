#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};






// int gcd(int numerator, int denominator)
// {
//     while (numerator && denominator)
//     {
//         if (numerator > denominator)
//             numerator %= denominator;
//         else
//             denominator %= numerator;
//     }

//     return denominator + numerator;
// }


// class Rational {
// private:
//   int num;
//   int denom;

// public:

//     Rational()
//     {
//         num = 0;
//         denom = 0;
//     }

//     Rational(int numerator, int denominator)
//     {
//         if (numerator == 0)
//         {
//             num = 0;
//             denom = 1;
//             return;
//         }


//         int divider = gcd(abs(numerator), abs(denominator));

//         num = numerator / divider;
//         denom = denominator / divider;            

//         if (num < 0 && denom < 0)
//         {
//             num = -num;
//             denom = -denom;
//         }

//         if (num > 0 && denom < 0)
//         {
//             num = -num;
//             denom = -denom;
//         }
//     }

//     int Numerator() const
//     {
//       return num;
//     }
//     int Denominator() const
//     {
//       return denom;
//     }
// };




void test_zero()
{
  Rational a;

  AssertEqual(a.Numerator(), 0);
  AssertEqual(a.Denominator(), 1);
}


void test_zero_num()
{
  Rational a(0, 122);

  AssertEqual(a.Numerator(), 0);
  AssertEqual(a.Denominator(), 1);
}


void test_equal()
{
  Rational a(100, 100);

  AssertEqual(a.Numerator(), 1);
  AssertEqual(a.Denominator(), 1);
}


void test_div()
{
  Rational a(100, 22);

  AssertEqual(a.Numerator(), 50);
  AssertEqual(a.Denominator(), 11);
}


void test_rev_div()
{
  Rational a(12, 51);

  AssertEqual(a.Numerator(), 4);
  AssertEqual(a.Denominator(), 17);
}


void test_diff_signs()
{
  Rational a(-8, -3);

  AssertEqual(a.Numerator(), 8);
  AssertEqual(a.Denominator(), 3);
}


void test_diff_signs_num()
{
  Rational a(-8, 3);

  AssertEqual(a.Numerator(), -8);
  AssertEqual(a.Denominator(), 3);
}

void test_diff_signs_denom()
{
  Rational a(8, -6);

  AssertEqual(a.Numerator(), -4);
  AssertEqual(a.Denominator(), 3);
}



void test_prime()
{
  Rational a(17, 7);

  AssertEqual(a.Numerator(), 17);
  AssertEqual(a.Denominator(), 7);
}


int main() {
  TestRunner runner;

  runner.RunTest(test_zero, "test_zero");
  runner.RunTest(test_zero_num, "test_zero_num");
  runner.RunTest(test_equal, "test_equal");
  runner.RunTest(test_div, "test_div");
  runner.RunTest(test_rev_div, "test_rev_div");
  runner.RunTest(test_diff_signs, "test_equal_signs");
  runner.RunTest(test_diff_signs_num, "test_diff_num");
  runner.RunTest(test_diff_signs_denom, "test_diff_signs_denom");
  runner.RunTest(test_prime, "test_prime");



  return 0;
}
