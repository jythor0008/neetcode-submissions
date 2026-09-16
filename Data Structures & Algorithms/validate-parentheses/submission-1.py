class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {
            ')': '(',
            ']': '[',
            '}': '{',
        }

        stack_ = []
        for c in s:
            if c in mapping:
                # Close operations
                if not stack_:
                    return False

                if mapping[c] != stack_[-1]:
                    return False

                stack_.pop()

            else:
                stack_.append(c)
            
        return not stack_

