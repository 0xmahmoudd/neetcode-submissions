#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int> numList;
const int MAX = 1000+1;
int memory[MAX][MAX];
string s1, s2;



class Solution
{
public:

    int lcs(int i, int j)
    {
        if (i == s1.size() || j == s2.size()) return 0;
        int &ans = memory[i][j];
        if (ans != -1) return ans;

        if (s1[i] == s2[j])
        {
            ans = 1 + lcs(i+1, j+1);
            return ans;
        }
        int choice1 = lcs(i+1, j); // leave first and keep second
        int choice2 = lcs(i, j+1); // leave second keep first
        ans = max(choice1, choice2);
        return ans;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        s1 = text1;
        s2 = text2;
        memset(memory, -1, sizeof(memory));
        return lcs(0, 0);
    }
};

// int main()
// {
//     Solution solution;
//     string s1 = "0010101";
//     string s2 = "010110110";
//     cout << solution.longestCommonSubsequence(s1, s2) << endl;
// }