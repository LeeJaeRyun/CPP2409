#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
protected:
    int hp;       // 체력
    int item_cnt; // 아이템 먹은 횟수

public:
    User(); // 생성자
    void DecreaseHp(int dec_hp); // HP 감소
    void IncreaseHp(int inc_hp); // HP 증가
    int GetHp() const;           // 현재 HP 반환
    void AddItem();              // 아이템 먹은 횟수 증가
    int GetItemCount() const;    // 현재 아이템 개수 반환
    void DoAttack() const;       // 기본 공격 함수

    friend ostream& operator<<(ostream& os, const User& user);
};

// Magician 클래스
class Magician : public User {
public:
    void DoAttack() const; // 공격 함수
};

// Warrior 클래스
class Warrior : public User {
public:
    void DoAttack() const; // 공격 함수
};

#endif
