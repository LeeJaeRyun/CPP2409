#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // 랜덤 아이템 생성을 위한 헤더 파일 추가
using namespace std;

const int mapX = 5;
const int mapY = 5;
const int initialHP = 20; // 초기 체력 설정

// 사용자 정의 함수 선언
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void moveUser(int &user_x, int &user_y, int dx, int dy, int &user_HP, int map[][mapX]); // 이동 최적화를 위한 함수 추가

int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                            {1, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0},
                            {0, 2, 3, 0, 0},
                            {3, 0, 0, 0, 2} };

    int user_x = 0; // 가로 번호
    int user_y = 0; // 세로 번호
    int user_HP = initialHP; // 초기 체력 20 설정

    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 설정

    // 게임 시작
    while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
        // 체력 상태와 명령어 입력
        cout << "현재 HP: " << user_HP << " | 명령어를 입력하세요 (up,down,left,right,map,finish): ";
        string user_input = "";
        cin >> user_input;

				//기존의 한글 명령어 코드는 오류가 있어서 영어인 up,down등으로 대체
        // 기존의 상, 하, 좌, 우 이동 중복 코드 대신 moveUser 함수를 호출하여 이동 처리
        if (user_input == "up") {
            moveUser(user_x, user_y, 0, -1, user_HP, map); // 위로 이동
        }
        else if (user_input == "down") {
            moveUser(user_x, user_y, 0, 1, user_HP, map); // 아래로 이동
        }
        else if (user_input == "left") {
            moveUser(user_x, user_y, -1, 0, user_HP, map); // 왼쪽으로 이동
        }
        else if (user_input == "right") {
            moveUser(user_x, user_y, 1, 0, user_HP, map); // 오른쪽으로 이동
        }
        else if (user_input == "map") {
            displayMap(map, user_x, user_y); // 지도 출력
        }
        else if (user_input == "finish") {
            cout << "종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // 체력이 0이 되면 게임 실패
        if (user_HP <= 0) {
            cout << "HP가 0입니다. 실패했습니다." << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // 목적지에 도달했는지 체크
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

// 유저 이동을 처리하는 함수
// - moveUser 함수를 추가하여 이동 중복 코드를 줄임
// - 이동 방향(dx, dy)을 받아 새로운 위치를 계산하고 맵 안에 있는지 확인
void moveUser(int &user_x, int &user_y, int dx, int dy, int &user_HP, int map[][mapX]) {
    int new_x = user_x + dx; // 새로운 x 좌표 계산
    int new_y = user_y + dy; // 새로운 y 좌표 계산

    // 이동 후 좌표가 맵 안에 있는지 확인
    if (!checkXY(new_x, mapX, new_y, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl; // 맵을 벗어나면 복귀 메시지 출력
    } else {
        user_x = new_x; // x 좌표 갱신
        user_y = new_y; // y 좌표 갱신
        cout << "이동했습니다." << endl;
        user_HP--; // 이동 시 체력 1 감소
        displayMap(map, user_x, user_y); // 이동 후 지도 출력

        // 현재 위치에 따른 상호작용 처리
        int posState = map[user_y][user_x];
        if (posState == 1) { // 아이템 위치일 경우
            int item = rand() % 2; // 무기(0) 또는 갑옷(1) 랜덤 결정
            if (item == 0) {
                cout << "무기를 획득했습니다!" << endl;
            } else {
                cout << "갑옷을 획득했습니다!" << endl;
            }
            map[user_y][user_x] = 0; // 아이템을 한 번 획득한 후 빈 공간으로 설정
        }
        else if (posState == 2) { // 적을 만났을 경우
            cout << "적을 만났습니다! HP가 2 감소합니다." << endl;
            user_HP -= 2; // 체력 2 감소
        }
        else if (posState == 3) { // 포션을 발견한 경우
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다." << endl;
            user_HP += 2; // 체력 2 회복
            map[user_y][user_x] = 0; // 포션을 한 번 획득한 후 빈 공간으로 설정
        }
    }
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |"; // 유저 위치 표시
            }
            else {
                int posState = map[i][j];
                switch (posState) {
                    case 0:
                        cout << "      |"; // 빈 공간
                        break;
                    case 1:
                        cout << "아이템|"; // 아이템 위치
                        break;
                    case 2:
                        cout << "  적  |"; // 적 위치
                        break;
                    case 3:
                        cout << " 포션 |"; // 포션 위치
                        break;
                    case 4:
                        cout << "목적지|"; // 목적지 위치
                        break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
// - 주어진 좌표가 맵 내부에 있는지 여부를 반환
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

// 유저의 위치가 목적지인지 체크하는 함수
// - 현재 위치에 목적지(4)가 있는지 여부를 반환
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}