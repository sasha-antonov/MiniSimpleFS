void format_data(void);
void output_PC(void);
void control(void);
uint16_t find_first_file_in_folder(uint16_t cursor_id_slice);
uint16_t find_free_slice(void);
void create_file(char* name_file, uint32_t val_temp);
void create_folder(char* name_folder, char* name_file, uint32_t val_temp);
void change_file(char* name_file, uint32_t val_temp);
void change_folder(char* name_folder);
