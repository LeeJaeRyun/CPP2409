#include <iostream>
using namespace std;

int main(){
  int a,b,c,largest;

  cout << "3개의 정수를 입력하시오: ";
  cin >> a >> b >> c;
  largest = a;
  if (largest <= b){
    largest = b;
  }else if (largest <= c){
    largest = c;
  }
  //기존코드의 문제점 : a와 b가 같은 값일 경우 무조건 largest는 c가 되기때문에 5 5 3 같은 경우 오류가 발생한다. 
  //largest를 a라고 가정한뒤 비교하는 방식으로 오류를 수정하고 좀 더 효율적이게 개선했다.
  cout << "가장 큰 정수는" << largest << endl;
  return 0;
}