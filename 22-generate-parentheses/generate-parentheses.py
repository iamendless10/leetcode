class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def cc(open,close,path):
            if len(path) == 2 * n:
                res.append("".join(path))
                return
            if open < n:
                path.append('(')
                cc(open + 1, close, path)
                path.pop()
            if close < open:
                path.append(')')
                cc(open , close + 1, path)
                path.pop()
        cc(0,0,[])
        return res