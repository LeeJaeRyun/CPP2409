#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "user.h"

using namespace std;

const int MAP_X = 5;
const int MAP_Y = 5;

// 함수 선언
bool CheckXY(int user_x, int MAP_X, int user_y, int MAP_Y);
void DisplayMap(const vector<vector<int>>& map, int user_x, int user_y);
bool CheckGoal(const vector<vector<int>>& map, int user_x, int user_y);
void MoveUser(int &user_x, int &user_y, int dx, int dy, User &user, vector<vector<int>>& map, bool &turn_passed);
bool CheckUser(const User& user);

int main() {
    Magician magician;
    Warrior warrior;

    vector<vector<int>> map_magician = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    vector<vector<int>> map_warrior = {
        {0, 1, 0, 0, 4},
        {0, 0, 2, 0, 0},
        {0, 2, 0, 1, 0},
        {3, 0, 0, 0, 0},
        {0, 0, 2, 0, 3}
    };

    int magician_x = 0, magician_y = 0;
    int warrior_x = 0, warrior_y = 0;

    User* current_player = &magician; // 시작 플레이어: Magician
    vector<vector<int>>* current_map = &map_magician;
    int* current_x = &magician_x;
    int* current_y = &magician_y;

    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        cout << "현재 플레이어: " << (current_player == &magician ? "Magician" : "Warrior") << endl;
        cout << "현재 HP: " << current_player->GetHp() << " | 명령어를 입력하세요 (up,down,left,right,map,finish,info,attack): ";
        string user_input;
        cin >> user_input;

        bool turn_passed = true; // 턴 전환 여부 플래그

        if (user_input == "up") {
            MoveUser(*current_x, *current_y, 0, -1, *current_player, *current_map, turn_passed);
        } else if (user_input == "down") {
            MoveUser(*current_x, *current_y, 0, 1, *current_player, *current_map, turn_passed);
        } else if (user_input == "left") {
            MoveUser(*current_x, *current_y, -1, 0, *current_player, *current_map, turn_passed);
        } else if (user_input == "right") {
            MoveUser(*current_x, *current_y, 1, 0, *current_player, *current_map, turn_passed);
        } else if (user_input == "map") {
            DisplayMap(*current_map, *current_x, *current_y);
            turn_passed = false; // 맵 확인만 하므로 턴 유지
        } else if (user_input == "info") {
            cout << *current_player << endl;
            turn_passed = false; // 정보 출력만 하므로 턴 유지
        } else if (user_input == "attack") {
            current_player->DoAttack();
            turn_passed = false; // 공격 시 턴 유지
        } else if (user_input == "finish") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            turn_passed = false; // 잘못된 입력이므로 턴 유지
        }

        if (!CheckUser(*current_player)) {
            cout << "HP가 0입니다. " << (current_player == &magician ? "Magician" : "Warrior") << "가 실패했습니다." << endl;
            break;
        }

        if (CheckGoal(*current_map, *current_x, *current_y)) {
            cout << "목적지에 도착했습니다! " << (current_player == &magician ? "Magician" : "Warrior") << "가 승리했습니다!" << endl;
            break;
        }

        // 턴 전환
        if (turn_passed) {
            if (current_player == &magician) {
                current_player = &warrior;
                current_map = &map_warrior;
                current_x = &warrior_x;
                current_y = &warrior_y;
            } else {
                current_player = &magician;
                current_map = &map_magician;
                current_x = &magician_x;
                current_y = &magician_y;
            }
        }
    }

    return 0;
}

void MoveUser(int &user_x, int &user_y, int dx, int dy, User &user, vector<vector<int>>& map, bool &turn_passed) {
    int new_x = user_x + dx;
    int new_y = user_y + dy;

    if (!CheckXY(new_x, MAP_X, new_y, MAP_Y)) {
        cout << "맵을 벗어났습니다. 다시 입력하세요." << endl;
        turn_passed = false; // 턴 유지
    } else {
        user_x = new_x;
        user_y = new_y;
        cout << "이동했습니다." << endl;
        user.DecreaseHp(1); // 이동 시 체력 1 감소
        DisplayMap(map, user_x, user_y);

        int pos_state = map[user_y][user_x];
        if (pos_state == 1) {
            cout << "아이템을 획득했습니다!" << endl;
            user.AddItem();
            map[user_y][user_x] = 0;
        } else if (pos_state == 2) {
            cout << "적을 만났습니다! HP가 2 감소합니다." << endl;
            user.DecreaseHp(2);
        } else if (pos_state == 3) {
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다." << endl;
            user.IncreaseHp(2);
            map[user_y][user_x] = 0;
        }
        turn_passed = true; // 성공적으로 이동하면 턴 넘기기
    }
}

bool CheckXY(int user_x, int MAP_X, int user_y, int MAP_Y) {
    return user_x >= 0 && user_x < MAP_X && user_y >= 0 && user_y < MAP_Y;
}

void DisplayMap(const vector<vector<int>>& map, int user_x, int user_y) {
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                switch (map[i][j]) {
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

bool CheckGoal(const vector<vector<int>>& map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

bool CheckUser(const User& user) {
    return user.GetHp() > 0;
}
