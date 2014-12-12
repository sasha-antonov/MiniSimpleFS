#define MAIN_F
#include "temporary.h"
#undef MAIN_F

int main(void)
{
	cursor.ID_file = 1;
	cursor.ID_folder = 1;
	cursor.ID_slice = 1;

	format_data();
	output_PC();
	control();
}