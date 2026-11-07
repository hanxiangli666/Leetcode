class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ret = []
        while matrix:
            #1) add first row/list of matrix
            ret += (matrix.pop(0))
            #2) add last element of each remaining row/list of matrix
            if matrix and matrix[0]:
                for row in matrix:
                    ret.append(row.pop())
            #3) add last row/list of matrix in reverse order
            if matrix:
                ret += (matrix.pop()[::-1])
            #4) add first element of each remaining row/list of matrix in reverse order
            if matrix and matrix[0]:
                for row in matrix[::-1]:
                    ret.append(row.pop(0))
        return ret
