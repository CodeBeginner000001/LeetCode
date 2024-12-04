class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
    if (n< str2.size())
        return false;
    int i = 0;
    int j = 0;
    while (i < n && j < str2.size())
    {
        if ((str1[i] == 'z' && str2[j] == 'a') || 
            (str1[i] == str2[j]) || 
            (str1[i] + 1 == str2[j]))
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j >= str2.size())
    {
        return true;
    }
    return false;
    }
};