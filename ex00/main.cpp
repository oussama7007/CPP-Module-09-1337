



#include <iostream>
#include <map>
#include <algorithm>
#include <string>



int main()
{
    std::string word = "Banana";
    std::map<char , int > charCount;


    for(size_t i = 0; i< word.length(); i++)
    {
        char c = word[i];
        // charCount[c]++;
        std::map<char , int >::iterator it = charCount.find(c);
        if(it != charCount.end())
            it->second = it->second + 1;
        else 
            charCount.insert(std::make_pair(c, 1));
    }
 
    std::map<char, int >::iterator it;

    std::cout << "Character counts" << std::endl;

    for(it = charCount.begin(); it != charCount.end(); ++it )
    {
        std::cout << it->first << ":" << it->second << std::endl;
    }
    return 0;

}