//
// Created by 刘新军 on 2018/6/25.
//

#include <iostream>
#include "MinStack.h"
using namespace std;

int main() {
    MinStack<int> minStack;

    minStack.push(10);
    cout << minStack.getMin() << endl;

    minStack.push(4);
    cout << minStack.getMin() << endl;

    minStack.push(8);
    cout << minStack.getMin() << endl;

    minStack.push(2);
    cout << minStack.getMin() << endl;

    MinStack<string> minStack1;

    minStack1.push("fead");
    cout << minStack1.getMin() << endl;

    minStack1.push("gbaad");
    cout << minStack1.getMin() << endl;

    minStack1.push("cdae");
    cout << minStack1.getMin() << endl;

    minStack1.push("asdva");
    cout << minStack1.getMin() << endl;
    cout << "done" << endl;
}