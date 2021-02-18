#include <stddef.h>
#include <stdio.h>
#include "struct_list.h"

void load_list(TODO* todo_list, size_t* add_pos)
{
	FILE *F;
	if((F = fopen("todo_list.dat", "rt")) == NULL)
	{
		fprintf(stderr, "Unable to open 'todo_list.dat'\n");
		return;
	}
	fscanf(F, "%zu\n", add_pos);
	for(size_t i=0; i<*add_pos; ++i)
	{
		fscanf(F, "%[^\n]%*c", todo_list[i].task);
		fscanf(F, "%s\n", todo_list[i].date);
	}

	fclose(F);

}

void save_list(TODO* todo_list, size_t add_pos, size_t rm_pos)
{
	FILE *F;
	if((F = fopen("todo_list.dat", "wt")) == NULL)
	{
		fprintf(stderr, "Unable to open 'todo_list.dat'\n");
		return;
	}

	fprintf(F, "%zu\n", (add_pos-rm_pos));
	for(size_t i=rm_pos; i<add_pos; ++i)
	{
		fprintf(F, "%s\n", todo_list[i].task);
		fprintf(F, "%s\n", todo_list[i].date);
	}
	fclose(F);

}
