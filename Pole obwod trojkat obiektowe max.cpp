#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;




class trojkat
{
  private:
   double a1, a2, a3;
   double h1, h2, h3;
  public:
   void set_a1(double x) {a1=x;}
   void set_a2(double x) {a2=x;}
   void set_a3(double x) {a3=x;}
   void set_a1a2a3(double a, double b, double c) { a1=a; a2=b; a3=c;}
   char spr();
   double pole();
   double obwod();
};

char trojkat::spr()
{
if( (a1+a2<a3) || (a2+a3<a1) || (a1+a3<a2) )
 return 1;
else 
 return 0; //nie mo¿na utwozyc trójkata
}


double trojkat::pole()
{
//Ko¿ystamy ze wzrou Herona

if( spr()==1 ) 
 { 
 double p=(a1+a2+a3)/2;
 return sqrt( p * (p-a1) * (p-a2) * (p-a3) );
 }
 else 
  {
   cout<<"Nie mozna utwozyc trojkata z takich odcinkow."<<endl;
   return 0;
  }
}

double trojkat::obwod()
{
if( spr()==1 )
 return a1+a2+a3;
 else 
  {
   cout<<"Nie mozna utwozyc trojkata z takich odcinkow."<<endl;
   return 0;
  }
}


int main()
{
double a,b,c;
int x;
int y=1;
trojkat trojkat1; //obiekt klasy trojkat

double pole;
double obwod;

while(y==1)
{
cout<<"Witamy!"<<endl;
cout<<"Dzialania:"<<endl;
cout<<"[1] Oblicz pole trojkata."<<endl;
cout<<"[2] Oblicz obwod trojkata."<<endl;
cout<<"[3] Sprawdz czy mozna utwozyc trojkat"<<endl;
cout<<"[4] Wyjscie"<<endl;
cout<<"Wybieram: ";
cin>>x;

if(x!=4)
{
cout<<"Podaj wymiary trojkata: ";
cin>>a;
cin>>b;
cin>>c;
trojkat1.set_a1a2a3(a,b,c);
}

switch(x)
 {
 case 1:
	 {
     pole=trojkat1.pole();
     cout<<"Pole podanego trojkata wynosi: "<<pole<<endl;
     system("pause");
     break;
	}
 case 2:
	{
     obwod=trojkat1.obwod();
     if( obwod>0 )
     cout<<"Obrod podanego trojkata wynosi: "<<obwod<<endl;
     system("pause");
     break;
	}
 case 3:
	{
    char t = trojkat1.spr();
    if(t==1) cout<<"Mozna utwozyc trojkat z takiej kombinacji bokow."<<endl;
    else cout<<"Nie mozna utwozyc trojkata z takich bokow."<<endl;
    system("pause");
    break;
    }
 case 4: 
     y=0;
     break;
  default:
   cout<<"Nie ma takiej mozliwosci."<<endl;
   system("pause");
 }
 
 system("cls");
}

cout<<"Dziekujemy! Do widzenia!"<<endl;
system("pause");
return 0;
}
