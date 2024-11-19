# Signal Handling in C

## Part 1: Basic Signal Handling
### File: `signal_handler.c`
- Registers a signal handler for `SIGINT` (Ctrl+C).
- The program prints a message when `SIGINT` is received and continues running.

### How to Run:
1. Compile the program:
    ```bash
    gcc signal_handler.c -o signal_handler
2. Run the program:
    ```
    ./signal_handler
---

## Part 2: System Signals
### `signal_alarm.c`
- Demonstrates the `SIGALRM` signal triggered by the `alarm()` system call.
- The program sets an alarm to go off after 5 seconds and prints a message when the signal is received.

### `signal_segfault.c`
- Demonstrates handling a segmentation fault (`SIGSEGV`) caused by dereferencing a null pointer.
- The program catches the `SIGSEGV` signal, prints a message, and allows the program to continue running, resulting in repeated faults.

### How to Run:
1. Compile the program:
   ```bash
    gcc signal_alarm.c -o signal_alarm
    gcc signal_segfault.c -o signal_segfault
2. Run the program:
    ```
    ./signal_alarm
    ./signal_segfault
---

## Part 3: Advanced Signal Handling with `sigaction`
### `signal_sigaction.c`
- Demonstrates using the `sigaction` system call to register a handler for `SIGUSR1`.
- The handler retrieves and prints the PID of the process that sent the signal.
- Utilizes the `SA_SIGINFO` flag to access additional signal information.

### How to Run:
1. Compile the program:
   ```bash
    gcc signal_sigaction.c -o signal_sigaction
2. Run the program:
    ```
    ./signal_sigaction
---

## Part 4: Sending Data with `sigqueue`
### `recv_signal.c`
- Registers a handler for `SIGUSR1` using `sigaction`.
- The handler retrieves and prints a custom integer (`sival_int`) sent with the signal.

### `send_signal.c`
- Sends `SIGUSR1` along with a random integer to a specified process using `sigqueue`.
- The random integer is generated with `rand()` and seeded using `srand` and the current time.

### How to Run:
1. Compile the program:
   ```bash
    gcc recv_signal.c -o recv_signal
    gcc send_signal.c -o send_signal
2. Run the program:
    ```
    ./recv_signal
    ./send_signal <PID>
---