#include <iostream>
#include <time.h>
using namespace std;

int main(){
  int i;
  int ans;
  cout << "산수 문제를 자동으로 출제합니다. " << endl;

  while (true) {
    int firstNum = rand()%100;
    int secondNum = rand()%100;
    ans = firstNum + secondNum;
    cout << firstNum << "+" << secondNum << "=";
    cin >> i;
    if (i==ans){
      cout << "맞았습니다." << endl;
      break;
    }else {
      cout << "틀렸습니다." << endl;
    }
  }
  return 0;
}