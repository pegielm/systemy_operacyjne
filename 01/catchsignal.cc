#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signum) {
    printf("Signal received: %d\n", signum);
}

int main() {

    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    signal(SIGUSR1, signalHandler);
    signal(SIGUSR2, signalHandler);

    printf("CatchSignal is running. PID: %d\n", getpid());
    while (1) {
        sleep(1);
    }

    return 0;
}
