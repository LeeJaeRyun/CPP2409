#include "user.h"

User::User() : hp(20), itemCnt(0) {} // 생성자, hp를 20으로 초기화하고 itemCnt를 0으로 초기화

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() const {
    return hp;
}

void User::AddItem() {
    itemCnt++;
}

int User::GetItemCount() const {
    return itemCnt;
}

// << 연산자 중복 정의
ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCount() << "개 입니다";
    return os;
}
