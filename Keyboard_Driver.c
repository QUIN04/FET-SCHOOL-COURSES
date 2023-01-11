#define PIC1_C 0x20
#define PIC1_D 0x21
#define PIC2_C 0xa0
#define PIC2_D 0xa1

#define ICW1_DEF 0x10
#define ICW1_ICW4 0x01
#define ICW4_x86 0x01
int CapsFlag;

void initIDT();
 extern void loadIdt();
 extern void isr1_Handler();
 void handleKeypress(int);
 void pressed(char);
 void picRemap();

 unsigned char inportb(unsigned short);
 void outportb(unsigned short , unsigned char);

struct IDT_ENTRY{
 unsigned short base_Lower;
 unsigned short selector;
 unsigned char zero;
 unsigned char flags;
 unsigned short base_Higher;
};

 struct IDT_ENTRY idt[256];
 extern unsigned int isr1;
 unsigned int base;

 void initIDT(){
 idt[1].base_Lower = (base & 0xFFFF);
 idt[1].base_Higher = (base >> 16) & 0xFFFF;
 idt[1].selector = 0x08;
 idt[1].zero = 0;
 idt[1].flags = 0x8e;
 picRemap();
 outportb(0x21 , 0xfd);
 outportb(0xa1 , 0xff);
 loadIdt();
 }
 unsigned char inportb(unsigned short _port){
 unsigned char rv;
 __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
 return rv;
 }

 void outportb(unsigned short _port, unsigned char _data){
 __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
 }
 extern void isr1_Handler(){
 handleKeypress(inportb(0x60));
 outportb(0x20 , 0x20);
 outportb(0xa0 , 0x20);
 }

 void handleKeypress(int code){
    EscVideo=code;
     char Scancode[] = {
         0 , 0 , '1' , '2' ,
         '3' , '4' , '5' , '6' ,
         '7' , '8' , '9' , '0' ,
         '-' , '=' , 0 , 0 , 'q' ,
         'w' , 'e' , 'r' , 't' , 'y' ,
         'u' , 'i' , 'o' , 'p' , '[' , ']' ,
          0 , 0 , 'a' , 's' , 'd' , 'f' , 'g' ,
         'h' , 'j' , 'k' , 'l' , ';' , '\'' , '`' ,
          0 , '\\' , 'z' , 'x' , 'c' , 'v' , 'b' , 'n' , 'm' ,
         ',' , '.' , '/' , 0 , '*' , 0 , ' '
     };
    char Scancode2[] = {
         0 , 0 , '1' , '2' ,
         '3' , '4' , '5' , '6' ,
         '7' , '8' , '9' , '0' ,
         '_' , '+' , 0 , 0 , 'Q' ,
         'W' , 'E' , 'R' , 'T' , 'Y' ,
         'U' , 'I' , 'O' , 'P' , '{' , '}' ,
          0 , 0 , 'A' , 'S' , 'D' , 'F' , 'G' ,
         'H' , 'J' , 'K' , 'L' , ':' , '\"' , '~' ,
          0 , '\\' , 'Z' , 'X' , 'C' , 'V' , 'B' , 'N' , 'M' ,
         '<' , '>' , '?' , 0 , '*' , 0 , ' '
     };

     if(code == 0x1c){
        if(TextEditorMode==0){
      char DoubleLine[]={"\n\n"};
      printString(DoubleLine);
      char OS[]="\nC:\\>";
      command[k]='\0';
      k=0;
      strEval(command);
      printString(OS);}
      else{
        printChar('\n');
        //At[]
      } 
     }
     
     else if(code==0x0E){
     BackSpace();
     k--;
     j--;
     }


     else if(code==0x01 && TextEditorMode==1){
     At[j]='\0';
     write();
     cls();
     int t;
     char Welcome3[] = "Welcome To FET_OS : Copyright 2022\n";
     char Welcome4[] = "Command Line Version 1.0.0.0\n\n";
     char Save[]= "\nYour Text Document was Saved\n";
     char OSM0[] = "C:\\>";
     printString(Welcome3);
     printString(Welcome4);
     printString(Save);
     printString(OSM0);
     //printString(Welcome3);
     TextEditorMode=0;
     j=0;
     k=0;
     }

     else if(code==0x4b)
     Left();
    else if(code==0x3a){
        if(CapsFlag==0)CapsFlag=1;
        else CapsFlag=0;
    }
     else if(code==0x4d)
     Right();

     else if(code < 0x3a){
     if(CapsFlag==0)pressed(Scancode[code]);
     else pressed(Scancode2[code]);
    }
}



 void pressed(char key){
 if(TextEditorMode==0){
    command[k]=key;
    k++;
 }
 else{
    At[j]=key;
    j++;
 }
 printChar(key);
 }


 void picRemap(){
 unsigned char a , b;
 a = inportb(PIC1_D);
 b = inportb(PIC2_D);

 outportb(PIC1_C , ICW1_DEF | ICW1_ICW4);
 outportb(PIC2_C , ICW1_DEF | ICW1_ICW4);

 outportb(PIC1_D , 0);
 outportb(PIC2_D , 8);

 outportb(PIC1_D , 4);
 outportb(PIC2_D , 2);

 outportb(PIC1_D , ICW4_x86);
 outportb(PIC2_D , ICW4_x86);

 outportb(PIC1_D , a);
 outportb(PIC2_D , b);
}

