/** Name: Cade Andrae
 *  Assignment: Lab 10 Signals
 *  Course: CPE 2600 - 111
 *
 * File: signal_alarm.c
 * Modified by: Cade Andrae
 * 
 * Brief summary of program:
 * Uses SIGALRM by scheduling an alarm to be sent after 5 seconds.
 * A signal handler is used to print a message when SIGALRM is received.
 */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handle_alarm(int signum) {
    printf("Received SIGALRM! Alarm triggered after 5 seconds.\n");
}

int main() {
    printf("Setting an alarm for 5 seconds...\n");

    // Register the SIGALRM handler
    signal(SIGALRM, handle_alarm);

    // Schedule an alarm for 5 seconds
    alarm(5);

    // Wait for signals in an infinite loop
    while (1) {
        pause();  // Suspend execution until a signal is caught
    }

    return 0;
}
