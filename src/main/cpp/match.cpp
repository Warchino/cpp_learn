#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>

//bool match(const std::string &phrase, std::string wild) {
    //if (wild == "*") return true;
    //long count_i = std::count(wild.begin(), wild.end(), '?');
    //if (count_i != std::string::npos) {
        //if (phrase.length() == wild.length()) {
            //return true;
        //}
    //}
    //char array[wild.length()];
    //strcpy(array, wild.c_str());
    //char *phc = strtok(array, "*");
    //while (phc != nullptr) {
        //if (phrase.find(phc) == std::string::npos) {
            //return false;
        //}
        //phc = strtok(nullptr, "*");
    //}
    //return true;
//}
bool match(const std::string &phrase, std::string wild) {
	//char array[wild.length()];
    //strcpy(array, wild.c_str());
    int count = 0;
    bool asterisc = false;
    bool flag = false;
    for (size_t i = 0; i < wild.length(); i++)
    {
		asterisc = (wild[i] == '*');
		for (size_t j = count; j < phrase.length(); j++)
		{
			if (asterisc){
				flag = true;
				//count++;
				break;
			}
			int newpos = phrase.find(wild[i], count);
			std::cout << newpos << std::endl;
			if (wild[i] == phrase[newpos] || flag)
			{
				count = newpos;
				flag = false;
				break;
			} else
			{
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
	
    std::string phrase;
    std::string wild;
    std::cout << "Introduce a string" << std::endl;
    std::getline(std::cin, phrase);
    std::cout << "Introduce a match" << std::endl;
    std::cin >> wild;
    if (match(phrase, wild)) {
        std::cout << "Match!!!!" << std::endl;
    } else {
        std::cout << "Does not match :(" << std::endl;
    }
    return 0;
}
