#include<stdio.h>
#include<time.h>

extern  long int Schedulelist[100] = {NULL};
extern  char ScheduleItems[100][200] = {NULL};
extern void Getlist();
extern void DeleteEntry(int val);
extern void AddEntry(int Day,int Year, int Month, int hour, char *Schedule);
extern void saveEntry();
extern int CompSched(time_t Sched);