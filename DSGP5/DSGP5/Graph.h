#pragma once
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <climits>

#define MISSING -1;
using namespace std;

template <class T> 
class WeightedGraph {
	struct Edge {
		int to;
		int weight;

		Edge(int to, int weight) {
			this->to = to;
			this->weight = weight;
		}

		bool operator<(const Edge &other) {
			return weight < other.weight;
		}

		bool operator>(const Edge &other) {
			return weight > other.weight;
		}

		bool operator<=(const Edge &other) {
			return weight <= other.weight;
		}

		bool operator>=(const Edge &other) {
			return weight >= other.weight;
		}

		bool operator==(const Edge &other) {
			return to == other.to && weight == other.weight;
		}
	};

	map<int,list<Edge> *> graph;
	map<int, T> values;
	int nextValue;

	int find(const T &item) {
		for (map<int, T>::iterator i = values.begin();i != values.end();i++) {
			if (i->second == item) {
				return i->first;
			}
		}
		return MISSING;
	}

	void addEdge(int fromIndex, int toIndex, int weight) {
		graph[fromIndex]->push_back(Edge(toIndex, weight));
	}
	
	void cleanup() {
		for (int i = nextValue - 1;i > MISSING;i--) {
			if (m.find(i) == m.end()) {
				if(i < nextValueMISSING)
			}
		}
	}
public:
	WeightedGraph() {
		nextValue = 0;
	}
	
	~WeightedGraph() {
		clear();
	}

	void clear() {
		for (map<int, list<Edge> *>::iterator i = graph.begin();i != graph.end();i++) {
			delete i->second;
		}
		graph.clear();
		values.clear();
	}

	bool isEmpty() {
		return graph.empty();
	}

	void addVertex(const T &item) {
		values.insert(nextValue, item);
		map.insert(nextValue, new list<Edge>());
		nextValue++;
	}

	void addEdge(const T &from, const T &to, int weight) {
		int fromIndex = find(from);
		int toIndex= find(to);
		if (fromIndex == MISSING || toIndex == MISSING) {
			throw logic_error("Item not in graph");
		}
	}

	bool contains(const T& value) {
		return find(value) != MISSING;
	}

	list<T> getConnections(const T &from) {
		int fromIndex = find(from);
		if (fromIndex == MISSING) {
			throw logic_error("Item not in graph");
		}
		list<Edge> * vertex = graph[fromIndex];
		list<T> results;
		for (list<Edge>::iterator i = vertex.begin();i != vertex.end();i++) {
			results.push_back(values[i->to]);
		}

	}

	void DFS(void(*func) (T &item)) {
		bool visited[graph.size()];
		stack<int> s;
		for (int i = 0;i < graph.size();i++) {
			s.push(i);
			while (!s.empty()) {
				int current = s.top();
				s.pop();
				if (!visited[current]) {
					keys.
					(*func)(values.at(current));
					for (list<Edge>::iterator j = graph[current]->begin();j < graph[current]->end;j++) {
						s.push(*j.to);
					}
					visited[current] = true;
				}
			}
		}
	}

	void BFS(void(*func) (T &item)) {
		bool * visited = new bool[graph.size()];
		queue<int> s;
		for (int i = 0;i < graph.size();i++) {
			s.push(i);
			while (!s.empty()) {
				int current = s.front();
				s.pop();
				if (!visited[current]) {
					(*func)(values.at(current));
					for (list<Edge>::iterator j = graph[current]->begin();j < graph[current]->end;j++) {
						s.push(*j.to);
					}
					visited[current] = true;
				}
			}
		}
		delete[] visited;
	}

	pair<list<T>, int> shortestPath(const T &to, const T& from) {
		int fromIndex = find(from);
		int toIndex = find(to);
		if (fromIndex == MISSING || toIndex == MISSING) {
			throw logic_error("Item not in graph");
		}
		bool * visited = new bool[nextValue];
		int * pathTo = new int[nextValue];
		int * distanceTo = new int[nextValue];
		for (int i = 0;i < nextValue;i++) {
			if (i != fromIndex) {
				distanceTo[i] = INT_MAX;
				pathTo[i] = MISSING;
			}			
		}
		pathTo[fromIndex] = fromIndex;
		distanceTo[fromIndex] = 0;
		priority_queue<Edge> dykstraQueue; //<distance,vertex>
		dykstraQueue.push(Edge(from,0);
		while (!dykstraQueue.empty()) {
			Edge index = dykstraQueue.top();
			dykstraQueue.pop();
			if (!visited[index.to]) {
				list<Edge> * edges = *graph[index.to];
				for (list<Edge>::iterator i = edges->begin;i < edges->end();i++) {
					int distance = distanceTo[index.to] + i->weight;
					if (distance < distanceTo[i->to]) {
						distanceTo[i->to] = distance;
						pathTo[i->to] = index->to;
						dykstraQueue.push(Edge(i->to, distance));
					}
				}
				visited[index.to] = true;
			}
		}
		list<T> path;
		if (pathTo[toIndex] == MISSING) {
			delete[] visited;
			delete[] pathTo;
			delete[] distanceTo;
			return pair<list<T>, int>(path, MISSING);
		}
		int location = toIndex;
		do  {
			path.push_front(values[location]);
			location = pathTo[location];
		} while (location != fromIndex);
		
		delete[] visited;
		delete[] pathTo;
		delete[] distanceTo;
		return pair<list<T>, int>(path, distanceTo[toIndex]);s
	}
};