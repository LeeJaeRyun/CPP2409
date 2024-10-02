#include <iostream>
using namespace std;

int main(){
  const int numCell = 3;
  char board[numCell][numCell]{};
  int x,y;

  //보드판 초기화
  for (x=0; x<numCell; x++){
    for (y=0; y<numCell; y++){
      board[x][y] = ' ';
    }
  }

  int k = 0;
  char currentUser = 'X';
  while (true) {
    //1. 누구 차례인지 출력
    //++세번째 유저까지 순서가 돌아가도록 조건 수정
    switch (k%3){
      case 0:
      cout << "첫번째 유저(X)의 차례입니다 -> ";
      currentUser = 'X';
      break;
      
      case 1:
      cout << "두번째 유저(O)의 차례입니다 -> ";
      currentUser = 'O';
      break;

      //++세번째 유저 추가
      case 2:
      cout << "세번째 유저(V)의 차례입니다 -> ";
      currentUser = 'V';
      break;
    }

    //2. 좌표 입력 받기
    cout << "(x,y) 좌표를 입력하세요: ";
    cin >> x >> y;

    //3. 입력받은 좌표의 유효성 체크
    if (x>=numCell || y>=numCell){
      cout << x << ", " << y << ": ";
      cout << " x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
      continue;
    }
    if (board[x][y] != ' '){
      cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
      continue;
    }

    //4. 입력받은 좌표에 현재 유저의 돌 놓기
    board[x][y] = currentUser;

    //5. 현재 보드 판 출력
    for (int i=0; i<numCell; i++){
      cout << "---|---|---" << endl;
      for (int j=0; j<numCell; j++){
        cout << board[i][j];
        if (j==numCell-1){
          break;
        }
        cout << "  |";
      }
      cout << endl;
    }
    cout << "---|---|---" << endl;
    k++;

    //6. 빙고시 승자 출력 후 종료
    bool bingo = false;

    //가로 체크
    for (int i=0; i<numCell; i++){
      if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser){
        bingo = true;
      }
    }
    //세로체크
    for (int i=0; i<numCell; i++){
      if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser){
        bingo = true;
      }
    }
    //대각선체크
    if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser){
      bingo = true;
    }
    if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser){
      bingo = true;
    }
    //승자가 나오면 게임 종료
    if (bingo){
      cout << currentUser << "유저가 승리하였습니다." << endl;
      break;
    }

    //7. 모든 칸이 찼으면 종료
    if (k==9){
      cout << "무승부입니다." << endl;
      break;
    }

  }
  return 0;
}