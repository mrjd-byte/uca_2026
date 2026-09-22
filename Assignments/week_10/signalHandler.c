#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

void handle_sigint(int sig) {
    signal_count++;

    if (signal_count < 3) {
        write(STDOUT_FILENO,
              "SIGINT received! Keep pressing Ctrl+C...\n",
              41);
    } else {
        write(STDOUT_FILENO,
              "SIGINT received 3 times. Exiting...\n",
              36);
        _exit(0);
    }
}

int main() {

    signal(SIGINT, handle_sigint);

    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}