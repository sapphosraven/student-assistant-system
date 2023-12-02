#include <stdio.h>
#include <time.h>
#include<string.h>
#include <stdlib.h>
#include "ToDo.h"

time_t ToDoTime;
time_t futureTime;



void SetToDoTime()
{
	//Get array of ToDoList and the date the ToDoList is set for
	FILE *PTR;
	PTR = fopen("ToDolist.txt", "r");
	char buff[80];
    int i = 0;
	
	if(fgets(buff, 50, PTR) != NULL)
	{		
		ToDoTime = atoi(buff);
		
		if( (int) ToDoTime == 0)
		{
			
			ToDoTime = time(NULL);
		}
		
	}
	else
	{
		ToDoTime = time(NULL);
	}
	while(fgets(buff, 50, PTR) != NULL)
	{
		
		
		strcpy(ToDoList[i], buff);
		printf("%s", ToDoList[i]);
		i++;
	}
	printf("%s\n", asctime(localtime(&ToDoTime)));
	struct tm * timeinfo;
	timeinfo = localtime(&ToDoTime);
	timeinfo ->tm_mday += 1;
	futureTime = mktime(timeinfo);

	
}


int CompTime()
{
	//Compares the time to delete the ToDoList(1 day forward), and returns 1 if the time has passed and 0 if it hasnt
	time_t t = time(NULL);
	 if (t < futureTime)
        return 0;
    else if (t > futureTime)
        return 1;
    else
        return 1;
	
}

void DelEntry(int val)
{
	//Delete a certain entry from the ToDoList array
	if(val > 0)
	{
	
	for(int i=val-1 ;i< 100 ; i++)
	{	
		strcpy(ToDoList[i], ToDoList[i+1]);
	}
	}
	else if(val == 0)
	{
		strcpy(ToDoList[0], "");
	}
}

void SaveEntry()
{
	//Save the ToDoList Array to the file and saves the current ToDoTime
	FILE *PTR;
	PTR = fopen("ToDolist.txt", "w");
	fprintf(PTR, "%d\n", ToDoTime);
		for(int i=0;i < 100;i++)
	{ 
	
		if(strlen(ToDoList[i]) != 0)
		{
		
			fprintf(PTR, "%s", ToDoList[i]);
			
		}
		
	}
	fclose(PTR);
	
}

void AddToDoEntry(char* ToDo)
{
	//Add a new Entry to the ToDoList Array
	for(int i=0;i < 100;i++)
	{
		if(strlen(ToDoList[i]) == 0)
		{
		
			strcpy(ToDoList[i], ToDo);
			break;
		}
		
	}
}

 void ResetToDo()
{
	//Completely erases the ToDolist and wipes the ToDoTime variable once the ToDoList deadline has been reached(One day away)
	ToDoTime = 0;	
	for(int i=0;i < 100;i++)
	{ 
	
		if(strlen(ToDoList[i]) != 0)
		{
		
			strcpy(ToDoList[i], "");
			
		}
		
	}	
	
		
		
		


}





