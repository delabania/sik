#include <vector>
#include <utility>
#include <cstdlib>

#include "events.h"

using namespace std;

int BOARD_WIDTH = 800;
int BOARD_HEIGHT = 600;
int PORT_NUMBER = 12345;
int ROUNDS_PER_SEC = 50;
int TURNING_SPEED = 6;


class Player {
	int socket;
	int session_id;
}

struct SnakeHead {
	pair <double, double> position;
	double moveDirection;
};


class GameState {
	int game_id;

	vector<Player> players;
	// pozycje głów węży graczy
	vector<SnakeHead> playersPositions;
	// tablica o rozmiarach BOARD_WIDTH x BOARD_HEIGHT
	vector<vector<int>> occupiedPixels;
	// wydarzenia od poczatku gry
	vector<shared_ptr<Event>> events;



};



int main() {
	int game_id = rand();




}