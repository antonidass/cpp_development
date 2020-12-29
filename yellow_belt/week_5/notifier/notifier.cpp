#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <memory>

using namespace std;



void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}


class INotifier
{
public:
    INotifier(const string &phone) : data(phone) {}

    virtual void Notify(const string &message) const = 0;

protected:
    const string data;
};



class SmsNotifier : public INotifier
{
public:
    SmsNotifier(const string &phone) : INotifier(phone) {}

    void Notify(const string &message) const override
    {
        SendSms(data, message);
    }
};


class EmailNotifier : public INotifier
{
public:
    EmailNotifier(const string &email) : INotifier(email) {}

    void Notify(const string &message) const override
    {
        SendEmail(data, message);
    }
};


void Notify(INotifier& notifier, const string& message) {
        notifier.Notify(message);
    }


int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
}
