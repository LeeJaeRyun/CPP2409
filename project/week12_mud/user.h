#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
private:
    int hp;       // 체력
    int itemCnt;  // 아이템 먹은 횟수

public:
    User(); // 생성자, hp를 20으로 초기화
    void DecreaseHP(int dec_hp); // HP 감소
    void IncreaseHP(int inc_hp); // HP 증가
    int GetHP() const; // 현재 HP 반환
    void AddItem();    // 아이템 먹은 횟수 증가
    int GetItemCount() const; // 현재 아이템 개수 반환

    // << 연산자 중복 정의
    friend ostream& operator<<(ostream& os, const User& user);
};

#endif
