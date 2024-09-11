#include <iostream>
#include <string>
using namespace std;

int main(){
  int h_temp;
  cout << "화씨온도: ";
  cin >> h_temp;
  cout << "섭씨온도 = " << (5.0/9.0)*(h_temp-32);
}