#include "type_temp.h"
#include "struct.h"
#include "header.h"

#ifdef MAIN_F
opt_slice_init* opt_slice;
data_slice_init* data_slice;
uint8_t mem[8192];
cursor_init cursor;
uint16_t number_busy_file;
uint16_t number_busy_folder;
#endif

extern opt_slice_init* opt_slice;
extern data_slice_init* data_slice;
extern uint8_t mem[8192];
extern cursor_init cursor;
extern uint16_t number_busy_file;
extern uint16_t number_busy_folder;

