/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

bool isValid(string s) {
    if (s.empty()) {
        return true;
    }

    stack<char> st;
    for (auto& ch : s) {
        switch(ch) {
            case '{':
            case '[':
            case '(':
                st.push(ch);
                break;

            case '}':
                if (st.empty()) {
                    return false;
                }
                if (st.top() == '{') {
                    st.pop();
                } else {
                    st.push(ch);
                }
                break;

            case ']':
                if (st.empty()) {
                    return false;
                }
                if (st.top() == '[') {
                    st.pop();
                } else {
                    st.push(ch);
                }
                break;

            case ')':
                if (st.empty()) {
                    return false;
                }
                if (st.top() == '(') {
                    st.pop();
                } else {
                    st.push(ch);
                }
                break;

            default:
                return false;
        }
    }

    if (st.empty()) {
        return true;
    }

    return false;
}

void test() {
    string str1 = "(())";
    string str2 = "()[]{}";
    string str3 = "(]";
    string str4 = "([)]";
    string str5 = "{[]}";
    string str6 = "]";
    string str7 = "(])";
    vector<string> vstr;
    vstr.push_back(str1);
    vstr.push_back(str2);
    vstr.push_back(str3);
    vstr.push_back(str4);
    vstr.push_back(str5);
    vstr.push_back(str6);
    vstr.push_back(str7);

    for (auto& str : vstr) {
        bool valid = isValid(str);
        cout << "input: " << str;
        cout << (valid ? " is valid" : " is not valid") << endl;
    }
}

int main() {
    test();
    return 0;
}
