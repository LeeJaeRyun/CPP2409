#include<iostream>
using namespace std;

class Time {
  private:
    int hour;
    int minute;
  public:
    Time(int h, int m) : hour(h), minute(m) {};
    void IncHour();
    void Print(){
      cout << hour << ":" << minute << endl;
    };

    int GetHour() {return hour;}
    int GetMinute() {return minute;}
    void SetHour(int h) {hour=h;}
    void SetMinute(int m) {minute=m;}
};

int main(){
  Time a{0,0};
  a.SetHour(6);
  a.SetMinute(30);

  a.Print();
  return 0;
}