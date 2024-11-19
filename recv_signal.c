/** Name: Cade Andrae
 *  Assignment: Lab 10 Signals
 *  Course: CPE 2600 - 111
 *
 * File: recv_signal.c
 * Modified by: Cade Andrae
 * 
 * Brief summary of program:
 * - Registers a signal handler for SIGUSR1.
 * - Retrieves and prints the data sent with the signal.
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// Signal handler for SIGUSR1
void handle_sigusr1(int signum, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 with data: %d\n", info->si_value.sival_int);
}

int main() {
    struct sigaction sa;

    // Configure sigaction
    sa.sa_sigaction = handle_sigusr1;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    // Register the signal handler for SIGUSR1
    sigaction(SIGUSR1, &sa, NULL);

    printf("Process running. PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    // Wait for signals
    while (1) {
        pause();
    }

    return 0;
}