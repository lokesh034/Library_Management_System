#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
int se;
static int count;

class student
{
	private:
		int semester,sse;
		char roll[50],name[30],addr[50],branch[15];
	public:

        int serials()
    {
          cout<<"enter your serial no\n";
          cin>>sse;
          return sse;
    }
		 void rollnumber()
        {
        	cout<<"enter your roll number\n";
        	fflush(stdin);
        	cin.getline(roll,50);
		}
		void sem()
		{
			cout<<"enter your semester\n";
			cin>>semester;
		}
		void sname()
		{
			cout<<"enter your name\n";
			fflush(stdin);
			gets(name);
		}
		void address()
		{
			cout<<"enter your address\n";
			fflush(stdin);
			gets(addr);
		}
		void sbranch()
		{
			 cout<<"enter your branch\n";
			 fflush(stdin);
			 gets(branch);

		}

    int pserials()
    {
          return sse;
    }

		 void prollnumber()
        {
        	cout<<"Roll number=";
        	puts(roll);
		}
		void psem()
		{
			cout<<"semester="<<semester;
		}
		void psname()
		{
			cout<<"\nname=";
			puts(name);
		}
		void paddress()
		{
			cout<<"\naddress=";
			puts(addr);
		}
		void psbranch()
		{
			 cout<<"branch=";
			 puts(branch);
		}

};


class faculty
{
	private:
		int selery,fse;
		char name[30],addr[50],department[15];
	public:
        int serialf()
      {
          cout<<"enter your serial no\n";
          cin>>fse;
          return fse;
      }
      int rserialf()
      {
      	return fse;
  	  }
		void fname()
		{
			cout<<"enter your name\n";
			fflush(stdin);
			gets(name);
		}
		void address()
		{
			cout<<"enter your address\n";
			fflush(stdin);
			gets(addr);
		}
		void depart()
		{
			 cout<<"enter your name of department\n";
			 	fflush(stdin);
			 gets(department);

		}
		void fselery()
		{
			cout<<"enter your selery\n";
		fflush(stdin);
			cin>>selery;
		}

		void pfname()
		{
			cout<<"\nname=";
			puts(name);
		}
		void paddress()
		{
			cout<<"\naddress=";
			puts(addr);
		}
		void pdepart()
		{
			 cout<<"department=";
			 puts(department);
        }
		void pfselery()
		{
			cout<<"selery="<<selery;
		}

};


class librery:public student,public faculty
{
    private:
  char book[100],author[50];
  int price,lse,ch;
public:
    int seriall()
    {
          cout<<"enter your serial no\n";
          cin>>lse;
          return lse;
    }
    int rseriall()
    {
    	return lse;
	}
    void lbook()
    {

        cout<<"enter book name\n";
        fflush(stdin);
        cin.getline(book,100);
    }
    void lauthor()
    {
        cout<<"enter authors name\n";
        fflush(stdin);
        cin.getline(author,50);
    }

    void lprice()
    {
        cout<<"enter price of book\n";
        cin>>price;
    }
    void check()
    {
    	cout<<"if you are student press 0 else 1\n";
    	cin>>ch;
	}

      void plbook()
    {
        cout<<"book name="<<book<<endl;
    }
    void plauthor()
    {
        cout<<"authors name="<<author<<endl;

    }

    void plprice()
    {
        cout<<"price of book="<<price;
    }
    int rcheck()
    {
    	return ch;
	}
};

int main()
{
    fstream f1,f2,f3;
    student *s,*r;
    faculty *fw,*fr;
    librery *lw,*lr;
    int ch,i,j,co=1,b;
    int flag;
    int flag1=0;
    if(flag1==0)
    {
      f1.open("student",ios::out|ios::app|ios::binary);
      f2.open("faculty",ios::out|ios::app|ios::binary);    
      f3.open("library",ios::out|ios::app|ios::binary);
      flag1=1;
    }
  if(f1.fail()&&f2.fail()&&f3.fail())
    {
        cout<<"can not crealte file\n";
        getch();
        exit(0);
    }
    else
    {
    do
    { 
       if(flag1==1)
       {
       	 f1.close();
       	 f2.close();
       	 f3.close();
       }	   
        cout<<"press 1 for store student information\n";
        cout<<"press 2 for print student information\n";
        cout<<"press 3 for store feculty information\n";
        cout<<"press 4 for print faculy information\n";
        cout<<"press 5 for book issued from library\n";
        cout<<"press 6 for book submit form library\n";
        cout<<"press 7 for exit\n";
        cout<<"\n\n\nplzz enter your choice\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
                f1.open("student",ios::out|ios::app|ios::binary);
                s=new student;
                i=s->serials();
                cout<<i<<"student\n";
                s->sname();
				s->rollnumber();
				s->sbranch();
				s->sem();
				s->student::address();
		        f1.write((char *)s,sizeof(student));
		        count++;
		        f1.close();
				break;
            case 2:
               f1.open("student",ios::in|ios::app|ios::binary);
            	 cout<<"enter serial no of student\n";
                 cin>>b;
                 r=new student;
                 f1.seekg(0,ios::beg);
                 f1.read((char *)r,sizeof(student));
                i=r->pserials();
                 while(!f1.eof())
                 {
                    if(b!=i)
                    {
                     f1.read((char *)r,sizeof(student));
                       i=r->pserials();
                   }
                   else
                     break;
                 }
                 cout<<b<<" student\n";
				r->psname();
				r->prollnumber();
				r->psbranch();
				r->psem();
				r->student::paddress();
				f1.close();
				break;
            case 3:
                f2.open("faculty",ios::out|ios::app|ios::binary);
                fw=new faculty;
                j=fw->serialf();
                cout<<j<<" faculty\n";
			    fw->fname();
				fw->depart();
				fw->fselery();
				fw->address();
				f2.write((char *)fw,sizeof(faculty));
				f2.close();
				break;
            case 4:
                f2.open("faculty",ios::in|ios::app|ios::binary);
                cout<<"enter serial of faculty members\n";
                cin>>b;
                fr=new faculty;
                f2.seekg(0,ios::beg);
                f2.read((char *)fr,sizeof(faculty));
                j=fr->rserialf();
                while(!f2.eof())
                 {
                    if(b!=j)
                    {
                     f2.read((char *)fr,sizeof(faculty));
                       j=fr->rserialf();
                   }
                   else
                     break;
                 }
                cout<<j<<" faculty\n";
			    fr->pfname();
				fr->pdepart();
				fr->pfselery();
				fr->paddress();
				f2.close();
				break;
			case 5:
			     f3.open("librery",ios::out|ios::app|ios::binary);
			     lw=new librery;
			     i=lw->seriall();
			     lw->lbook();
			     lw->lauthor();
			     lw->lprice();
			     lw->check();
			     f3.write((char *)lw,sizeof(librery));
			     f3.close();
			     break;  
           case 6:
                 f1.open("student",ios::in|ios::app|ios::binary);
			     f2.open("faculty",ios::in|ios::app|ios::binary);
			     f3.open("librery",ios::in|ios::app|ios::binary);
                 lr=new librery;
                 cout<<"enter your serial number\n";
                 cin>>b;
                f3.seekg(0,ios::beg);
                f3.read((char *)lr,sizeof(librery));
                j=lr->rseriall();
                while(!f3.eof())
                 {
                    if(b!=j)
                    {
                     f3.read((char *)lr,sizeof(librery));
                       j=lr->rseriall();
                   }
                   else
                     break;
                 }
                 cout<<j<<" student\n";
                 lr->plbook();
			     lr->plauthor();
			     lr->plprice();
			     i=lr->rcheck();
			     if(i==0)
			     {
			      r=new student;	
			      f1.seekg(j);
                  f1.read((char *)r,sizeof(student));
				  r->psname();
				  r->prollnumber();
				  r->psbranch();
				  r->psem();
				  r->student::paddress();
				 }
				 else
				 {
				 	fr=new faculty;
                    f2.seekg(j);
                    f2.read((char *)fr,sizeof(faculty));
			        fr->pfname();
			     	fr->pdepart();
			     	fr->pfselery();
				    fr->paddress();
				 	
				 }
				 f1.close();
				 f2.close();
				 f3.close();
				 break;
  
           case 7:
                exit(0);
            default:
                cout<<"your choice in invalid\n\n";


        }
        printf("\n\n\n");
    }while(1);


   }

    getch();
    return 0;
}

