#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Worker {
public:

    Worker(string name) : name_(name) {}

    virtual void Walk(string dest) const = 0;

    const string name_;
};


class Student : public Worker {
public:

    Student(string name, string favouriteSong) : Worker(name) {
        FavouriteSong = favouriteSong;
    }

    void Learn() const {
        cout << "Student: " << name_ << " learns" << endl;
    }

    void Walk(string destination) const override {
        cout << "Student: " << name_ << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << name_ << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};


class Teacher : public Worker {
public:

    Teacher(string name, string subject) : Worker(name) {
        Subject = subject;
    }

    void Teach() {
        cout << "Teacher: " << name_ << " teaches: " << Subject << endl;
    }

    void Walk(string destination) const override {
        cout << "Teacher: " << name_ << " walks to: " << destination << endl;
    }

private:
    string Subject;
};


class Policeman : public Worker {
public:
    Policeman(string name) : Worker(name) {}

    void Check(Teacher t) {
        cout << "Policeman: " << name_ << " checks Teacher. Teacher's name is: " << t.name_ << endl;
    }

    void Check(Student s) {
        cout << "Policeman: " << name_ << " checks Student. Student's name is: " << s.name_ << endl;
    }

    void Check(Policeman p) {
        cout << "Policeman: " << name_<< " checks Policeman. Policeman's name is: " << p.name_ << endl;
    }

    void Walk(string destination) const override {
        cout << "Policeman: " << name_ << " walks to: " << destination << endl;
    }
};


template <typename T>
void VisitPlaces(T worker, vector<string> places) {
    for (auto p : places) {
        worker.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}