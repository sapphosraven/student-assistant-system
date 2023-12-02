#include <stdio.h>

extern time_t ToDoTime;
extern time_t futureTime;
extern char ToDoList[100][200] = {NULL};
extern void SetToDoTime();
extern int CompTime();
extern void DelEntry(int val);
extern void SaveEntry();
extern void AddToDoEntry(char* schedule);
extern void ResetToDo();