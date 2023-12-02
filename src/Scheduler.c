#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Scheduler.h"





  

void Getlist()
{
	//Get Schedule and Items from file and save in array
	FILE* PTR;
    
	PTR = fopen("schedulelist.txt", "r");
	int x = 0;
	char buff[80];
	while (fgets(buff, 50, PTR) != NULL) 
	{
		Schedulelist[x] = atoi(buff);
		x++;
    }
    fclose(PTR);
    
    	FILE* PTR1;
    
	PTR1 = fopen("scheduleitems.txt", "r");
	int y = 0;
	char buff1[80];
	while (fgets(buff1, 50, PTR1) != (NULL)) 
	{	
	
		if(strlen(buff1) != 0)
		{
				buff1[strcspn(buff1, "\n")] = 0;
				strcpy(ScheduleItems[y], buff1);
				y++;	
		}
		
    }
    fclose(PTR1);
   
}

void DeleteEntry(int val)
{
	//Deletes a chosen entry from both array of schedules
	if(val > 0)
	{
	
	for(int i=val-1 ;i< 100 ; i++)
	{	
	Schedulelist[i]=Schedulelist[i+1];
	strcpy(ScheduleItems[i], ScheduleItems[i+1]);
	}
	}
	else if(val == 0)
	{
		Schedulelist[0] = (long int) 0;
		strcpy(ScheduleItems[0], "");
	}
}

void AddEntry(int Day, int Year, int Month, int hour, char *Schedule)
{
	//Adds a new entry to both arrays
	struct tm Time;
	Time.tm_year = Year - 1900;
   Time.tm_mon = Month - 1;
   Time.tm_mday = Day;
   Time.tm_hour = hour - 1;
   Time.tm_min = 0;
   Time.tm_sec = 0;
   Time.tm_isdst = 0;
	time_t t = mktime(&Time);
	for(int i=0;i < 100;i++)
	{
	
		if((Schedulelist[i] == (long int) 0))
		{
			
			Schedulelist[i] = t;
			break;
		}
	
	}
	for(int i=0;i < 100;i++)
	{
		if(strlen(ScheduleItems[i]) == 0)
		{
			strcpy(ScheduleItems[i], Schedule);
			break;
		}
		
	}
}

void saveEntry()
{
	//saves arrays to file
	FILE* fptr2 = fopen("schedulelist.txt", "w");
	
	for(int i=0;i < 100;i++)
	{
		if(Schedulelist[i] != 0)
		{
		
		fprintf(fptr2, "%d\n", Schedulelist[i]);
		}
		
	}
	fclose(fptr2);
	FILE* fptr3 = fopen("scheduleitems.txt", "w+");
	
	for(int i=0;i < 100;i++)
	{ 
	
		
		
			fprintf(fptr2, "%s\n", ScheduleItems[i]);
			
	
		
	}
	fclose(fptr3);
}

int CompSched(time_t Sched)
{
	//function compares time and returns one if it has passed or is the same time and 0 if that time has not passed
	time_t t = time(NULL);
	 if ((t < Sched) && ((int)Sched != 0))
        return 0;
     else if (t > Sched)
        return 1;
     else
        return 1;
    return 0;    
    
}









