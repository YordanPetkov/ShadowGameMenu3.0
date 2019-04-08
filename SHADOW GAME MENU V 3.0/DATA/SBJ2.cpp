#include<iostream>
#include<windows.h>
#include<string>
#include <time.h>
#include <ctime>
using namespace std;
namespace SBJgame
{

int deck[54],sum=0,sum11=0,values[10],valuesr,csum=0,csum11=0,cvalues[10],bet,gsum,gcsum,brmycards=2,brccards=2,pot,cmoney=2000,mymoney=2000;
char mycards[11][11],cccards[11][11];
string nickname;
void clearGAME()
{
    for(int i=1;i<=54;i++)
    {
        deck[i]=0;
        sum=0;
        sum11=0;
        if(i<10){values[i]=0;cvalues[i]=0;}
        valuesr=0;
        csum=0;
        csum11=0;
        gsum=0;
        gcsum=0;
        brmycards=2;
        brccards=2;
        pot=0;


    }
}
void color(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}

class card{
    public:
    int value , symbol ;

    void cards(int);
    char valuecard(int);
    char symbolcard(int);
    };

   void card::cards(int pos)
    {
        value = pos-(pos/13)*13;
        symbol = pos/13+2;
        if(pos%13==0)value=13;
        if(pos<13)symbol=pos/13+3;
    }

   char card::valuecard(int pos)
    {
            cards(pos);
            if(value==1){valuesr=1;return 'A';}
            if(value==2){valuesr=2;return '2';}
            if(value==3){valuesr=3;return '3';}
            if(value==4){valuesr=4;return '4';}
            if(value==5){valuesr=5;return '5';}
            if(value==6){valuesr=6;return '6';}
            if(value==7){valuesr=7;return '7';}
            if(value==8){valuesr=8;return '8';}
            if(value==9){valuesr=9;return '9';}
            if(value==10){valuesr=10;return 'T';}
            if(value==11){valuesr=10;return 'J';}
            if(value==12){valuesr=10;return 'Q';}
            if(value==13){valuesr=10;return 'K';}
    }

   char card::symbolcard(int pos)
    {
        cards(pos);
        return symbol;
    }
card cards[10],ccards[10];
void visualgame(int brccards,int brmycards,int csum11,int csum,int mysum11,int mysum,int cmoney,int mymoney,int pot,string nickname)
{
    system("CLS");
    color(41);
    cout<<" =============================================================================="<<endl;
    cout<<"                         Shadow Black Jack <SBJ> v1.0 2016"<<endl;
    cout<<" =============================================================================="<<endl;
    cout<<"                                  Have Fun !"<<endl;
color(41);cout<<"   ";
                     for(int i=1;i<=brccards;i++)
                     cout<<"-    ";
                     cout<<endl;
color(41);cout<<"   ";
                    for(int i=1;i<=brccards;i++)
                    {
                        if(cccards[i][2]==5 || cccards[i][2]==6)color(32);
                        else color(44);
                        cout<<"|"<<cccards[i][1]<<"| ";
                    }
                    color(41);
                    cout<<endl;
color(41);cout<<"   ";
                    for(int i=1;i<=brccards;i++)
                    {
                        if(cccards[i][2]==5 || cccards[i][2]==6)color(32);
                        else color(44);
                        cout<<"|"<<cccards[i][2]<<"| ";
                    }
                    color(41);
                    cout<<endl;
color(41);cout<<"   ";
                    for(int i=1;i<=brccards;i++)
                     cout<<"-    ";
                     cout<<endl;
    if(csum11==0)cout<<"  "<<cmoney<<"$            sum : "<<csum<<endl;
    else cout<<"  "<<cmoney<<"$            sum : "<<csum<<"/"<<csum11<<endl;
    cout<<endl;cout<<endl;cout<<endl;
    cout<<"                                    pot : "<<pot<<"$"<<endl;
    cout<<endl;cout<<endl;cout<<endl;
    if(mysum11==0)cout<<"  sum : "<<mysum<<"                 "<<mymoney<<"$"<<endl;
    else cout<<"  sum : "<<mysum<<"/"<<mysum11<<"                 "<<mymoney<<"$"<<endl;

    cout<<"    ";
    for(int i=1;i<=brmycards;i++)
    {
        if(mycards[i][2]==5 || mycards[i][2]==6)color(32);
                        else color(44);
                     cout<<"-   ";
    }
    color(41);
                     cout<<"    ";

                     cout<<endl;
                     cout<<"   ";
    for(int i=1;i<=brmycards;i++)
                    {
                        if(mycards[i][2]==5 || mycards[i][2]==6)color(32);
                        else color(44);
                        cout<<"|"<<mycards[i][1]<<"| ";
                    }
                    color(41);
                    cout<<"   ";
                    cout<<endl;
                    cout<<"   ";
    for(int i=1;i<=brmycards;i++)
                    {
                        if(mycards[i][2]==5 || mycards[i][2]==6)color(32);
                        else color(44);
                        cout<<"|"<<mycards[i][2]<<"| ";
                    }
                    color(41);
                    cout<<"   ";
                    cout<<endl;
                    cout<<"    ";
    for(int i=1;i<=brmycards;i++)
    {
        if(mycards[i][2]==5 || mycards[i][2]==6)color(32);
                        else color(44);
                     cout<<"-   ";
    }
    color(41);
                     cout<<"  ";
                     cout<<endl;
    cout<<"                               "<<nickname<<endl;


}
void rules()
{
    string ans;
    system("CLS");
    cout<<"Blackjack is pretty simple."<<endl;
    cout<<"The basic premise of the game is that "<<endl;
    cout<<"you want to have a hand value that is closer to 21"<<endl;
    cout<<"than that of the dealer, without going over 21."<<endl;
    cout<<"Other players at the table are of no concern. "<<endl;
    cout<<"Your hand competes only against the hand of the dealer."<<endl;
    cout<<"The rules of play for the dealer are strictly dictated,"<<endl;
    cout<<"leaving no decisions up to the dealer."<<endl;
    cout<<"Therefore, there is no problem  with the dealer or any of the other players "<<endl;
    cout<<"at the table seeing the cards in your hand. "<<endl;
    cout<<"In fact, if you are playing at a shoe game, "<<endl;
    cout<<"the player cards are all dealt face up."<<endl;
    cout<<endl;cout<<endl;
    cout<<"If you are ready write 'ready'"<<endl;
    cin>>ans;
    if(ans!="ready")rules();
    system("CLS");
}
void startgamecard ()
{
    int r;
    int r1;
    for(int i=1;i<10;i++)
    {

    random:
    r=rand()%54+1;
    if(deck[r]==1)goto random;
    else {deck[r]=1;mycards[i][1]=cards[i].valuecard(r);values[i]=cards[i].value;mycards[i][2]=cards[i].symbolcard(r);}
    }
    for(int i=1;i<10;i++)
    {

    random1:
    r=rand()%54+1;
    if(deck[r]==1)goto random1;
    else {deck[r]=1;cccards[i][1]=ccards[i].valuecard(r);cvalues[i]=ccards[i].value;cccards[i][2]=ccards[i].symbolcard(r);}
    }
    visualgame(0,0,0,0,0,0,cmoney,mymoney,0,nickname);
}
void pickcard(int ii)
{
    brmycards++;
    if(values[ii]<10)sum=sum+values[ii];
    else sum=sum+10;
    if(mycards[ii][1]=='A')sum11=sum11+11;
    else if(values[ii]<10)sum11=sum11+values[ii];
    else sum11=sum11+10;
    color(41);
}
void pickccard(int ii)
{
    brccards++;
    if(cvalues[ii]<10)csum=csum+cvalues[ii];
    else csum=csum+10;
    if(cccards[ii][1]=='A')csum11=csum11+11;
    else if(cvalues[ii]<10)csum11=csum11+cvalues[ii];
    else csum11=csum11+10;
    color(41);
}
void compgame()
{
    color(41);
    if(cvalues[1]<10)csum=csum+cvalues[1];if(cvalues[1]>9) csum=csum+10;
    if(cvalues[2]<10)csum=csum+cvalues[2];if(cvalues[2]>9) csum=csum+10;
    if(cccards[1][1]=='A')csum11=csum11+11;
    else if(cvalues[1]<10)csum11=csum11+cvalues[1];
        else csum11+=10;
          if(cccards[2][1]=='A')csum11=csum11+11;
           else if(cvalues[2]<10)csum11=csum11+cvalues[2];
                else csum11+=10;



                int ii=3;

    cardcheckwrite :
       if(csum>21 && csum11>21){gcsum=csum;return;}
       if(csum==csum11) {visualgame(brccards,brmycards,0,csum,0,gsum,cmoney,mymoney,pot,nickname);gcsum=csum;}
       else if(csum>21 || csum-csum11<10){visualgame(brccards,brmycards,0,csum11,0,gsum,cmoney,mymoney,pot,nickname);gcsum=csum11;}
             else if(csum11>21){visualgame(brccards,brmycards,0,csum,0,gsum,cmoney,mymoney,pot,nickname);gcsum=csum;}
                   else {visualgame(brccards,brmycards,csum11,csum,0,gsum,cmoney,mymoney,pot,nickname);if(csum>csum11)gcsum=csum;else gcsum=csum11;}
    if(gcsum<gsum){pickccard(ii);ii++;goto cardcheckwrite;}
    else return;
}
void game()
{

    string cardcheck;
    if(values[1]<10)sum=sum+values[1];if(values[1]>9) sum=sum+10;
    if(values[2]<10)sum=sum+values[2];if(values[2]>9) sum=sum+10;
    if(mycards[1][1]=='A')sum11=sum11+11;
    else if(values[1]<10)sum11=sum11+values[1];
        else sum11+=10;
          if(mycards[2][1]=='A')sum11=sum11+11;
           else if(values[2]<10)sum11=sum11+values[2];
                else sum11+=10;

    int ii=3;

    cardcheckwrite :
        if(sum>21 && sum11>21){gsum=22;return;}
       if(sum==sum11) visualgame(0,brmycards,0,0,0,sum,cmoney,mymoney,pot,nickname);
       else if(sum>21 || sum>sum11){visualgame(0,brmycards,0,0,0,sum11,cmoney,mymoney,pot,nickname);}
             else if(sum11>21){visualgame(0,brmycards,0,0,0,sum,cmoney,mymoney,pot,nickname);}
                   else {visualgame(0,brmycards,0,0,sum11,sum,cmoney,mymoney,pot,nickname);}

    cardorcheck:
    cout<<"If you want card write 'card' "<<endl;
    cout<<"If you want to check write 'check' "<<endl;
    cin>>cardcheck;
    if(cardcheck=="card"){pickcard(ii);ii++;goto cardcheckwrite;}
    else if(cardcheck=="check"){if(sum>sum11 && sum<22)gsum=sum; if(sum11>sum && sum11<22)gsum=sum11;if(sum11==sum && sum11<22)gsum=sum11;visualgame(brccards,brmycards,0,0,0,gsum,cmoney,mymoney,pot,nickname);compgame();}
         else goto cardorcheck;

}
int gameon()
{
    betpot:
    system("CLS");
    cout<<"                          SHADOW BLACKJACK v 1.0"<<endl; cout<<endl; cout<<endl;
    cout<<"                                YOUR MONEY ARE "<<mymoney<<endl;
    cout<<endl;
    string ans,b;
    int regbet;

    if(mymoney<cmoney){cout<<"                            Write your bet (1-"<<mymoney<<") : ";regbet=mymoney;}
    if(mymoney>cmoney){cout<<"                            Write your bet (1-"<<cmoney<<") : ";regbet=cmoney;}
    if(mymoney==cmoney){cout<<"                            Write your bet (1-"<<mymoney<<") : ";regbet=mymoney;}

    cin>>bet;
    if(bet>regbet || bet<1)goto betpot;
            pot=2*bet;
    mymoney=mymoney-bet;
    cmoney=cmoney-bet;
    newcard:
    startgamecard();
    game();
    system("CLS");
    visualgame(brccards,brmycards,0,gcsum,0,gsum,cmoney,mymoney,pot,nickname);
    cout<<endl;
    if((gsum>gcsum || gcsum>21) && gsum<22){cout<<endl;cout<<"                           YOU WON"<<endl;cout<<"Write something to continue "<<endl;cout<<endl;cin>>b;return 1;}
    if((gsum<gcsum || gsum>21)&& gcsum<22){cout<<endl;cout<<"                           YOU LOSE"<<endl;cout<<"Write something to continue "<<endl;cout<<endl;cin>>b;return 2;}
    if(gsum==gcsum ){cout<<endl;cout<<"                           DRAW"<<endl;cout<<"Write something to continue "<<endl;cout<<endl;cin>>b;return 3;}
}
int SBJg(string nick1)
{
    string ans;
    int winner,flag=0;
    sum=0;sum11=0;
    color(41);
    system("CLS");
    srand(time(NULL));

    cout<<"                          SHADOW BLACKJACK v 1.0"<<endl;
    nickname=nick1;
    cleargame:
    clearGAME();
    system("CLS");
    playorno:
        cout<<"                          SHADOW BLACKJACK v 1.0"<<endl;
    cout<<"                         If you want to see the rules write 'rules'"<<endl;
    cout<<"                         If you want to quit the game write 'quit'"<<endl;
    cout<<"                         If you want to start the game write 'play'"<<endl;
    cout<<"                             -";cin>>ans;
    if(ans=="rules"){rules();goto playorno;}
    if(ans=="quit")return 0;
    if(ans!="play"){goto playorno;}
    cout<<endl;
    if(flag==0)
    {

    cout<<"                          SHADOW BLACKJACK v 1.0"<<endl;
    money:
        cout<<"                          Write with how many money you wand to start : ";cin>>mymoney;
        if(mymoney>1000000 || mymoney < 0)goto money;cmoney=mymoney;
    }
        flag=1;

    winner=gameon();
    cout<<endl;
    if(winner==1){mymoney=mymoney+pot;pot=0;}
    if(winner==2){cmoney=cmoney+pot;pot=0;}
    if(winner==3){mymoney=mymoney+bet;cmoney=cmoney+bet;pot=0;}
    if(winner==0)return 0;
    if(mymoney>0 && cmoney>0){goto cleargame;}
    system("CLS");
    if(mymoney==0)
    {
        cout<<"                            Thanks for playing"<<endl;
        cout<<"                          SHADOW BLACKJACK v 1.0"<<endl;
        cout<<"                             GAME OVER"<<endl;
        cout<<"                           YOU ARE HAVING FALIT"<<endl;
    }
    if(cmoney==0)
    {
        cout<<"                            Thanks for playing"<<endl;
        cout<<"                          SHADOW BLACKJACK v 1.0"<<endl;
        cout<<"                             GAME OVER"<<endl;
        cout<<"                           YOU ARE THE WINNER"<<endl;
        cout<<"                                GOOD"<<endl;
        cout<<"                             NOW YOU HAVE MUCH MONEY"<<endl;
    }
    string b;
    cout<<"Write something to continue "<<endl;cout<<endl;cin>>b;

return 0;
}
}

