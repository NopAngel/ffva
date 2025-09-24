## FFVA - Fucking Fast Visual ASM

It's a CLI app that allows you to view the assembly of an application.

This CLI application does NOT harm your computer (I mean, it won't crash it).

It's designed to be able to see "another part of the code," that is, to be able to do "reverse engineering" or verify whether an application is sending the data it requires.

### HOW TO INSTALL

To use the application, you'll need GCC and CAPSTONE installed, then compile the application.

```bash
sudo pacman -S gcc # if you have Arch/Manjaro
make
```

That's it! You should now have FFVA compiled on your PC.

### HOW TO USE

To use the application is as simple as putting "./ffva <process>", something that is important to emphasize, the process does not refer to the
PID of the application, but the name of the application (literally), eg:
```bash
./ffva firefox
``` 
