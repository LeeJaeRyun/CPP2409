#include "user.h"

// User 기본 생성자
User::User() : hp(20), item_cnt(0) {}

// User 공격 함수
void User::DoAttack() const {
    cout << "공격합니다." << endl;
}

// User 멤버 함수 구현
void User::DecreaseHp(int dec_hp) {
    hp -= dec_hp;
}

void User::IncreaseHp(int inc_hp) {
    hp += inc_hp;
}

int User::GetHp() const {
    return hp;
}

void User::AddItem() {
    item_cnt++;
}

int User::GetItemCount() const {
    return item_cnt;
}

// << 연산자 중복 정의
ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHp() << "이고, 먹은 아이템은 총 " << user.GetItemCount() << "개 입니다";
    return os;
}

// Magician 클래스 구현
void Magician::DoAttack() const {
    cout << "마법을 사용합니다." << endl;
}

// Warrior 클래스 구현
void Warrior::DoAttack() const {
    cout << "베기를 사용합니다." << endl;
}
