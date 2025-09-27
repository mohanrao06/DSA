class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int i=0;
        int j=0;
        int sum=0;
        while(i<seats.size() && j<students.size()){
            sum=sum+abs(students[j]-seats[i]);
            i++;
            j++;
        }
        return abs(sum);
        
    }
};