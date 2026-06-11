#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/tracer.h"
#include "../include/version.h"
#include <sys/ptrace.h>

void _splash() {
    printf("\033[1;31mF F\033[1;34m V A \n");
    printf("\033[1;34mFucking Fast Visual ASM v%s\n", VERSION_COMPLETE);

    printf("\033[1;90mby: <NopAngel>      LICENSE GPL-2.0 \033[0m\ \n\n\2");
}

int main(int argc, char **argv) {
    _splash();
    if(argc < 2) {
        printf("use: %s <prog>\n", argv[0]);
        return 1;
    }
    
    pid_t pid = fork();
    if(pid == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execvp(argv[1], &argv[1]);
        perror("\033[1;31mexec fail.");
        exit(1);
    } else {
        trace_all(pid);
    }
    
    return 0;
}
