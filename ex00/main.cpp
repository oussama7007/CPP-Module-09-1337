#include <iostream>
#include <map>
#include <string>

class MyClass
{
private:
    std::map<std::string, double> mymap;

public:
    MyClass();
    void function() const;
};

MyClass::MyClass()
{
    mymap["2002-11-02"] = 0.15;
    mymap["2002-11-12"] = 0.20;
}

void MyClass::function() const
{
    std::map<std::string, double>::const_iterator it;

    it = mymap.begin(); // هنا غالبا compile error

    while (it != mymap.end())
    {
        std::cout << it->first << " : " << it->second << std::endl;
        ++it;
    }
}

int main()
{
    MyClass obj;
    obj.function();
}