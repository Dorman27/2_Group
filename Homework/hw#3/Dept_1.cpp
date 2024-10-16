#include <iostream>
using namespace std;

class Dept {
    int size;
    int* scores;

public:
    Dept(int size) {
        this->size = size;
        scores = new int[size];
    }

    Dept(const Dept& dept) {
        size = dept.size;
        scores = new int[size];
        for (int i = 0; i < size; i++) {
            scores[i] = dept.scores[i];
        }
    }

    ~Dept() {
        delete[] scores;
    }

    int getSize() { return size; }

    void read() {
        cout << "10°³ Á¡¼ö ÀÔ·Â>> ";
        for (int i = 0; i < size; i++) {
            cin >> scores[i];
        }
    }

    bool overSixteen(int index) {
        return scores[index] > 60;
    }
};

int countPass(Dept dept) {
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.overSixteen(i)) count++;
    }
    return count;
}

int main() {
    Dept com(10);
    com.read();
    int n = countPass(com);
    cout << "60점 이상은 " << n << "¸í";
}
