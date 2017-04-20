#pragma once
#include <list>
#include <map>
#include <stack>

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
		return -1;
	}

	void addEdge(int fromIndex, int toIndex, int weight) {
		graph[fromIndex]->push_back(Edge(toIndex, weight));
	}

public:
	WeightedGraph() {
		nextValue = 0;
	}
	
	~WeightedGraph() {
		clear();
	}

	void clear() {
		for (map<int, list<Edge> *>::iterator i = values.begin();i != values.end();i++) {
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
		if (fromIndex == -1 || toIndex == -1) {
			throw logic_error("Item not in graph");
		}
	}

	list<T> getConnections(const T &from) {
		int fromIndex = find(from);
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
		bool visited[graph.size()];
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
	}
};