



#include <map>
#include <iostream>
#include <string>



int main()
{
    std::map<int , std::string> student;

    student[19] = "Oussama";
    student[20] = "laarbi";
    student[9] = "bocal";
    
    student.insert(std::make_pair(9, "bocal"));
    student.insert(std::make_pair(20, "laarbi"));
    

    std::map<int , std::string>::iterator it;
    for(it = student.begin() ; it !=  student.end(); it++)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }  
    return 0;


}