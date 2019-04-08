#include <iostream>
#include <string>
#include <cmath>
#include<windows.h>
#include <algorithm>
using namespace std;
namespace enigmagame
{
    void color(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}
string s,cods="";
int s1;
char s2,s3;
int cod1()
{       if(s2==' '){cods=cods+" ";return 0;}
       if(s2=='4'){cods=cods+"6";return 0;}
    if(s2=='6'){cods=cods+"4";return 0;}
    if(s2==','){cods=cods+",";return 0;}
    if(s2=='?'){cods=cods+"?";return 0;}
    if(s2=='!'){cods=cods+"!";return 0;}
    if(s2=='.'){cods=cods+".";return 0;}
    if(s1-s2==0){cods=cods+'Z';return 0;}
    if(s1=='N'){cods=cods+char(142-s2);return 0;}
    if(s2=='M'){cods=cods+char(s1+2*(s2-char(s1)));return 0;}
    if(s2=='A'){cods=cods+char(155-char(s1));return 0;}
    if(s2=='Z'){cods=cods+char(s1);return 0;}
    if(char(s1)-s2==1){cods=cods+'Y';return 0;}
    if(char(s1)-s2==2){cods=cods+'X';return 0;}
    if(char(s1)-s2==3){cods=cods+'W';return 0;}
    if(char(s1)-s2==4){cods=cods+'V';return 0;}
    if(char(s1)-s2==5){cods=cods+'U';return 0;}
    if(char(s1)-s2==6){cods=cods+'T';return 0;}
    if(char(s1)-s2==7){cods=cods+'S';return 0;}
    if(char(s1)-s2==8){cods=cods+'R';return 0;}
    if(char(s1)-s2==9){cods=cods+'Q';return 0;}
    if(char(s1)-s2==10){cods=cods+'P';return 0;}
    if(char(s1)-s2==11){cods=cods+'O';return 0;}
    if(char(s1)-s2==-1){cods=cods+'N';return 0;}
    if(char(s1)-s2==-2){cods=cods+'O';return 0;}
    if(char(s1)-s2==-3){cods=cods+'P';return 0;}
    if(char(s1)-s2==-4){cods=cods+'Q';return 0;}
    if(char(s1)-s2==-5){cods=cods+'R';return 0;}
    if(char(s1)-s2==-6){cods=cods+'S';return 0;}
    if(char(s1)-s2==-7){cods=cods+'T';return 0;}
    if(char(s1)-s2==-8){cods=cods+'U';return 0;}
    if(char(s1)-s2==-9){cods=cods+'V';return 0;}
    if(char(s1)-s2==-10){cods=cods+'W';return 0;}
    if(char(s1)-s2==-11){cods=cods+'X';return 0;}



}
int cod2()
{if(s2==' '){cods=cods+" ";return 0;}
    if(s2=='4'){cods=cods+"6";return 0;}
    if(s2=='6'){cods=cods+"4";return 0;}
        if(s2==','){cods=cods+",";return 0;}
    if(s2=='?'){cods=cods+"?";return 0;}
    if(s2=='!'){cods=cods+"!";return 0;}
    if(s2=='.'){cods=cods+".";return 0;}
    if(char(s1)==s2){cods=cods+'Z';return 0;}
    if(char(s1)=='N'){cods=cods+char(char(s1)-s2+64);return 0;}
    if(s2=='M'){cods=cods+char(char(s1)-s2+64);return 0;}
    if(s2=='A'){cods=cods+char(155-char(s1));return 0;}
    if(s2=='Z'){cods=cods+char(s1);return 0;}
    if(char(s1)+s2==165){cods=cods+'C';return 0;}
    if(char(s1)+s2==164){cods=cods+'D';return 0;}
    if(char(s1)+s2==163){cods=cods+'E';return 0;}
    if(char(s1)+s2==162){cods=cods+'F';return 0;}
    if(char(s1)+s2==161){cods=cods+'G';return 0;}
    if(char(s1)+s2==160){cods=cods+'H';return 0;}
    if(char(s1)+s2==159){cods=cods+'I';return 0;}
    if(char(s1)+s2==158){cods=cods+'J';return 0;}
    if(char(s1)+s2==157){cods=cods+'K';return 0;}
    if(char(s1)+s2==156){cods=cods+'L';return 0;}
    if(char(s1)+s2==155){cods=cods+'A';return 0;}
    if(char(s1)+s2==154){cods=cods+'B';return 0;}
    if(char(s1)+s2==153){cods=cods+'C';return 0;}
    if(char(s1)+s2==152){cods=cods+'D';return 0;}
    if(char(s1)+s2==151){cods=cods+'E';return 0;}
    if(char(s1)+s2==150){cods=cods+'F';return 0;}
    if(char(s1)+s2==149){cods=cods+'G';return 0;}
    if(char(s1)+s2==148){cods=cods+'H';return 0;}
    if(char(s1)+s2==147){cods=cods+'I';return 0;}
    if(char(s1)+s2==146){cods=cods+'J';return 0;}
    if(char(s1)+s2==145){cods=cods+'K';return 0;}
    if(char(s1)+s2==144){cods=cods+'L';return 0;}



}
int cod3()
{if(s2==' '){cods=cods+" ";return 0;}
    if(s2=='4'){cods=cods+"6";return 0;}
    if(s2=='6'){cods=cods+"4";return 0;}
        if(s2==','){cods=cods+",";return 0;}
    if(s2=='?'){cods=cods+"?";return 0;}
    if(s2=='!'){cods=cods+"!";return 0;}
    if(s2=='.'){cods=cods+".";return 0;}
    if(char(s1)==s2){cods=cods+'Z';return 0;}

    if(s2=='N'){cods=cods+char(char(s1)+1);return 0;}
    if(char(s1)=='M'){cods=cods+char(s2-13);return 0;}
    if(s2=='A'){cods=cods+char(155-char(s1));return 0;}
    if(s2=='Z'){cods=cods+char(s1);return 0;}
    if(char(s1)+s2==144){cods=cods+'C';return 0;}
    if(char(s1)+s2==145){cods=cods+'D';return 0;}
    if(char(s1)+s2==146){cods=cods+'E';return 0;}
    if(char(s1)+s2==147){cods=cods+'F';return 0;}
    if(char(s1)+s2==148){cods=cods+'G';return 0;}
    if(char(s1)+s2==149){cods=cods+'H';return 0;}
    if(char(s1)+s2==150){cods=cods+'I';return 0;}
    if(char(s1)+s2==151){cods=cods+'J';return 0;}
    if(char(s1)+s2==152){cods=cods+'K';return 0;}
    if(char(s1)+s2==153){cods=cods+'L';return 0;}
    if(char(s1)+s2==154){cods=cods+'M';return 0;}
    if(char(s1)+s2==155){cods=cods+'A';return 0;}
    if(char(s1)+s2==156){cods=cods+'B';return 0;}
    if(char(s1)+s2==157){cods=cods+'C';return 0;}
    if(char(s1)+s2==158){cods=cods+'D';return 0;}
    if(char(s1)+s2==159){cods=cods+'E';return 0;}
    if(char(s1)+s2==160){cods=cods+'F';return 0;}
    if(char(s1)+s2==161){cods=cods+'G';return 0;}
    if(char(s1)+s2==162){cods=cods+'H';return 0;}
    if(char(s1)+s2==163){cods=cods+'I';return 0;}
    if(char(s1)+s2==164){cods=cods+'J';return 0;}
    if(char(s1)+s2==165){cods=cods+'K';return 0;}

}
int cod4()
{if(s2==' '){cods=cods+" ";return 0;}
    if(s2=='4'){cods=cods+"6";return 0;}
    if(s2=='6'){cods=cods+"4";return 0;}
    if(s2==','){cods=cods+",";return 0;}
    if(s2=='?'){cods=cods+"?";return 0;}
    if(s2=='!'){cods=cods+"!";return 0;}
    if(s2=='.'){cods=cods+".";return 0;}
    if(char(s1)==s2){cods=cods+'Z';return 0;}
    if(char(s1)=='N'){cods=cods+char(char(s1)-s2+90);return 0;}
    if(s2=='N'){cods=cods+char(char(s1)-1);return 0;}
    if(s2=='A'){cods=cods+char(155-char(s1));return 0;}
    if(s2=='Z'){cods=cods+char(s1);return 0;}
    if(s2-char(s1)==11){cods=cods+'O';return 0;}
    if(s2-char(s1)==10){cods=cods+'P';return 0;}
    if(s2-char(s1)==9){cods=cods+'Q';return 0;}
    if(s2-char(s1)==8){cods=cods+'R';return 0;}
    if(s2-char(s1)==7){cods=cods+'S';return 0;}
    if(s2-char(s1)==6){cods=cods+'T';return 0;}
    if(s2-char(s1)==5){cods=cods+'U';return 0;}
    if(s2-char(s1)==4){cods=cods+'V';return 0;}
    if(s2-char(s1)==3){cods=cods+'W';return 0;}
    if(s2-char(s1)==2){cods=cods+'X';return 0;}
    if(s2-char(s1)==1){cods=cods+'Y';return 0;}
    if(s2-char(s1)==0){cods=cods+'Z';return 0;}
    if(s2-char(s1)==-1){cods=cods+'N';return 0;}
    if(s2-char(s1)==-2){cods=cods+'O';return 0;}
    if(s2-char(s1)==-3){cods=cods+'P';return 0;}
    if(s2-char(s1)==-4){cods=cods+'Q';return 0;}
    if(s2-char(s1)==-5){cods=cods+'R';return 0;}
    if(s2-char(s1)==-6){cods=cods+'S';return 0;}
    if(s2-char(s1)==-7){cods=cods+'T';return 0;}
    if(s2-char(s1)==-8){cods=cods+'U';return 0;}
    if(s2-char(s1)==-9){cods=cods+'V';return 0;}
    if(s2-char(s1)==-10){cods=cods+'W';return 0;}
    if(s2-char(s1)==-11){cods=cods+'X';return 0;}

}
int enigmag()
{
    color(15);
    system("CLS");
    int n,lol;
    int p;

    cout<<"If you want to quit write : '/quit'"<<endl;
    int flag=1,stop=1;
    while(stop == 1)
    {

    cout<<"To not bug please write with CAPSLOCK"<<endl;
    cout<<endl;cout<<"                  Write text  ";
    getline(cin, s);cout<<endl;
    color(10);

    cout<<"                  Your text is : "<<s<<endl;color(15);
    if(s=="/quit")return 0;
    n=s.size();
    cods=cods+s[0];
    for(int i=0;i<n-1;i++)
    {
        lol=i;
        if(i>=26)lol=i-26;
        s1=lol+65;
        s3=s[1];
        if(s3>96)s2=s3-32;
        else s2=s3;
        s=s.erase(0,1);
        if(s1<78&&s2<78)cod1();
        if(s1>77&&s2<78)cod2();
        if(s1<78&&s2>77)cod3();
        if(s1>77&&s2>77)cod4();
    }
    color(12);
    cout <<"                  Coded text is : "<<cods<<endl;color(15);
    cods="";
    cout<<endl;
    cout<<"If you want to quit write quit : '/quit'"<<endl;
    if(flag==1){flag=2;system("CLS");}
    }
    color(31);

    return 0;
}
}
