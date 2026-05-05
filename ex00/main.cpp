



#include <iostream>
#include <map>
#include <algorithm>
#include <string>



int main()
{
  std::map<int , std::string> my_map;
    my_map[-7] = "oussma";
    my_map[-12] = "anass";
    my_map[13] = "Achraf";
    
    typedef std::map<int , std::string>::iterator iterator;

    for(iterator it = my_map.begin(), it != my_map.end(), it++)
        std::cout << it->first << ":" << it->second << std::endl;
        
}     