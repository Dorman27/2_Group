#ifndef RAM_H
#define RAM_H

class Ram {
    char mem[100 * 1024];  // 100KB 메모리
    int size;
public:
    Ram();   // 생성자
    ~Ram();  // 소멸자
    char read(int address);  // 메모리 값 읽기
    void write(int address, char value);  // 메모리 값 쓰기
};

#endif
