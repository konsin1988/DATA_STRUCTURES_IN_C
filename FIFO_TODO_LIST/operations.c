#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "struct_list.h"

void str_split(int argc, char** argv, char* task, char* date)
{
	sscanf(argv[2], "%s", task);
	for(size_t i=3; i<argc-1; ++i)
	{
		if(strlen(task)+1+strlen(argv[i]) > 50)
			break;
		strcat(task, " ");
		strcat(task, argv[i]);
	}
	sscanf(argv[argc-1], "%s", date);
}

void add_task(TODO* todo_list, int argc, char** argv, size_t* add_pos)
{
	if((*add_pos) > 99)
	{
		printf("Stack overflow. Stop\n");
		return;
	}
	char task[50];
	char date[15];
	str_split(argc, argv, task, date);

	sscanf(task, "%49[^\n]%*c", todo_list[*add_pos].task);
	sscanf(date, "%14s", todo_list[*add_pos].date);

	(*add_pos)++;
}

void show_task(TODO* todo_list, size_t add_pos)
{
	if(add_pos == 0)
	{
		printf("There is nothing to show. All tasks done!!!\n");
		return;
	}
	printf("First in line task: \t");
	printf("%s\t", todo_list[0].task);
	printf("%s\n", todo_list[0].date);
}

void task_done(TODO* todo_list, size_t add_pos, size_t* rm_pos)
{
	if(add_pos == 0)
	{
		printf("There is nothing to remove. All tasks done!!!\n");
		return;
	}
	printf("Task \"%s\" done! Congratulations!!!\n", todo_list[0].task);
	++(*rm_pos);
}
