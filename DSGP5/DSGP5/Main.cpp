#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	WeightedGraph<string> w;
	w.addVertex("Houston");
	w.addVertex("New_York");
	w.addVertex("St_Louis");
	w.addEdge("Houston", "New_York", 500);
	w.addEdge("New_York", "St_Louis", 115);
	w.addEdge("St_Louis", "Houston", 380);


	system("pause");
	return 0;
}