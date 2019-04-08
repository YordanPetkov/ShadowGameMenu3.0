#include<iostream>
#include<string>
#include<string.h>
#include<windows.h>
using namespace std;
namespace tttgame
{
string nickname[3],levelpl[3],rankpl[3],nickgl;
char plt[3];
int cell[5][5],win[3],flag=1,flag1=1,x1,y1,xbot,ybot,players,quit=0;
void color(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}

void swapplayers()
{
    string c;
    int d;
    c=nickname[1];
    nickname[1]=nickname[2];
    nickname[2]=c;
    c=levelpl[1];
    levelpl[1]=levelpl[2];
    levelpl[2]=c;
    c=rankpl[1];
    rankpl[1]=rankpl[2];
    rankpl[2]=c;
    d=win[1];
    win[1]=win[2];
    win[2]=d;
}
void visualScore()
{
    for(int i=1;i<=3;i++)
    {
        cout<<"                                     |";
        for(int j=1;j<=3;j++)
        {
            if(cell[i][j]==1){color(140);cout<<plt[1];color(142);}
            if(cell[i][j]==2){color(138);cout<<plt[2];color(142);}
            if(cell[i][j]==0){color(142);cout<<" ";}
            color(142);
            cout<<"|";
        }
        cout<<endl;
        cout<<"                                     -------"<<endl;


    }

}
void visualGame1pl(string Level , string Rank , string Nickname ,char symbol)
{

    system("CLS");
    color(137);
    cout<<" =============================================================================="<<endl;
    cout<<"                         TicTacToe Game <TTT> v2.2 2016"<<endl;
    cout<<" =============================================================================="<<endl;
    cout<<"                                  Have Fun !"<<endl;
    cout<<" Available levels : 5                                       Available ranks : 5"<<endl;
    cout<<"---------------------                                       -------------------"<<endl;
    cout<<"Level 1: Easy                                               Rank 1 : ~-Newbie-~"<<endl;
    cout<<"Level 2: Normal                                             Rank 2 : ~Amateur!~"<<endl;
    cout<<"Level 3: Hard                                               Rank 3 : ~Hardcore~"<<endl;
    cout<<"Level 4: Expert               Version : TTT Game v1.1       Rank 4 : Elite Pack"<<endl;
    cout<<"Level 5: Professional         Author  : Yordan Petkov       Rank 5 : TTT Master"<<endl;
    cout<<"---------------------                ";color(142);cout<<"-------";color(137);cout<<"                -------------------"<<endl;
     color(142);
    visualScore();
    color(137);
    cout<<"                                  Game Score "<<endl;
    cout<<"        G A M E                    ";color(139);cout<<"-Level : "<<Level;color(137);cout<<"        V E R S I O N"<<endl;
    cout<<" P R O G R A M M I N G             ";color(139);cout<<"-Rank : "<<Rank;color(137);cout<<"           2 . 2"<<endl;color(137);
    cout<<"          B Y                      ";color(139);cout<<"-Ninkname : "<<Nickname<<"                  "<<endl;color(137);
    cout<<"                                   ";color(139);cout<<"-SYMBOL : "<<symbol<<endl;color(137);
    cout<<"                           "<<endl;
    cout<<"      S h a d o w                  ";color(143);cout<<"Include coordinates : ";color(137);


}
void space(int nick1,int nick2)
{
    int n;
    color(137);
    n=70-nick1-nick2;
    for(int i=1;i<=n;i++)
        cout<<" ";
}
void visualGame2pl(string Level , string Rank , string Nickname ,char symbol)
{

    system("CLS");
    color(137);
    cout<<" =============================================================================="<<endl;
    cout<<"                         TicTacToe Game <TTT> v2.2 2016"<<endl;
    cout<<" =============================================================================="<<endl;
    cout<<"                                  Have Fun !"<<endl;
    cout<<"    "<<nickname[1];
    space(nickname[1].size(),nickname[2].size());
    cout<<nickname[2]<<endl;
    cout<<"---------------------                                       -------------------"<<endl;
    cout<<"    WINS : "<<win[1]<<"                                                     WINS : "<<win[2]<<endl;
    cout<<"                                                            "<<endl;
    cout<<"    Rank : "<<rankpl[1]<<"                                        Rank :"<<rankpl[2]<<endl;
    cout<<"                               Version : TTT Game v2.2       "<<endl;
    cout<<"    SYMBOL : "<<plt[1]<<"                 Author  : Yordan Petkov          SYMBOL : "<<plt[2]<<endl;
    cout<<"---------------------                ";color(142);cout<<"-------";color(137);cout<<"                -------------------"<<endl;
    color(142);visualScore();color(137);
    cout<<"                                  Game Score "<<endl;
    cout<<"        G A M E                    ";color(139);cout<<"-Level : "<<Level;color(137);cout<<"        V E R S I O N"<<endl;
    cout<<" P R O G R A M M I N G             ";color(139);cout<<"-Rank : "<<Rank;color(137);cout<<"           2 . 2"<<endl;color(137);
    cout<<"          B Y                      ";color(139);cout<<"-Ninkname : "<<Nickname<<"                  "<<endl;color(137);
    cout<<"                                   ";color(139);cout<<"-SYMBOL : "<<symbol<<endl;color(137);
    cout<<"                           "<<endl;
    cout<<"      S h a d o w                  ";color(143);cout<<"Include coordinates : ";color(137);

}
void cleargame()
{
    for(int z1=1;z1<=3;z1++)
        for(int z2=1;z2<=3;z2++)
        {
        cell[z1][z2]=0;
        cell[1][1]=0;
        }


}
int checkgame()
{
    char c;
    if(win[1]>4)return 1;
    if(win[2]>4)return 2;
    c=plt[1];
    plt[1]=plt[2];
    plt[2]=c;
    if(win[1]==1){levelpl[1]="2 <Normal>";rankpl[1]="~Amateur!~";}
    if(win[2]==1){levelpl[2]="2 <Normal>";rankpl[2]="~Amateur!~";}
    if(win[1]==2){levelpl[1]="3 <Hard>";rankpl[1]="~Hardcore~";}
    if(win[2]==2){levelpl[2]="3 <Hard>";rankpl[2]="~Hardcore~";}
    if(win[1]==3){levelpl[1]="4 <Expert>";rankpl[1]="Elite Pack";}
    if(win[2]==3){levelpl[2]="4 <Expert>";rankpl[2]="Elite Pack";}
    if(win[1]==4){levelpl[1]="5 <Professional>";rankpl[1]="TTT Master";}
    if(win[2]==4){levelpl[2]="5 <Professional>";rankpl[2]="TTT Master";}
    return 0;

}
int checkgame1pl()
{
    if(win[1]>4)return 1;
    if(win[1]==1){levelpl[1]="2 <Normal>";rankpl[1]="~Amateur!~";}
    if(win[1]==2){levelpl[1]="3 <Hard>";rankpl[1]="~Hardcore~";}
    if(win[1]==3){levelpl[1]="4 <Expert>";rankpl[1]="Elite Pack";}
    if(win[1]==4){levelpl[1]="5 <Professional>";rankpl[1]="TTT Master";}


    return 0;

}
bool Win(int player)
{
    if(cell[1][1]==player && cell[1][2]==player && cell[1][3]==player)return true;
    if(cell[2][1]==player && cell[2][2]==player && cell[2][3]==player) return true;
    if(cell[3][1]==player && cell[3][2]==player && cell[3][3]==player) return true;
    if(cell[1][1]==player && cell[2][1]==player && cell[3][1]==player) return true;
    if(cell[1][2]==player && cell[2][2]==player && cell[3][2]==player) return true;
    if(cell[1][3]==player && cell[2][3]==player && cell[3][3]==player) return true;
    if(cell[1][1]==player && cell[2][2]==player && cell[3][3]==player) return true;
    if(cell[3][1]==player && cell[2][2]==player && cell[1][3]==player)return true;
    return false;
}

void gameover1pl(int winner)
{
    system("CLS");
    if(winner==1)rankpl[1]="UNBELIVEBLE MASTER";
    color(129);
    cout<<" =============================================================================="<<endl;
    cout<<"                         TicTacToe Game <TTT> v2.2 2016"<<endl;
    cout<<" =============================================================================="<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    color(140);cout<<"                                   GAME OVER"<<endl;color(129);
    cout<<endl;
    cout<<endl;
    cout<<"                                 GAME STATISTIC"<<endl;
    cout<<"                                Nickname : "<<nickname[1]<<endl;
    cout<<"                                Level :"<<levelpl[1]<<endl;
    cout<<"                                Rank : "<<rankpl[1]<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    color(140);cout<<"                              THE WINNER IS ----->  "<<nickname[winner]<<endl;color(129);
    cout<<endl;
    cout<<"                        THANKS FOR PLAYING TicTacToe GAME v2.2 2016"<<endl;
    cout<<"                                         AUTHOR"<<endl;
    cout<<"                                       Yordan Petkov"<<endl;
    cout<<"                                         Shadow"<<endl;
    cout<<endl;cout<<endl;
    cout<<endl;cout<<endl;
    color(143);cout<<"                              To restart the game write : 'restart'"<<endl;
    cout<<"                              To quit the game write : 'quit'"<<endl;color(129);


}
void gameover(int winner)
{

    cout<<" =============================================================================="<<endl;
    cout<<"                         TicTacToe Game <TTT> v2.2 2016"<<endl;
    cout<<" =============================================================================="<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    color(140);cout<<"                                   GAME OVER"<<endl;color(129);
    cout<<endl;
    cout<<endl;
    cout<<"                                 GAME STATISTIC"<<endl;
    cout<<"                                Nickname : "<<nickname[1]<<endl;
    cout<<"                                Level :"<<levelpl[1]<<endl;
    cout<<"                                Rank : "<<rankpl[1]<<endl;
    cout<<endl;
    cout<<"                                Nickname : "<<nickname[2]<<endl;
    cout<<"                                Level :"<<levelpl[2]<<endl;
    cout<<"                                Rank : "<<rankpl[2]<<endl;
    cout<<endl;
    cout<<endl;
    color(140);cout<<"                                THE WINNER IS ----->  "<<nickname[winner]<<endl;color(129);
    cout<<endl;
    cout<<"                            THANKS FOR PLAYING TicTacToe GAME v2.2 2016"<<endl;
    cout<<"                                            AUTHOR"<<endl;
    cout<<"                                        Yordan  Petkov"<<endl;
    cout<<"                                            Shadow"<<endl;
    cout<<endl;cout<<endl;
    cout<<endl;cout<<endl;
    color(143);cout<<"                              To restart the game write : 'restart'"<<endl;
    cout<<"                              To quit the game write : 'quit'"<<endl;
    color(129);
}
bool restart(int flag)
{
    if(flag==1)
    {
        string restartg;
            cout<<"                                 ";
            cin>>restartg;
    if(restartg=="restart"){system("CLS");return 1;}
    if(restartg=="quit"){return 0;}
    restart(1);
    }
    if(flag==2)
    {
        cout<<endl;cout<<endl;
        color(143);cout<<"           Level completed , to continue write 'play' "<<endl;
        cout<<"                            to quit write 'quit' "<<endl;color(129);
        string restartg;
        cout<<"                                 ";
        cin>>restartg;
        if(restartg=="play"){system("CLS");return 1;}
        if(restartg=="quit"){return 0;}
        restart(2);
    }
}

void gameofplayer1(int pl)
{
    if(players==1)visualGame1pl(levelpl[pl],rankpl[pl],nickname[pl],plt[pl]);
    if(players==2)visualGame2pl(levelpl[pl],rankpl[pl],nickname[pl],plt[pl]);
    int  x,y;
    cin>>x>>y;
    if(x<1 || y<1){color(139);cout<<"The coordinates must be bigger than 0"<<endl;color(129);gameofplayer1(pl);}
    if(x>3 || y>3){color(139);cout<<"The coordinates must be smaller than 4"<<endl;color(129);gameofplayer1(pl);}
    if(cell[x][y]==1){color(139);cout<<"There is X"<<endl;color(129);gameofplayer1(pl);}
    if(cell[x][y]==2){color(139);cout<<"There is O"<<endl;color(129);gameofplayer1(pl);}
    if(cell[x][y]==0)cell[x][y]=pl;

    x1=x;
    y1=y;
}
void twoplayers()
{
    int check;
    players=2;
    string nick2;
    system("CLS");
    if(flag==1)
    {
    cout<<"           W E L L C O M E  T o  T i c T a c T o e  G A M E   v 2 . 2 "<<endl;
    cout<<"                            author : YORDAN PETKOV"<<endl;cout<<endl;cout<<endl;cout<<endl;
    cout<<"       Player 1 write your Nickname : ";cin>>nickname[1];
    cout<<"       Player 2 write your Nickname : ";cin>>nick2;
    nickname[2]=nick2;
    }
    int pl=1;
    for(int turn=1;turn<=9;turn++)
    {
        if(turn%2==0)pl=2;
        if(turn%2==1)pl=1;
        visualGame2pl(levelpl[pl],rankpl[pl],nickname[pl],plt[pl]);
        gameofplayer1(pl);
        system("CLS");
        if(pl==1)visualGame2pl(levelpl[2],rankpl[2],nickname[2],plt[2]);
        if(pl==2)visualGame2pl(levelpl[1],rankpl[1],nickname[1],plt[1]);
       if(Win(1)){cout<<endl;win[1]++;cout<<endl;cout<<"                                              "<<nickname[1]<<" WIN"<<endl;if(!restart(2))quit=1;;break;}
       if(Win(2)){cout<<endl;win[2]++;cout<<endl;cout<<"                                              "<<nickname[2]<<" WIN"<<endl;if(!restart(2))quit=1;;break;}
    }
    if(quit==0)
    {
    check=checkgame();
    string ansres;
    if(check==1 || check==2){gameover(check);cin>>ansres;if(ansres=="restart"){flag=2;cleargame();swapplayers();twoplayers();}}
    else {flag=2;cleargame();swapplayers();twoplayers();}
    }
}

int botEasy()
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(cell[i][j]==0){cell[i][j]=2;return 0;}
}
int botNormal(int t)
{
    if(t==1)
    {
        if(x1!=2&&y1!=2)
        {
            xbot=4-x1;
            ybot=4-y1;
            cell[xbot][ybot]=2;
            return 0;
        }
        else
        {
            if(x1!=2 || y1!=2)
            {
                if(x1==2)
                {
                    ybot=4-y1;
                    xbot=2;
                    cell[xbot][ybot]=2;
                    return 0;

                }
                if(y1==2)
                {
                    xbot=4-x1;
                    ybot=2;
                    cell[xbot][ybot]=2;
                    return 0;

                }
            }
                if(x1==2 && y1==2)
                {
                    xbot=1;
                    ybot=1;
                    cell[xbot][ybot]=2;
                    return 0;
                }


        }

    }
    if(t==2)
    {
        if((xbot+ybot)%2==0)
        {
            if(cell[xbot][2]==0){cell[xbot][2]=2;return 0;}
            if(cell[2][ybot]==0){cell[2][ybot]=2;return 0;}
        }
        else
            {
                if(xbot!=2)
                {
                    if(cell[xbot][xbot]==0){cell[xbot][xbot]=2;return 0;}
                    if(cell[xbot][4-xbot]==0){cell[xbot][4-xbot]=2;return 0;}
                }
                else
                {
                    if(cell[ybot][ybot]==0){cell[ybot][ybot]=2;return 0;}
                    if(cell[4-ybot][ybot]==0){cell[4-ybot][ybot]=2;return 0;}
                }
            }
    }
    if(t==3)
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=2;
                    if(Win(2))return 0;
                    cell[i][j]=0;
                }
            }
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
        for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(cell[i][j]==0){cell[i][j]=2;return 0;}

    }
    if(t==4)
    {
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(cell[i][j]==0){cell[i][j]=2;return 0;}
    }
}
int botHard(int t)
{

    if(t==1)
    {
        if((x1+y1)%2==0)
        {
            if(cell[x1][2]==0){cell[x1][2]=2;return 0;}
            if(cell[2][y1]==0){cell[2][y1]=2;return 0;}
        }
        else
            {
                if(xbot!=2)
                {
                    if(cell[x1][x1]==0){cell[x1][x1]=2;return 0;}
                    if(cell[x1][4-xbot]==0){cell[x1][4-x1]=2;return 0;}
                }
                else
                {
                    if(cell[y1][y1]==0){cell[y1][y1]=2;return 0;}
                    if(cell[4-y1][y1]==0){cell[4-y1][y1]=2;return 0;}
                }
            }
            for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(cell[i][j]==0){cell[i][j]=2;return 0;}
    }
    if(t==2)
    {
        if((xbot+ybot)%2==0)
        {
            if(cell[xbot][2]==0){cell[xbot][2]=2;return 0;}
            if(cell[2][ybot]==0){cell[2][ybot]=2;return 0;}
        }
        else
            {
                if(xbot!=2)
                {
                    if(cell[xbot][xbot]==0){cell[xbot][xbot]=2;return 0;}
                    if(cell[xbot][4-xbot]==0){cell[xbot][4-xbot]=2;return 0;}
                }
                else
                {
                    if(cell[ybot][ybot]==0){cell[ybot][ybot]=2;return 0;}
                    if(cell[4-ybot][ybot]==0){cell[4-ybot][ybot]=2;return 0;}
                }
            }
            for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
    }
     if(t==3)
    {

        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
        for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(cell[i][j]==0){cell[i][j]=2;return 0;}

    }
    if(t==4)
    {
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(cell[i][j]==0){cell[i][j]=2;return 0;}
    }
}
int botExpert(int t)
{
    if(t==1)
    {
        if(x1!=2&&y1!=2)
        {
            xbot=4-x1;
            ybot=4-y1;
            cell[xbot][ybot]=2;
            return 0;
        }
        else
        {
            if(x1!=2 || y1!=2)
            {
                if(x1==2)
                {
                    ybot=4-y1;
                    xbot=2;
                    cell[xbot][ybot]=2;
                    return 0;

                }
                if(y1==2)
                {
                    xbot=4-x1;
                    ybot=2;
                    cell[xbot][ybot]=2;
                    return 0;

                }
            }
                if(x1==2 && y1==2)
                {
                    xbot=1;
                    ybot=1;
                    cell[xbot][ybot]=2;
                    return 0;
                }


        }

    }
    if(t==2)
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=2;
                    if(Win(2))return 0;
                    cell[i][j]=0;
                }
            }
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
        if(xbot+ybot%2==0)
        {
            if(cell[xbot][2]==0){cell[xbot][2]=2;return 0;}
            if(cell[2][ybot]==0){cell[2][ybot]=2;return 0;}
        }
        else
            {
                if(xbot!=2)
                {
                    if(cell[xbot][xbot]==0){cell[xbot][xbot]=2;return 0;}
                    if(cell[xbot][4-xbot]==0){cell[xbot][4-xbot]=2;return 0;}
                }
                else
                {
                    if(cell[ybot][ybot]==0){cell[ybot][ybot]=2;return 0;}
                    if(cell[4-ybot][ybot]==0){cell[4-ybot][ybot]=2;return 0;}
                }
            }
    }
    if(t==3)
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=2;
                    if(Win(2))return 0;
                    cell[i][j]=0;
                }
            }
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }

        for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        if(cell[i][j]==0){cell[i][j]=2;return 0;}

    }
    if(t==4)
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=2;
                    if(Win(2))return 0;
                    cell[i][j]=0;
                }
            }
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }

            for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        if(cell[i][j]==0){cell[i][j]=2;return 0;}

    }

}
int protip,x11,y11;
int botProfessional (int t)
{
    if(t==1)
    {
        x11=x1;
        y11=y1;
        if((x1+y1)%2==0 && x1!=2 && y1!=2)
        {
            protip=1;
            xbot=2;
            ybot=2;
            cell[2][2]=2;
        }
        else
            if(x1==2 && y1==2)
             {
                 protip=2;
                  xbot=1;
                  ybot=1;
                  cell[1][1]=2;
             }
             else
             {
                   protip=3;
                   xbot=2;
                   ybot=2;
                   cell[2][2]=2;
             }
    }
    if(t==2)
    {
        if(protip==1)
        {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
            if((x1+y1+x11+y11)%2!=0){cell[4-x11][4-y11]=2;return 0;}
            else cell[2][1]=2;return 0;

        }
        if(protip==2)
        {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
            cell[4-xbot][ybot]=2;
            return 0;
        }
        if(protip==3)
        {
            for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
            if((x1+y1)%2!=0&&(x11+y11)%2!=0)
            {
                if(y1!=y11&&x1!=x11)
                {
            if(cell[x1][y11]==0){cell[x1][y11]=2;return 0;}
            if(cell[x11][y1]==0){cell[x11][y1]=2;return 0;}
                }
                else
                {
                    cell[y1][x1]=2;
                    return 0;
                }

            }
            else
            {
                if(x11==2){cell[x1][y11]=2;return 0;}
                if(y11==2){cell[x11][y1]=2;return 0;}
            }


        }



    }
    if(t==3)
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=2;
                    if(Win(2))return 0;
                    cell[i][j]=0;
                }
            }
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
            if(protip==1)
            {
            for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if((i+j)%2!=0 && cell[i][j]==2 ){cell[4-x11][4-y11]=2;return 0;}
            }
            if(x1==1&&y1==2){if(cell[3][1]==0){cell[3][1]=2;return 0;}if(cell[3][3]==0){cell[3][3]=2;return 0;}}
            if(x1==2&&y1==1){if(cell[1][3]==0){cell[1][3]=2;return 0;}if(cell[3][3]==0){cell[3][3]=2;return 0;}}
            if(x1==2&&y1==3){if(cell[1][1]==0){cell[1][1]=2;return 0;}if(cell[3][1]==0){cell[3][1]=2;return 0;}}
            if(x1==3&&y1==2){if(cell[1][1]==0){cell[1][1]=2;return 0;}if(cell[1][3]==0){cell[1][3]=2;return 0;}}
            }
            if(protip==2)
            {
               cell[3][1]=2;
               return 0;
            }
            if(protip==3)
            {
               if(cell[1][1]==0 && cell[1][3]==0 && cell[3][1]==0 && cell[3][3]==0)
               {
                   if(cell[1][2]==2 || cell[2][1]==2){cell[1][1]=2;return 0;}
                   if(cell[2][3]==2 || cell[3][2]==2){cell[3][3]=2;return 0;}
               }
               if(cell[1][1]==0){cell[1][1]=2;return 0;}
               if(cell[1][3]==0){cell[1][3]=2;return 0;}
               if(cell[3][1]==0){cell[3][1]=2;return 0;}
               if(cell[3][3]==0){cell[3][3]=2;return 0;}

            }

    }
    if(t==4)
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=2;
                    if(Win(2))return 0;
                    cell[i][j]=0;
                }
            }
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0)
                {
                    cell[i][j]=1;
                    if(Win(1)){cell[i][j]=2;return 0;}
                    cell[i][j]=0;
                }
            }
         for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(cell[i][j]==0){cell[i][j]=2;return 0;}
            }
    }
}
void gameofbot(int botturn)
{
    if(levelpl[1]=="1 <Easy>")botEasy();
    if(levelpl[1]=="2 <Normal>")botNormal(botturn);
    if(levelpl[1]=="3 <Hard>")botHard(botturn);
    if(levelpl[1]=="4 <Expert>")botExpert(botturn);
    if(levelpl[1]=="5 <Professional>")botProfessional(botturn);
}
void oneplayer()
{
    int check;
    players=1;
    system("CLS");
    if(flag1==1)
    {
    cout<<"           W E L L C O M E  T o  T i c T a c T o e  G A M E   v 2 . 2 "<<endl;
    cout<<"                            author : YORDAN PETKOV"<<endl;cout<<endl;cout<<endl;cout<<endl;
    nickname[1]=nickgl;
    nickname[2]="BOT";
    }
    int pl=1;
    for(int turn=1;turn<=9;turn++)
    {
        if(turn%2==0)gameofbot(turn/2);
        if(turn%2==1)gameofplayer1(1);
        system("CLS");
        visualGame1pl(levelpl[1],rankpl[1],nickname[1],plt[1]);
       if(Win(1)){cout<<endl;win[1]++;cout<<endl;cout<<"                                              "<<nickname[1]<<" WIN"<<endl;if(!restart(2))quit=1;;break;}
       if(Win(2)){cout<<endl;win[2]++;cout<<endl;cout<<"                                              "<<nickname[2]<<" WIN"<<endl;if(!restart(2))quit=1;if(quit==0)gameover1pl(2);break ;}
    }
    if(quit==0)
    {
    if(win[2]==0)
    {
    check=checkgame1pl();
    if(check==1){gameover1pl(1);}
    else {flag1=2;cleargame();oneplayer();}
    }
    cleargame();
    }

}
string type;
string menu()
{
    system("CLS");
    cout<<"           W E L L C O M E  T o  T i c T a c T o e  G A M E   v 2 . 2          "<<endl;
    cout<<"                            author : YORDAN PETKOV                             "<<endl;
    cout<<"                            Choose type of Game"<<endl;
    cout<<"                          For two players write : 'two' "<<endl;
    cout<<"                          For one player write : 'one' "<<endl;
    cout<<"                          For quit the game write: 'quit'"<<endl;
    cout<<"                                   -";
    cin>>type;
    return type;

}
int TTTg(string nick1)
{

    nickgl=nick1;
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    cout<<"                                  Have Fun !"<<endl;
    system("CLS");
    color(129);
    levelpl[1]="1 <Easy>";
    levelpl[2]="1 <Easy>";
    rankpl[1]="~-Newbie-~";
    rankpl[2]="~-Newbie-~";
    win[1]=0;
    win[2]=0;
    plt[1]='X';
    plt[2]='O';
    menu();
        if(type=="two")twoplayers();
    else{

        if(type=="one")oneplayer();
        else {if(type=="quit")return 0;
            else {system("CLS");menu();}
        }
    }

    if(quit==0)if(restart(1))TTTg(nickgl);
    color(31);
    cleargame();
    return 0;
}}
