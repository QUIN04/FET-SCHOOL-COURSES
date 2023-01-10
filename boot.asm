 [org 0x7c00]
 [bits 16]
  mov ah, 0x0b ;Load Bios color modification routine
  mov bh, 0x00 ;
  mov bl, 0x01 ; Set color to Background color of bootscreen to Blue(0x01)
  int 0x10; Bios interrupt to display on screen
  
  mov ah, 0x0e ; Load Bios scroll teletyping routine so we can print characters
  mov al, 'L'  ; Load character 'L'
  int 0x10     ; Bios interrupt to disaply Loaded character on screen
  mov al, 'O'
  int 0x10
  mov al, 'A'
  int 0x10
  mov al, 'D'
  int 0x10
  mov al, 'I'
  int 0x10
  mov al, 'N'
  int 0x10
  mov al, 'G'
  int 0x10
  mov al, ' '
  int 0x10
  mov al, 'O'
  int 0x10
  mov al, 'S'
  int 0x10
  mov al, '.'
  int 0x10
  mov al, '.'
  int 0x10
  mov al, '.'
  int 0x10
  
  mov bx , 0x1000 ; Memory offset to which kernel will be loaded
  mov ah , 0x02 ; Bios Read Sector Function
  mov al , 40   ; Assume our boot sector will occupy just 40 HDD sectors for now(40 x 512bytes)
  mov ch , 0x00 ; Select Cylinder 0 from harddisk; the very first drive cylinder
  mov dh , 0x00 ; Select head 0 from hard disk; the first disk head
  mov cl , 0x02 ; Start Reading from Second sector(Sector just after boot sector) where kernel image is found

  int 0x13 ; Bios Interrupt to read from disk

  
 ;Switch To Protected Mode
 cli ; Turns Bios Interrupts off so OS can only use drivers to produce interrupts; Bios routines can only be used in real mode
 lgdt [GDT_DESC] ; Loads Our GDT
 
 mov eax , cr0; cr0 is a 1 bit flip-flop 0=16bit mode and 1=32bit mode
 or eax , 0x1; Peform an  OR to set it to 1
 mov cr0 , eax ; Switch To Protected Mode

 jmp CODE_SEG:INIT_PM ; Jumps To Our 32 bit Code
 ;Forces the cpu to flush out contents in cache memory

 [bits 32]

 INIT_PM:
 mov ax , DATA_SEG
 mov ds , ax
 mov ss , ax
 mov es , ax
 mov fs , ax
 mov gs , ax

 mov ebp , 0x90000
 mov esp , ebp ; Updates Stack Segment
 
 call 0x1000; hands execution to kernel in loaded location after being read

 jmp $ ;Endless jump to self to ensure padded zeros are not executed which may place machine in an Unwanted State

 GDT_BEGIN:

 GDT_NULL_DESC: ;The Mandatory Null Descriptor
 dd 0x0
 dd 0x0

 GDT_CODE_SEG:
 dw 0xffff ;Limit
 dw 0x0 ;Base
 db 0x0 ;Base
 db 10011010b ;Flags
 db 11001111b ;Flags
 db 0x0 ;Base

 GDT_DATA_SEG:
 dw 0xffff ;Limit
 dw 0x0 ;Base
 db 0x0 ;Base
 db 10010010b ;Flags
 db 11001111b ;Flags
 db 0x0 ;Base

 GDT_END:

 GDT_DESC:
 dw GDT_END - GDT_BEGIN - 1
 dd GDT_BEGIN

 CODE_SEG equ GDT_CODE_SEG - GDT_BEGIN
 DATA_SEG equ GDT_DATA_SEG - GDT_BEGIN
  
  times 510-($-$$) db 0 ; pads the reaming bytes with 0's up to 510byte
  dw 0xaa55; define last 2 word completing 512byte