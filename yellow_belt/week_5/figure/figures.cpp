#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;




class Figure
{
public:
    Figure(const string &type_) : type(type_) {}
    

    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;

    const string type;
};


class Triangle : public Figure
{
public:
    Triangle(int a, int b, int c) : Figure("TRIANGLE"), perim(a + b + c)
    {
        // perim = a + b + c;
        area = sqrt(perim / 2 * (perim / 2 - a) * (perim / 2 - b) * (perim / 2 - c));
    }

    string Name() const override
    {
        return type;
    }

    double Perimeter() const override
    {
        return perim;
    }

    double Area() const override
    {
        return area;
    }

private:
    double perim;
    double area;
};




class Rect : public Figure
{
public:
    Rect(int width, int height) : Figure("RECT"),
        perim(2 * width + 2 * height),
        area(width * height)
        {}
    

    string Name() const override
    {
        return type;
    }

    double Perimeter() const override
    {
        return perim;
    }

    double Area() const override
    {
        return area;
    }

private:
    double perim;
    double area;
};




class Circle : public Figure
{
public:
    Circle(int r) : Figure("CIRCLE")
    {
        perim = 2 * 3.14 * r;
        area = 3.14 * r * r;
    }

    string Name() const override
    {
        return type;
    }

    double Perimeter() const override
    {
        return perim;
    }

    double Area() const override
    {
        return area;
    }

private:
    double perim;
    double area;
};





shared_ptr<Figure> CreateFigure(istream &is)
{
    string name;

    is >> name;

    if (name == "TRIANGLE")
    {
        int a, b, c;

        is >> a >> b >> c;

        shared_ptr<Triangle> triangle = make_shared<Triangle>(a, b, c);
        return triangle;
    }
    else if (name == "RECT")
    {
        int width, height;

        is >> width >> height;

        shared_ptr<Rect> rect = make_shared<Rect>(width, height);
        return rect;
    }
    else if (name == "CIRCLE")
    {
        int r;

        is >> r;

        shared_ptr<Circle> circle = make_shared<Circle>(r);
        return circle;
    }

    return NULL;
}










int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}