#include "ask.h"
#include <stdio.h>
#include <ctype.h>  // For tolower()
#include <string.h>  // For strlen()

bool askYorN(const char* message) {
    char response[3];  // Array to store the user's response (Y/n)

    printf("%s [Y/n]: ", message);

    // Read a line of input (up to 2 characters + null terminator)
    if (fgets(response, sizeof(response), stdin) == NULL) {
        return true;  // Default to 'Y' if input fails
    }

    // Remove newline character if it's there (fgets includes newline in input)
    response[strcspn(response, "\n")] = '\0';

    // If input is empty (just Enter pressed), return true (Y)
    if (strlen(response) == 0) {
        return true;  // Default to 'Y'
    }

    // Convert the response to lowercase and check if it's 'y'
    if (tolower(response[0]) == 'y') {
        return true;
    } else {
        return false;
    }
}
