#include <iostream>
#include "Player.h"
#include "GamblingGame.h"
using namespace std;

int main() {
    string name1, name2;

    cout << "***** ���� ������ �����մϴ�. *****" << endl;

    cout << "ù��° ���� �̸�>>";
    cin >> name1;

    cout << "�ι�° ���� �̸�>>";
    cin >> name2;

    Player p1(name1);
    Player p2(name2);

    GamblingGame game(&p1, &p2);
    game.play();

    return 0;
}