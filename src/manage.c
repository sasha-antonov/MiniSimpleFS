#include "temporary.h"


void manage(void)
{
	
}

void create_file(char* name_file, uint32_t val_temp)
{
	uint16_t work_slice;
	opt_slice_init* opt_new_slice;
	opt_slice_init* opt_next_slice;
	uint8_t i;

	work_slice = find_free_slice();
	opt_new_slice = (opt_slice_init*) &mem[(work_slice - 1)*32];
	opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];									

	opt_new_slice->ID_slice = work_slice;
	opt_new_slice->ID_folder = opt_slice->ID_folder;
	number_busy_file++;
	opt_new_slice->ID_file = number_busy_file;
	opt_new_slice->safe = 1;
	opt_new_slice->size = 1;
	for(i = 0; i < 6; i++)
	{
		opt_new_slice->name[i] = name_file[i]; 
		name_file[i] = 0;
	}
	opt_new_slice->data[0] = val_temp; 
	opt_new_slice->prev_slice = cursor.ID_slice;
	
	if(opt_slice->next_slice != 0)
	{
		opt_next_slice = (opt_slice_init*) &mem[(opt_slice->next_slice - 1)*32];
		opt_next_slice->prev_slice = opt_new_slice->ID_slice;
	}
	opt_new_slice->next_slice = opt_slice->next_slice;
	opt_slice->next_slice = opt_new_slice->ID_slice;
}

void create_folder(char* name_folder, char* name_file, uint32_t val_temp)
{
	uint16_t work_slice;
	opt_slice_init* opt_new_slice;
	opt_slice_init* opt_next_slice;
	uint8_t i;

	work_slice = find_free_slice();
	opt_new_slice = (opt_slice_init*) &mem[(work_slice - 1)*32];
	opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];									

	opt_new_slice->ID_slice = work_slice;
	opt_new_slice->ID_folder = opt_slice->ID_folder;
	number_busy_file++;
	opt_new_slice->ID_file = number_busy_file;
	opt_new_slice->safe = 3;
	opt_new_slice->size = 0;
	for(i = 0; i < 6; i++)
	{
		opt_new_slice->name[i] = name_folder[i]; 
		name_folder[i] = 0;
	}
	opt_new_slice->prev_slice = cursor.ID_slice;
	
	if(opt_slice->next_slice != 0)
	{
		opt_next_slice = (opt_slice_init*) &mem[(opt_slice->next_slice - 1)*32];
		opt_next_slice->prev_slice = opt_new_slice->ID_slice;
	}
	opt_new_slice->next_slice = opt_slice->next_slice;
	opt_slice->next_slice = opt_new_slice->ID_slice;

	work_slice = find_free_slice();
	opt_next_slice = (opt_slice_init*) &mem[(work_slice - 1)*32];
	opt_new_slice->next_slice_folder = work_slice;
	opt_next_slice->prev_slice_folder = opt_new_slice->ID_slice;



	opt_next_slice->ID_slice = work_slice;
	number_busy_folder++;
	opt_next_slice->ID_folder = number_busy_folder;
	number_busy_file++;
	opt_next_slice->ID_file = number_busy_file;
	opt_next_slice->safe = 1;
	opt_next_slice->size = 1;
	for(i = 0; i < 6; i++)
	{
		opt_next_slice->name[i] = name_file[i]; 
		name_file[i] = 0;
	}
	opt_next_slice->data[0] = val_temp; 
	opt_next_slice->prev_slice = 0;
	opt_next_slice->next_slice = 0;
}

void change_file(char* name_file, uint32_t val_temp)
{
	uint8_t i;

	opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];									
	for(i = 0; i < 6; i++)
	{
		opt_slice->name[i] = name_file[i]; 
		name_file[i] = 0;
	}
	opt_slice->data[0] = val_temp; 
}

void change_folder(char* name_folder)
{
	uint8_t i;

	opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];									
	for(i = 0; i < 6; i++)
	{
		opt_slice->name[i] = name_folder[i];
		name_folder[i] = 0;
	}
}

