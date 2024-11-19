/** Name: Cade Andrae
 *  Assignment: Lab 10 Signals
 *  Course: CPE 2600 - 111
 */

/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Cade Andrae
 * 
 * Brief summary of modifications:
 * Removed exit(1), added getpid()
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message
 */
void handle_signal() {
    printf("Received SIGINT, not exiting.\n");
}

int main() {
    pid_t pid = getpid();
    printf("Program started. PID: %d\n", pid);
    printf("Use 'kill -SIGINT %d' to send SIGINT, or 'kill -SIGKILL %d' to terminate.\n", pid, pid);

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}