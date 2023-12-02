#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "colorprint.h"

int budgeter();
int newbudget();
int withdrawal();
int deposit();

//int alreadyasked = 0;

int budgeter(){
	//function that opens up budgeter
	FILE *ptr;
	
	time_t rawtime;
    struct tm* timeinfo;

    char buffer[80] = {""};
 
	char week[7][12] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
	time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%A", timeinfo);
 
    char day[10] = {""};
	strcpy(day, buffer);
	int todayday, nextmon, calcval;
	
	for(int i = 0; i < 7; i++){
		if((strcmp(day, week[i])) == 0) {
			todayday = i;
			nextmon = 6 - todayday;
			calcval = 7 - todayday;
			break;
		}
	}
	
	
	if ((ptr = fopen("budget.txt", "r")) == NULL) {
        fclose(ptr);
       
	    int firstbudget = 0;
	    char fbstr[20] = {""};
       
       	system("cls");
	    printf("Kindly tell us what your budget is till the end of the week\nso we can set it up for the first time: Rs.");
        scanf("%d", &firstbudget);
        
        itoa(firstbudget, fbstr, 10);
		ptr = fopen("budget.txt", "w");
		//printf("%s", fbstr);
		fputs(fbstr, ptr);
	//	fputs("\n", ptr);
//		fputs("1\n",ptr);    //so the program doesnt ask the user to make the budget again if its a monday
		fclose(ptr);
		
    }

	system("cls");
    printf("Today is %s, there are %d days to the next week\n", day, nextmon);	
	
	char budget[50] = {""};
//	char alrstr[50] = {""};
	int temporary = 0;
	
	ptr = fopen("budget.txt","a+");
	fgets(budget, 50, ptr);
	
	temporary = atoi(budget);
	
	printf("Your remaining budget for the week is: Rs.%d\n", temporary);
	
		
	if(temporary < 0){
		
		char line[] = "You are over budget!!!\n";
		
		printred(line);
	}
	else{
		
		char line2[] = "You are on budget\n";
		
		printgreen(line2);
		
		int perday;
	
		perday = temporary / calcval;
	
		printf("You need to spend no more than %d per day to stay on budget", perday);
	}
	
//	fgets(alrstr, 50, ptr);
	//alreadyasked = atoi(alrstr);
	//printf("%d", alreadyasked);
	
//	if((todayday == 0) && (alreadyasked == 0)){
//		newbudget();
//	}
  //  else if(todayday != 0){
 //   	alreadyasked = 0;
//	}
    
	char line3[] = "\n\n1. Withdraw Money\n";
	char line4[]= "2. Deposit Money\n";
	char line5[] = "3. Go back\n";
	
	printyellow(line3);
	printyellow(line4);
	printyellow(line5);
	
	int nextmenu;
	scanf("%d", &nextmenu);
	
	switch(nextmenu){
		case 1:
			withdrawal();
			return 0;
			break;
		case 2:
			deposit();
			return 0;
			break;
		case 3: 
			return 0;
			break;
	}
	return 0;
}

/*
int newbudget(){
	system("cls");
	
	int newb;
	printf("Would you like to make a new budget for this week?\n1. Yes\n2. No\n");
	scanf("%d`", &newb);
	
	switch(newb){
		case 1: ;
		
			FILE *ptr;
		
			ptr = fopen("budget.txt","a+");
			
			fputs("0\n", ptr);
			fputs("1\n", ptr);   //reset budget

			fclose(ptr);
			
			printf("Operation completed succesfully!\n");
							
			alreadyasked = 1;
			budgeter();
			return 0;
			break;
			
		case 2:
			system("cls");
			alreadyasked = 1;
			return 0;
			break;
	}
	return 0;
}
*/

int withdrawal(){

	system("cls");
	FILE *ptr;
	char readnum[50] = {""};
	int readint;
		
	ptr = fopen("budget.txt","r");
	fgets(readnum, 50 , ptr);
	fclose(ptr);
	
	readint = atoi(readnum);
	//printf("%d", readint);
	
	
	ptr = fopen("budget.txt","w");
	int withdraw;
	
	printf("How much money would you like to withdraw?: Rs.");
	scanf("%d", &withdraw);
	
	readint -= withdraw;
	
//	printf("%d", readint);
	
    char intstring[50] = {""};
    itoa(readint, intstring, 10);
	
    fputs(intstring, ptr);
    
  //  printf("%s", intstring);
    
    //char alrstr[50] = {""};
    //itoa(alreadyasked, alrstr, 10);
    
	//fputs("\n", ptr);
	//fputs(alrstr, ptr);
	//fputs("\n", ptr);
	fclose(ptr);
	
	char linea[] = "Operation completed succesfully!\n";
	printpurple(linea);
	
	getchar();
	getchar();
	budgeter();
	return 0;
	
}
                           
	
int deposit(){
		
	system("cls");
	FILE *ptr;
	char readnum[50] = {""};
	int readint;
		
			
	ptr = fopen("budget.txt","r");
	fgets(readnum, 50 , ptr);
	fclose(ptr);
	
	readint = atoi(readnum);
	//printf("%d", readint);	printf("%d", readint);
	
	ptr = fopen("budget.txt","w");
	int deposit;
	
	printf("How much money would you like to deposit?: Rs.");
	scanf("%d", &deposit);
	
	readint += deposit;
	
    char intstring[50] = {""};
    itoa(readint, intstring, 10);
	
    fputs(intstring, ptr);
    
   // printf("%s", intstring);
    
   // char alrstr[50] = {""};
    //itoa(alreadyasked, alrstr, 10);
    
	//fputs("\n", ptr);
	//fputs(alrstr, ptr);
	//fputs("\n", ptr);
	fclose(ptr);
	
	char lineb[] = "Operation completed succesfully!\n";
	printpurple(lineb);
	
	getchar();
	getchar();
	budgeter();
	return 0;
	
	
}
