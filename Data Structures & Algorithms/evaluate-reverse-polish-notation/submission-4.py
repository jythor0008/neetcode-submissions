class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for tok in tokens:
            if tok in ("+-/*"):
                second = stack.pop()
                first = stack.pop()
                if tok == "+":
                    stack.append(first + second)
                elif tok == "-":
                    stack.append(first - second)
                elif tok == "*":
                    stack.append(first*second)
                elif tok == "/":
                    stack.append(int(first/second))
            else:
                stack.append(int(tok))

        return stack[-1]