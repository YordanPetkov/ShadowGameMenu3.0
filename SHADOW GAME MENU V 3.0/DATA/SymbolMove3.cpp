#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std;
namespace SMgame
{
int x1=1,y1=1,x2=15,y2=50,fire[16][51],n,m,k,brfire=0,pl;
int lt1=2,lt2=1;
bool Exit=false;
bool moves1pl();
bool moves2pl();
void visualGame(int x1,int y1,int x2,int y2);
int coutBG(string AEs);
void coutChar(int n,char c);
int SMg()
{
    system("cls");
    srand(time(NULL));
      nm:
      coutChar(35,' ');coutBG("ZDRAVEYTE");cout<<endl;
      coutChar(34,' ');coutBG("VIE IGRAETE");cout<<endl;
      coutChar(30,' ');coutBG("SIMVOLNO DVIJENIE 2");cout<<endl;
      cout<<endl;
      cout<<endl;
      coutBG("VUVEDI KOLKO DA E GOLQMA TABLICATA n*m I DALE4NOSTTA NA KUR6UMITE k");cout<<endl;cout<<"( 5<n<16,5<m<51,2<k<n ,2<k<m ):"<<endl;
      cout<<"n=";cin>>n;cout<<"m=";cin>>m;cout<<"k=";cin>>k;
      if(n>15 || m>50 || n<6 || m<6 || k>=n || k>=m){system("cls");goto nm;}
      coutBG("IZBERI ZA 1 ILI ZA 2 IGRA4I DA E IGRATA :");cout<<endl;
      cout<<"1-> ";coutBG("NATISNI ");cout<<"1"<<endl;
      cout<<"2-> ";coutBG("NATISNI ");cout<<"2"<<endl;
      int pl1or2;
      p1or2:
      pl1or2=getch();
      if(pl1or2==50)//2
      {
          pl=2;
          x2=n;
          y2=m;
          system("cls");
          visualGame(x1,y1,x2,y2);
          int i=1;
          while(i==1)
          {
                if(!moves1pl())i=2;
          }
      }
      else
      {
            if(pl1or2==49)//1
            {
                pl=1;
                x2=n;
          y2=m;
          system("cls");
          visualGame(x1,y1,x2,y2);
          int i=1;
          while(i==1)
          {
                if(!moves2pl())i=2;
          }
            }
            else goto p1or2;
      }
      system("cls");

      return 0;
}

bool moves1pl()
{
    if(Exit)return false;
    start:
    char turn;
    turn = getch();
    switch(turn)
    {
    case 27 :
        return false;
        break;
    case 72 :lt1=1;
        if(x1!=1 && fire[x1-1][y1]==0){x1--;}
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 80 :lt1=2;
        if(x1!=n && fire[x1+1][y1]==0){x1++;}
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 75 :lt1=3;
        if(y1!=1 && fire[x1][y1-1]==0){y1--;}
         else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 77 :lt1=4;
        if(y1!=m && fire[x1][y1+1]==0){y1++;}
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 119 :lt2=1;
        if(x2!=1 && fire[x2-1][y2]==0){x2--;}
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 115 :lt2=2;
        if(x2!=n && fire[x2+1][y2]==0){x2++;}
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 97 :lt2=3;
        if(y2!=1 && fire[x2][y2-1]==0){y2--;}
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 100 :lt2=4;
        if(y2!=m && fire[x2][y2+1]==0){y2++;}
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 13 :
        switch(lt1)
        {
        case 1 :
            for(int i=k;i>=1;i--)
            {
                if(x1-i>0 && fire[x1-i][y1]!=1){fire[x1-i][y1]=1;break;}
            }

            break;
        case 2 :
            for(int i=k;i>=1;i--)
            {
                if(x1+i<n+1 && fire[x1+i][y1]!=1){fire[x1+i][y1]=1;break;}
            }

            break;
        case 3 :
            for(int i=k;i>=1;i--)
            {
                if(y1-i>0 && fire[x1][y1-i]!=1){fire[x1][y1-i]=1;break;}
            }

            break;
         case 4 :
             for(int i=k;i>=1;i--)
            {
                if(y1+i<m+1 && fire[x1][y1+i]!=1){fire[x1][y1+i]=1;break;}
            }

            break;
        }
        break;




    case 32 :
        switch(lt2)
        {
        case 1 :
            for(int i=k;i>=1;i--)
            {
                if(x2-i>0 && fire[x2-i][y2]!=1){fire[x2-i][y2]=1;break;}
            }

            break;
        case 2 :
            for(int i=k;i>=1;i--)
            {
                if(x2+i<n+1 && fire[x2+i][y2]!=1){fire[x2+i][y2]=1;break;}
            }

            break;
        case 3 :
            for(int i=k;i>=1;i--)
            {
                if(y2-i>0 && fire[x2][y2-2]!=1){fire[x2][y2-i]=1;break;}
            }

            break;
        case 4 :
            for(int i=k;i>=1;i--)
            {
                if(y2+i<m+1 && fire[x2][y2+i]!=1){fire[x2][y2+i]=1;break;}
            }

            break;
        }
        break;
    default :
        goto start;
        break;
    }
    visualGame(x1,y1,x2,y2);
        return true;

}

bool moves2pl()
{
    if(Exit)return false;
    if(brfire==5)brfire=0;
    brfire++;
    Sleep(100);
    char turn;
 if (kbhit())
 {
     start:
    turn = getch();
    switch(turn)
    {
    case 27 :
        return false;
        break;
    case 72 :
        lt1=1;
        if(x1!=1 && fire[x1-1][y1]==0){x1--;}
        else
        {
            cout<<"\a";
        }
        break;
    case 80 :
        lt1=2;
        if(x1!=n && fire[x1+1][y1]==0){x1++;}
        else
        {
            cout<<"\a";
        }
        break;
    case 75 :
        lt1=3;
        if(y1!=1 && fire[x1][y1-1]==0){y1--;}
         else
        {
            cout<<"\a";
        }
        break;
    case 77 :
        lt1=4;
        if(y1!=m && fire[x1][y1+1]==0){y1++;}
        else
        {
            cout<<"\a";
        }
        break;
    case 32 :
        switch(lt1)
        {
        case 1 :
            for(int i=k;i>=1;i--)
            {
                if(x1-i>0 && fire[x1-i][y1]!=1){fire[x1-i][y1]=1;break;}
            }

            break;
        case 2 :
            for(int i=k;i>=1;i--)
            {
                if(x1+i<n+1 && fire[x1+i][y1]!=1){fire[x1+i][y1]=1;break;}
            }

            break;
        case 3 :
            for(int i=k;i>=1;i--)
            {
                if(y1-i>0 && fire[x1][y1-i]!=1){fire[x1][y1-i]=1;break;}
            }

            break;
         case 4 :
             for(int i=k;i>=1;i--)
            {
                if(y1+i<m+1 && fire[x1][y1+i]!=1){fire[x1][y1+i]=1;break;}
            }

            break;
        }
        break;
    default :
        break;
    }

 }

       lt2 = rand()%4+1;
       switch(lt2)
       {
          case 1 :
            if(x2!=1 && fire[x2-1][y2]==0){x2--;}
            break;
          case 2 :
            if(x2!=n && fire[x2+1][y2]==0){x2++;}
             break;
          case 3 :
            if(y2!=1 && fire[x2][y2-1]==0){y2--;}
             break;
          case 4 :
            if(y2!=m && fire[x2][y2+1]==0){y2++;}
             break;
       }
       if(brfire==5)
       {
           int turnpl1=3;
       if(x2>x1 && x2-x1 >= abs(y1-y2))turnpl1=1;
       if(x2<x1 && x1-x2 >= abs(y1-y2))turnpl1=2;
       if(y2>y1 && y2-y1 >= abs(x1-x2))turnpl1=3;
       if(y1>y2 && y1-y2 >= abs(x1-x2))turnpl1=4;
        switch(turnpl1)
        {
        case 1 :
            for(int i=k;i>=1;i--)
            {
                if(x2-i>0 && fire[x2-i][y2]!=1){fire[x2-i][y2]=1;break;}
            }

            break;
        case 2 :
            for(int i=k;i>=1;i--)
            {
                if(x2+i<n+1 && fire[x2+i][y2]!=1){fire[x2+i][y2]=1;break;}
            }

            break;
        case 3 :
            for(int i=k;i>=1;i--)
            {
                if(y2-i>0 && fire[x2][y2-2]!=1){fire[x2][y2-i]=1;break;}
            }

            break;
        case 4 :
            for(int i=k;i>=1;i--)
            {
                if(y2+i<m+1 && fire[x2][y2+i]!=1){fire[x2][y2+i]=1;break;}
            }

            break;
        }
       }




            visualGame(x1,y1,x2,y2);
        return true;
}
void visualGame(int x1,int y1,int x2,int y2)
{
    int winner=0;
    system("cls");
    if(fire[x1][y1]==1)winner=2;
    if(fire[x2][y2]==1)winner=1;
    string con1="",con2="W S A D";
    char ch;
    ch=24;
    con1=con1+ch+" ";
    ch=25;
    con1=con1+ch+" ";
    ch=26;
    con1=con1+ch+" ";
    ch=27;
    con1=con1+ch;
    coutChar(35,' ');coutBG("ZDRAVEYTE");cout<<endl;
    coutChar(34,' ');coutBG("VIE IGRAETE");cout<<endl;
    coutChar(30,' ');coutBG("SIMVOLNO DVIJENIE 2");cout<<endl;
    cout<<endl;
    cout<<endl;
    coutChar(5,' ');coutChar(m+2,'*');cout<<endl;
    for(int i=1;i<=n;i++)
    {
        coutChar(5,' ');cout<<"*";
        for(int j=1;j<=m;j++)
        {
            if(fire[i][j]==1)cout<<"*";
            else
            {
            if(x1 == x2 && y1==y2 && x1==i && y1==j)cout<<"#\a";
            else
            {
            if(i==x1 && j==y1)
            {
                if(fire[x1][y1]==1)cout<<"@";
                else cout<<"X";
            }
            else
                {
                    if(i==x2 && j==y2)
                    {
                        if(fire[x2][y2]==1)cout<<"@";
                        else cout<<"Y";
                    }
                    else cout<<" ";
                }
            }
            }
        }
        cout<<"*";
        if(pl==2)
        {
        if(i==1){coutChar(5,' ');coutBG("KONTROLITE SA :");}
        if(i==n/3){coutChar(4,' ');coutBG("IGRA4 1 X :");cout<<con1;}
        if(i==n/3+1){coutChar(4,' ');coutBG("OGyN : ");cout<<"ENTER";}
        if(i==n/3*2){coutChar(4,' ');coutBG("IGRA4 2 ");cout<<"Y :"<<con2;}
        if(i==n/3*2+1){coutChar(4,' ');coutBG("OGyN : ");cout<<"SPACE";}
        cout<<endl;
        }
        else
        {
        if(i==1){coutChar(5,' ');coutBG("KONTROLITE SA :");}
        if(i==n/3){coutChar(4,' ');coutBG("IGRA4 1 X :");cout<<con1;}
        if(i==n/3+1){coutChar(4,' ');coutBG("OGyN : ");cout<<"SPACE";}
        cout<<endl;
        }
    }
       coutChar(5,' ');coutChar(m+2,'*');cout<<endl;
    coutChar(23,' ');coutBG("AKO ISKA6 DA IZLEZE6 NATISNI escape");
    if(winner!=0)
    {
        exitor:
        if(getch()!=27)goto exitor;
        system("cls");
        coutChar(35,' ');coutBG("ZDRAVEYTE");cout<<endl;
    coutChar(34,' ');coutBG("VIE IGRAETE");cout<<endl;
    coutChar(30,' ');coutBG("SIMVOLNO DVIJENIE 2");cout<<endl;
    cout<<endl;
    cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        coutChar(10,' ');coutChar(24,'*');cout<<endl;
        coutChar(10,' ');cout<<"* ";coutBG("POBEDITELQT E IGRA4 ");cout<<winner;cout<<"*"<<endl;
        coutChar(10,' ');coutChar(24,'*');cout<<endl;
    coutChar(23,' ');coutBG("AKO ISKA6 DA IZLEZE6 NATISNI escape");
    Exit=true;
    getch();
    return;
    }

}

void coutChar(int n,char c)
{
    for(int i=1;i<=n;i++)
        cout<<c;
}
int coutBG(string AEs)
{
    string BGs="";
    char c;
    int n=AEs.size();
    for(int i=0;i<n;i++)
    {
        if(AEs[i]==' '){c=' ';BGs=BGs+c;continue;}
        if(AEs[i]=='A'){c=128;BGs=BGs+c;continue;}//À
        if(AEs[i]=='B'){c=129;BGs=BGs+c;continue;}//Á
        if(AEs[i]=='V'){c=130;BGs=BGs+c;continue;}//Â
        if(AEs[i]=='G'){c=131;BGs=BGs+c;continue;}//Ã
        if(AEs[i]=='D'){c=132;BGs=BGs+c;continue;}//Ä
        if(AEs[i]=='E'){c=133;BGs=BGs+c;continue;}//Å
        if(AEs[i]=='J'){c=134;BGs=BGs+c;continue;}//Æ
        if(AEs[i]=='Z'){c=135;BGs=BGs+c;continue;}//Ç
        if(AEs[i]=='I'){c=136;BGs=BGs+c;continue;}//È
        if(AEs[i]=='Y'){c=137;BGs=BGs+c;continue;}//É
        if(AEs[i]=='K'){c=138;BGs=BGs+c;continue;}//Ê
        if(AEs[i]=='L'){c=139;BGs=BGs+c;continue;}//Ë
        if(AEs[i]=='M'){c=140;BGs=BGs+c;continue;}//Ì
        if(AEs[i]=='N'){c=141;BGs=BGs+c;continue;}//Í
        if(AEs[i]=='O'){c=142;BGs=BGs+c;continue;}//Î
        if(AEs[i]=='P'){c=143;BGs=BGs+c;continue;}//Ï
        if(AEs[i]=='R'){c=144;BGs=BGs+c;continue;}//Ð
        if(AEs[i]=='S'){c=145;BGs=BGs+c;continue;}//Ñ
        if(AEs[i]=='T'){c=146;BGs=BGs+c;continue;}//Ò
        if(AEs[i]=='U'){c=147;BGs=BGs+c;continue;}//Ó
        if(AEs[i]=='F'){c=148;BGs=BGs+c;continue;}//Ô
        if(AEs[i]=='H'){c=149;BGs=BGs+c;continue;}//Õ
        if(AEs[i]=='C'){c=150;BGs=BGs+c;continue;}//Ö
        if(AEs[i]=='4'){c=151;BGs=BGs+c;continue;}//×
        if(AEs[i]=='6'){c=152;BGs=BGs+c;continue;}//Ø
        if(AEs[i]=='^'){c=153;BGs=BGs+c;continue;}//Ù
        if(AEs[i]=='y'){c=154;BGs=BGs+c;continue;}//Ú
        if(AEs[i]=='!'){c=156;BGs=BGs+c;continue;}//Ü
        if(AEs[i]=='u'){c=158;BGs=BGs+c;continue;}//Þ
        if(AEs[i]=='Q'){c=159;BGs=BGs+c;continue;}//ß
        BGs=BGs+AEs[i];


    }
    cout<< BGs ;
    return BGs.size();
}
}


