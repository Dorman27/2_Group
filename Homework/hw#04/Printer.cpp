#include "Printer.h"

Printer::Printer(string mo, string me, int a) : model(mo), manufacturer(me), availableCount(a), printedCount(0) {}

bool Printer::isValidPrint(int pages) {
    return availableCount >= pages;
}

void Printer::print(int pages) {
    if (isValidPrint(pages)) {
        printedCount += pages;
        availableCount -= pages;
    }
    else {
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
    }
}

void Printer::showPrinter() {
    cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장";
}

InkJetPrinter::InkJetPrinter(string mo, string me, int a, int i) : Printer(mo, me, a), availableInk(i) {}

bool InkJetPrinter::isValidInkJetPrint(int pages) {
    return availableInk >= pages;
}

void InkJetPrinter::printInkJet(int pages) {
    if (isValidPrint(pages)) {
        if (isValidInkJetPrint(pages)) {
            print(pages);
            availableInk -= pages;
            cout << "프린트하였습니다" << endl;
        }
        else {
            cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
        }
    }
    else {
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
    }
}

void InkJetPrinter::showInkJetPrinter() {
    showPrinter();
    cout << ", 남은 잉크 " << availableInk << endl;
}

LaserPrinter::LaserPrinter(string mo, string me, int a, int t) : Printer(mo, me, a), availableToner(t) {}

bool LaserPrinter::isValidLaserPrint(int pages) {
    return availableToner >= pages;
}

void LaserPrinter::printLaser(int pages) {
    if (isValidPrint(pages)) {
        if (isValidLaserPrint(pages)) {
            print(pages);
            availableToner -= pages;
            cout << "프린트하였습니다" << endl;
        }
        else {
            cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
        }
    }
    else {
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
    }
}

void LaserPrinter::showLaserPrinter() {
    showPrinter();
    cout << ", 남은 토너 " << availableToner << endl;
}
