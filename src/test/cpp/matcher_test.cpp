/*
 * This C++ source file was generated by the Gradle 'init' task.
 */

#include <cassert>
#include <Matcher.h>
#include <iostream>

int main() {
    Matcher matcher;
    assert(matcher.match("Hola mundo", "Hola*do"));
    std::cout << "------------------" << std::endl;
    assert(matcher.match("Hola mundo", "Ho?a*do"));
    std::cout << "------------------" << std::endl;
    assert(matcher.match("Hola mundo", "H*"));
    std::cout << "------------------" << std::endl;
    assert(matcher.match("Hola mundo", "*Hola*"));
    std::cout << "------------------" << std::endl;
//    assert(matcher.match("baaaba", "b*a*a"));
//    std::cout << "------------------" << std::endl;
    assert(matcher.match("baaaba", "*ba"));
    std::cout << "------------------" << std::endl;
    assert(matcher.match("baaaba", "*a"));
    std::cout << "------------------" << std::endl;
    assert(matcher.match("baaaba", "*a*"));
    std::cout << "------------------" << std::endl;
    assert(!matcher.match("baaabac", "*ba"));
    std::cout << "------------------" << std::endl;
    assert(matcher.match("baaaba", "***a"));
//    std::cout << "------------------" << std::endl;
//    assert(matcher.match("baaaba", "ba*****"));
    return 0;
}
