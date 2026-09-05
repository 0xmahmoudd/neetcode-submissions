#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<stack>
using namespace std;

class Solution
{
private:

public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        
        for (int i = 0; i < n; i++)
        {
            while(!st.empty() && temperatures[i] > st.top().first)
            {
                auto p = st.top();
                st.pop();
                ans[p.second] = i - p.second;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};

