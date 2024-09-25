#include <iostream>
using namespace std;

int main(){
  int userInput;
  int count=0;
  cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";
  for (int i=0; i<10; i++){
    cin >> userInput;
    if (userInput == 0){
      break;
    }
    cout << "입력값: " << userInput << " 횟수 :" << count++ << endl;
  }
  cout << "종료 되었습니다";
  return 0;
}