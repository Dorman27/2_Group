#include "Printer.h"

int main() {
    InkJetPrinter ink("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

    cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
    cout << "잉크젯 : ";
    ink.showInkJetPrinter();
    cout << "레이저 : ";
    laser.showLaserPrinter();

    int printer, paper;
    char ch;
    while (true) {
        cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> printer >> paper;
        switch (printer) {
        case 1:
            ink.printInkJet(paper);
            break;
        case 2:
            laser.printLaser(paper);
            break;
        default:
            break;
        }
        ink.showInkJetPrinter();
        laser.showLaserPrinter();

        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> ch;
        if (ch == 'n') break;
    }

    return 0;
}
