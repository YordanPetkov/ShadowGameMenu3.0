#include<iostream>
#include<cstdlib>
#include<string>
#include <time.h>
#include <ctime>
#include <windows.h>
#include<conio.h>
using namespace std;
namespace disgame
{
    int DISg(string nick1);
    void color(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}
int posplayer,flag1=1;
string nickpl,nick[5],difbot1="easy",difbot2="normal",difbot3="hard",check[5],nickgl;
int a[7],bra[7],b[7],brb[7],c[7],brc[7],d[7],brd[7],zalozi[25][10],plizbor,pas[5],poslzalbr;
int poslzalz,vuzmzalog[8],posledniqigral=4,poslzaligr[5][4],f=4,s=4,t=4,l=4,all[7];

void rules() //this is the rules
{
    system("CLS");
    string ans;
    cout<<"      You and every bot have five dice."<<endl;
    cout<<"    You must bet how many dice from same value there are."<<endl;
    cout<<"    You can bet only bets whose are higher* than last bets."<<endl;cout<<endl;
    cout<<"    highter bet -> the value of your bet is higher than the value of last bets "<<endl;
    cout<<"    or the number of your bet is higher than number of last bets."<<endl;
    cout<<"    If you want to keep your last bet , you must say 'check' " <<endl;
    cout<<"                        HAVE FUN!!"<<endl;
    cout<<endl;
    cout<<"    Press any key to continue "<<endl;
    cout<<"    -> ";getch();


}
string difans(int f) //answer of people about the bot's difficulty
{
    string ans23;
    if(f==2)cout<<"              ";
    cin>>ans23;
   if(ans23=="easy" || ans23=="normal" || ans23=="hard" || ans23=="expert")return ans23;
   difans(2);
}
int m;
void regans(int a,int b)
{
    cin>>m;
    if(m<a || m>b){
            cout<<"                                                      ";
            regans(a,b);
    }
}
void start() // options of game
{
    string ans,ans2;
    int ans1;
    system("CLS");
    if(flag1==1)
    {
        flag1=2;
    cout<<"           W E L L C O M E  T o  Dice in Shadow   v 1 . 2 "<<endl;
    cout<<"                       author : YORDAN PETKOV             "<<endl;
    cout<<"                                  Have Fun !"<<endl;
    cout<<"       From whose possition you want to start 1-4 : ";regans(1,4);posplayer=m;nick[posplayer]=nickpl;
    cout<<"       Do you want to choose the difficulty of bots or be random? "<<endl;
    cout<<"                    choose / random : ";    cin>>ans;
    }
    else
    {
        cout<<"           W E L L C O M E  T o  Dice in Shadow   v 1 . 2 "<<endl;
        cout<<"                       author : YORDAN PETKOV             "<<endl;
        cout<<"                                  Have Fun !"<<endl;
        cout<<"       Write your nickname : "<<nickpl<<endl;
        cout<<"       From whose possition you want to start 1-4 : "<<posplayer<<endl;
        cout<<"       Do you want to choose the difficulty of bots or be random? "<<endl;
        cout<<"                choose / random : ";cin>>ans;
    }
    cout<<endl;
    if(ans=="choose")
    {
        cout<<"       easy / normal / hard / expert "<<endl;
        cout<<"       BOT1 : ";
        difbot1=difans(1);
        cout<<"       BOT2 : ";
        difbot2=difans(1);
        cout<<"       BOT3 : ";
        difbot3=difans(1);
        }


    if(ans!="random" && ans!="choose")start();


}
int rulestart()// turn on the rules or the start
{
    system("CLS");
    string ans;
    cout<<"           W E L L C O M E  T o  Dice in Shadow   v 1 . 2 "<<endl;
    cout<<"                       author : YORDAN PETKOV             "<<endl;
    cout<<"                                  Have Fun !"<<endl;
    cout<<endl;cout<<endl;cout<<endl;
    cout<<"                  To see the rules write : 'rules' "<<endl;
    cout<<"                  To start the game write : 'start' "<<endl;
    cout<<"                  To quit the game write : 'quit' "<<endl;
    cout<<"                                            -";cin>>ans;
    if(ans=="rules")rules();
    if(ans=="quit")return 1;
    if(ans!="start")rulestart();
    if(ans=="start")start();

}
string desktop(int pos)
{
    string ans;
    system("CLS");
    nick[2]="BOT1";
    nick[3]="BOT2";
    nick[4]="BOT3";
    cout<<" =============================================================================="<<endl;
    cout<<"                         Dice in Shadow <DiS> v1.2 2016"<<endl;
    cout<<" =============================================================================="<<endl;
    cout<<"                                  Have Fun !"<<endl;
    cout<<" Last bets                                                       Who is check  "<<endl;


        if(pos==1)
        {
            cout<<nickpl<<": "<<poslzaligr[0][1]<<" "<<poslzaligr[0][2]<<"                                          "<<check[1]<<endl;
            cout<<nick[2]<<": "<<poslzaligr[1][1]<<" "<<poslzaligr[1][2]<<"                                           "<<check[2]<<endl;
            cout<<nick[3]<<": "<<poslzaligr[2][1]<<" "<<poslzaligr[2][2]<<"                                           "<<check[3]<<endl;
            cout<<nick[4]<<": "<<poslzaligr[3][1]<<" "<<poslzaligr[3][2]<<"                                           "<<check[4]<<endl;

        }
        if(pos==2)
        {
            cout<<nick[2]<<": "<<poslzaligr[1][1]<<" "<<poslzaligr[1][2]<<"                                           "<<check[2]<<endl;
            cout<<nickpl<<": "<<poslzaligr[0][1]<<" "<<poslzaligr[0][2]<<"                                            "<<check[1]<<endl;
            cout<<nick[3]<<": "<<poslzaligr[2][1]<<" "<<poslzaligr[2][2]<<"                                           "<<check[3]<<endl;
            cout<<nick[4]<<": "<<poslzaligr[3][1]<<" "<<poslzaligr[3][2]<<"                                           "<<check[4]<<endl;
        }
        if(pos==3)
        {
            cout<<nick[2]<<": "<<poslzaligr[1][1]<<" "<<poslzaligr[1][2]<<"                                           "<<check[2]<<endl;
            cout<<nick[3]<<": "<<poslzaligr[2][1]<<" "<<poslzaligr[2][2]<<"                                           "<<check[3]<<endl;
            cout<<nickpl<<": "<<poslzaligr[0][1]<<" "<<poslzaligr[0][2]<<"                                            "<<check[1]<<endl;
            cout<<nick[4]<<": "<<poslzaligr[3][1]<<" "<<poslzaligr[3][2]<<"                                           "<<check[4]<<endl;
        }
        if(pos==4)
        {
            cout<<nick[2]<<": "<<poslzaligr[1][1]<<" "<<poslzaligr[1][2]<<"                                           "<<check[2]<<endl;
            cout<<nick[3]<<": "<<poslzaligr[2][1]<<" "<<poslzaligr[2][2]<<"                                           "<<check[3]<<endl;
            cout<<nick[4]<<": "<<poslzaligr[3][1]<<" "<<poslzaligr[3][2]<<"                                           "<<check[4]<<endl;
            cout<<nickpl<<": "<<poslzaligr[0][1]<<" "<<poslzaligr[0][2]<<"                                            "<<check[1]<<endl;
        }

    cout<<"                               Version : DiS v1.1                          "<<endl;
    cout<<"                               Author  : Yordan Petkov                           "<<endl;
    cout<<"---------------------                                       -------------------"<<endl;
    cout<<"                                    YOUR DICE"<<endl;
    cout<<"                                   -----------"<<endl;
    color(43);cout<<"                                   |"<<a[0]<<"|"<<a[1]<<"|"<<a[2]<<"|"<<a[3]<<"|"<<a[4]<<"|"<<endl;color(47);
    cout<<"                                   -----------"<<endl;
    cout<<endl;
    cout<<"                              To bet write 'bet' "<<endl;
    cout<<"        G A M E               To check write 'check'              V E R S I O N"<<endl;
    cout<<" P R O G R A M M I N G        To see the rules write 'rules'          1 . 1"<<endl;
    cout<<"          B Y                 "<<endl;
    if(check[1]==nickpl)return nick[2];
    cout<<"                                                  -";cin>>ans;
    if(ans!="bet" && ans!="check" && ans!="rules")desktop(pos);
    return ans;

    }
void podrejdane(int first)
{
    if(s==first)
    {
        s=f;
        f=first;
    }

    if(t==first)
    {
        t=s;
        s=f;
        f=first;
    }

    if(l==first)
    {
        l=t;
        t=s;
        s=f;
        f=first;
    }
}
void populvanezalozi(int broi,int zar4e)
{
    for(int i=1;i<=broi;i++)
        for(int j=1;j<=zar4e;j++)
              {
                   zalozi[i][j]=1;
              }
         poslzalbr=broi;
         poslzalz=zar4e;
         for(int i=1;i<=zar4e;i++)
         {
             if(vuzmzalog[i]<broi)vuzmzalog[i]=broi;

         }

}
bool proverka(int broi,int zar4e)
{
    if(broi>20 || zar4e>6)return 0;
    if(broi<0 || zar4e<0)return 0;
    if(zalozi[broi][zar4e]==1)return 0;
    if(zalozi[broi][zar4e]==0)return 1;
}

int player()
{
    system("CLS");
    if(check[1]==nickpl)return 0;
    if(pas[0]==1)return 0;
    if(posledniqigral==0)return 0;
    int vhodplbr,vhodplz;
    string zalpas;
    desktopa:
    zalpas=desktop(posplayer);
    if(zalpas!="bet" && zalpas!="check"){player();}
    if(zalpas=="rules"){rules();goto desktopa;}
    if(zalpas=="bet")
    {
        cout<<"                                    Value : ";cin>>vhodplbr;
        cout<<"                                    Dice : ";cin>>vhodplz;
        if(!proverka(vhodplbr,vhodplz)){player();}
        populvanezalozi(vhodplbr,vhodplz);posledniqigral=0;
    poslzaligr[0][1]=vhodplbr;
    poslzaligr[0][2]=vhodplz;
    podrejdane(0);
    }
    if(zalpas=="check")
    {
        pas[0]=1;
        check[1]=nickpl;
    }
    return 0;

}
int bot1()
{
    if(pas[1]==1)return 0;
    if(posledniqigral==1)return 0;
    for(int i=1;i<=poslzalz;i++)
    {
        if(brb[i]+2>poslzalbr)
            {
                if(proverka(brb[i]+2,i)==1)
                {
                    populvanezalozi(brb[i]+2,i);
                    posledniqigral=1;
                    poslzaligr[1][1]=brb[i]+2;
                    poslzaligr[1][2]=i;
                    podrejdane(1);
                    return 0;
                }


            }
    }
    for(int i=1;i<=6;i++)
    {
        if(brb[i]+2>vuzmzalog[i])
        {
            if(proverka(brb[i]+2,i)==1)
                {
                    populvanezalozi(brb[i]+2,i);
                    posledniqigral=1;
                    poslzaligr[1][1]=brb[i]+2;
                    poslzaligr[1][2]=i;
                    podrejdane(1);
                    return 0;
                }
        }
    }
    check[2]="BOT1";
    pas[1]=1;
    return 0;
}
int bot2()
{
    if(pas[2]==1)return 0;
    if(posledniqigral==2)return 0;
    for(int i=1;i<=poslzalbr;i++)
    {
        if(brc[poslzalz+1]>=i)
        {
            if(proverka(brc[poslzalz+1]+1,poslzalz+1)==1)
                {
                    if(brc[poslzalz+1]+1>6)return 0;
                    populvanezalozi(brc[poslzalz+1]+1,poslzalz+1);
                    posledniqigral=2;
                    poslzaligr[2][1]=brc[poslzalz+1]+1;
                    poslzaligr[2][2]=poslzalz+1;
                    podrejdane(2);
                    return 0;
                }
        }
    }
    for(int i=1;i<=6;i++)
    {
        if(brc[i]>vuzmzalog[i])
        {
            if(proverka(brc[i],i)==1)
                {
                    if(brc[i]>6)return 0;
                    populvanezalozi(brc[i],i);
                    posledniqigral=2;
                     poslzaligr[2][1]=brc[i];
                    poslzaligr[2][2]=i;
                    podrejdane(2);
                    return 0;
                }
        }
    }
    check[3]="BOT2";
    pas[2]=1;
    return 0;
}
int bot3()
{
    if(pas[3]==1)return 0;
    if(posledniqigral==3)return 0;
    for(int i=1;i<=poslzalz;i++)
    {
        if(brd[i]+3>poslzalbr)
            {
                if(proverka(brd[i]+3,i)==1)
                {
                    populvanezalozi(brd[i]+3,i);
                    posledniqigral=3;
                    poslzaligr[3][1]=brd[i]+3;
                    poslzaligr[3][2]=i;
                    podrejdane(3);
                    return 0;
                }


            }
    }
    for(int i=1;i<=6;i++)
    {
        if(brd[i]+3>vuzmzalog[i])
        {
            if(proverka(brd[i]+3,i)==1)
                {
                    populvanezalozi(brd[i]+3,i);
                    posledniqigral=3;
                    poslzaligr[3][1]=brd[i]+3;
                    poslzaligr[3][2]=i;
                    podrejdane(3);
                    return 0;
                }
        }
    }
    check[4]="BOT3";
    pas[3]=1;
    return 0;
}
int ple1()
{

    if(pas[0]+pas[1]+pas[2]+pas[3]==3)return 0;
    cout<<endl;cout<<endl;cout<<endl;
    f=0;
    s=1;
    t=2;
    l=3;
    if(pas[0]+pas[1]+pas[2]+pas[3]<3)
    {
        player();
        bot1();
        bot2();
        bot3();
        ple1();
    }
    return 0;


}
int ple2()
{

    if(pas[0]+pas[1]+pas[2]+pas[3]==3)return 0;
    cout<<endl;cout<<endl;cout<<endl;
    f=1;
    s=0;
    t=2;
    l=3;
    if(pas[0]+pas[1]+pas[2]+pas[3]<3)
    {

        bot1();
        player();
        bot2();
        bot3();
        ple2();
    }
    return 0;


}
int ple3()
{

    if(pas[0]+pas[1]+pas[2]+pas[3]==3)return 0;
    cout<<endl;cout<<endl;cout<<endl;
    f=1;
    s=2;
    t=0;
    l=3;
    if(pas[0]+pas[1]+pas[2]+pas[3]<3)
    {

        bot1();
        bot2();
        player();
        bot3();

        ple3();
    }
    return 0;


}
int ple4()
{

    if(pas[0]+pas[1]+pas[2]+pas[3]==3)return 0;
    cout<<endl;cout<<endl;cout<<endl;
    f=1;
    s=2;
    t=3;
    l=0;
    if(pas[0]+pas[1]+pas[2]+pas[3]<3)
    {

        bot1();
        bot2();
        bot3();
        player();
        ple4();
    }
    return 0;


}
void sumall()
{
    for(int i=1;i<=6;i++)
    {
        all[i]=bra[i]+brb[i]+brc[i]+brd[i];
        cout<<"                                    ALL "<<i<<" are "<<all[i]<<endl;
    }
}
int winner()
{
    sumall();
    if(poslzaligr[f][1]==all[poslzaligr[f][2]])
    {
        if(f==0)cout<<"                                    YOU WIN"<<endl;
        else
            if(f<4)cout<<"                BOT"<<f<<" WIN. You lose . Try again :)"<<endl;
            return f;
    }

    if(poslzaligr[s][1]==all[poslzaligr[s][2]])
    {
        if(s==0)cout<<"                                    YOU WIN"<<endl;
        else
           if(s<4) cout<<"                BOT"<<s<<" WIN. You lose . Try again :)"<<endl;
            return s;
    }

    if(poslzaligr[t][1]==all[poslzaligr[t][2]])
    {
        if(t==0)cout<<"                                    YOU WIN"<<endl;
        else
            if(t<4)cout<<"                BOT"<<t<<" WIN. You lose . Try again :)"<<endl;
            return t;
    }

    if(poslzaligr[l][1]==all[poslzaligr[l][2]])
    {
        if(l==0)cout<<"                                    YOU WIN"<<endl;
        else
        {
            if(l<4)cout<<"                BOT"<<l<<" WIN. You lose . Try again :)"<<endl;
            return l;
        }

    }
    return 4;
}
int DISg(string nick1)
{
    nickgl=nick1;
    nickpl=nick1;
    color(47);
    system("CLS");
    nick[2]="BOT1";
    nick[3]="BOT2";
    nick[4]="BOT3";
    int win;
    string ans;
    srand(time(NULL));
    system("CLS");
    if(rulestart()==1)return 0;
    for(int i=0;i<5;i++)
    {
    a[i] = rand()%6+1;
    b[i] = rand()%6+1;
    c[i] = rand()%6+1;
    d[i] = rand()%6+1;
    }
    for(int i=0;i<5;i++)
    {
        bra[a[i]]++;
        brb[b[i]]++;
        brc[c[i]]++;
        brd[d[i]]++;
    }

    if(posplayer == 1)ple1();
    if(posplayer == 2)ple2();
    if(posplayer == 3)ple3();
    if(posplayer == 4)ple4();

        if(desktop(posplayer)=="rules")rules();
        cout<<"                                    BOT1 DICE"<<endl;
    cout<<"                                   -----------"<<endl;
    cout<<"                                   |"<<b[0]<<"|"<<b[1]<<"|"<<b[2]<<"|"<<b[3]<<"|"<<b[4]<<"|"<<endl;
    cout<<"                                   -----------"<<endl;
        cout<<"                                    BOT2 DICE"<<endl;
    cout<<"                                   -----------"<<endl;
    cout<<"                                   |"<<c[0]<<"|"<<c[1]<<"|"<<c[2]<<"|"<<c[3]<<"|"<<c[4]<<"|"<<endl;
    cout<<"                                   -----------"<<endl;
        cout<<"                                    BOT3 DICE"<<endl;
    cout<<"                                   -----------"<<endl;
    cout<<"                                   |"<<d[0]<<"|"<<d[1]<<"|"<<d[2]<<"|"<<d[3]<<"|"<<d[4]<<"|"<<endl;
    cout<<"                                   -----------"<<endl;
        cout<<endl;cout<<endl;cout<<endl;cout<<endl;

    win=winner();

    cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    if(win==0)cout<<"                          $$$$$$$$$$$$$$$ YOU WIN $$$$$$$$$$$$$$$"<<endl;
    if(win==1||win==2||win==3)cout<<"                          *************** YOU LOSE ***************"<<endl;
    if(win==4)cout<<"                          *************** DRAW ***************"<<endl;
     cout<<endl;cout<<endl;cout<<endl;cout<<endl;
     restartgame:
     string restart;
     cout<<"                                   If you want to restart write 'restart'."<<endl;
     cout<<"                                   If you want to quit write 'quit'."<<endl;
     cin>>restart;
     if(restart=="restart")DISg(nickgl);
     if(restart!="quit")goto restartgame;

     color(31);


return 0;
}
}
