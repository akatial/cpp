#include <iostream>
#include <sstream>

template<class Istr>
void show_separated_str(Istr& istr, char delim){
    std::string str;
    while(std::getline(istr, str, delim)){
        std::cout << str << std::endl;
    }
}

int main(){
    std::string animals = "cat/dog/c++/rabbit";
    std::stringstream ss(animals);

    char delim = '/';
    std::cout << "stringstream:" << std::endl;
    show_separated_str(ss, delim);

    std::cout << std::endl;

    std::cout << "cin:" << std::endl;
    show_separated_str(std::cin, delim);
    
    return 0;
}
