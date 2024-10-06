#include "GamblingGame.h"

void GamblingGame::play() {
    srand((unsigned)time(0));  
    while (true) {
        if (takeTurn(player1)) break;
        if (takeTurn(player2)) break; 
    }
}

bool GamblingGame::takeTurn(Player* player) {
    cout << player->getName() << " <Enter> Å° ÀÔ·Â";

    cin.get();

    int num1 = rand() % 3;
    int num2 = rand() % 3;
    int num3 = rand() % 3;

    cout << num1 << " " << num2 << " " << num3 << " ";

    if (num1 == num2 && num2 == num3) {
        cout << player->getName() << "´Ô ½Â¸®!!" << endl;
        return true;
    }
    else {
        cout << "¾Æ½±±º¿ä!" << endl;
        return false;
    }
}
