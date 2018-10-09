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
        stack = []
        for ch in s:
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

class Solution2(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        stack = []
        lookup = {")": "(", "]": "[", "}": "{"}
        for ch in s:
            if ch in lookup.values():
                stack.append(ch)
            elif ch in lookup.keys():
                if not stack or (stack and lookup[ch] != stack.pop()):
                    return False
            else:
                return False

        return not stack


def test():
    solu = Solution2()
    # s = "()"
    # s = "()[]{}"
    # s = "(]"
    # s = "([)]"
    s = "{[]}"
    result = solu.isValid(s)
    print("Output: " + str(result))


def main():
    test()


if __name__ == "__main__":
    main()
