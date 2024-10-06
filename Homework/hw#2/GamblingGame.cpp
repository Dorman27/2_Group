#include "GamblingGame.h"

void GamblingGame::play() {
    srand((unsigned)time(0));  
    while (true) {
        if (takeTurn(player1)) break;
        if (takeTurn(player2)) break; 
    }
}

bool GamblingGame::takeTurn(Player* player) {
    cout << player->getName() << " <Enter> Ű �Է�" << endl;

    cin.get();

    int num1 = rand() % 3;
    int num2 = rand() % 3;
    int num3 = rand() % 3;

    cout << num1 << " " << num2 << " " << num3 << " ";

    if (num1 == num2 && num2 == num3) {
        cout << player->getName() << "�� �¸�!!" << endl;
        return true;
    }
    else {
        cout << "�ƽ�����!" << endl;
        return false;
    }
}