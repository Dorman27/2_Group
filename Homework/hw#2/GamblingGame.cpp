#include "GamblingGame.h"
#include <cstdlib>
#include <ctime>

GamblingGame::~GamblingGame() 
{
    std::cout << "게임을 종료합니다." << std::endl;
}

void GamblingGame::play() 
{
    std::string p1, p2;
    std::cout << "***** 겜블링 게임을 시작합니다. *****" << std::endl;
    std::cout << "첫번째 선수 이름>>";
    std::cin >> p1;
    p[0].setName(p1);
    std::cout << "두번째 선수 이름>>";
    std::cin >> p2;
    p[1].setName(p2);
    std::cin.ignore();
    srand((unsigned)time(0));
    int end = 0;

    while (true)
    {
        for (int k = 0; k < 2; k++) 
        {
            std::cout << p[k].getName() << ":<Enter>" << std::endl;
            while (true)
            {
                char ch;
                std::cin.get(ch);
                if (ch == '\n')
                    break;
            }
            
            int n[3];
            std::cout << "\t" << "\t";

            for (int i = 0; i < 3; i++)
            {
                n[i] = rand() % 3;
                std::cout << n[i] << "\t";
            }
            if (n[0] == n[1] && n[0] == n[2] && n[1] == n[2])
            {
                std::cout << p[k].getName() << "님 승리!!" << std::endl;
                end = 1;
                break;
            }
            else
                std::cout << "아쉽군요!" << std::endl;
        }
        if (end == 1)
            break;
    }
}
