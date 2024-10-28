#include <iostream>
using namespace std;

const int numCell = 5; // 보드판의 가로 세로 길이

// 좌표 유효성 검사 함수
bool isValid(int x, int y, char board[numCell][numCell]) {
    if (x >= numCell || y >= numCell) {
        cout << x << "," << y << ": x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return false;
    }
    if (board[x][y] != ' ') {
        cout << x << "," << y << ": 이미 돌이 차 있습니다." << endl;
        return false;
    }
    return true;
}

// 승리 조건 체크 함수
bool checkWin(char currentUser, char board[numCell][numCell]) {
    // 가로, 세로 체크
    for (int i = 0; i < numCell; i++) {
        bool rowWin = true;
        bool colWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) rowWin = false; // 가로 빙고 체크
            if (board[j][i] != currentUser) colWin = false; // 세로 빙고 체크
        }
        if (rowWin || colWin) return true;
    }
    
    // 대각선 체크
    bool diagWin1 = true;
    bool diagWin2 = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) diagWin1 = false; // 왼쪽 위에서 오른쪽 아래 대각선 체크
        if (board[i][numCell - 1 - i] != currentUser) diagWin2 = false; // 오른쪽 위에서 왼쪽 아래 대각선 체크
    }
    return diagWin1 || diagWin2;
}

int main() {
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser; // 현재 유저의 돌을 저장하기 위한 변수
    char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
    int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

    // 보드판 초기화
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    // 게임을 무한 반복
    while (true) {
        // 1. 누구 차례인지 출력 (3인용 게임으로 변경)
        switch (k % 3) {
            case 0:
                currentUser = 'X';
                break;
            case 1:
                currentUser = 'O';
                break;
            case 2:
                currentUser = 'H';
                break;
        }
        cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (!isValid(x, y, board)) continue; // 유효하지 않으면 다시 입력

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                cout << " " << board[i][j] << " "; // 칸 내용 출력
                if (j < numCell - 1) cout << "|"; // 세로 구분선 출력
            }
            cout << endl;
            if (i < numCell - 1) { // 가로 구분선 출력
                for (int j = 0; j < numCell; j++) {
                    cout << "---";
                    if (j < numCell - 1) cout << "+";
                }
                cout << endl;
            }
        }

        // 6. 승리 조건 체크
        if (checkWin(currentUser, board)) {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

        // 7. 모든 칸 다 찼는지 체크하기
        int checked = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') checked++;
            }
        }
        if (checked == 0) {
            cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
            break;
        }

        k++; // 턴 증가
    }

    return 0;
}
