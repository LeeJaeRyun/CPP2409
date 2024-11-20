#include <iostream>
using namespace std;

class Person
{
protected: // name도 protected로 변경
  string name; 
  string address;
};

class Student : public Person // public 상속 추가
{
public:
  void SetAddress(string add){
    address = add;
  }
  string GetAddress(){
    return address;
  }
  void SetName(string name) { 
    this->name = name; 
  }
  string GetName(){
    return name;
  }
};

int main(){
  Student obj;
  obj.SetName("미수");
  obj.SetAddress("서울시 종로구 1번지");
  cout << "Name: " << obj.GetName() << endl;//이름도 출력하게 해줌ㄱ
  cout << "Address: " << obj.GetAddress() << endl;
  return 0;
}
