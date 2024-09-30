#include <iostream>
#include <string>
using namespace std;

int main(){
  const int maxPeople = 5;
  string names[maxPeople];
  int ages[maxPeople];
  int number;
  cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

  for (int i=0; i<maxPeople; i++){
    cout << "사람 " << i+1 << "의 이름: ";
    cin >> names[i];
    cout << "사람 " << i+1 << "의 나이: ";
    cin >> ages[i];
  }
  //동점일 경우 배열을 활용해 모두 출력하기
  while (1){
    cout << "숫자를 입력하시오 (1. 가장 나이가 많은 사람 출력 2. 가장 나이가 적은 사람 출력 3. 종료) : ";
    cin >> number;
    if (number == 1){
      string maxarr[maxPeople];
      int maxnumber = ages[0];
      string maxname = names[0];

      for(int i=1; i<maxPeople; i++){
        if(ages[i]>maxnumber){
          maxnumber = ages[i];
          maxname = names[i];
        }
      }
      for (int i=0; i<maxPeople; i++){
        if(ages[i]==maxnumber){
          maxarr[i] += (to_string(ages[i])+names[i]);
        }
      }
      for (int i=0; i<maxPeople; i++){
        cout << maxarr[i] + " ";
      }
      cout << "이 나이가 제일 많습니다." << endl;
      
    }else if (number == 2){
      string minarr[maxPeople];
      int minnumber = ages[0];
      string minname = names[0];

      for(int i=1; i<maxPeople; i++){
        if(ages[i]<minnumber){
          minnumber = ages[i];
          minname = names[i]; 
        }
      }
      for (int i=0; i<maxPeople; i++){
        if(ages[i]==minnumber){
          minarr[i] += (to_string(ages[i])+names[i]);
        }
      }
      for (int i=0; i<maxPeople; i++){
        cout << minarr[i] + " ";
      }
      cout << "이 나이가 제일 적습니다." << endl;
    }else {
      cout << "프로그램을 종료합니다" << endl;
      break;
    }
  }
  
  return 0;
}