# use a dict to convert string to number
# 56 ms faster than 69.18%
# 13 MB, less than 6.04%
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        num = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}
        x = y = 0
        for c in num1:
            x = 10 * x + num[c]
        for c in num2:
            y = 10 * y + num[c]
        z = x * y
        return str(z)