#include <cstdint>
#include <vector>
#include <string>



using namespace std;


struct Event {
	static uint32_t event_count;
	uint32_t _len, _event_no, _crc32;
	int8_t _event_type;

	Event(uint32_t event_no, int8_t event_type) :
		_event_no(event_count++), _event_type(event_type) {}
};


struct NewGameEvent : public Event {
	uint32_t _maxx, _maxy;
	//lista nazw graczy - czy vector, czy tablica charow z '/0'
	vector<string> _player_names;

	NewGameEvent(uint32_t event_no, uint32_t maxx, uint32_t maxy,
	             vector<string> player_names) :
		Event(event_no, 0), _maxx(maxx), _maxy(maxy),
		_player_names(player_names) {
		    //@TODO: len, crc32
		    //len = 40 + (dlugosc player_names w bitach + '/0')
	}

};

struct PixelEvent : public Event {
	int8_t _player_number;
	uint32_t _x, _y;

	PixelEvent(uint32_t event_no, int8_t player_number,
	           uint32_t x, uint32_t y) :
		Event(event_no, 1), _player_number(player_number),
		_x(x), _y(y) {
		//@TODO: len, crc32
		_len = 96; //w bitach
	}

};

struct PlayerEliminatedEvent : public Event {
	int8_t _player_number;

	PlayerEliminatedEvent(uint32_t event_no, int8_t player_number) :
		Event(event_no, 2), _player_number(player_number) {
		//@TODO: len, crc32
		_len = 48;
	}

};

struct GameOverEvent : public Event {
	GameOverEvent(uint32_t event_no) : Event(event_no, 3) {
		_len = 40;
	}
};



