#!/bin/python2.7

"""
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
"""


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        print("input s: " + s)
        stack = []
        for ch in s:
            print("ch: " + ch)
            if ch == "(" or ch == "[" or ch == "{":
                stack.append(ch)
                continue

            if len(stack)  == 0 and (ch == ")" or ch == "]" or ch == "}"):
                return  False

            if ch == ")"  and stack[-1] != "(":
                return  False

            if ch == "]"  and stack[-1] != "[":
                return  False

            if ch == "}"  and stack[-1] != "{":
                return  False

            stack.pop()

        if len(stack) == 0:
            return True

        return False


def test():
    solu = Solution()
    # s = "()"
    # s = "()[]{}"
    s = "(]"
    # s = "([)]"
    # s = "{[]}"
    result = solu.isValid(s)
    print("Output: " + str(result))


def main():
    test()


if __name__ == "__main__":
    main()
