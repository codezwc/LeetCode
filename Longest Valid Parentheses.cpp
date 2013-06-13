class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int length = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                int continuous_left = 1;
                for (int j = i + 1; j < s.length(); ++j)
                {
                    if (s[j] == '(')
                    {
                        ++continuous_left;
                    }
                    else
                    {
                        break;
                    }
                }

                int last_valid_j = 0;
                int count = continuous_left;
                int min_count = count;
                for (int j = i + continuous_left; j < s.length(); ++j)
                {
                    if (s[j] == '(')
                    {
                        count += 1;
                    }
                    else
                    {
                        count -= 1;

                        if (count == 0)
                        {
                            last_valid_j = j;
                            if (j + 1 - i > length)
                            {
                                length = j + 1 - i;
                            }
                        }
                        
                        if (count < 0)
                        {
                            break;
                        }

                        if (count < min_count)
                        {
                            min_count = count;
                        }
                    }
                }
                
                if (last_valid_j != 0)
                {
                    i = last_valid_j;
                }
                else
                {
                    i = i + min_count - 1;
                }
            }
        }
        
        return length;
    }
};