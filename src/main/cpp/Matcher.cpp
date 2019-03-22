//
// Created by rodric on 3/20/19.
//

#include <iostream>
#include "Matcher.h"

bool Matcher::match(std::string phrase, std::string match) {
    size_t count = 0;
    for (char match_letter: match) {
        if (match_letter == phrase[count] || match_letter == '?') {
            count++;
            continue;
        }
        if (match_letter == '*') {
            size_t aux = count;
            char next_letter = match[++aux];
            while (next_letter == '*') {
                next_letter = match[aux++];
                if (aux + count == match.length()) {
                    return true;
                }
            }
            if (match_letter == match[0] && count == 0) {
                std::string auxp = match;
                auxp.erase(0, 1);
                count = phrase.find_last_of(auxp);
                continue;
            }
            if (next_letter == '?') {
                continue;
            }
            for (size_t i = aux; i < phrase.length(); ++i) {
                if (next_letter == phrase[i]) {
                    break;
                }
                count++;
            }
        }
    }
    return true;
}
