#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

// User 추상 클래스
class User {
protected:
    int hp;       // 체력
    int item_cnt; // 아이템 먹은 횟수
    int weapon_cnt; // 무기 획득 수
    int armor_cnt;  // 갑옷 획득 수

public:
    User() : hp(20), item_cnt(0), weapon_cnt(0), armor_cnt(0) {} // 기본 생성자
    virtual ~User() = default;     // 가상 소멸자

    virtual void DecreaseHp(int dec_hp) = 0;  // HP 감소
    virtual void IncreaseHp(int inc_hp) = 0;  // HP 증가
    virtual int GetHp() const = 0;            // 현재 HP 반환
    virtual void AddItem() = 0;               // 아이템 획득
    virtual void DoAttack() const = 0;        // 적과 싸울 때 호출

    virtual void DisplayItems() const = 0;    // 현재 아이템 정보 출력

    friend ostream& operator<<(ostream& os, const User& user);
};

// Magician 클래스
class Magician : public User {
public:
    Magician();
    void DecreaseHp(int dec_hp) override;
    void IncreaseHp(int inc_hp) override;
    int GetHp() const override;
    void AddItem() override;
    void DoAttack() const override;
    void DisplayItems() const override;
};

// Warrior 클래스
class Warrior : public User {
public:
    Warrior();
    void DecreaseHp(int dec_hp) override;
    void IncreaseHp(int inc_hp) override;
    int GetHp() const override;
    void AddItem() override;
    void DoAttack() const override;
    void DisplayItems() const override;
};

#endif