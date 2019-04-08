#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include "DIS2.cpp"
#include "enigma2.cpp"
#include "TTT2.cpp"
#include "SBJ2.cpp"
#include "SymbolMove3.cpp"
#include "SNAKE.cpp"

using namespace std;
int main();
int loginsucces=0,flag2=0;
string nickgl;
string nickname,password;
void color(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}
void passwordcin()
{
    password="";
    START:
    system("CLS");
    cout<<"                         Write your nickname and password"<<endl;
    cout<<"                 -nickname : ";cout<<nickname<<endl;
    cout<<"                 -password : ";
    char pass[32];
    int i=0,k;
    char a;
    for(i=0;;)
    {
        a=getch();
        k=a;
        if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
        {
            password=password+a;
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(k==8 && i>=1)
        {
            --i;
            system("CLS");
            cout<<"                         Write your nickname and password"<<endl;
            cout<<"                 -nickname : ";cout<<nickname<<endl;
            cout<<"                 -password : ";
            if(i!=0){for(int j=0;j<i;j++)cout<<"*";
            password.erase(i-1,1);}


        }
        if(k==13)
        {
            pass[i]='/0';
            break;
        }
    }
    if(i<=5)
    {
        cout<<"            Minimun 6 digits needed."<<endl;
        getch();
        goto START;
    }

}
bool thereISthatMember(string nick)
{
    char membersfile[256];
        string prom,massive[255];
    ifstream reg ("members.txt",ios::in);
    int i=0;
    while(! reg.eof())
    {

        reg>>prom;
        massive[i]=prom;
        i++;
    }
    for(int j=0;j<=i;j++)
    {
        if(massive[j]==nick)return true;
    }
    return false;

}
void login()
{
        system("CLS");
        char membersfile[256];
        string prom,massive[255],loginmem;
        cout<<"                                        LOGIN"<<endl;
    cout<<endl;
        cout<<"                         Write your nickname and password"<<endl;
    cout<<"                 -nickname : ";cin>>nickname;cout<<endl;
    cout<<"                 -password : ";passwordcin();cout<<endl;
    ifstream reg ("members.txt",ios::in);
    int i=0;
    while(! reg.eof())
    {

        getline(reg, prom);
        massive[i]=prom;
        i++;
    }
    loginmem = nickname + " " + password;
    for(int j=0;j<=i;j++)
    {
        if(massive[j]==loginmem){system("CLS");MessageBox(NULL,"You are login successful","GameMenu",NULL | MB_ICONINFORMATION);cout<<endl;loginsucces=1;nickgl=nickname;return;}
    }
    system("CLS");MessageBox(NULL,"Error with login","GameMenu",NULL | MB_ICONSTOP);loginsucces=2;main();
}
void registration()
{
    registerA:
        system("CLS");
    cout<<"                                     REGISTRATION"<<endl;
    cout<<endl;
    cout<<"                         Write your nickname and password"<<endl;
    cout<<"                 -nickname : ";cin>>nickname;
    cout<<"                 -password : ";passwordcin();
    ofstream reg ("members.txt",ios::app);
    if(thereISthatMember(nickname)) {MessageBox(NULL,"There is member with same nickname","GameMenu",NULL | MB_ICONSTOP);goto registerA;}
    if(reg.is_open())
    {
        reg<<endl;
        reg<<nickname<<" ";
        reg<<password;
        reg.close();
        system("CLS");MessageBox(NULL,"You are register successful","GameMenu",NULL | MB_ICONINFORMATION);nickgl=nickname;

    }
}
int loginreg1()
{
    int sq=4;
    sq=4;
    STARTCHOOSE:
    system("CLS");
    cout<<"                         HELLO to GAME SHADOW MENU v 1.0"<<endl;
    cout<<endl;cout<<endl;
    if(sq==1)
    {cout<<"                            MENU"<<endl;
        cout<<"                        -> login"<<endl;
     cout<<"                           register"<<endl;
     cout<<"                           quit"<<endl;}
    else {
        if(sq==2){
                cout<<"                            MENU"<<endl;
     cout<<"                           login"<<endl;
     cout<<"                        -> register"<<endl;
     cout<<"                           quit"<<endl;}
        else if(sq==3){
                cout<<"                            MENU"<<endl;
          cout<<"                           login"<<endl;
     cout<<"                           register"<<endl;
     cout<<"                        -> quit"<<endl;
        }
         else if(sq==4){
                cout<<"                         -> MENU"<<endl;
          cout<<"                           login"<<endl;
     cout<<"                           register"<<endl;
     cout<<"                           quit"<<endl;
        }
    }

    char a;
        int k;
        a=getch();
        k=a;
        if(k==13)
    {
        if(sq==1)
        {
            login();
            return 0;
        }
        else{if(sq==2)
            {registration();return 0;}
            else if(sq==3)return 3;}
    }

        if(k==80)
        {
            if(sq==4)sq=1;
            else { if(sq!=3)sq++;
            else sq=1;
            }
            goto STARTCHOOSE;
        }
        if(k==72)
        {
            if(sq!=1)sq--;
            else sq=3;
            goto STARTCHOOSE;
        }
    else goto STARTCHOOSE;
}
string choosegame1()
{
    int sq=8;
    sq=8;
    STARTQUIT:
    system("CLS");
    cout<<"                         HELLO to GAME SHADOW MENU v 2.0"<<endl;
    cout<<endl;cout<<endl;
    switch(sq)
    {
    case 1 :
    cout<<"                             MENU "<<endl;
    cout<<"                   ->";color(129);cout<<"-play TicTacToe v2.2 "<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-play Shadow Black Jack "<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-code in enigma "<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-play DiceInShadow v2.0 "<<endl;color(30);
    color(28);cout<<"                     ";color(15);cout<<"-play SymbolMove 3 "<<endl;color(30);
    color(28);cout<<"                     ";color(7);cout<<"-play Snake GAME "<<endl;color(30);
    color(31);cout<<"                         sign out "<<endl;
    break;

    case 2 :

            cout<<"                             MENU "<<endl;
     cout<<"                     ";color(129);cout<<"-play TicTacToe v2.2 "<<endl;color(31);
    color(27);cout<<"                   ->";color(41);cout<<"-play Shadow Black Jack "<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-code in enigma "<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-play DiceInShadow v2.0 "<<endl;color(30);
        color(28);cout<<"                     ";color(15);cout<<"-play SymbolMove 3 "<<endl;color(30);
        color(28);cout<<"                     ";color(7);cout<<"-play Snake GAME "<<endl;color(30);
    color(31);cout<<"                         sign out "<<endl;
    break;

    case 3 :
    cout<<"                             MENU "<<endl;
    cout<<"                     ";color(129);cout<<"-play TicTacToe v2.2 "<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-play Shadow Black Jack "<<endl;
    color(27);cout<<"                   ->";color(15);cout<<"-code in enigma "<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-play DiceInShadow v2.0 "<<endl;color(30);
        color(28);cout<<"                     ";color(15);cout<<"-play SymbolMove 3 "<<endl;color(30);
        color(28);cout<<"                     ";color(7);cout<<"-play Snake GAME "<<endl;color(30);
    color(31);cout<<"                         sign out "<<endl;
    break;
    case 4 :
           cout<<"                             MENU "<<endl;
            cout<<"                     ";color(129);cout<<"-play TicTacToe v2.2 "<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-play Shadow Black Jack "<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-code in enigma "<<endl;color(31);
    color(28);cout<<"                   ->";color(47);cout<<"-play DiceInShadow v2.0 "<<endl;color(30);
        color(28);cout<<"                     ";color(15);cout<<"-play SymbolMove 3 "<<endl;color(30);
        color(28);cout<<"                     ";color(7);cout<<"-play Snake GAME "<<endl;color(30);
    color(31);cout<<"                         sign out "<<endl;
    break;
    case 5 :
    color(31);cout<<"                             MENU "<<endl;
    cout<<"                     ";color(129);cout<<"-play TicTacToe v2.2 "<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-play Shadow Black Jack "<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-code in enigma "<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-play DiceInShadow v2.0 "<<endl;color(30);
    color(28);cout<<"                   ->";color(15);cout<<"-play SymbolMove 3 "<<endl;color(30);
    color(28);cout<<"                     ";color(7);cout<<"-play Snake GAME "<<endl;color(30);
    color(31);cout<<"                         sign out "<<endl;
    break;
    case 6 :
            cout<<"                             MENU "<<endl;
       cout<<"                     ";color(129);cout<<"-play TicTacToe v2.2 "<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-play Shadow Black Jack "<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-code in enigma "<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-play DiceInShadow v2.0 "<<endl;color(30);
        color(28);cout<<"                     ";color(15);cout<<"-play SymbolMove 3 "<<endl;color(30);
    color(28);cout<<"                   ->";color(7);cout<<"-play Snake GAME "<<endl;color(30);
    color(31);cout<<"                         sign out "<<endl;
    break;

    case 7 :
    color(31);cout<<"                             MENU "<<endl;
    cout<<"                     ";color(129);cout<<"-play TicTacToe v2.2 "<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-play Shadow Black Jack "<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-code in enigma "<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-play DiceInShadow v2.0 "<<endl;color(30);
    color(28);cout<<"                     ";color(15);cout<<"-play SymbolMove 3 "<<endl;color(30);
    color(28);cout<<"                     ";color(7);cout<<"-play Snake GAME "<<endl;color(30);
    color(31);cout<<"                     ->  sign out "<<endl;
    break;

    case 8 :
    color(31);cout<<"                           ->MENU "<<endl;
    cout<<"                     ";color(129);cout<<"-play TicTacToe v2.2 "<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-play Shadow Black Jack "<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-code in enigma "<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-play DiceInShadow v2.0 "<<endl;color(30);
    color(28);cout<<"                     ";color(15);cout<<"-play SymbolMove 3 "<<endl;color(30);
    color(28);cout<<"                     ";color(7);cout<<"-play Snake GAME "<<endl;color(30);
    color(31);cout<<"                         sign out "<<endl;
    break;
    }
    char a;
        int k;
        a=getch();
        k=a;
        if(k==13)
    {
        switch(sq)
        {
    case 1 :
        return "TTT";
    break;
    case 2 :
        return "SBJ";
    break;
    case 3:
        return "enigma";
    break;
    case 4:
        return "DIS";
    break;
    case 5:
        return "SM";
    break;
    case 6:
        return "snake";
    case 7:
        return "exit";
    break;
        }
    }

        if(k==80)
        {
            if(sq==8)sq=1;
            else {if(sq!=7)sq++;
            else sq=1;
            }
            goto STARTQUIT;
        }
        if(k==72)
        {
            if(sq!=1)sq--;
            else sq=7;
            goto STARTQUIT;
        }
    else goto STARTQUIT;
}
void menugame()
{
    system("CLS");
    string loginreg,game;
    if(flag2==0)
    {
    if(loginsucces==2)MessageBox(NULL,"Error with login","GameMenu",NULL | MB_ICONSTOP);

    color(31);
    cout<<"                         HELLO to GAME SHADOW MENU v 1.0"<<endl;
    if(loginreg1()==3)return;
    /*cout<<"                     -If you new in shadow menu please write : 'register'"<<endl;
    cout<<"                     -If you want to login in shadow menu write : 'login'"<<endl;
    cout<<endl;
    cin>>loginreg;
    if(loginreg == "login")login();
    if(loginreg == "register")registration();
    if(loginreg != "login" && loginreg != "register")main();
    */flag2=1;
    }
    /*cout<<"                     ";color(129);cout<<"-to play TicTacToe v2.2 write : 'TTT'"<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-to play Shadow Black Jack write : 'SBJ'"<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-to code in enigma write : 'enigma'"<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-to play DiceInShadow v2.0 write : 'DIS'"<<endl;color(30);
    color(31);cout<<"                      To sign out write : 'exit'"<<endl;cout<<"                     ";
    cin>>game;*/
    game=choosegame1();
    color(31);
    if(game=="TTT")tttgame::TTTg(nickgl);
    if(game=="enigma")enigmagame::enigmag();
    if(game=="DIS")disgame::DISg(nickgl);
    if(game=="SBJ")SBJgame::SBJg(nickgl);
    if(game=="SM")SMgame::SMg();
    if(game=="snake"){SNAKEgame::SetNick(nickgl);SNAKEgame::SnakeGame();}
    if(game=="exit"){
            int ansbox;
            ansbox=MessageBox(NULL,"Do you want to sign out?","GameMenu",MB_YESNO | MB_ICONQUESTION);
            if(ansbox==7)menugame();
            flag2=0;
            menugame();
    }
    if(game!="TTT" && game!="enigma" && game!="DIS" && game!="SBJ" && game!="exit" && game!="SM" && game!="snake")main();
    menuorquit:
    system("CLS");
    cout<<"                         HELLO to GAME SHADOW MENU v 1.0"<<endl;
    cout<<"                         If you want to play new game write 'menu'"<<endl;
    cout<<"                         If you want to quit the game write 'quit'"<<endl;
    string menu;cout<<"                         ";
    cin>>menu;
    if(menu=="menu")main();
    if(menu=="quit")return ;
    if(menu!="quit" && menu!="menu")goto menuorquit;
}
int main()
{
    system("CLS");
    color(31);
    cout<<"                        HELLO to GAME SHADOW MENU v1.0"<<endl;
    menugame();
    return 0;
}
