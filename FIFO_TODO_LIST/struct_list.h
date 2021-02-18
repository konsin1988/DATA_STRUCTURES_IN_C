#include <stddef.h>
#include <stdlib.h>

#ifndef __TODO_
#define __TODO_

struct tegTODO_STRUCT
{
	char task[50];
	char date[15];
};

typedef struct tegTODO_STRUCT TODO;

void load_list(TODO* todo_list, size_t* add_pos);
void save_list(TODO* todo_list, size_t add_pos, size_t rm_pos);

#endif
