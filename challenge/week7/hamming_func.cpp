#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str){
  for (char &c : str){
    c = tolower(c);
  }
  return str;
}

string toUpperStr(string str){
  for (char &c : str){
    c = toupper(c);
  }
  return str;
}

int calcHammingDist(string s1, string s2){
  int count = 0;
  string change_s1 = toUpperStr(s1);
  string change_s2 = toUpperStr(s2);
  for (int i=0; i<change_s1.length(); i++){
      if (change_s1[i] != change_s2[i]){
        count += 1;
      }
  }
  return count;
}

int main(){
  string s1,s2;
  int count = 0;

  cout << "DNA1: ";
  cin >> s1;
  cout << "DNA2: ";
  cin >> s2;

  if (s1.length() != s2.length()){
    cout << "오류: 길이가 다름" << endl;
  }else {
    int count = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << count << endl;
  }
  return 0;
}
