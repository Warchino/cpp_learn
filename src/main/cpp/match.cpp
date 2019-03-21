#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>

bool match(const std::string &phrase, std::string wild) {
    //char array[wild.length()];
    //strcpy(array, wild.c_str());
    size_t count = 0;
    bool asterisc = false;
    bool flag = false;
    for (char i : wild) {
        asterisc = (i == '*');
        for (size_t j = count; j < phrase.length(); j++) {
            if (asterisc) {
                flag = true;
                //count++;
                break;
            }
            unsigned long newpos = phrase.find(i, count);
            std::cout << newpos << std::endl;
            if (i == phrase[newpos] || flag) {
                count = newpos;
                flag = false;
                break;
            } else {
                return false;
            }
        }
    }
    //if(count != phrase.length())
    //{
    //std::cout << "No";
    //}
    return true;
}


int main() {

//    std::string phrase;
//    std::string wild;
//    std::cout << "Introduce a string" << std::endl;
//    std::getline(std::cin, phrase);
//    std::cout << "Introduce a match" << std::endl;
//    std::cin >> wild;
//    if (match(phrase, wild)) {
//        std::cout << "Match!!!!" << std::endl;
//    } else {
//        std::cout << "Does not match :(" << std::endl;
//    }
    return 0;
}
