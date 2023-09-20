#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <utility>
#include "header.hpp"

int lengthOfLongestSubstring(std::string s)
{
    std::unordered_map<char, int> *letters = new std::unordered_map<char, int>();
    int length = 0;
    int maxlength = 0;
    int first = 0;
    if (!s.empty())
    {

        for (int i = 0; i < s.size(); i++)
        {
            if (letters->find(s[i]) == letters->end())
            {
                (*letters)[s[i]] = i;
                length++;
                if (length > maxlength)
                    maxlength = length;
            }
            else
            {
                int where = (*letters)[s[i]];
                if (where < first)
                {
                    
                    (*letters)[s[i]] = i;
                    length++;
                    if (length > maxlength)
                        maxlength = length;
                }
                else
                {
                    first = where + 1;
                    (*letters)[s[i]] = i;
                    length = std::max(1, i + 1 - first);
                }
            }
        }
    }

    delete letters;
    return maxlength;
}

int main()
{
    std::string s = "dvdf";
    std::cout << lengthOfLongestSubstring(s) << std::endl;
    return 0;
}