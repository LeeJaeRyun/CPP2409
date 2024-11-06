#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> scores; // int 동적 배열을 생성한다.
  int i, sum = 0;
  while (true){
    int score;
    cout << "성적을 입력하시오(종료는 -1) : ";
    cin >> score;
    if (score == -1)
      break;
    scores.push_back(score);
  }
  for (auto &value : scores){
    sum += value;
  }
  double avg = (double)sum / scores.size();
  cout << "성적 평균=" << avg << endl;
  return 0;
}