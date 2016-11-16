InterviewBit Beta

Search for problems, users or companies

 Chat
 Puzzles
 309
 50
giribalaji 
×Hey, it looks like you are stuck. You can use the seek help button and avail help from others.
Programming Dynamic Programming Arrange Ii
Arrange IIBookmark Suggest Edit
You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
Example:


Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option. 

If a solution is not possible, then return -1

See Expected Output
NotesAll Notes


 841 : 04 : 57 Current Possible Score: 0  Max Score: 350 
Seek Help  


1
2
3
int Solution::arrange(string A, int B) {
}
SaveReset  SubmitTestToggle Dropdown
Hints
Hint 1
Solution Approach
Complete Solution
Similar Problems
Best Time to Buy and Sell Stocks II
Max Sum Without Adjacent Elements
746 successful submissions.
Stuck?
Find your friends who have solved this problem.
 Connect with facebook
Asked In:
Amazon
Problem Discussion
Solution Discussion
This thread is for people who have not yet solved the problem. Please do not post solutions here. 
Join us on IRC at #interviewbit on freenode for bugs, help or suggestions.
About Us FAQ Contact Us Terms Privacy Policy
 Like Us   Follow Us   Email
 We are in beta! We would love to hear your feedback.  Loved InterviewBit? Write us a testimonial.
×Close
Access Hint
C
C++
Java
Python
JS

class Solution {
    public:
    
    vector<vector<int> > dp;

    int rec(int start, int stables, string str, int K) {
        int N = str.size();
        if(start == N) {
            if(stables == K)
                    return 0;
            return INT_MAX;
        }

        if(stables == K)
                return INT_MAX;

        if(dp[start][stables] != -1)
                return dp[start][stables];

        int W = 0;
        int B = 0;
        int ans = INT_MAX;

        for(int i = start; i < N; ++i) {
            W += str[i] == 'W';
            B += str[i] == 'B';
            if (W * B > ans) break;
            int Temp = rec(i + 1, stables + 1, str, K);
            if(Temp != INT_MAX) {
                ans = min(ans, Temp + (W * B));
            }
        }
        
        return dp[start][stables] =  ans;
    }

    int arrange(string str, int K) {
        int N = str.size();
        dp.clear();
        dp.resize(N, vector<int>(K, -1));

        int ans = rec(0, 0, str, K);
        return ans == INT_MAX ? -1 : ans;
    }
};




