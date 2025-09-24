#include <stdio.h>
#include <sys/ptrace.h>
#include "../include/regs.h"

#define RIP 16
#define RAX 10
#define RBX 11

void show_regs(pid_t pid) {
    long rax = ptrace(PTRACE_PEEKUSER, pid, 8*RAX, NULL);
    long rbx = ptrace(PTRACE_PEEKUSER, pid, 8*RBX, NULL);
    long rip = ptrace(PTRACE_PEEKUSER, pid, 8*RIP, NULL);
    printf("\033[1;36mregs:\033[0m ");
    printf("rip=\033[1;32m%lx\033[0m ", rip);
    printf("rax=\033[1;34m%lx\033[0m ", rax);
    printf("rbx=\033[1;35m%lx\033[0m\n", rbx);
}
