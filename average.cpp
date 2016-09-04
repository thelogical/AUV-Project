#include <iostream>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

using namespace std;


int total=0,no_of_observations=0;
char k='f';

int &obs=no_of_observations;

void wait_for_user()
{
	while(k!='e')
  {
    cout<<"Enter any key for avg or 'e' to exit \n";
    cin>>k;
    cout<<(float)total/obs<<"\n";
  }
  exit(0);
}
   	
     

void delay(int a)
{
  for(int i=0;i<=a*100000;i++)
  {}
}


void* averager(void*) 
{
  do
  {	
   delay(100);
   total=total + (rand() % 360);
   obs++;
   if(total>=32767)
   	total=total/obs;
   if(obs>=32767)
   {
    total=total/obs;
    obs=0;
   }
  }while(k!='e');
  if(k=='e')
  {

   cout<<"Program exited \n";
   exit(0);
  }
}



int main()
{
	srand(time(NULL));
	pthread_t t2;
	pthread_create(&t2,NULL,&averager,NULL);
	wait_for_user();
    return 0;
}