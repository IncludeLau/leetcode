//
// Created by 刘新军 on 2018/4/24.
//

#include <cmath>
#include "Solution.h"


int Solution::climbStairs(int n) {
    vector<int> v(n+1, 0);
    if (n == 1) return 1;
    v[1] = 1;
    if (n == 2) return 2;
    v[2] = 2;
    for (int i = 3; i <= n; i++ ) {
        v[i] = v[i-1] + v[i-2];
    }
    return v[n];
}

int Solution::reverse(int x) {
    bool flag = x < 0;
    long y = x;
    y = std::abs(y);
    queue<int> s;
    while (y){
        s.push(static_cast<int>(y%10));
        y /= 10;
    }
    y = 0;
    while (!s.empty()) {
        int i = s.front();
        y = y * 10 + i;
        if (y > INT32_MAX || -1 * y < INT32_MIN){
            return 0;
        }
        s.pop();
    }
    int r = static_cast<int>(y);
    if(flag){
        r = -1 * r;
    }
    return r;
}

int Solution::firstUniqChar(string s) {
    map<char, int> m;
    for (char c : s) ++m[c];
    for (int i = 0; i < s.size(); ++i) {
        if (m[s[i]] == 1) return i;
    }
    return -1;
}

bool Solution::isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    map<char, int> m;
    for(char c: s) ++m[c];
    for(char c: t) {
        --m[c];
        if (m[c] < 0)return false;
    }
    return true;
}

bool Solution::isPalindrome(string s) {
    if(s.empty()) return true;
    size_t i = 0, j = s.size() - 1;
    while (i<=j) {
        while (i < j && !isalpha(s[i]) && !isdigit(s[i])) i++;
        while (i < j && !isalpha(s[j]) && !isdigit(s[j])) j--;

        if (tolower(s[i]) != tolower(s[j])) return false;
        i++;
        j--;
    }
    return true;
}

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    int l1 = 0, l2 = 0;
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while (p1){
        l1++;
        p1 = p1->next;
    }
    while (p2) {
        l2++;
        p2 = p2->next;
    }

    while(l1 > l2) {
        headA = headA->next;
        l1--;
    }
    while (l2 > l1) {
        headB = headB->next;
        l2--;
    }
    while (headA) {
        if(headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}

ListNode* Solution::removeElements(ListNode *head, int val) {
    if (!head) return head;
    ListNode dummy(0);
    ListNode* pre = &dummy;
    while (head) {
        ListNode* next = head->next;
        if(head->val != val) {
            pre->next = head;
            head->next = nullptr;
            pre = head;
        }
        head = next;
    }
    return dummy.next;
}

bool Solution::isPalindrome(ListNode *head) {
    if(!head || !head->next) return true;
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* nhead = reverseList(slow->next);
    slow->next = nullptr;
    while (head && nhead) {
        if (head->val != nhead->val) {
            return false;
        }
        head = head->next;
        nhead =  nhead->next;
    }
    return true;
}

ListNode* Solution::reverseList(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode* np = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return np;
}

ListNode* Solution::oddEvenList(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode *odd = head, *even = head->next, *even_head = even;
    while (even && even->next) {
        odd = odd->next = even->next;
        even = even->next = odd->next;
    }
    odd->next = even_head;
    return head;
}

int Solution::numTrees(int n) {
    if(n <= 0) return 1;
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

bool _isValidBst(TreeNode* root, int min, int max) {
    if(!root) return true;
    if(root->val <=min || root->val >= max) return false;
    return _isValidBst(root->left, min, root->val) && _isValidBst(root->left, root->val, max);
}

bool Solution::isValidBst(TreeNode *root) {
    return _isValidBst(root, INT_MIN, INT_MAX);
}

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool symmetric(TreeNode *p,TreeNode *q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    if (p->val != q->val) return false;
    return symmetric(p->left, q->right) && symmetric(p->right, q->left);
}

bool Solution::isSymmetric(TreeNode *root) {
    if(!root) return true;
//    stack<TreeNode*> sta;
//    sta.push(root->left);
//    sta.push(root->right);
//    while (!sta.empty()) {
//        auto p = sta.top();
//        sta.pop();
//        auto q = sta.top();
//        sta.pop();
//        if (!p && !q) continue;
//        if (!p || !q) return false;
//        if(p->val != q->val) return false;
//        sta.push(p->left);
//        sta.push(q->right);
//        sta.push(p->right);
//        sta.push(q->left);
//    }
//    return true;
    return symmetric(root->left, root->right);
}

int Solution::maxDepth(TreeNode *root) {
    if(!root) return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool Solution::isBalanced(TreeNode *root) {
    if (!root) return true;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    if (abs(lh - rh) > 1) return false;
    return isBalanced(root->right) && isBalanced(root->left);
}

int Solution::minDepth(TreeNode *root) {
    if(!root) return 0;
    if (!root->right && !root->left) return 1;
    int lh = root->left ? minDepth(root->left) : INT_MAX;
    int rh = root->right ? minDepth(root->right) : INT_MAX;
    int l = lh < rh ? lh : rh;
    return l + 1;
}

int Solution::maxSubArray(vector<int> &nums) {
    if(nums.empty()) return 0;
    vector<int> v(nums.size());
    v[0] = nums[0];
    int m = v[0];
    for(int i = 1; i < nums.size(); ++i) {
        v[i] = std::max(nums[i], v[i-1] + nums[i]);
        m = v[i] > m ? v[i] : m;
    }
    return m;
}

vector<int> Solution::maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> sums;
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        sums.push_back(sum);
    }
    vector<int> res;
    for(int i = 0; i < nums.size() - k + 1; ++i) {
        res.push_back(sums[i+k-1] - sums[i] + nums[i]);
    }
    return res;
}

vector<int> Solution::singleNumber(vector<int> &nums) {
    int sum = 0;
    for (auto &num : nums) {
        sum ^= num;
    }

    int index = 0;
    while (sum) {
        if (sum & 1) break;
        index++;
        sum >>= 1;
    }

    int x = 0, y = 0;
    for(auto& num : nums) {
        if((num >> index) & 1) {
            x ^= num;
        }else {
            y ^= num;
        }
    }

    vector<int> res = {x, y};
    return res;
}

string Solution::decodeString(string s) {
    if(s.empty()) return "";
}

bool Solution::hasAlternatingBits(int n) {
    n ^= (n >> 1);
    while (n) {
        if((n & 1) == 0) return false;
        n >>= 1;
    }
    return true;
}


int Solution::minCostClimbingStairs(vector<int> &cost) {

}

vector<int> Solution::diffWaysToCompute(string input) {
    return ways(input);
}

int Solution::minDistance(string word1, string word2) {
    int l1 = static_cast<int>(word1.length());
    int l2 = static_cast<int>(word2.length());

    vector<vector<int>> d(l1+1, vector<int>(l2+1, 0));
    for (int i = 0; i <= l1; ++i) {
        d[i][0] = i;
    }
    for (int j = 0; j <= l1; ++j) {
        d[0][j] = j;
    }
    for(int i = 1; i <= l1; ++i) {
        for(int j = 1; j <= l2; ++j) {
            int c = (word1[i-1] ==word2[j-1])? 0 : 1;
            d[i][j] = std::min(d[i-1][j-1]+c, std::min(d[i][j-1], d[i-1][j]) +1);
        }
    }
    return d[l1][l2];
}

const vector<int> Solution::ways(const string& input) {
    if(m_.count(input)) return m_[input];
    vector<int> ans;
    for(unsigned long i=0; i<input.length(); ++i) {
        char op = input[i];
        if(op == '+' || op == '-' || op == '*') {
            const string left = input.substr(0, i);
            const string right = input.substr(i+1);
            const vector<int> l = ways(left);
            const vector<int> r = ways(right);

            std::function<int(int, int)> f;
            switch(op) {
                case '+': f = [](int x, int y) -> int { return x + y; }; break;
                case '-': f = [](int x, int y) -> int { return x - y; }; break;
                case '*': f = [](int x, int y) -> int { return x * y; }; break;
            }

            for(int a : l)
                for(int b: r)
                    ans.push_back(f(a, b));
        }
    }
    if (ans.empty()) {
        ans.push_back(std::stoi(input));
    }
    m_[input] = ans;
    return ans;
}

int Solution::minSteps(int n) {
    if (n <= 1) return 0;
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = i;
        int s = static_cast<int>(std::sqrt(i));
        for(int j = s; j >= 1; --j) {
            if (i % j == 0) {
                dp[i] = std::min(dp[i], dp[i/j]+i);
            }
        }
    }
    return dp[n];
}

vector<int> Solution::twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    int i = 0, j = static_cast<int>(numbers.size()) -1;
    while(i < j) {
        if (numbers[i] + numbers[j] == target) {
            res.push_back(i+1);
            res.push_back(j+1);
            break;
        }else if(numbers[i] + numbers[j] > target) {
            j--;
        }else{
            i++;
        }
    }
    return res;
}

string Solution::complexNumberMultiply(string a, string b) {
    std::function<pair<int, int>(string)> f = [](string s) -> pair<int, int> {
        unsigned long pos = s.find('+');
        int a = std::stoi(s.substr(0, pos));
        int b = std::stoi(s.substr(pos+1, s.size()-2));
        return std::make_pair(a, b);
    };

    pair<int, int> pa = f(a);
    pair<int, int> pb = f(b);

    int ca = pa.first * pb.first - pa.second * pb.second;
    int cb = pa.first * pb.second + pa.second * pb.first;

    return std::to_string(ca) + '+' + std::to_string(cb) + 'i';
}






