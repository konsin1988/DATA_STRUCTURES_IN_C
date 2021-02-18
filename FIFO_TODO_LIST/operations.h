#include <stddef.h>
#include "struct_list.h"

void add_task(TODO* todo_list, int argc, char** argv, size_t* add_pos);
void show_task(TODO* todo_list, size_t add_pos);
void task_done(TODO* todo_list, size_t add_pos, size_t* rm_pos);
