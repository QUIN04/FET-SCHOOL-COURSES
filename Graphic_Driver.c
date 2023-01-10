 #define SCREEN_WIDTH 80

 void cls(); //clear screen
 void setMonitorColor(char);//sets background Color
 void printString(char*);//Prints String
 void printChar(char); //Prints A Character to String

 void scroll();//Scroll view

 void printColorString(char* , char);//Render Colored String
 void printColorChar(char , char);//Render Colored Character
 void getDecAscii(int);//Prints Ascii value of integer
 void update_cursor(int, int);

void outport(unsigned short _port, unsigned char _data){
 __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
 }


 char* TM_START;
 char NumberAscii[10];
 int CELL;
 int x;
 int y;


 void cls(){
 int i = 0;
 CELL = 0;
 while(i < (2 * 80 * 25)){
 *(TM_START+i) = ' '; // Clear screen
 i += 2;
 }
 x=0;
 y=0;
update_cursor(x,y);
 }

 void setMonitorColor(char Color){
 int i = 1;
 while(i < (2 * 80 * 25)){
 *(TM_START + i) = Color;
 i += 2;
 }
 }

 void printString(char* cA){
 int i = 0;
 while(*(cA + i) != '\0'){
 printChar(*(cA + i));
 i++;
 }
 }

 void printChar(char c){
 if(CELL == 2 * 80 * 25)
 scroll();
 if(c == '\n'){
 CELL = ((CELL + 160) - (CELL % 160));
 y++;
 x=0;
 update_cursor(x,y);
 return;
 }
 *(TM_START + CELL) = c;
  CELL += 2;
  x++;
  update_cursor(x,y);
 }

 void scroll(){
 int i = 160 , j = 0;
 while(i < 2 * 80 * 25){
 *(TM_START + j) = *(TM_START + i);
 i += 2;
 j += 2;
 }
 CELL = 2 * 80 * 24;
 i = 0;
 while(i < 160){
 *(TM_START + CELL + i) = ' ';
 i += 2;
 }
 }

 void printColorString(char* c , char co){
 int i = 0;
 while(*(c + i) != '\0'){
 printColorChar(*(c + i) , co);
 i++;
}
}

 void printColorChar(char c , char co){
 if(CELL == 2 * 80 * 25)
 scroll();
 if(c == '\n'){
 CELL = ((CELL + 160) - (CELL % 160));
 y++;
 x=0;
 update_cursor(x,y);
 return;
  }
*(TM_START + CELL) = c;
*(TM_START + CELL + 1) = co;
 CELL += 2;
 update_cursor(x,y);
 x++;
 }

 void getDecAscii(int num){
 if(num == 0){
 NumberAscii[0] = '0';
 return;
 }
 char NUM[10];
 int i = 0 , j = 0;
 while(num > 0){
 NUM[i] = num % 10;
 num /= 10;
 i++;
 }
 i--;
 while(i >= 0){
 NumberAscii[j] = NUM[i];
 i--;
 j++;
 }
 NumberAscii[j] = 'J';
 j = 0;
 while(NumberAscii[j] != 'J'){
 NumberAscii[j] = '0' + NumberAscii[j];
 j++;
 }
 NumberAscii[j] = 0;
 }

 void BackSpace(){
    if(*(TM_START + CELL-2)!='>' && *(TM_START + CELL-2)!='\\')
    {*(TM_START+CELL-2)=' ';
     CELL-=2;
     if(x>0){
       x--;
     update_cursor(x,y); 
      }
      else{
      y--;
      x=80;
      update_cursor(x,y);
      }
     
 }
 }

 void update_cursor(int i, int j){

    unsigned short pos =j*SCREEN_WIDTH+i;
    outport(0x3d4, 0x0f);
    outport(0x3d5, (unsigned char) (pos & 0xff));
    outport(0x3d4, 0x0e);
    outport(0x3d5, (unsigned char) ((pos >> 8) & 0xff));
 }

  void Left(){
    if(*(TM_START + CELL-2)!='>' && *(TM_START + CELL-2)!='\\'){
     x--;
     update_cursor(x,y);
     CELL-=2;
    }
 }

 void Right(){
    int k=0;
    int Checker=CELL;
    while(Checker<2*80*25){
        if(*(TM_START + Checker)!=' ')
            k=1;
            break;
    }
    if(k==1){
    x++;
    update_cursor(x,y);
    CELL+=2;
    }
 }


