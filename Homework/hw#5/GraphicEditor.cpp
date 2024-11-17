#include <iostream>
using namespace std;

// Shape 클래스 (추상 클래스)
class Shape {
public:
    virtual void draw() = 0; 
    virtual ~Shape() {}     
};

// Line 클래스
class Line : public Shape {
public:
    void draw() override {
        cout << "Line" << endl;
    }
};

// Circle 클래스
class Circle : public Shape {
public:
    void draw() override {
        cout << "Circle" << endl;
    }
};

// Rect 클래스
class Rect : public Shape {
public:
    void draw() override {
        cout << "Rectangle" << endl;
    }
};

// GraphicEditor 클래스
class GraphicEditor {
private:
    Shape** shapes; 
    int capacity;   
    int size;       

    // 배열 크기 확장 메서드
    void expand() {
        int newCapacity = capacity * 2;
        Shape** newShapes = new Shape * [newCapacity];

        // 기존 배열의 내용을 복사
        for (int i = 0; i < size; ++i) {
            newShapes[i] = shapes[i];
        }

        // 기존 배열 삭제 후 새 배열로 교체
        delete[] shapes;
        shapes = newShapes;
        capacity = newCapacity;
    }

public:
    GraphicEditor() : capacity(10), size(0) {
        shapes = new Shape * [capacity]; // 초기 용량 10으로 배열 생성
    }

    ~GraphicEditor() {
        // 동적 배열 메모리 해제
        for (int i = 0; i < size; ++i) {
            delete shapes[i];
        }
        delete[] shapes;
    }

    void addShape(int type) {
        // 용량 부족 시 배열 확장
        if (size == capacity) {
            expand();
        }

        // 도형 추가
        switch (type) {
        case 1:
            shapes[size++] = new Line();
            break;
        case 2:
            shapes[size++] = new Circle();
            break;
        case 3:
            shapes[size++] = new Rect();
            break;
        default:
            cout << "Invalid shape type!" << endl;
            break;
        }
    }

    void deleteShape(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }

        // 삭제할 도형의 메모리 해제
        delete shapes[index];

        // 배열의 나머지 부분을 앞으로 이동
        for (int i = index; i < size - 1; ++i) {
            shapes[i] = shapes[i + 1];
        }

        --size; // 크기 감소
    }

    void drawAllShapes() {
        for (int i = 0; i < size; ++i) {
            cout << i + 1 << ": ";
            shapes[i]->draw();
        }
    }
};

// main 함수
int main() {
    GraphicEditor editor;
    int command, type, index;

    cout << "그래픽 에디터입니다." << endl;

    while (true) {
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> command;

        switch (command) {
        case 1: // 도형 삽입
            cout << "선:1, 원:2, 사각형:3 >> ";
            cin >> type;
            editor.addShape(type);
            break;

        case 2: // 도형 삭제
            cout << "삭제할 도형의 인덱스 >> ";
            cin >> index;
            editor.deleteShape(index);
            break;

        case 3: // 모든 도형 출력
            editor.drawAllShapes();
            break;

        case 4: // 프로그램 종료
            return 0;

        default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
    }

    return 0;
}
