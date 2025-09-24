#include <stdio.h>
#include <sys/ptrace.h>
#include <capstone/capstone.h>
#include "../include/disasm.h"

#define RIP 16

void disasm_inst(pid_t pid) {
    csh handle;
    cs_insn *insn;
    size_t count;
    
    long rip = ptrace(PTRACE_PEEKUSER, pid, 8*RIP, NULL);
    long code = ptrace(PTRACE_PEEKTEXT, pid, rip, NULL);
    
    if(cs_open(CS_ARCH_X86, CS_MODE_64, &handle) == CS_ERR_OK) {
        uint8_t code_bytes[8];
        for(int i=0; i<8; i++) code_bytes[i] = (code >> (i*8)) & 0xFF;
        
        count = cs_disasm(handle, code_bytes, 8, rip, 1, &insn);
        if(count > 0) {
            printf("asm: %s %s\n", insn[0].mnemonic, insn[0].op_str);
            cs_free(insn, count);
        }
        cs_close(&handle);
    }
}
