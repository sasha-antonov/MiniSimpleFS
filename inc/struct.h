
typedef struct
{
	uint8_t safe;
	uint16_t prev_slice;
	uint16_t next_slice;
	uint8_t name[6];
	uint16_t ID_file;
	uint16_t size;
	uint16_t ID_folder;
	uint16_t ID_slice;
	uint16_t prev_slice_folder;
	uint16_t next_slice_folder;
	uint32_t data[2];
	uint8_t prop_data;
} opt_slice_init;

typedef struct
{
	uint8_t safe;
	uint16_t prev_slice;
	uint16_t next_slice;
	uint16_t ID_slice;
	uint8_t data[26];
} data_slice_init;

typedef struct
{
	uint16_t ID_folder;
	uint16_t ID_file;
	uint16_t ID_slice;
} cursor_init;


