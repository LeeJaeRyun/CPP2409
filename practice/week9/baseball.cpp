#include <iostream>
#include <string>
using namespace std;

int main() {
    int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
    int firstNum; // 정답의 첫번째 자리수
    int secondNum; // 정답의 두번째 자리수
    int thirdNum; // 정답의 세번째 자리수

    while (1) {		
        randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성 (100 ~ 999 사이의 숫자 생성)

        bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

        // TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
        firstNum = randomNum / 100;       // 첫 번째 자리수 추출
        secondNum = (randomNum / 10) % 10; // 두 번째 자리수 추출
        thirdNum = randomNum % 10;         // 세 번째 자리수 추출

        // 모든 수가 다르면 same을 true로 설정
        if (firstNum != secondNum && secondNum != thirdNum && firstNum != thirdNum) {
            same = true; // 모든 자리 숫자가 다를 경우 true로 설정하여 반복문 종료
        }

        if (same == true) { // 조건이 충족되면 반복 종료
            break;
        }
    }

    int turn = 0; // 시도 횟수를 저장하는 변수
    while (1) {
        cout << turn + 1 << "번째 시도입니다. " << endl; // 시도 횟수 출력

        int userNumber; // 사용자가 입력한 세자리수 저장 변수
        int guessFirst; // 추측한 숫자의 첫번째 자리수
        int guessSecond; // 추측한 숫자의 두번째 자리수
        int guessThird; // 추측한 숫자의 세번째 자리수

        // 사용자에게 세자리 수를 입력받는 코드 블록
        while (1) {
            cout << "세자리 수를 입력해주세요: ";
            cin >> userNumber;

            bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

            // TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
            guessFirst = userNumber / 100;       // 첫 번째 자리수 추출
            guessSecond = (userNumber / 10) % 10; // 두 번째 자리수 추출
            guessThird = userNumber % 10;         // 세 번째 자리수 추출

            // 입력된 숫자가 서로 다른지 체크
            if (guessFirst != guessSecond && guessSecond != guessThird && guessFirst != guessThird) {
                same = true; // 각 자리의 숫자가 다를 경우 true로 설정하여 입력 완료
            }

            if (to_string(userNumber).length() != 3) {
                cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
                continue; // 숫자가 3자리가 아니면 다시 입력
            }

            if (same == true) { // 모든 자리의 숫자가 다르면 입력 종료
                break;
            } else {
                cout << "모든 자리수가 달라야 합니다. 다시 입력하세요." << endl;
            }
        }

        int strike = 0; // 스트라이크 갯수를 저장하는 변수
        int ball = 0; // 볼 갯수를 저장하는 변수

        // TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
        // 스트라이크 판별: 위치와 숫자가 일치하는 경우
        if (guessFirst == firstNum) strike++;
        if (guessSecond == secondNum) strike++;
        if (guessThird == thirdNum) strike++;

        // 볼 판별: 위치는 다르지만 숫자가 일치하는 경우
        if (guessFirst == secondNum || guessFirst == thirdNum) ball++;
        if (guessSecond == firstNum || guessSecond == thirdNum) ball++;
        if (guessThird == firstNum || guessThird == secondNum) ball++;

        // 결과 출력: 스트라이크와 볼의 개수
        cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
        
        if (strike == 3) { // 스트라이크가 3개일 경우 정답
            cout << "정답을 맞췄습니다. 축하합니다.";
            break; // 정답을 맞췄으면 반복문 종료
        }

        turn += 1; // 시도 횟수 증가
    }

    return 0;
}
