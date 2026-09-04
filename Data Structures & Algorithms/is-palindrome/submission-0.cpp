#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    bool is_valid(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isPalindrome(string s)
    {
        string result = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                result += tolower(s[i]);
            }
        }
        return is_valid(result);
    }
};