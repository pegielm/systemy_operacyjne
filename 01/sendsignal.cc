#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <PID> <signal>\n", argv[0]);
        return 1;
    }

    pid_t dest_pid = atoi(argv[1]);
    int signal_num = atoi(argv[2]);

    if (kill(dest_pid, signal_num) == 0) {
        printf("Signal %d sent to process %d\n", signal_num, dest_pid);
    } else {
        perror("Error sending signal");
        return 1;
    }

    return 0;
}
