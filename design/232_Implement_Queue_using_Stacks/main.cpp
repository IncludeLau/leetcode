//
// Created by 刘新军 on 2018/6/25.
//

#include <iostream>
#include "MyQueue.h"

using namespace std;

int main() {

    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    cout << myQueue.pop() << endl;
    myQueue.push(3);
    cout << myQueue.pop() << endl;
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);
    cout << myQueue.pop() << endl;
    cout << myQueue.pop() << endl;
    cout << myQueue.pop() << endl;
    cout << myQueue.pop() << endl;


    cout << "done" << endl;
    return 0;
}
