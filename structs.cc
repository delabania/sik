#include <cstdint>


struct event;

struct client_to_server {
	uint64_t session_id;
	int8_t turn_direction;
	uint32_t next_expected_event_no;
	char player_name[65]; // pytanie czy tablica czy alokacja dynamiczna
};


struct server_to_client {
	uint32_t game_id;
	struct event * events;
};

struct event {
	uint32_t len;
	int8_t event_type;
	//....
	uint32_t crc32;
};


int64_t seed = time(NULL);

int64_t randomNumber (int32_t i, int64_t r) {
	if(i == 0)
		return r;
	return r * 279470273 % 4294967291;
}
