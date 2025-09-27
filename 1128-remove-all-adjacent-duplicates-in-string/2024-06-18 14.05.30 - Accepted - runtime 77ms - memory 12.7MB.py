class Solution(object):
    def removeDuplicates(self, s):
        
            
    
        l = []

        for c in s:
            l.append(c)

            while len(l) > 1 and l[-2] == l[-1]:
                l.pop()
                l.pop()

        return ''.join(l)
        