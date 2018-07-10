//
// Created by 刘新军 on 2018/6/25.
//

#include <iostream>
#include "MyStack.h"

using namespace std;

int main() {
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << "done" << endl;
}

