



#include <map>
#include <iostream>
#include <string>



int main()
{
    std::map<int , std::string> student;

    student[19] = "Oussama";
    student[20] = "laarbi";
    student[9] = "bocal";
    
    // student.insert(std::make_pair(99, "bocal"));
    // student.insert(std::make_pair(2000, "laarbi"));
    
    std::cout << student[190] <<std::endl;
    std::map<int , std::string>::iterator it;
    for(it = student.begin() ; it !=  student.end(); it++)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }  
    return 0;


}