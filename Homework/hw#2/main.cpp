#include <iostream>
#include "Player.h"
#include "GamblingGame.h"
using namespace std;

int main() {
    string name1, name2;

    cout << "***** 갬블링 게임을 시작합니다. *****" << endl;

    cout << "첫번째 선수 이름>>";
    cin >> name1;

    cout << "두번째 선수 이름>>";
    cin >> name2;

    Player p1(name1);
    Player p2(name2);

    GamblingGame game(&p1, &p2);
    game.play();

    return 0;
}