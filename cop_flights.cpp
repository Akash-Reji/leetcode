/*
There are n flights that are labeled from 1 to n.

You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

 

Example 1:

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]
Example 2:

Input: bookings = [[1,2,10],[2,2,15]], n = 2
Output: [10,25]
Explanation:
Flight labels:        1   2
Booking 1 reserved:  10  10
Booking 2 reserved:      15
Total seats:         10  25
Hence, answer = [10,25]

*/
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        ans.push_back(0);
        for(int i=0;i<bookings.size();i++){
            int a=bookings[i][0];
        
            int b=bookings[i][1];
            
            int k=bookings[i][2];
            
            ans[a-1]+=k;
            if(b<n){
            ans[b]+=-k;
            }
            
        }
        ans.pop_back();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ans[i];
            ans[i]=sum;
        }
        return ans;
    }
