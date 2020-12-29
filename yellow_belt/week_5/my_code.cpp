#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Man {
public:
	Man(const string& type, const string& name) 
		: type_(type), name_(name) {};
	virtual void Walk(const string& destination) const {
		cout << type_ << ": " << name_ << " walks to: " << destination << endl;
	}
	string GetType() const {
		return type_;
	}
	string GetName() const {
		return name_;
	}
	string GetTypeAndName() const {
		return GetType() + ": " + GetName();
	}
protected:
	const string type_, name_;
};

class Student : public Man {
public:
	Student(const string& name, const string& song)
		: Man("Student", name), song_(song) {};
	void SingSong() const {
		cout << this->GetTypeAndName() << " sings a song: " << this->song_ << endl;
	}
	void Walk(const string& destination) const override {
		Man::Walk(destination);
		this->SingSong();
	}
private:
	const string song_;
};

class Teacher : public Man {
public:
	Teacher(const string& name, const string& subject)
		: Man("Teacher", name), subject_(subject) {};
	void Teach() const {
		cout << this->GetTypeAndName() << " teaches: " << this->subject_ << endl;
	}
private:
	const string subject_;
};

class Policeman : public Man {
public:
	Policeman(const string& name) : Man("Policeman", name) {};
	void Check(const Man& man) const {
		cout << this->GetTypeAndName() << " checks "
			<< man.GetType() << ". " << man.GetType() << "'s name is: "
			<< man.GetName() << endl;
	}
};

void VisitPlaces(const Man& man, const vector<string>& places) {
	for (const auto& p : places) {
		man.Walk(p);
	}
}

int main() {
	
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");
	
	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	p.Check(t);
	p.Check(p);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}
