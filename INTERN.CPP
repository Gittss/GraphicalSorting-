#include<iostream.h>
#include<conio.h>
#include<limits.h>
#include<stdlib.h>
#include<graphics.h>
int g=500;
class generate
{  int a[500];
public:
   generate();
   void show();
   void select();
   void bubble();
   void insert();

};
generate::generate()
{  int i,j;
      for(i=0;i<g;i++)
      {   a[i]=rand()%900+1;  }
}
void generate::show()
{  int gd=DETECT,gm,i,j;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   setfillstyle(1,4);
   bar(0,478,640,479);
   for(i=0,j=10;i<g;i++,j++)
      { rectangle(j,479-(a[i]/2),j+1,470);  }
}
void generate::select()
{  int s,i,j,pos,temp;
   for(i=0;i<g;i++)
   {  clrscr();
      s=a[i];
      pos=i;
      for(j=i+1;j<g;j++)
      {  if(a[j]<s)
	 { s=a[j];
	   pos=j;
	 }
      }temp=a[i];
      a[i]=a[pos];
      a[pos]=temp;
      show();
   }
}
void generate::bubble()
{  int temp,i,j;
   for(i=0;i<g;i++)
   {  clrscr();
      for(j=0;j<g-i;j++)
	 if(a[j]>a[j+1])
	 {  temp=a[j];
	    a[j]=a[j+1];
	    a[j+1]=temp;
	 }
      show();
   }
}
void generate::insert()
{  int i,j,temp,k;
   a[0]=INT_MIN;
   for(i=1;i<=g;i++)
   {  clrscr();
      temp=a[i];
      j=i-1;
      while(temp<a[j])
      {   a[j+1]=a[j];
	  j--;
      }
      a[j+1]=temp;
      show();
   }
}
void main()
{  int ch;
   randomize();
   generate gen;
   clrscr();
       cout<<"\n1.Selection Sort"
	   <<"\n2.Bubble Sort"
	   <<"\n3.Insertion Sort"
	   <<"\n4.Exit"
	   <<"\n\nEnter your choice : ";
       cin>>ch;
       switch(ch)
       {  case 1: gen.select();
		  break;
	  case 2: gen.bubble();
		  break;
	  case 3: gen.insert();
		  break;
	  case 4: cout<<"\nTerminating...";
		  break;
	  default:cout<<"\nWrong Choice";
       }
       getch();
}