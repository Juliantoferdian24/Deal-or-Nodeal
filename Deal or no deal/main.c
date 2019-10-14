#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include <time.h>
#include"std.h"
int tema = 6;
int main()
{
    remove_scrollbar();
    splashscreen();
    fullscreen();
    loadingscreen();
    system("color 04");
    menu();
}

int menu()
{
    int posisi =1, key =0, xx=1, yy=1;
	int warna =6 ;
	if(tema ==1)
	{
		warna = 5;
	}
	else if(tema==2)
	{
		warna = 2;
	}
	else if(tema ==3)
	{
		warna = 6;
	}
	else if(tema == 4)
	{
		warna = 7;
	}
	system("cls");
    while(key!=13){
    fflush(stdin);
    normal();
    boxLine(3,0,160,10);
    gotoxy(2,2);
    header();

    boxFill(30,15,20,10,arrowmenu(1,xx,yy));

    boxFill(34,17,12,1,warna);
    boxFill(34,17,2,2,warna);
    boxFill(44,17,2,2,warna);
    boxFill(34,19,12,1,warna);
    boxFill(34,17,2,5,warna);

    gotoxy(34,24);
    printfColor(warna,arrowmenu(1,xx,yy),"PLAY GAME");


    boxFill(60,15,20,10,arrowmenu(2,xx,yy));

    boxFill(64,17,3,6,warna);
    boxFill(64,19,10,2,warna);
    boxFill(74,17,3,6,warna);

    gotoxy(67,24);
    printfColor(warna,arrowmenu(2,xx,yy),"HISTORY");

    boxFill(90,15,20,10,arrowmenu(3,xx,yy));

    boxFill(94,17,10,1,warna);
    boxFill(94,18,2,5,warna);
    boxFill(94,22,10,1,warna);

    gotoxy(97,24);
    printfColor(warna,arrowmenu(3,xx,yy),"CREDIT");

    boxFill(120,15,20,10,arrowmenu(4,xx,yy));

    boxFill(124,18,12,1,warna);
    boxFill(129,18,2,5,warna);

    gotoxy(127,24);
    printfColor(warna,arrowmenu(4,xx,yy),"THEME");

    //Help
    boxFill(30,26,20,10,arrowmenu(5,xx,yy));

    boxFill(34,28,3,6,warna);
    boxFill(34,30,11,2,warna);
    boxFill(44,28,3,6,warna);
    gotoxy(37,35);
    printfColor(warna,arrowmenu(5,xx,yy),"HELP ?");

    boxFill(60,26,20,10,arrowmenu(6,xx,yy));

    boxFill(64,28,10,1,warna);
    boxFill(64,29,2,5,warna);
    boxFill(64,33,10,1,warna);
    gotoxy(67,35);
    printfColor(warna,arrowmenu(6,xx,yy),"CHECK UPDATE");

    boxFill(90,26,20,10,arrowmenu(7,xx,yy));

    boxFill(94,28,10,1,warna);
    boxFill(94,28,2,5,warna);
    boxFill(94,30,10,1,warna);
    boxFill(94,32,10,1,warna);

    gotoxy(97,35);
    printfColor(warna,arrowmenu(7,xx,yy),"EXIT");
        key=getch();
        if(key == 77 && xx != 4){
          xx++;
        }
        else if(key == 75 && xx != 1){
          xx--;
        }
        else if(key == 75 && xx == 1){
          xx = 4;
        }
        else if(key == 77 && xx == 4){
          xx = 1;
        }
        else if(key == 72 && yy != 1){
          yy--;
        }
        else if(key == 80 && yy != 2){
          yy++;
        }
        else if(key == 72 && yy == 1){
          yy = 2;
        }
        else if(key == 80 && yy==2){
          yy = 1;
        }
        else{
          yy = yy;
          xx = xx;
        }
    }
   posisi= xx+((yy-1)*4);
  if (posisi==1)
  {
      game();
  }
  else if (posisi==2)
  {
      history();
  }
  else if (posisi==3)
  {
      PlaySound("C:\\Deal or no deal\\music\\Deal or No Deal Cues - Banker's Theme-Small Offer.wav", NULL, SND_FILENAME|SND_ASYNC|SND_APPLICATION|SND_LOOP);
      credit();

  }
   else if (posisi==4)
  {
      theme();
  }
  else if (posisi==5)
  {
      rules();
  }
  else if (posisi==6)
  {
      updateapps();
  }
  else if (posisi==7)
  {
      thankyou();
      return 0;
  }
}
int theme()
{
    char awal[4][20]={"BLACK PURPLE", "BLACK GREEN","BLACK YELLOW", "BLACK WHITE"};
    int  key = 0, a;
    tema = 1;
    while(key != 13){
    fflush(stdin);
    system("cls");
    normal();
    header();
    printf("\n\n\n\n\t\t\t\t\t\t\t\tSELAMAT DATANG! SILAHKAN PILIH SALAH SATU TEMA\n\n");
    for(a = 0; a < 4; a++){
      arrowmenu1(a + 1, tema);
      printf("\n\t\t\t\t\t\t\t\t\t\t%s \n", awal[a]);
      printf("\t\t\t\t\t\t\t\t\t      $$$$$$$$$$$$$$$\n");
    }
    footer();
    key = getch();
    if(key == 80 && tema != 4){
      tema++;
    }
    else if(key == 72 && tema != 1){
      tema--;
    }
    else if(key == 72 && tema == 1){
      tema = 4;
    }
    else if(key == 80 && tema == 4){
      tema = 1;
    }
  }
  fflush(stdin);
    if(tema==1)
    {
        system("color 05");
        system("pause");
        menu();
    }
    if(tema==2)
    {
        system("color 0A");
        system("pause");
        menu();
    }
    if(tema==3)
    {
        system("color 06");
        system("pause");
        menu();
    }
    if(tema==4)
    {
        system("color 07");
        system("pause");
        menu();
    }
}
int game()
{
	PlaySound("C:\\Deal or no deal\\music\\Custom Deal or No Deal Cues - Opening Cases.wav", NULL, SND_FILENAME|SND_ASYNC|SND_APPLICATION|SND_LOOP);
    int pilihan;
    int koper[4][5] = {
    {1, 5, 10, 25, 50},
    {100, 300, 500, 1000, 5000},
    {10000, 15000, 25000, 50000, 75000},
    {100000, 300000, 500000, 750000, 1000000}
    };
    int scan[4][5] = {};
    int a,b,d;
    int x,y;
    fflush(stdin);
    system("cls");
    FILE *p ;
    p=fopen("C:\\Deal or no deal\\data\\scan.txt","w+");
    for( x = 0; x < 4; x++){
	    for( y = 0; y < 5; y++){
            	scan[x][y]=0;
		}
    }
    for( a = 0; a < 4; a++){
    	for( b = 0; b < 5; b++){
        		fprintf(p, "%d", scan[a][b]);
	      	}
	   }
    fclose(p);
    int n;
    n = sizeof(koper)/ sizeof(koper[0][0]);
    randomize(koper,n);
    posisikoper(koper);
}

int history()
{
    system("cls");
    logohistory();
    char s;
    FILE *fp;
    fp= fopen("C:\\Deal or no deal\\data\\username.txt","r");
    boxLine(2,10,165,20);
    boxLine(2,11,165,19);
    gotoxy(11,11);
	if(fp==NULL)
	{
		printf("\nCAN NOT OPEN FILE");
		getch();
	}
	do
{
		s=getc(fp);
		printf("%c",s);
	}
	while(s!=EOF);
	fclose(fp);
	getch();
	menu();
}
int loadingscreen()
{
 int r, q;
 int x;
 double y;
 char name1[] = "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPESAN KESEHATAN: \n\t\t\t\t1.Jangan melihat layar terlalu dekat.\n\t\t\t\t2.Ingatlah waktu selagi anda bermain, jangan sampai anda lupa makan dan minum.\n\t\t\t\t3.Jagalah emosi anda selama bermain agar tidak stress. Ini hanya permainan.\n\t\t\t\tTujuan game ini adalah untuk menghibur dan menghilangkan kebosanan anda. Maka dari itu kami perhatian dengan kesehatan anda\n";
 gotoxy(10,15);
 printf("\n\n\n\t\t\t\t\t\t\t\t\t\tLoading...\n\t\t\t\t\t\t\t\t\t");
 for(r=1;r<=25;r++){
  for(q=0;q<=10000000;q++);
  printf("%c", 139);
 }
 system("cls");
 printf("\n\n");
     boxBorder(2,10,165,20,3,3,3);
     gotoxy(2,10);
    for(x=0; name1[x]!=NULL; x++)
   {
        printf("%c",name1[x]);

      for(y=0; y<=1000000; y++)
      {

      }
   }
    printf("\n\t\t\t\t");
    system("pause");
    system("cls");
    sponsor();
    Sleep(2000);
    system("cls");
    boxFill(75,0,20,48,4);
    boxFill(0,20,170,10,7);
    Sleep(3000);
    system("cls");
}

