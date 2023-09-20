#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <utility>
#include "header.hpp"

int lengthOfLongestSubstring(std::string s){
    std::unordered_map<char,int>* letters = new std::unordered_map<char,int>();
    int length = 0;
    int maxlength = 0;
    if (!s.empty())
    {
        
        for (int i = 0; i < s.size(); i++)
        {   
            if (letters->find(s[i]) == letters->end())
            {
                letters->insert(std::make_pair(s[i],i));
                length++;
                if (length > maxlength)
                    maxlength = length;
            }
            else
            {
                length = 0;
                i = letters->at(s[i]);
                letters->clear();
            }
        }

    }
    

    delete letters;
    return maxlength;
}

int main() {
    std::cout << "asd" << std::endl;
    return 0;


}