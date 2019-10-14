#include <stdio.h>
#include <windows.h>
#include <math.h>



void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void boxLine(const int posX, const int posY, const int sizeX, const int sizeY){
   gotoxy(posX,posY);
   printf("%c",218);
   int a;
   for(a=posX;a<posX+sizeX;a++ )printf("%c",196);
   gotoxy(posX+sizeX,posY);
   printf("%c",191);
   for(a=posY+1;a<posY+sizeY+1;a++){
       gotoxy(posX,a);
       printf("%c",179);
       gotoxy(posX+sizeX,a);
       printf("%c",179);
   }
   gotoxy(posX,posY+sizeY+1);
   printf("%c",192);
   for(a=posX;a<posX+sizeX;a++ )printf("%c",196);
   gotoxy(posX+sizeX,posY+sizeY+1);
   printf("%c",217);
}

void printfColor(int ForgC,int BackC,const char *val, ...){
	va_list arg_list;
	int my_arg;
	va_start(arg_list, &val);
    int charlen=strlen(val);
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	for (my_arg = 0; my_arg<charlen; my_arg++){
        if(val[my_arg]=='%'){
            int r=0;
            char value[16];
            while(my_arg<charlen){
                value[r]=val[my_arg];
                value[r+1]=0;
                if(val[my_arg]=='d'||val[my_arg]=='c'||val[my_arg]=='s'){
                    printf(value, va_arg(arg_list, int));
                    break;
                }
                else if(val[my_arg]=='f'){
                    printf(value, va_arg(arg_list, double));
                    break;
                }
                my_arg++;r++;
            }
        }
        else if(val[my_arg]!='%')printf("%c",val[my_arg]);
	}
	va_end(arg_list);
	SetConsoleTextAttribute ( h, wOldColorAttrs);
}

void boxFill(const int posX, const int posY, const int sizeX, const int sizeY, const int colorBg){
	int a,b;
    for(a=0;a<sizeY;a++){
		gotoxy(posX, posY+a);
		for(b=0;b<sizeX;b++){
			printfColor(3, colorBg, " ");
		}
		printf("\n");
	}
}

void boxBorder(const int posX, const int posY, const int sizeX, const int sizeY, const int colorBg, const int tebelX, const int tebelY){
	int a,b;
    for(a=0;a<sizeY;a++){
    	if(a<tebelY || a>=sizeY-tebelY){
    		gotoxy(posX, posY+a);
			for(b=0;b<sizeX;b++){
				printfColor(2, colorBg, " ");
			}
			printf("\n");
		}
		else{
			gotoxy(posX, posY+a);
			for(b=0;b<sizeX;b++){
				if(b<tebelX || b>=sizeX-tebelX){
					printfColor(2, colorBg, " ");
				}
				else{
					printfColor(2, 0," ");
				}
			}
			printf("\n");
		}

	}
}

void clear()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 40, 45 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

