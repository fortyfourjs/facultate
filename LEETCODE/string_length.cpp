#include <iostream>
#include <string>

using namespace std;

class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
            int length = 0;
            bool charFound = false;

            for(int i = s.length() - 1; i >= 0; i--)
            {
                if(s[i] != ' ')
                {
                    charFound = true;
                    length++;
                }
                else if(charFound)
                {
        
                    return length;
                }
            }
            return length;
        }
};

int main()
{
    Solution s;
    string test = "Hello world1";
    cout << "the length of the last word is: " << s.lengthOfLastWord(test) << '\n';

    return 0;
}
