#include "temporary.h"

void format_data(void)
{
	uint16_t i = 0;
	uint16_t j = 0;
	uint16_t t = 0;

	// сброс всех slice
	for(i = 0; i < 8192; i++)
	{
		if(j == 0)
		{
			opt_slice = (opt_slice_init*) &mem[i];
			opt_slice->safe = 0; // 0 - пустой, 1 - занят option, 3 - занят data
			opt_slice->ID_file = 0;
			opt_slice->ID_folder = 0;
			opt_slice->next_slice = 0;
			opt_slice->prev_slice = 0;
			opt_slice->size = 0;
			opt_slice->prev_slice_folder = 0;
			opt_slice->next_slice_folder = 0;
			opt_slice->ID_slice = 0;
			for(t = 0; t < 6; t++)
			{
				opt_slice->name[t] = 0;
			}
			for(t = 0; t < 2; t++)
			{
				opt_slice->data[t] = 0;
			}
			opt_slice->prop_data = 0;
			
		}
		j++;
		if(j == 32)
		{
			j = 0;
		}
	}

	// создание home-dir
	opt_slice = (opt_slice_init*) &mem[0];
	opt_slice->safe = 1;
	opt_slice->ID_file = 1;
	number_busy_file++;
	opt_slice->ID_folder = 1;
	number_busy_folder = 1;
	opt_slice->ID_slice = 1;
	opt_slice->prev_slice = 0;
	opt_slice->size = 1;
	opt_slice->name[0] = 88;
	opt_slice->data[0] = 1;
	opt_slice->next_slice = 2;

	opt_slice = (opt_slice_init*) &mem[32];
	opt_slice->safe = 1;
	opt_slice->ID_file = 2;
	number_busy_file++;
	opt_slice->ID_folder = 1;
	opt_slice->ID_slice = 2;
	opt_slice->prev_slice = 1;
	opt_slice->size = 1;
	opt_slice->name[0] = 89;
	opt_slice->data[0] = 2;
	opt_slice->next_slice = 3;
	opt_slice->prev_slice = 1;

	opt_slice = (opt_slice_init*) &mem[64];
	opt_slice->safe = 3;
	opt_slice->ID_file = 3;
	number_busy_file++;
	opt_slice->ID_folder = 1;
	opt_slice->ID_slice = 3;
	opt_slice->prev_slice = 2;
	opt_slice->size = 1;
	opt_slice->name[0] = 70;
	opt_slice->name[1] = 95;
	opt_slice->name[2] = 90;
	opt_slice->data[0] = 0;
	opt_slice->next_slice_folder = 4;
	opt_slice->next_slice = 0;
	opt_slice->prev_slice = 2;

	opt_slice = (opt_slice_init*) &mem[96];
	opt_slice->safe = 1;
	opt_slice->ID_file = 4;
	number_busy_file++;
	number_busy_folder++;
	opt_slice->ID_folder = 2;
	opt_slice->ID_slice = 4;
	opt_slice->prev_slice = 0;
	opt_slice->size = 1;
	opt_slice->name[0] = 89;
	opt_slice->data[0] = 2;
	opt_slice->next_slice = 5;
	opt_slice->prev_slice_folder = 3;

	opt_slice = (opt_slice_init*) &mem[128];
	opt_slice->safe = 1;
	opt_slice->ID_file = 5;
	number_busy_file++;
	opt_slice->ID_folder = 2;
	opt_slice->ID_slice = 5;
	opt_slice->prev_slice = 4;
	opt_slice->size = 1;
	opt_slice->name[0] = 90;
	opt_slice->data[0] = 3;
	opt_slice->next_slice = 0;
}

