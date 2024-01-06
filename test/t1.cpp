#include <iostream>

// 示例函数1
void printMessage1() {
    std::cout << "Hello from Function 1!" << std::endl;
}

// 示例函数2
void printMessage2() {
    std::cout << "Hello from Function 2!" << std::endl;
}

int main() {
    // 定义函数指针类型
    typedef void (*FunctionPointer)();

    // 动态分配内存创建存储函数指针的数组
    FunctionPointer* functionArray = new FunctionPointer[2];

    // 将函数指针存储在数组中
    functionArray[0] = printMessage1;
    functionArray[1] = printMessage2;

    // 使用数组中的函数指针调用函数
    for (int i = 0; i < 2; ++i) {
        functionArray[i]();
    }

    // 释放动态分配的内存
    delete[] functionArray;

    return 0;
}
