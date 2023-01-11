  START:
 [bits 32] ; Makes assembler readjusts all opcodes to 32bits
 [extern _Kernel]; imports our c Kernel method
 call _Kernel; calls the Kernel since it is a method
 jmp $; jump to self to prevent unwanted execution of code that may set computer to unstable state