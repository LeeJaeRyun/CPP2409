// user클래스 선언
#ifndef USER_H
#define USER_H

class User {
private:
    int hp;

public:
    User(); // 생성자, hp를 20으로 초기화
    void DecreaseHP(int dec_hp); // HP 감소
    void IncreaseHP(int inc_hp); // HP 증가
    int GetHP() const; // 현재 HP 반환
};

#endif