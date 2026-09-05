class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.length();

        if (n % 2 == 1 || n == 0) return false;

        if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }

            else if (!st.empty())
            {
                if (s[i] == ')')
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

                else if (s[i] == ']')
                {
                    if (st.top() == '[')
                    {
                        st.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

                else if (s[i] == '}')
                {
                    if (st.top() == '{')
                    {
                        st.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            else return false;
        }

        return st.empty();
    }
};