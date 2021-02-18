#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "std.h" 


size_t rm_pos = 0; 
size_t add_pos;

int main(int argc, char** argv)
{
	char operation[9];
	if(in_param(argc, argv, operation))
	{
		TODO todo_list[100];
		load_list(todo_list, &add_pos);
		if(!strcmp(operation, "add"))
		{
			add_task(todo_list, argc, 
					argv, &add_pos);

		}
		else if(!strcmp(operation, "show"))
		{
			show_task(todo_list, add_pos);

		}

		else if(!strcmp(operation, "rm"))
		{
			task_done(todo_list, add_pos, &rm_pos);
		}
		save_list(todo_list, add_pos, rm_pos);

	}
	return 0;
}
	
