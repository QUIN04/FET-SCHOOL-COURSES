//#include "./Keyboard_Driver.c"
void vid();
//void strcmp(char*, char*);
void strEval(char*);
extern void read();
extern void write();
void textEditor();
int getLoctation(char);

int TextEditorMode;
int j;
int blockAddr;
char At[512];
int k;
int EscVideo;
char command[512];
char theme;

char strcmp(char* sou , char* dest){
int i = 0;
while(*(sou + i) == *(dest + i)){
if(*(sou + i) == 0 && *(dest + i) == 0)
return 1;
i++;
}
 return 0;
}

void strEval(char* CMD){
 
char cmd1[] = "Clear_Screen";
char cmd2[] = "white theme";
char cmd3[] = "blue theme";
char cmd4[] = "red theme";
char cmd5[] = "green theme";
char cmd10[]= "yellow theme";
char cmd11[]= "gray theme";
char cmd6[] = "vid";
char cmd7[] = "--version";
char cmd8[] = "store";
char cmd9[] = "retrieve";

 char msg1[] = "\n\nFET_OS Command_line version 1.0.0.0\nCopyright 2023\n";
 if(strcmp(CMD , cmd1))
 cls();

 else if(strcmp(CMD , cmd2)){
 setMonitorColor(0xf8);
 theme=0xf8;	
 }
 

 else if(strcmp(CMD , cmd3)){
 setMonitorColor(0x0f);
 theme=0x0f;
}

 else if(strcmp(CMD , cmd4)){
 setMonitorColor(0x4f);
 theme=0x4f;
 }
 else if(strcmp(CMD , cmd5)){
  setMonitorColor(0x28);
  theme=0x28;
 }
else if(strcmp(CMD , cmd10)){
setMonitorColor(0xe8);
 theme=0xe8;
}
else if(strcmp(CMD , cmd11)){
 setMonitorColor(0x8f);
 theme=0x8f;
}

 else if(strcmp(CMD , cmd6))
 vid();
 else if(strcmp(CMD , cmd7))
 printString(msg1);
 else if(strcmp(CMD , cmd8)){
 //blockAddr = 0;
 //int i = 0;
 textEditor();
}
 else if(strcmp(CMD , cmd9)){
 
 blockAddr = 3;
 read();
 printString(At);
 }

else {
	char Error[]=" Command is invalid";
	char st[]="\n\n\"";
	printString(st);
	printString(CMD);
	printChar('\"');
	printString(Error);
	printChar('\n');

}
 }


 void vid(){
 int z=0;
 char clr = 'A';                                                           
 while(z!=2000){
 int i = 0;
 while(i < 2 * 80 * 25){
 *(TM_START + i) = clr;
 clr++;
 i++;
 }
 z++;
 }
 cls();
 setMonitorColor(theme);
 char Welcome[] = "Welcome To FET_OS : Copyright 2022\n";
 char Welcome2[] = "Command Line Version 1.0.0.0\n\n";
 printString(Welcome);
 printString(Welcome2);
 }

 void textEditor(){
    At[0]='3';
    //char LocationToSave[]={"\nEnter Location to Save"};
    //char BootLaoderWarn[]={"\nBootLoader can get currupted\n"};
    //printString(LocationToSave);
    //if(At[0]=='0')printString(BootLaoderWarn);
    cls();
    blockAddr=getLoctation(At[0]);
    j=0;
    TextEditorMode=1;
    char doubleLine[]={"\n\n"};
    char Title[]={"    -------- TEXT EDITOR --------"};
    printString(doubleLine);
    printString(Title);
    printString(doubleLine);
 }


 int getLoctation(char loc){
     int locate=loc-'0';
     getDecAscii(locate);
     return locate;
 }