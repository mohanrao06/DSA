class Solution(object):
    def countStudents(self, students, sandwiches):
        no=0
        while no != len(students):
            curr=students.pop(0)
            if curr==sandwiches[0]:
                sandwiches.pop(0)
                no=0
            else:
                students.append(curr)
                no+=1
        return len(students)

        