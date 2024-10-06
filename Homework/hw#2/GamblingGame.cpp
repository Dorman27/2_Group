#include "GamblingGame.h"

void GamblingGame::play() {
    srand((unsigned)time(0));  
    while (true) {
        if (takeTurn(player1)) break;
        if (takeTurn(player2)) break; 
    }
}

bool GamblingGame::takeTurn(Player* player) {
    cout << player->getName() << " <Enter> 키 입력" << flush;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cin.get();

    int num1 = rand() % 3;
    int num2 = rand() % 3;
    int num3 = rand() % 3;

    cout << num1 << " " << num2 << " " << num3 << " ";

    if (num1 == num2 && num2 == num3) {
        cout << player->getName() << "님 승리!!" << endl;
        return true;
    }
    else {
        cout << "아쉽군요!" << endl;
        return false;
    }
}
