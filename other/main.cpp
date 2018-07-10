#include <iostream>
#include "ShuffleArray.h"
#include "Solution.h"
#include "util.cpp"
#include <vector>
#include "Tree.cpp"
#include "sort.h"

using namespace std;



void print_v(vector<int> &v) {
    for(int& t: v) {
        std::cout << t << " ";
    }
    cout << endl;
}

void print_list(ListNode* head) {
    ListNode* p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {

    Solution solution;
    string s = solution.complexNumberMultiply("1+2i", "2+3i");
    cout << s << endl;
    return 0;
}