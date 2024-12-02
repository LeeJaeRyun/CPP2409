#include "user.h"
#include <cstdlib>
#include <ctime>

// << 연산자 중복 정의
ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHp() << "이고, 아이템을 총 " << user.item_cnt << "개 획득했습니다.";
    return os;
}

// Magician 클래스 구현
Magician::Magician() {
    hp = 20;
    item_cnt = 0;
    weapon_cnt = 0;
    armor_cnt = 0;
}

void Magician::DecreaseHp(int dec_hp) {
    hp -= dec_hp;
}

void Magician::IncreaseHp(int inc_hp) {
    hp += inc_hp;
}

int Magician::GetHp() const {
    return hp;
}

void Magician::AddItem() {
    item_cnt++;
    int item_type = rand() % 2; // 0: 무기, 1: 갑옷
    if (item_type == 0) {
        weapon_cnt++;
        cout << "마법사가 무기를 획득했습니다!" << endl;
    } else {
        armor_cnt++;
        cout << "마법사가 갑옷을 획득했습니다!" << endl;
    }
}

void Magician::DoAttack() const {
    cout << "마법사가 적을 만났습니다! 마법을 사용합니다." << endl;
}

void Magician::DisplayItems() const {
    cout << "무기: " << weapon_cnt << ", 갑옷: " << armor_cnt << endl;
}

// Warrior 클래스 구현
Warrior::Warrior() {
    hp = 30;
    item_cnt = 0;
    weapon_cnt = 0;
    armor_cnt = 0;
}

void Warrior::DecreaseHp(int dec_hp) {
    hp -= dec_hp;
}

void Warrior::IncreaseHp(int inc_hp) {
    hp += inc_hp;
}

int Warrior::GetHp() const {
    return hp;
}

void Warrior::AddItem() {
    item_cnt++;
    int item_type = rand() % 2; // 0: 무기, 1: 갑옷
    if (item_type == 0) {
        weapon_cnt++;
        cout << "전사가 무기를 획득했습니다!" << endl;
    } else {
        armor_cnt++;
        cout << "전사가 갑옷을 획득했습니다!" << endl;
    }
}

void Warrior::DoAttack() const {
    cout << "전사가 적을 만났습니다! 검을 휘두릅니다." << endl;
}

void Warrior::DisplayItems() const {
    cout << "무기: " << weapon_cnt << ", 갑옷: " << armor_cnt << endl;
}
