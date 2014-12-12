#include "temporary.h"

void output_PC(void)
{
	uint16_t i;
	uint8_t end_dir = 0;
	uint16_t work_slice;

	work_slice = find_first_file_in_folder(cursor.ID_slice);
	work_slice = work_slice - 1;
	
	while(end_dir == 0)
	{
		opt_slice = (opt_slice_init*) &mem[work_slice * 32];
		if(cursor.ID_file == opt_slice->ID_file)
		{
			printf("> ");
		}
		else
		{
			printf("  ");
		}
		for(i = 0; i < 6; i++)
		{
			printf("%c", opt_slice->name[i]);
		}
		if(opt_slice->safe == 3)
		{
			printf("\n");
		}
		else
		{
			for(i = 0; i < opt_slice->size; i++)
			{
				printf("  %d", opt_slice->data[i]);
				printf("\n");
			}
		}
		if(opt_slice->next_slice == 0)
		{
			end_dir = 1;
		}
		else
		{
			work_slice = opt_slice->next_slice - 1;
		}
	}	
}

uint16_t find_first_file_in_folder(uint16_t cursor_id_slice)
{
	uint16_t work_slice;
	uint8_t start_dir = 0;
	opt_slice_init* prev_opt_slice;

	work_slice = cursor_id_slice;
	// поиск начала директории
	while(start_dir == 0)
	{
		opt_slice = (opt_slice_init*) &mem[(work_slice - 1)*32];
		if(opt_slice->prev_slice != 0)
		{
			prev_opt_slice = (opt_slice_init*) &mem[(opt_slice->prev_slice - 1)*32]; 
			if(prev_opt_slice->ID_folder == opt_slice->ID_folder)
			{
				work_slice = opt_slice->prev_slice;
			}
			else
			{
				start_dir = 1;
			}
		}
		else
		{
			start_dir = 1;
		}
	}
	return(work_slice );
}
