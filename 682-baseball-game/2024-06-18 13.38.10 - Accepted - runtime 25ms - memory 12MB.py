import math
class Solution(object):
    def calPoints(self, operations):
        res=[]
        for i in range(len(operations)):
            if operations[i]=="C":
                res.pop()
            elif operations[i]=="D":
                double=res[-1]*2
                res.append(double)
            elif operations[i]=="+":
                s=res[-1]+res[-2]
                res.append(s)
            else:
                res.append(int(operations[i]))
        
        return sum(res)
        