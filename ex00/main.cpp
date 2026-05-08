

#include <iostream>
#include <map>
#include <algorithm>
#include <string>


int main()
{

  std::map<int , std::string> my_map;
  char *end;
   double a = std::strtod("123455",&end );
  std::cout << a;
  if(*end != '\0')
    std::cout << "naaadi" << std::endl;


}     