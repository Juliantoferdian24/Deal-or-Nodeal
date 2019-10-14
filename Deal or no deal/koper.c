#include<stdio.h>
#include<windows.h>
int l=1,i=1,r,mykoper=1,nilaikoper;
void posisikoper(int array[4][5]){
  fflush(stdin);
  char kursi[4][5]={
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20}
  };
  int scan[4][5] = {};
    int a = 0, b = 0, key = 0, xx = 1, yy = 1;
    while(key != 13){
    system("cls");
    fflush(stdin);
     FILE *p ;
    p=fopen("C:\\Deal or no deal\\data\\scan.txt","r");
    int x,y,z;
    for( x = 0; x < 4; x++){
      for( y = 0; y < 5; y++){
          fscanf(p, "%1d", &scan[x][y]);
      }
    }
    fclose(p);
    normal();
    header();
    boxLine(40,10,90,20);
    gotoxy(2,15);
    if (mykoper==1)
    {
        printf("\n\t\t\t\t\t\t\t\t\tPILIH KOPER YANG INGIN ANDA TAHAN\n\n\n");
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\t\tPILIH KOPER YANG ANDA INGIN ANDA BUKA\n\n\n");
    }
    normal();
    for(a = 0; a < 4; a++){
      for(b = 0; b < 5; b++){
        arrow(a + 1, b + 1, xx, yy);
        if(b == 0){
          printf("\t\t\t\t\t\t\t\t\t   ");
        }
        if((a == 0 || a == 1) && b < 4){
          if(scan[a][b] == 1){
            printf("[ %d] ", kursi[a][b]);
          }
          else{
            printf("  %d  ", kursi[a][b]);
          }
        }
        else{
          if(scan[a][b] == 1){
            printf("[%d] ", kursi[a][b]);
          }
          else{
            printf(" %d  ", kursi[a][b]);
          }
        }
        if(b == 4){
          printf("  ");
        }
      }
      printf("\n\n");
    }
        printf("\n\n\n");
        footer();
        key = getch();

        if(key == 80 && xx != 4){
          xx++;
        }
        else if(key == 72 && xx != 1){
          xx--;
        }
        else if(key == 72 && xx == 1){
          xx = 4;
        }
        else if(key == 80 && xx == 4){
          xx = 1;
        }
        else if(key == 75 && yy != 1){
          yy--;
        }
        else if(key == 77 && yy != 5){
          yy++;
        }
        else if(key == 75 && yy == 1){
          yy = 5;
        }
        else if(key == 77 && yy){
          yy = yy;
        }
        else{
          yy = yy;
          xx = xx;
        }
    }
    scankoper(array,xx, yy);
  }


int scankoper(int array[4][5],int xx, int yy){

    fflush(stdin);
  int ta[4][5] = {}, key = 0;
  FILE *baca;
baca=fopen("C:\\Deal or no deal\\data\\scan.txt","r");
int a,b,d;
  for( a = 0; a < 4; a++){
    for( b = 0; b < 5; b++){
        fscanf(baca, "%1d", &ta[a][b]);
    }
  }
  fclose(baca);
  if(ta[xx - 1][yy - 1] == 1){
    hijau();
    printf("\n\n\t\t\t\t\t\t\t\t\t  KOPER SUDAH DIBUKA \n\n");
    printf("\n\t\t\t\t\t\t\t\t       KEMBALI KE MENU SEBELUMNYA\n");
    printf("\t\t\t\t\t\t\t\t      ============================\n");
    normal();
    key = getch();
    posisikoper(array);
  }
  else{
    ta[xx - 1][yy - 1] = 1;
    hijau();
    if(mykoper==1)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t KOPER DITAHAN \n\n");
        printf("\n\n\t\t\t\t\t\t\t\t\tANDA TELAH MEMILIH KOPER NOMOR %d",(xx-1)*5+(yy));
        nilaikoper=array[xx-1][yy-1];
        l--;
       mykoper++;
    }
    else
    {
        mykoper++;
        printf("\n\n\t\t\t\t\t\t\t\t\t\t MEMBUKA KOPER \n\n");
        normal();
        count();
        printf("\n\n\t\t\t\t\t\t\t\t\tANDA TELAH MEMBUKA KOPER SENILAI $ %d\n\t\t\t\t\t\t\t\t\t",array[xx-1][yy-1]);
    }
    merah();
    printf("\n\t\t\t\t\t\t\t\t\t\t LANJUT\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t========\n");
    normal();
    key = getch();
  }
  FILE *tulis;
        tulis=fopen("C:\\Deal or no deal\\data\\scan.txt","w");
  for( a = 0; a < 4; a++){
    for( b = 0; b < 5; b++){
        fprintf(tulis, "%d", ta[a][b]);
    }
  }
  fclose(tulis);
  if (l==5)
  {
    int offer[10]={500, 1000, 5000, 10000, 15000, 25000, 50000, 75000, 100000, 300000};
    PlaySound("C:\\Deal or no deal\\music\\Deal or No Deal Cues - Large Offer.wav", NULL, SND_FILENAME|SND_ASYNC);
    int r = rand() % 10;
    char awal[2][20]={"    DEAL    ", "  NO DEAL"};
    int b = 1, key = 0,a;
    while(key != 13){
    fflush(stdin);
    system("cls");
    normal();
    bankeroffer();
    printf("\n\t\t\t\t\t\t\t\t\t\tOFFER   : $ %d",offer[r]);
    printf("\n\t\t\t\t\t\t\t\t\t\tDEAL OR NO DEAL ?\n\n");
    for(a = 0; a < 2; a++){
      arrowmenu1(a + 1, b);
      printf("\n\t\t\t\t\t\t\t\t\t\t%s \n", awal[a]);
      printf("\t\t\t\t\t\t\t\t\t      $$$$$$$$$$$$$$$\n");
    }
    footer();
    key = getch();
    if(key == 80 && b != 4){
      b++;
    }
    else if(key == 72 && b != 1){
      b--;
    }
    else if(key == 72 && b == 1){
      b = 4;
    }
    else if(key == 80 && b == 4){
      b = 1;
    }
  }
    if(b==1)
    {
        normal();
        count();
        mykoper=1;
        system("cls");

        int j;
        if(nilaikoper>offer[r])
        {
            PlaySound("C:\\Deal or no deal\\music\\Was it a Good Deal-Case Holds.wav", NULL, SND_FILENAME|SND_ASYNC);
            boxBorder(2,10,165,40,3,3,3);
            gotoxy(2,14);
        printf("\t\t\t\t\t\t\t\tNILAI KOPER YANG ANDA TAHAN ADALAH $ %d\n",nilaikoper);
            gotoxy(2,15);
            baddeal();
            printf("\n\t\t\t\t\t\t\tSELAMAT ANDA MEMBAWA HADIAH SEBESAR $ %d\n",offer[r]);
            printf("\t\t\t\t\t\t\t");
            system("pause");
            j=1;
        }
        else
        {
            PlaySound("C:\\Deal or no deal\\music\\Deal or No deal Cues - Big Deal.wav", NULL, SND_FILENAME|SND_ASYNC);
            boxBorder(2,10,165,30,3,3,3);
            gotoxy(2,14);
        printf("\t\t\t\t\t\t\t\tNILAI KOPER YANG ANDA TAHAN ADALAH $ %d\n",nilaikoper);
            gotoxy(2,15);
            gooddeal();
            printf("\n\t\t\t\t\t\t\tSELAMAT ANDA MEMBAWA HADIAH SEBESAR $ %d\n",offer[r]);
            j=2;
            printf("\t\t\t\t\t\t\t");
            system("pause");
        }
        char name[1000];
        FILE *fptr;
        fptr=fopen("C:\\Deal or no deal\\data\\username.txt","a");
        if(fptr == NULL)
        {
            printf("Error!");
            exit(1);
        }
        printf("\t\t\t\t\t\t\t(MAX 7 KARAKTER)\n");
        printf("\t\t\t\t\t\t\tUsername : ");
        scanf("%s",name);
        printf("\t\t\t\t\t\t\t");
        system("pause");
        if(j==1)
        {
            fprintf(fptr,"\t\t\t\t\t\t\t%s\t\t\t%d\t\tBAD DEAL\n", name,offer[r]);
        }
        else if(j==2)
        {
            fprintf(fptr,"\t\t\t\t\t\t\t%s\t\t\t%d\t\tGOOD DEAL\n", name,offer[r]);
        }
        fclose(fptr);
        menu();
    }
    else
    {
        i++;
        l = i;
        posisikoper(array);
    }
            r++;
  }
        l++;
    fflush(stdin);
  posisikoper(array);
}
