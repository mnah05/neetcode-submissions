class Solution:
    def isPalindrome(self, s: str) -> bool:
        tempString = ''.join(c.lower() for c in s if c.isalnum())
        left,right = 0,len(tempString)-1
        while left<=right:
            if tempString[left] != tempString[right]:
                return False
            else:
                left += 1
                right -= 1
        return True
        