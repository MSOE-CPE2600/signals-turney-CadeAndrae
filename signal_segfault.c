/** Name: Cade Andrae
 *  Assignment: Lab 10 Signals
 *  Course: CPE 2600 - 111
 */

/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Cade Andrae
 * 
 * Brief summary of modifications: 
 * Added a signal handler to catch and print a message
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Signal handler for SIGSEGV
void handle_segfault(int signum) {
    printf("SIGSEGV received. Segmentation fault\n");
    sleep(1);
}

int main(int argc, char* argv[]) {
    // Register the signal handler for SIGSEGV
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}