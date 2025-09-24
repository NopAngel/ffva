CC = gcc
FLAGS = -lcapstone



compile:
	$(CC) -o ffva src/ffva.c src/regs.c src/tracer.c src/disasm.c $(FLAGS)
	./ffva
