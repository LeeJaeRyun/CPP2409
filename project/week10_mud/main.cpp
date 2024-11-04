// main.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수 선언
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void moveUser(int &user_x, int &user_y, int dx, int dy, User &user, int map[][mapX]);
bool CheckUser(User user); // 체력이 0인지 확인하는 함수

int main() {
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                            {1, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0},
                            {0, 2, 3, 0, 0},
                            {3, 0, 0, 0, 2} };

    User user; // 단일 유저 객체 생성
    int user_x = 0;
    int user_y = 0;

    srand(static_cast<unsigned int>(time(0)));

    // 게임 시작
    while (true) {
        cout << "현재 HP: " << user.GetHP() << " | 명령어를 입력하세요 (up,down,left,right,map,finish): ";
        string user_input;
        cin >> user_input;

        if (user_input == "up") {
            moveUser(user_x, user_y, 0, -1, user, map);
        } else if (user_input == "down") {
            moveUser(user_x, user_y, 0, 1, user, map);
        } else if (user_input == "left") {
            moveUser(user_x, user_y, -1, 0, user, map);
        } else if (user_input == "right") {
            moveUser(user_x, user_y, 1, 0, user, map);
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
        } else if (user_input == "finish") {
            cout << "종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (!CheckUser(user)) {
            cout << "HP가 0입니다. 실패했습니다." << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

void moveUser(int &user_x, int &user_y, int dx, int dy, User &user, int map[][mapX]) {
    int new_x = user_x + dx;
    int new_y = user_y + dy;

    if (!checkXY(new_x, mapX, new_y, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
    } else {
        user_x = new_x;
        user_y = new_y;
        cout << "이동했습니다." << endl;
        user.DecreaseHP(1); // 이동 시 체력 1 감소
        displayMap(map, user_x, user_y);

        int posState = map[user_y][user_x];
        if (posState == 1) {
            int item = rand() % 2;
            cout << (item == 0 ? "무기를 획득했습니다!" : "갑옷을 획득했습니다!") << endl;
            map[user_y][user_x] = 0;
        } else if (posState == 2) {
            cout << "적을 만났습니다! HP가 2 감소합니다." << endl;
            user.DecreaseHP(2);
        } else if (posState == 3) {
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다." << endl;
            user.IncreaseHP(2);
            map[user_y][user_x] = 0;
        }
    }
}

bool CheckUser(User user) {
    return user.GetHP() > 0;
}

void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                int posState = map[i][j];
                switch (posState) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}
