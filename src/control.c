#include <stdlib.h>
#include "temporary.h"

opt_slice_init* prev_opt_slice;
char name_file[6];
char name_folder[6];
uint32_t val_temp;

void control(void)
{
	uint16_t work_slice;
	char c = 0;

	while(c != 27)
	{
		c = getch();
		if(c == 80)
		{
			opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];
			if(opt_slice->next_slice != 0)
			{
				cursor.ID_slice = opt_slice->next_slice;
				opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];
				cursor.ID_file = opt_slice->ID_file;
				cursor.ID_folder = opt_slice->ID_folder;
			}
			system("cls");
			output_PC();
			//cursor(output_PC)
		}
		if(c == 72)
		{
			opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];
			if(opt_slice->prev_slice != 0)
			{
				prev_opt_slice = (opt_slice_init*) &mem[(opt_slice->prev_slice - 1)*32]; 
				if(prev_opt_slice->ID_folder == opt_slice->ID_folder)
				{
					cursor.ID_slice = opt_slice->prev_slice;
					opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];
					cursor.ID_file = opt_slice->ID_file;
					cursor.ID_folder = opt_slice->ID_folder;	
				}				
			}
			system("cls");
			output_PC();
			//cursor(output_PC)
		}
		if(c == 13)
		{
			opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];
			if(opt_slice->safe == 3)
			{
				cursor.ID_slice = opt_slice->next_slice_folder;
				opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];
				cursor.ID_file = opt_slice->ID_file;
				cursor.ID_folder = opt_slice->ID_folder;
			}
			system("cls");
			output_PC();
			//cursor(output_PC)
		}
		if(c == 8)
		{
			opt_slice = (opt_slice_init*) &mem[(cursor.ID_slice - 1)*32];
			if(opt_slice->ID_folder != 1)
			{
				work_slice = find_first_file_in_folder(cursor.ID_slice);			
				opt_slice = (opt_slice_init*) &mem[(work_slice - 1)*32];
				prev_opt_slice = (opt_slice_init*) &mem[(opt_slice->prev_slice - 1)*32]; 								
				
				work_slice = find_first_file_in_folder(opt_slice->prev_slice_folder);
				opt_slice = (opt_slice_init*) &mem[(work_slice - 1)*32];
				cursor.ID_slice = opt_slice->ID_slice;
				cursor.ID_file = opt_slice->ID_file;
				cursor.ID_folder = opt_slice->ID_folder;

				system("cls");
				output_PC();
				//cursor(output_PC)
			}
		}
		if(c == 32)
		{
			system("cls");
			printf("Enter name temporary and value: \n");
			scanf("%s %u", &name_file, &val_temp);
			//getch();
			//printf("Enter value temporary \n");
			//scanf("/u", &val_temp);
			
			create_file(&name_file[0], val_temp);
			system("cls");
			output_PC();
			//cursor(output_PC)	
		}
		if(c == 57)
		{
			system("cls");
			printf("Enter name folder, name first temporary in folder\n and her value: \n ");
			scanf("%s %s %u", &name_folder, &name_file, &val_temp);
			//getch();
			//printf("Enter value temporary \n");
			//scanf("/u", &val_temp);
			
			create_folder(&name_folder[0], &name_file[0], val_temp);
			system("cls");
			output_PC();
			//cursor(output_PC)
		}
		if(c == 56)
		{
			system("cls");
			printf("Enter name temporary and value: \n");
			scanf("%s %u", &name_file, &val_temp);

			change_file(&name_file[0], val_temp);
			system("cls");
			output_PC();
		}
		if(c == 55)
		{
			system("cls");
			printf("Enter name folder: \n");
			scanf("%s", &name_folder);

			change_folder(&name_folder[0]);
			system("cls");
			output_PC();
		}
	}	
}

