#include "./Graphic_Driver.c" 
#include "./Shell.c"
#include "./Keyboard_Driver.c"
//#include "./HardDisk_Driver.c"

int Kernel(){

       k=0;
       CapsFlag=0;
       TM_START = (char*) 0xb8000;
       EscVideo=0;
       CELL = 0;
       TextEditorMode=0;
       j=0;
       x=0;
       y=0;

       base = (unsigned int)&isr1;

       cls();
       theme=0x0f;
       setMonitorColor(theme);
       char BootUpdate[]="BOOTING COMPLETED...\n\n";
       char Welcome[] = "Welcome To FET_OS : Copyright 2022\n";
       char Welcome2[] = "Command Line Version 1.0.0.0\n\n";
       char OSM[] = "C:\\>";

       printColorString(BootUpdate, 0x05);
       printString(Welcome);
       printString(Welcome2);
       printColorString(OSM , 0x0f);
   
       initIDT();
}
