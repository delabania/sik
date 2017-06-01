#include <cstdint>

using namespace std;


class Event {
	uint32_t len;
	int8_t event_type;
	uint32_t crc32;

};


class EventNewGame : public Event {
	
}