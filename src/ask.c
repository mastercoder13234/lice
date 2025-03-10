#include "ask.h"
#include <stdio.h>
#include <ctype.h>  // For tolower()

bool askYorN(const char* message) {
    char response;

    printf("%s [Y/n]: ", message);
    scanf(" %c", &response);  // The space before %c is to skip any leading whitespace characters

    // Convert to lowercase and compare
    response = tolower(response);

    if (response == 'y') {
        return true;
    } else {
        return false;
    }
}