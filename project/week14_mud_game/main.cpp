#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
void MoveUser(int &user_x, int &user_y, int dx, int dy, User &user, vector<vector<int>>& map);
bool CheckUser(const User& user);
vector<vector<int>> LoadMapFromFile(const string& file_name);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    User* current_player = nullptr;

    cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
    int job_choice;
    cin >> job_choice;

    if (job_choice == 1) {
        current_player = new Magician();
    } else if (job_choice == 2) {
        current_player = new Warrior();
    } else {
        cout << "잘못된 선택입니다. 게임을 종료합니다." << endl;
        return 0;
    }

    vector<vector<int>> map = LoadMapFromFile("map.txt");
    if (map.empty()) {
        cout << "맵을 불러올 수 없습니다. 게임을 종료합니다." << endl;
        delete current_player;
        return 0;
    }

    int user_x = 0, user_y = 0;

    while (true) {
        cout << "현재 HP: " << current_player->GetHp() << " | 명령어를 입력하세요 (up,down,left,right,map,finish,info): ";
        string user_input;
        cin >> user_input;

        if (user_input == "up") {
            MoveUser(user_x, user_y, 0, -1, *current_player, map);
        } else if (user_input == "down") {
            MoveUser(user_x, user_y, 0, 1, *current_player, map);
        } else if (user_input == "left") {
            MoveUser(user_x, user_y, -1, 0, *current_player, map);
        } else if (user_input == "right") {
            MoveUser(user_x, user_y, 1, 0, *current_player, map);
        } else if (user_input == "map") {
            DisplayMap(map, user_x, user_y);
        } else if (user_input == "info") {
            cout << *current_player << endl;
            current_player->DisplayItems();
        } else if (user_input == "finish") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
        }

        if (!CheckUser(*current_player)) {
            cout << "HP가 0입니다. 게임 오버!" << endl;
            break;
        }

        if (CheckGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 승리했습니다!" << endl;
            break;
        }
    }

    delete current_player; // 동적 메모리 해제
    return 0;
}

vector<vector<int>> LoadMapFromFile(const string& file_name) {
    ifstream file(file_name);
    vector<vector<int>> map;

    if (!file) {
        cerr << "파일을 열 수 없습니다: " << file_name << endl;
        return map; // 빈 벡터 반환
    }

    string line;
    while (getline(file, line)) {
        vector<int> row;
        for (char c : line) {
            if (isdigit(c)) {
                row.push_back(c - '0');
            }
        }
        if (!row.empty()) {
            map.push_back(row);
        }
    }

    file.close();

    // 맵 크기 유효성 검사
    if (map.size() != MAP_Y || (map.size() > 0 && map[0].size() != MAP_X)) {
        cerr << "맵 크기가 유효하지 않습니다. " << MAP_X << "x" << MAP_Y << "이어야 합니다." << endl;
        map.clear(); // 빈 벡터로 초기화
    }

    return map;
}

void MoveUser(int &user_x, int &user_y, int dx, int dy, User &user, vector<vector<int>>& map) {
    int new_x = user_x + dx;
    int new_y = user_y + dy;

    if (!CheckXY(new_x, MAP_X, new_y, MAP_Y)) {
        cout << "맵을 벗어났습니다. 다시 입력하세요." << endl;
    } else {
        user_x = new_x;
        user_y = new_y;
        cout << "이동했습니다." << endl;
        user.DecreaseHp(1); // 이동 시 체력 1 감소
        DisplayMap(map, user_x, user_y);

        int pos_state = map[user_y][user_x];
        if (pos_state == 1) {
            user.AddItem();
            map[user_y][user_x] = 0;
        } else if (pos_state == 2) {
            user.DoAttack(); // 가상 함수 호출
            user.DecreaseHp(2); // 적과 싸우면서 HP 감소
        } else if (pos_state == 3) {
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다." << endl;
            user.IncreaseHp(2);
            map[user_y][user_x] = 0;
        }
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