 #include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include <time.h>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
#define MIN_snake_size 5
#define MAX_snake_size 20
#define MAXlevels 10
#define MAXN 13
#define MAXM 16
#define MAXApple 15
namespace SNAKEgame
{
    string nickSnake;
unsigned int score=0,level=1,apple=0;
int snake_size=MAX_snake_size,speed=100,delS=5;
bool level_completed = 0 , gameover = 0 , quit = 0;
//unsigned int Up=72,Down=80,Right=77,Left=75;
unsigned int Up=119,Down=115,Right=100,Left=97;
//char Upc='^',Downc='v',Rightc='>',Leftc='<',turn=77;
char Upc='w',Downc='s',Rightc='d',Leftc='a',turn=100;
int table[MAXN][MAXM];
void firstMenu();

void startgame();
void viewstartgame();
void applegame();

void resume_quit();
void options();
void CControls();
char controlsGEN();
void CLevel();
void colour(int i);
void Gameover();
void levels(int level);

void saveGame();
void loadGame();
void SetNick(string nickname);
class Snake
{
    public:
    int x;
    int y;
    int type;
};
Snake snake[26];
void cleargame()
{
    for(int i=0;i<=MAXN;i++)
        for(int j=0;j<=MAXM;j++)
        table[i][j]=0;
    turn=77;
    snake_size=MIN_snake_size;
    snake[0].x=0;
    snake[0].y=4;
    snake[0].type=2;
    snake[1].x=0;
    snake[1].y=3;
    snake[1].type=1;
    snake[2].x=0;
    snake[2].y=2;
    snake[2].type=1;
    snake[3].x=0;
    snake[3].y=1;
    snake[3].type=1;
    snake[4].x=0;
    snake[4].y=0;
    snake[4].type=1;
    table[0][0]=1;
    table[0][1]=1;
    table[0][2]=1;
    table[0][3]=1;
    table[0][4]=2;
    apple=0;
    level_completed = 0;
}
int SnakeGame()
{
    srand(time(NULL));
    if(level_completed==1)
    {
        LC:
        system("cls");
        apple=0;
        cout<<"\tSnake Game Shadow"<<endl;
        cout<<"\tLEVEL COMPLETE"<<endl;
        cout<<"\n\tTo continue press enter"<<endl;
        if(getch()!=13)goto LC;
    }
    cleargame();
    if(gameover==1){level=1;score=0;saveGame();}


    system("cls");
    firstMenu();
    saveGame();
    return 0;
}

void firstMenu()
{
    if(quit==1)return;
    int k,v=1;
    start_fMenu:
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    switch(v)
    {
    case 1 :
        cout<<"\t   MINE MENU"<<endl;
        cout<<"\t-> CONTINUE GAME"<<endl;
        cout<<"\t   START NEW GAME"<<endl;
        cout<<"\t   OPTIONS"<<endl;
        cout<<"\t   QUIT"<<endl;
        break;
    case 2 :
        cout<<"\t   MINE MENU"<<endl;
        cout<<"\t   CONTINUE GAME"<<endl;
        cout<<"\t-> START NEW GAME"<<endl;
        cout<<"\t   OPTIONS"<<endl;
        cout<<"\t   QUIT"<<endl;
        break;
    case 3 :
        cout<<"\t   MINE MENU"<<endl;
        cout<<"\t   CONTINUE GAME"<<endl;
        cout<<"\t   START NEW GAME"<<endl;
        cout<<"\t-> OPTIONS"<<endl;
        cout<<"\t   QUIT"<<endl;
        break;
    case 4 :
        cout<<"\t   MINE MENU"<<endl;
        cout<<"\t   CONTINUE GAME"<<endl;
        cout<<"\t   START NEW GAME"<<endl;
        cout<<"\t   OPTIONS"<<endl;
        cout<<"\t-> QUIT"<<endl;
        break;
    }
    fMenu:
    k=getch();
    switch(k)
    {
    case 72 :
        if(v==1)v=4;
        else v--;
        break;
    case 80 :
        if(v==4)v=1;
        else v++;
        break;
    case 13 :
        switch(v)
        {
        case 1 :
            loadGame();
            startgame();
            break;
        case 2 :
            startgame();
            break;
        case 3 :
            options();
            break;
        case 4 :
            quit=1;
            return;
            break;
        }
        break;

    }
   goto start_fMenu;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void startgame()
{
    levels(level);
    applegame();
    viewstartgame();
}

void applegame()
{
    int xA,yA;

    xA = rand()%MAXN;
    yA = rand()%MAXM;
    if(table[xA][yA]==0)table[xA][yA]=3;
    else {applegame();return;}
}



void viewstartgame()
{
    snake_size=MIN_snake_size+apple;
    int lx,ly;
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    cout<<"\n\n\n";
    cout<<"\tScore : "<<score<<"\tLevel : "<<level<<"\tApples : "<<apple<<"/"<<MAXApple<<endl;
    cout<<"\n\n\n";
    cout<<"\t";
    for(int i=0;i<=MAXM+1;i++)
        cout<<"*";
        cout<<endl;
    for(int i=0;i<MAXN;i++)
    {
        cout<<"\t*";
        for(int j=0;j<MAXM;j++)
        {
             if(table[i][j]==2){colour(10);cout<<"G";colour(7);}
             else
             {
                if(table[i][j]==1){colour(10);cout<<"o";colour(7);}
                else
                {
                    if(table[i][j]==3){colour(12);cout<<"@";colour(7);}
                    else
                    {
                        if(table[i][j]==4){colour(8);cout<<"#";colour(7);}
                       else if(table[i][j]==0)cout<<" ";
                    }
                }

             }
        }
        cout<<"*"<<endl;
    }
    cout<<"\t";
        for(int i=0;i<=MAXM+1;i++)
        cout<<"*";
    cout<<endl;
    cout<<"\n\n\t Press ESCAPE to quit"<<endl;
    if(kbhit())
    {////////////////////////////
        lx=snake[snake_size-1].x;
        ly=snake[snake_size-1].y;
        /////////////////////

        char button=getch();
        if((button==Down && turn ==Up)|| (button == Up && turn==Down)|| (button==Right && turn==Left) || (button==Left && turn == Right) )goto CPU;
        if(button!=Down && button!=Up && button!=Right && button!=Left && button!= 27)goto CPU;

        if(button==Up && turn != Down)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            //cout<<snake[snake_size-1].x<<" "<<snake[snake_size-1].y<<endl;getch();
            //cout<<snake_size-1<<" "<<snake[snake_size-1].x<<" "<<snake[snake_size-1].y<<" "<<snake[snake_size-1].type<<endl;
            //cout<<"TABLE : "<<table[snake[snake_size-1].x][snake[snake_size-1].y]<<endl;getch();
            for(int i=snake_size-1;i>0;i--)
            {

                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                //cout<<i<<" "<<snake[i].x<<" "<<snake[i].y<<" "<<snake[i].type<<endl;
                //cout<<"TABLE : "<<snake[i].x<<" "<<snake[i].y<<" "<<table[snake[i].x][snake[i].y]<<endl;getch();

            }



            if(snake[0].x==0)snake[0].x=MAXN-1;
                else snake[0].x-=1;

                ////////////////
                if(table[snake[0].x][snake[0].y]==3)
                {
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;saveGame();
                        SnakeGame();
                        return;
                    }
                }
                  if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
                ///////////////

            table[snake[0].x][snake[0].y]=snake[0].type;
            turn=Up;
        }

        if(button==Down && turn!=Up)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn=Down;
            }
            if(snake[0].x==MAXN-1)snake[0].x=0;
            else snake[0].x+=1;
            if(table[snake[0].x][snake[0].y]==3)
                {
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;saveGame();
                        return;
                    }
                }
            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
            turn=Down;
        }
        else if(button==Right && turn !=Left)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn=Right;
            }
            if(snake[0].y==MAXM-1)snake[0].y=0;
                else snake[0].y+=1;
                if(table[snake[0].x][snake[0].y]==3)
                {
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;saveGame();SnakeGame();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
               turn=Right;
        }
        if(button==Left && turn!=Right)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn = Left;
            }
            if(snake[0].y==0)snake[0].y=MAXM-1;
                else snake[0].y-=1;
                if(table[snake[0].x][snake[0].y]==3)
                {
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;saveGame();SnakeGame();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
            turn=Left;
        }
        if(button==27)
        {
            saveGame();
            resume_quit();
            return;
        }
                if(button==Right || button==Left)Sleep(speed-delS*level);
        else Sleep(speed-delS*level+20);
        viewstartgame();
    }
    else
    {
        CPU:
        lx=snake[snake_size-1].x;
        ly=snake[snake_size-1].y;
        char button=turn;
        if(button==Up)
        {


            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            //cout<<snake[snake_size-1].x<<" "<<snake[snake_size-1].y<<endl;getch();
            //cout<<snake_size-1<<" "<<snake[snake_size-1].x<<" "<<snake[snake_size-1].y<<snake[snake_size-1].type<<endl;
            //cout<<"TABLE : "<<table[snake[snake_size-1].x][snake[snake_size-1].y]<<endl;getch();
            for(int i=snake_size-1;i>0;i--)
            {
                //cout<<table[snake[snake_size-1].x][snake[snake_size-1].y]<<endl;getch();
                //cout<<"snake["<<i<<"].x : "<<snake[i].x<<" snake ["<<i<<"].y "<<snake[i].y<<endl;getch();
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                //cout<<"snake["<<i<<"].x : "<<snake[i].x<<" snake ["<<i<<"].y "<<snake[i].y<<endl;getch();
                table[snake[i].x][snake[i].y]=snake[i].type;
                //cout<<i<<" "<<snake[i].x<<" "<<snake[i].y<<" "<<snake[i].type<<endl;
                //cout<<"TABLE : "<<snake[i].x<<" "<<snake[i].y<<" "<<table[snake[i].x][snake[i].y]<<endl;getch();
                turn=Up;
            }

            if(snake[0].x==0)snake[0].x=MAXN-1;
                else snake[0].x-=1;
                if(table[snake[0].x][snake[0].y]==3)
                {
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;saveGame();SnakeGame();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
        }
        if(button==Down)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn=Down;
            }
            if(snake[0].x==MAXN-1)snake[0].x=0;
            else snake[0].x+=1;
            if(table[snake[0].x][snake[0].y]==3)
                {
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;saveGame();SnakeGame();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
        }
        if(button==Right)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                //cout<<"snake["<<i<<"].x : "<<snake[i].x<<" snake ["<<i<<"].y "<<snake[i].y<<endl;getch();
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                //cout<<"snake["<<i<<"].x : "<<snake[i].x<<" snake ["<<i<<"].y "<<snake[i].y<<endl;getch();
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn=Right;
            }
            if(snake[0].y==MAXM-1)snake[0].y=0;
                else snake[0].y+=1;
                if(table[snake[0].x][snake[0].y]==3)
                {
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;saveGame();SnakeGame();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;

        }
        if(button==Left)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn = Left;
            }
            if(snake[0].y==0)snake[0].y=MAXM-1;
                else snake[0].y-=1;
                if(table[snake[0].x][snake[0].y]==3)
                {
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;saveGame();SnakeGame();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
        }
        if(button==27)
        {
            resume_quit();
            return;
        }
        if(button==Right || button==Left)Sleep(speed-delS*level);
        else Sleep(speed-delS*level+10);
        viewstartgame();
    }


}

void resume_quit()
{
    char ch;
    resumeORquit:
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    cout<<"\t ENTER-> QUIT"<<endl;
    cout<<"\t ESCAPE-> Resume"<<endl;
    ch=getch();
    int k=ch;
    switch(k)
    {
    case 27 :
        viewstartgame();
        break;
    case 13:
        SnakeGame();
        break;
    default:
        goto resumeORquit;
        break;

    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void options()
{
    int k,v=1;
    start_options:
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    switch(v)
    {
    case 1 :
    cout<<"\t-> OPTIONS"<<endl;
    cout<<"\t   Controls"<<endl;
    cout<<"\t   Level"<<endl;
    cout<<"\t   Back"<<endl;
        break;
    case 2 :
    cout<<"\t   OPTIONS"<<endl;
    cout<<"\t-> Controls"<<endl;
    cout<<"\t   Level"<<endl;
    cout<<"\t   Back"<<endl;
        break;
    case 3 :
    cout<<"\t   OPTIONS"<<endl;
    cout<<"\t   Controls"<<endl;
    cout<<"\t-> Level"<<endl;
    cout<<"\t   Back"<<endl;
        break;
    case 4 :
    cout<<"\t   OPTIONS"<<endl;
    cout<<"\t   Controls"<<endl;
    cout<<"\t   Level"<<endl;
    cout<<"\t-> Back"<<endl;
        break;
    }
    Options:
    k=getch();
    switch(k)
    {
    case 72 :
        if(v==1 || v==2)v=4;
        else v--;
        break;
    case 80 :
        if(v==4)v=2;
        else v++;
        break;
    case 13 :
        switch(v)
        {
        case 2 :
            CControls();
            break;
        case 3 :
            CLevel();
            break;
        case 4 :
            return;
        }
        break;
    default :
        goto Options;
        break;

    }
   goto start_options;
}

void CControls()
{
    int k,v=1;
    start_options:
        if(Up>200)Up=72;
        if(Down>200)Down=80;
        if(Right>200)Right=77;
        if(Left>200)Left=75;
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    if(Up!='H')Upc=Up;
    if(Down!='P')Downc=Down;
    if(Right!='M')Rightc=Right;
    if(Left!='K')Leftc=Left;
    switch(v)
    {
    case 1 :
    cout<<"\tAction\t\tKey"<<endl;
    cout<<"\tMove Up\t\t"<<Upc<<endl;
    cout<<"\tMove Down\t"<<Downc<<endl;
    cout<<"\tMove Right\t"<<Rightc<<endl;
    cout<<"\tMove Left\t"<<Leftc<<endl;
        break;
    case 2 :
    cout<<"\tAction\t\tKey"<<endl;
    colour(9);cout<<"\tMove Up\t\t"<<Upc<<endl;colour(7);
    cout<<"\tMove Down\t"<<Downc<<endl;
    cout<<"\tMove Right\t"<<Rightc<<endl;
    cout<<"\tMove Left\t"<<Leftc<<endl;
        break;
    case 3 :
    cout<<"\tAction\t\tKey"<<endl;
    cout<<"\tMove Up\t\t"<<Upc<<endl;
    colour(9);cout<<"\tMove Down\t"<<Downc<<endl;colour(7);
    cout<<"\tMove Right\t"<<Rightc<<endl;
    cout<<"\tMove Left\t"<<Leftc<<endl;
        break;
    case 4 :
    cout<<"\tAction\t\tKey"<<endl;
    cout<<"\tMove Up\t\t"<<Upc<<endl;
    cout<<"\tMove Down\t"<<Downc<<endl;
    colour(9);cout<<"\tMove Right\t"<<Rightc<<endl;colour(7);
    cout<<"\tMove Left\t"<<Leftc<<endl;
        break;
    case 5 :
    cout<<"\tAction\t\tKey"<<endl;
    cout<<"\tMove Up\t\t"<<Upc<<endl;
    cout<<"\tMove Down\t"<<Downc<<endl;
    cout<<"\tMove Right\t"<<Rightc<<endl;
    colour(9);cout<<"\tMove Left\t"<<Leftc<<endl;colour(7);
    }
    cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
    cout<<"\n\n\n\t To back press escape"<<endl;
    Options:
    k=getch();
    switch(k)
    {
    case 72 :
        if(v==1 || v==2)v=5;
        else v--;
        break;
    case 80 :
        if(v==5)v=2;
        else v++;
        break;

    char k2;
    int k2i;
    case 27 :
        return;
    case 13 :
        switch(v)
        {
        case 2 :
            system("cls");
            cout<<"\tSnake Game Shadow"<<endl;
            cout<<"\tAction\t\tKey"<<endl;
            colour(12);cout<<"\tMove Up\t\t"<<Upc<<endl;colour(7);
            cout<<"\tMove Down\t"<<Downc<<endl;
            cout<<"\tMove Right\t"<<Rightc<<endl;
            cout<<"\tMove Left\t"<<Leftc<<endl;
            cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
            cout<<"\n\n\n\t To back press escape"<<endl;
            k2=72;
            k2=getch();
            k2i=k2;
            if(k2==' ')goto start_options;
            if(k2i!=27 || k2i<200)Up=k2i;
            if(k2i==27) return;
            if(k2i>200)Up=72;
            break;
        case 3 :
            system("cls");
            cout<<"\tSnake Game Shadow"<<endl;
            cout<<"\tAction\t\tKey"<<endl;
            cout<<"\tMove Up\t\t"<<Upc<<endl;
            colour(12);cout<<"\tMove Down\t"<<Downc<<endl;colour(7);
            cout<<"\tMove Right\t"<<Rightc<<endl;
            cout<<"\tMove Left\t"<<Leftc<<endl;
            cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
            cout<<"\n\n\n\t To back press escape"<<endl;
            k2=80;
            k2=getch();
            k2i=k2;
            if(k2==' ')goto start_options;
            if(k2i!=27 || k2i<200)Down=k2i;
            if(k2i==27) return;
            if(k2i>200)Down=80;
            break;
        case 4 :
            system("cls");
            cout<<"\tSnake Game Shadow"<<endl;
            cout<<"\tAction\t\tKey"<<endl;
            cout<<"\tMove Up\t\t"<<Upc<<endl;
            cout<<"\tMove Down\t"<<Downc<<endl;
            colour(12);cout<<"\tMove Right\t"<<Rightc<<endl;colour(7);
            cout<<"\tMove Left\t"<<Leftc<<endl;
            cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
            cout<<"\n\n\n\t To back press escape"<<endl;
            k2=77;
            k2=getch();
            k2i=k2;
            if(k2==' ')goto start_options;
            if(k2i!=27 || k2i<200)Right=k2i;
            if(k2i==27) return;
            if(k2i>200)Right=77;
            break;
        case 5 :
            system("cls");
            cout<<"\tSnake Game Shadow"<<endl;
            cout<<"\tAction\t\tKey"<<endl;
            cout<<"\tMove Up\t\t"<<Upc<<endl;
            cout<<"\tMove Down\t"<<Downc<<endl;
            cout<<"\tMove Right\t"<<Rightc<<endl;
            colour(12);cout<<"\tMove Left\t"<<Leftc<<endl;colour(7);
            cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
            cout<<"\n\n\n\t To back press escape"<<endl;
            k2=75;
            k2=getch();
            k2i=k2;
            if(k2==' ')goto start_options;
            if(k2i!=27 || k2i<200)Left=k2i;
            if(k2i==27) return;
            if(k2i>200)Left=75;
            break;
        }
        break;
        case 32 :
            Up=72;
            Down=80;
            Right=77;
            Left=75;
            Upc='^';
            Downc='v';
            Rightc='>';
            Leftc='<';
            break;
    default :
        goto Options;
        break;

    }
   goto start_options;

}
void CLevel()
{
    start_Clevel:
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    cout<<"\tLEVEL : "<<"<"<<level<<">"<<endl;
    cout<<"\tPress ENTER to continue"<<endl;
    int k=getch();
    switch (k)
    {
    case 72 :
        if(level==MAXlevels)level=1;
        else level++;
        break;
    case 77 :
        if(level==MAXlevels)level=1;
        else level++;
        break;
    case 75 :
        if(level==1)level=MAXlevels;
        else level--;
        break;
    case 80 :
        if(level==1)level=MAXlevels;
        else level--;
        break;
    case 13 :
        return;
    default :
        goto start_Clevel;
        break;
    }
    goto start_Clevel;
}
void Gameover()
{
    gameOVER:
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    cout<<"\tGAMEOVER"<<endl;
    cout<<"\tLevel : "<<level<<endl;
    cout<<"\tScore : "<<score<<endl;
    cout<<"\tTo continue press ENTER"<<endl;
    if(getch()!=13)goto gameOVER;
    SnakeGame();
}
void levels(int level)
{
    for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXM;j++)
                table[i][j]=0;
    switch(level)
    {
    case 1:
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;

    case 2:
        table[MAXN/4][MAXM/4]=4;
        table[MAXN/4*3][MAXM/4*3]=4;
        table[MAXN/4][MAXM/4*3]=4;
        table[MAXN/4*3][MAXM/4]=4;
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 3:
        for(int i=MAXN/4;i<=MAXN/4*3;i++)
        {
            table[i][MAXM/4]=4;
            table[i][MAXM/4*3]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
        case 4:
        for(int i=0;i<MAXM;i++)
            table[0][i]=4;
        for(int i=0;i<MAXM;i++)
            table[MAXN-1][i]=4;
        for(int i=0;i<MAXN;i++)
        {
            table[i][0]=4;
            table[i][MAXM-1]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=1;
            snake[i].y=snake_size-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 5:
        for(int i=MAXN/4;i<=MAXN/4*3;i++)
        {
            table[i][MAXM/4]=4;
            table[i][MAXM/4*3]=4;
        }
        for(int i=MAXM/4;i<=MAXM/4*3;i++)
        {
            table[MAXN/4][i]=4;
            table[MAXN/4*3][i]=4;
        }
        table[MAXN/2][MAXM/4]=0;
        table[MAXN/2][MAXM/4*3]=0;
        table[MAXN/4][MAXM/2]=0;
        table[MAXN/4*3][MAXM/2]=0;
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 6:
        for(int i=1;i<=MAXM-2;i++)
        {
            table[MAXN/4][i]=4;
            table[MAXN/4*3][i]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 7:
        for(int i=0;i<MAXN/4;i++)
        {
            table[i][MAXM/4]=4;
        }
        for(int i=0;i<MAXM/4;i++)
        {
            table[MAXN/4*3][i]=4;
        }
        for(int i=MAXM/4*3;i<=MAXM-1;i++)
        {
            table[MAXN/4][i]=4;
        }
        for(int i=MAXN/4*3;i<=MAXN-1;i++)
        {
            table[i][MAXM/4*3]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=MAXN/2;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 8:
        for(int i=0;i<MAXN/4;i++)
        {
            table[i][MAXM/4]=4;
        }
        for(int i=0;i<MAXM/4;i++)
        {
            table[MAXN/4*3][i]=4;
        }
        for(int i=MAXM/4*3;i<=MAXM-1;i++)
        {
            table[MAXN/4][i]=4;
        }
        for(int i=MAXN/4*3;i<=MAXN-1;i++)
        {
            table[i][MAXM/4*3]=4;
        }
        for(int i=0;i<MAXM;i++)
        {
            table[MAXN/2][i]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=MAXN/2-1;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 9:
        for(int i=1;i<MAXN-1;i++)
        {
            table[i][MAXM/4]=4;
            table[i][MAXM/2]=4;
            table[i][MAXM/4*3]=4;
        }
        for(int i=MAXM/2;i<=MAXM/4*3;i++)
        {
            table[1][i]=4;
        }
        for(int i=MAXM/4;i<=MAXM/2;i++)
        {
            table[MAXN-2][i]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 10:
        for(int i=1;i<MAXN-1;i++)
        {
            table[i][MAXM/4]=4;
            table[i][MAXM/2]=4;
            table[i][MAXM/4*3]=4;
        }
        for(int i=MAXM/2;i<=MAXM/4*3;i++)
        {
            table[1][i]=4;
            table[MAXN-2][i]=4;
        }
        table[MAXN/2][MAXM/4*3]=0;
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    }

}
void saveGame()
{
    string s="" ;
    char c;
    int sc=score,l=level,a=apple;
    while(sc!=0)
        {
            c=sc%10+48;
            s=c+s;
            sc/=10;
        }
        ofstream score_of_load_game("score.txt",ios::out);
        //ofstream score_of_load_game("score.txt",ios::app);
        if(score_of_load_game.is_open()){
             //score_of_load_game<<nickSnake<<" ";
             score_of_load_game<<s;


        }
        score_of_load_game.close();
        s="";
            while(a!=0)
        {
            c=a%10+48;
            s=c+s;
            a/=10;
        }
        ofstream apple_of_load_game("apple.txt",ios::out);
        //ofstream apple_of_load_game("apple.txt",ios::app);
        if(apple_of_load_game.is_open()){
             //apple_of_load_game<<nickSnake<<" ";
             apple_of_load_game<<s;


        }
        score_of_load_game.close();
    s="";
    if(l!=10)s=l+48;
    else s="10";
    ofstream level_of_load_game("level.txt",ios::out);
    //ofstream level_of_load_game("level.txt",ios::app);
    if(level_of_load_game.is_open())
    {
    //level_of_load_game<<nickSnake<<" ";
    level_of_load_game<<s;

    }
    level_of_load_game.close();
}

void loadGame()
{
    string load_score,load_level,load_apple;
    ifstream score_of_load_game("score.txt",ios::in);
    score_of_load_game>>load_score;
    score=atoi( load_score.c_str() );
    score_of_load_game.close();

    ifstream level_of_load_game("level.txt",ios::in);
    level_of_load_game>>load_level;
    level=atoi( load_level.c_str() );
    level_of_load_game.close();

    ifstream apple_of_load_game("apple.txt",ios::in);
    apple_of_load_game>>load_apple;
    apple=atoi( load_apple.c_str() );
    apple_of_load_game.close();

    //if(level.size()>1)level=10;
    //else level=level-48;
}
void SetNick(string nickname)
{
    nickSnake=nickname;
}
void colour(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}
}
