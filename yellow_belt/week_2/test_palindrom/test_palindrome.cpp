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

// bool IsPalindrom(const string& str) {
//   // Вы можете вставлять сюда различные реализации функции,
//   // чтобы проверить, что ваши тесты пропускают корректный код
//   // и ловят некорректный
// }





void TestPalindrom()
{
  AssertEqual(IsPalindrom(""), true, "empty string");
  AssertEqual(IsPalindrom("a"), true, "one sym string");
  AssertEqual(IsPalindrom("   "), true, "spaces string");
  AssertEqual(IsPalindrom("madam"), true, "common right string");
  AssertEqual(IsPalindrom("madamsds"), false, "common wrong string");
  AssertEqual(IsPalindrom("madamsds"), false, "common wrong string");
  AssertEqual(IsPalindrom("amadam"), false, "ignore first string");
  AssertEqual(IsPalindrom("madamd"), false, "ignore last string");
  AssertEqual(IsPalindrom("mad am"), false, "ignore space string");
  AssertEqual(IsPalindrom("madxzdam"), false, "ignore error string");
  AssertEqual(IsPalindrom("wasitacaroracatisaw"), true, "long ");
  AssertEqual(IsPalindrom("wasitacaroxzracatisaw"), false, "long ignoore ");
  AssertEqual(IsPalindrom("  wasitacaroracatisaw"), false, "long ignoore  space");

  AssertEqual(IsPalindrom(" madam "), true, "common right string");

  AssertEqual(IsPalindrom(" madam  "), false, "common right string");
  AssertEqual(IsPalindrom("maddam"), true, "common right string");
  AssertEqual(IsPalindrom("madzam"), false, "common right string");
  AssertEqual(IsPalindrom("abc"), false, "common right string");
  AssertEqual(IsPalindrom("aba"), true, "common right string");
  AssertEqual(IsPalindrom("ab"), false, "common right string");
  AssertEqual(IsPalindrom("aa"), true, "common right string");
  AssertEqual(IsPalindrom(" !1aa1! "), true, "common right string");

}



int main() {
  TestRunner runner;
  runner.RunTest(TestPalindrom, "TestPalindrom");
  return 0;
}
