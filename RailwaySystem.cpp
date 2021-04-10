#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>

char f[5]="f",s[5]="s",m[15];
int addr,ad,flag,f1,d,i,amt;
float tamt;

class login
  {
  public:
  char id[25],pass[25],*password;
  void getid()
    {
    cout<<"Enter your id :";gets(id);
    password=getpass("Enter password:");
    strcpy(pass,password);
    }
  void displayid()
    {
    cout<<"\nId      :"<<id;
    cout<<"\nPassword:"<<pass<<"\n";
    }
  };

class detail
  {
  public:
  char bp[25],dest[25],m[15];
  int tno,c1,c1fare,c2,c2fare,d,y;
  void getdetail()
    {
    cout<<"Enter train no      :";cin>>tno;
    cout<<"Enter boarding point:";gets(bp);
    cout<<"Enter destination   :";gets(dest);
    cout<<"Enter date of travel (eg- 1 Jan 2017)\n";
    cout<<"\tDate :";cin>>d;
    cout<<"\tMonth:";cin>>m;
    cout<<"\tYear :";cin>>y;
    cout<<"Enter no of seats\n";
    cout<<"\tSeats in 1st class:";cin>>c1;
    cout<<"\tFare per ticlet   :";cin>>c1fare;    
    cout<<"\tSeats in 2nd class:";cin>>c2;
    cout<<"\tFare per ticket   :";cin>>c2fare;
    }
  void displaydetail()
    {
    cout<<"\nTrain no       :"<<tno;
    cout<<"\nBoarding point :"<<bp;
    cout<<"\nDestination    :"<<dest;
    cout<<"\nDate of travel :"<<d<<"/"<<m<<"/"<<y;
    cout<<"\n1st class seats:"<<c1<<", Rs."<<c1fare;
    cout<<"\n2nd class seats:"<<c2<<", Rs."<<c2fare;
    }
  };

class reser
  {
  public:
  int pnr,tno,age[10],nosr,i,d,y,con;
  char bp[25],dest[25],pname[10][25],clas[5],m[15];
  float amc;
  void getresdet();
  void displayresdet();
  };

void reser::getresdet()
  {
  cout<<"Enter train no       :";cin>>tno;
  cout<<"Enter boarding point :";gets(bp);
  cout<<"Enter destination    :";gets(dest);
  cout<<"Enter no of seats req:";cin>>nosr;
  for(i=0;i<nosr ;i++)
    {
    cout<<"Enter passenger name :";gets(pname[i]);
    cout<<"Enter passenger age  :";cin>>age[i];
    }
  cout<<"Enter date of travel (eg- 1 Jan 2017)\n";
  cout<<"\tDate :";cin>>d;
  cout<<"\tMonth:";cin>>m;
  cout<<"\tYear :";cin>>y;
  cout<<"Enter class 'f' - 1st & 's' - 2nd class\n";cin>>clas;
  cout<<"Enter the concession category";
  cout<<"\n1.Military";
  cout<<"\n2.Senior citizen";
  cout<<"\n3.Children below 5 years";
  cout<<"\n4.None\n";
  cin>>con;
  cout<<"          END OF GETTING DETAILS          ";
  }

void reser::displayresdet()
  {
  cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout<<"Pnr no         :"<<pnr;
  cout<<"\nTrain no       :"<<tno;
  cout<<"\nBoarding point :"<<bp;
  cout<<"\nDestination    :"<<dest;
  cout<<"\nNo of seats req:"<<nosr;
  cout<<"\nDate of travel :"<<d<<"/"<<m<<"/"<<y;
  for(i=0;i<nosr;i++)
    {
    cout<<"\nPassenger name :"<<pname[i];
    cout<<"\nPassenger age  :"<<age[i];
    }
  cout<<"\nClass          :"<<clas;
  cout<<"\nConcession cat :"<<con;
  cout<<"\nTotal fare     :"<<amc<<"\n";
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  }

void manage();
void user();
void database();
void reserve();
void displaypassdetail();
void enquiry();

void main()
  {
  clrscr();
  int ch;
  do
    {
    cout<<"  WELCOME TO RAILWAY RESERVATION SYSTEM ";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"Enter your choice";
    cout<<"\n\t1.Administrator mode";
    cout<<"\n\t2.User mode";
    cout<<"\n\t3.Exit\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cin>>ch;
    switch(ch)
      {
      case 1:database();
             break;
      case 2:user();
             break;
      case 3:exit(0);
      }
    }while(ch<=3);
  getch();
  }

void database()
  {
  char c,*password,*pass="12345678";
  password=getpass("Enter the admin password:");
  detail a;
  fstream f;
  int ch;
  if(strcmp(pass,password)!=0)
    {
    cout<<"Enter the password correctly \n";
    cout<<"You are not permitted to login\n";
    goto h;
    }
  if(strcmp(pass,password)==0)
    {
    char c;
    do
      {
      clrscr();
      cout<<"          ADMINISTRATOR MENU          ";
      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
      cout<<"Enter your choice";
      cout<<"\n\t1.Create detail data base";
      cout<<"\n\t2.Add details";
      cout<<"\n\t3.Display details";
      cout<<"\n\t4.User management";
      cout<<"\n\t5.Display passenger details";
      cout<<"\n\t6.Return to main menu\n";
      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
      cin>>ch;
      cout<<"\n";
      switch(ch)
        {
        case 1:f.open("t.txt",ios::out|ios::binary);
               do
                 {
                 a.getdetail();
                 f.write((char *) & a,sizeof(a));
                 cout<<"Add another record?\n";
                 cout<<"y-for Yes     n-for No\n";
                 cin>>c;
                 }while(c=='y');
               f.close();
               break;
        case 2:f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
               a.getdetail();
               f.write((char *) & a,sizeof(a));
               f.close();
               break;
        case 3:f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
               f.seekg(0);
               while(f.read((char *) & a,sizeof(a)))
                 {
                 a.displaydetail();
                 }
               f.close();
               break;
        case 4:clrscr();
               manage();
               getch();
               break;
        case 5:displaypassdetail();
               getch();
               break;
        }
      getch();
      }while(ch<=5);
    f.close();
    clrscr();
    }
  h:
  }

void reserve()
  {
  detail a;
  reser b;
  fstream f1,f2;
  time_t t;
  f1.open("t.txt",ios::in|ios::out|ios::binary); f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
  int ch;
  b.getresdet();
  while(f1.read((char *) &a,sizeof(a)))
    {
    if(a.tno==b.tno)
      {
      if(strcmp(b.clas,f)==0)
        {
        if(a.c1>=b.nosr)
          {
          amt=a.c1fare;
          addr=f1.tellg();
          ad=sizeof(a.c1);
          f1.seekp(addr-(7*ad));
          a.c1=a.c1-b.nosr;
          f1.write((char *) & a.c1,sizeof(a.c1));
          if(b.con==1)
            {
            cout<<"Concession:Military Personnel\n";
            b.amc=b.nosr*((amt*50)/100);
            }
          else if(b.con==2)
            {
            cout<<"Concession:Senior Citizen\n";
            b.amc=b.nosr*((amt*60)/100);
            }
          else if(b.con==3)
            {
            cout<<"Concession:Children Below Five\n";
            b.amc=0.0;
            }
          else if(b.con==4)
            {
            cout<<"You cannot get any concession\n";
            b.amc=b.nosr*amt;
            }
          srand((unsigned) time(&t));
          b.pnr=rand();
          f2.write((char *) & b,sizeof(b));
          b.displayresdet();
          cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
          cout<<"     Your ticket is reserved      ";
          cout<<"     End of reservation menu      ";
          }
        else
          cout<<"  Sorry req seats not available   ";
        }
      else if(strcmp(b.clas,s)==0)
        {
        if(a.c2>=b.nosr)
          {
          amt=a.c2fare;
          addr=f1.tellg();
          ad=sizeof(a.c2);
          f1.seekp(addr-(5*ad));
          a.c2=a.c2-b.nosr;
          f1.write((char *) & a.c2,sizeof(a.c2));
          if(b.con==1)
            {
            cout<<"Concession:Military Personnel\n";
            b.amc=b.nosr*((amt*50)/100);
            }
          else if(b.con==2)
            {
            cout<<"Concession:Senior Citizen\n";
            b.amc=b.nosr*((amt*60)/100);
            }
          else if(b.con==3)
            {
            cout<<"Concession:Cildren Below Five\n";
            b.amc=0.0;
            }
          else if(b.con==4)
            {
            cout<<"You cannot get any concession\n";
            b.amc=b.nosr*amt;
            }
          f2.write((char *) & b,sizeof(b));
          b.displayresdet();
          cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
          cout<<"     Your ticket is reserved      ";
          cout<<"     End of reservation menu      ";
          }
        else
          cout<<"  Sorry req seats not available   ";
        }
      getch();
      goto h;
      }
    else
      flag=0;
    }
  if(flag==0)
    {
    cout<<"            Wrong train no              ";
    cout<<" Enter the train no from the data base  ";
    }
  f1.close();
  f2.close();
  getch();
  h:
  }

void displaypassdetail()
  {
  fstream f;
  reser b;
  f.open("p.txt",ios::in|ios::out|ios::binary);
  f.seekg(0);
  while(f.read((char *) & b,sizeof(b)))
    {
    b.displayresdet();
    }
  f.close();
  getch();
  }

void enquiry()
  {
  fstream f;
  f.open("t.txt",ios::in|ios::out|ios::binary);
  detail a;
  while(f.read((char *) & a,sizeof(a)))
    {
    a.displaydetail();
    }
  getch();
  }

void user()
  {
  login a;
  int ch;
  char *password;
  fstream f;
  f.open("id.txt",ios::in|ios::out|ios::binary);
  char id[100];
  puts("Enter your id:");gets(id);
  password=getpass("Enter your password:");
  while(f.read((char *) & a,sizeof(a)))
    { if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
      {
      do
        {
        clrscr();
        cout<<"      WELCOME TO THE USER MENU      ";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"Enter your choice";
        cout<<"\n\t1.Reserve";
        cout<<"\n\t2.Enquiry";
        cout<<"\n\t3.Return to the main menu\n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cin>>ch;
        cout<<"\n";
        switch(ch)
          {
          case 1:reserve();
                 cout<<"     END OF RESERVATION    ";
                 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                 getch();
                 break;
          case 2:enquiry();
                 getch();
                 break;
          }
        }while(ch<=2);
      goto j;
      }
    else
      d=1;
    }
  if(d==1)
    cout<<"Enter your user id and password correctly\n";
  getch();
  j:
  }

void manage()
  {
  int ch;
  fstream f;
  char c;
  login a;
  do
    {
    cout<<"  WELCOME TO THE USER MANAGEMENT MENU   ";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"Enter your choice";
    cout<<"\n\t1.Create id data base";
    cout<<"\n\t2.Add details";
    cout<<"\n\t3.Display details";
    cout<<"\n\t4.Return to the main menu\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cin>>ch;
    switch(ch)
      {
      case 1:f.open("id.txt",ios::out|ios::binary);
             do
               {
               a.getid();
               f.write((char *) & a,sizeof(a));
               cout<<"Add another record?\n";
               cout<<"y-Yes     n-No\n";
               cin>>c;
               }while(c=='y');
             f.close();
             clrscr();
             break;
      case 2:f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
             a.getid();
             f.write((char *) & a,sizeof(a));
             f.close();
             clrscr();
             break;
      case 3:
       f.open("id.txt",ios::in|ios::out|ios::binary);
             f.seekg(0);
             while(f.read((char *) & a,sizeof(a)))
               {
               a.displayid();
               }
             f.close();
             break;
      }
    }while(ch<=3);
  getch();
  }
