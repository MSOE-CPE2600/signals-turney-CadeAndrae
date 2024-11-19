/** Name: Cade Andrae
 *  Assignment: Lab 10 Signals
 *  Course: CPE 2600 - 111
 *
 * File: signal_sigaction.c
 * Modified by: Cade Andrae
 * 
 * Brief summary of program:
 * - Uses sigaction to register a handler for SIGUSR1.
 * - The handler prints the PID that sent the signal.
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// Signal handler for SIGUSR1
void handle_sigusr1(int signum, siginfo_t* info, void* context) {
    printf("SIGUSR1 received from process: %d\n", info->si_pid);
}

int main() {
    struct sigaction sa;

    // Configure sigaction
    sa.sa_sigaction = handle_sigusr1;
    sa.sa_flags = SA_SIGINFO; // Enable detailed information
    sigemptyset(&sa.sa_mask);

    // Register the signal handler for SIGUSR1
    sigaction(SIGUSR1, &sa, NULL);

    printf("Process running. PID: %d\n", getpid());
    printf("Send SIGUSR1 to this process using `kill -SIGUSR1 %d`\n", getpid());

    // Wait for signals
    while (1) {
        pause();
    }

    return 0;
}


