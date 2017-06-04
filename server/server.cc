#include <memory>
#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


#include "events.h"
#include "err.h"

using namespace std;

int BOARD_WIDTH = 800;
int BOARD_HEIGHT = 600;
int PORT_NUMBER = 12345;
int ROUNDS_PER_SEC = 50;
int TURNING_SPEED = 6;


struct Player {
	int socket;
	int session_id;
	string name;
};

struct SnakeHead {
	pair <double, double> position;
	double moveDirection;
};


struct GameState {
	int game_id;
	// informacje o podłączonych graczach
	vector<Player> players;
	// pozycje głów węży graczy
	map<Player, SnakeHead> positions;
	// tablica o rozmiarach BOARD_WIDTH x BOARD_HEIGHT
	vector<vector<int>> occupiedPixels;
	// wydarzenia od poczatku gry
	vector<shared_ptr<Event>> events;
};

// datagram od klienta
struct ClientDatagram {
	uint64_t session_id;
	int8_t turn_direction;
	uint32_t next_expected_event_no;
	char player_name[65];
};


// datagram od servera
struct ServerDatagram {
	uint32_t game_id;
	vector<shared_ptr<Event>> events;
};


void createServerSocket() {
	struct sockaddr_in server_address;
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
		syserr("socket");

	server_address.sin_family = AF_INET; // IPv4
	server_address.sin_addr.s_addr = htonl(INADDR_ANY); // listening on all interfaces
	server_address.sin_port = htons(PORT_NUMBER); // default port for receiving is PORT_NUM

	if (bind(sock, (struct sockaddr *) &server_address,
	         (socklen_t) sizeof(server_address)) < 0)
		syserr("bind");
}



int main() {
	createServerSocket();
	for (;;) {}


}