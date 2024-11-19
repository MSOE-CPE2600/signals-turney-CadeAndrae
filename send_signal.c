/** Name: Cade Andrae
 *  Assignment: Lab 10 Signals
 *  Course: CPE 2600 - 111
 *
 * File: send_signal.c
 * Modified by: Cade Andrae
 * 
 * Brief summary of program:
 * - Accepts a PID as a command-line argument.
 * - Sends SIGUSR1 along with a random integer to the PID.
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    // Convert the argument to a PID
    pid_t pid = atoi(argv[1]);
    if (pid <= 0) {
        fprintf(stderr, "Invalid PID: %s\n", argv[1]);
        return 1;
    }

    srand(time(NULL));

    // Generate a random integer between 0 and 99
    int random_number = rand() % 100;
    printf("Sending SIGUSR1 with data: %d to PID: %d\n", random_number, pid);

    // Prepare the signal value
    union sigval value;
    value.sival_int = random_number;

    // Send the signal with the random integer
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }

    return 0;
}