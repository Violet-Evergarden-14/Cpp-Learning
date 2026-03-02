#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SPLIT_TIME_MIN = 500;
const int SPLIT_TIME_MAX = 2000;

class Cell {
private:
	static int count;
	int id;
	int time;
public:
	Cell(int birth): id(count++) {
		time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
	}
	int get_id() const {return id;}
	int get_split_time() const {return time;}
	bool operator<(const Cell& s) const {return this->time > s.time;}

	void split() const;
};

priority_queue<Cell> cell_queue;

void Cell::split() const {
		Cell child1(time), child2(time);
		cout << time << "s: Cell #" << id << " splits to #" << child1.get_id() << " and #" << child2.get_id() << endl;
		cell_queue.push(child1);
		cell_queue.push(child2);
	}

int Cell::count = 0;

int main()
{
	srand(static_cast<unsigned>(time(0)));
	int t;
	cout << "Simulation time: ";
	cin >> t;
	cell_queue.push(Cell(0));
	while (cell_queue.top().get_split_time() <= t) {
		cell_queue.top().split();
		cell_queue.pop();
	}
}