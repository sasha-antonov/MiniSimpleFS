#include "temporary.h"

uint16_t find_free_slice(void)
{
	uint16_t number_slice;
	uint16_t i;
	number_slice = 8192 / 32;

	for(i = 0; i < number_slice; i++)
	{
		opt_slice = (opt_slice_init*) &mem[i * 32];
		if(opt_slice->safe == 0)
		{
			break;
		}
		if(i == (number_slice - 1))
		{
			// error!!!
		}
	}

	return(i + 1);
}

