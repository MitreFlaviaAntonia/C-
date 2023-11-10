#include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t)
{
    int i = 0;
    int j = 0;

    while (i < s.length() && j < t.length())
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }

    return i == s.length();
}

int main(){
    std::string s = "abc";
    std::string t = "ahbgdc";
    bool result = isSubsequence(s, t);

    std::cout << std::boolalpha << result << std::endl;

    return 0;
}