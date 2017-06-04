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

	virtual void set_len() = 0;
	virtual void set_crc32() = 0; // ?
};


struct NewGameEvent : public Event {
	uint32_t _maxx, _maxy;
	//lista nazw graczy - czy vector, czy tablica charow z '/0'
	vector<string> _player_names;

	NewGameEvent(uint32_t event_no, uint32_t maxx, uint32_t maxy, 
				vector<string> player_names) :
				Event(event_no, 1), _maxx(maxx), _maxy(maxy), 
				_player_names(player_names) {}

	//@TODO :
	void set_len() {
		_len = 10;
	}

	//@TODO
	void set_crc32() {
		_crc32 = 11;
	}
};

struct PixelEvent : public Event {

};

struct PlayerEliminatedEvent : public Event {

};

struct GameOverEvent : public Event {
};