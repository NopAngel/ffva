#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include "../include/regs.h"
#include "../include/disasm.h"
#include "../include/tracer.h"
#include <unistd.h>

void trace_all(pid_t pid) {
    int status;
    waitpid(pid, &status, 0);
    
    ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACEEXEC);
    ptrace(PTRACE_CONT, pid, NULL, NULL);
    waitpid(pid, &status, 0);
    
    int steps = 0;
    while(steps < 20 && WIFSTOPPED(status)) {
        printf("\n--- step %d ---\n", steps);
        show_regs(pid);
        disasm_inst(pid);
        
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        waitpid(pid, &status, 0);
        steps++;
    }
    
    printf("end\n");
}
