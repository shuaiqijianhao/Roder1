#pragma once#include <iostream> 

using namespace std;

#define DefaultVertexes 30 
#define maxWeight 100 
int visited[DefaultVertexes];


template <typename T>
class Graph {
public:
	Graph(int sz = DefaultVertexes);
	~Graph() {
		delete[] vexs;
		delete[] arcs;
	}
	void CreateGraph();
	void PrintGraph();
	bool InsertVex(const T &vex);
	bool InsertEdge(const T &fromVex, const T &endVex, int weight);
	bool RemoveVex(const T &vex);
	bool RemoveEdge(const T &fromVex, const T &endVex);
	bool IsGraphFull() {
		if (numVexes == maxVexes || numArcs == numVexes*(numVexes - 1) / 2) {
			return true;
		}
		return false;
	}
	bool IsGraphEmpty() {
		if (numVexes == 0) {
			return true;
		}
		return false;
	}

	int GetLocation(const T &vex) {
		int i = 0;
		for (i = 0; i < numVexes; ++i) {
			if (vex == vexs[i]) {
				return i;
			}
		}
		return -1;
	}

	T GetValue(int pos) {
		if (pos >= 0 && pos < numVexes) {
			return vexs[pos];
		}
		return -1;
	}

private:
	T *vexs;
	int **arcs;
	int maxVexes;
	int numVexes;
	int numArcs;
};

template <typename T>
bool Graph<T>::InsertVex(const T &vex) {
	if (IsGraphFull()) {
		return false;
	}
	vexs[numVexes++] = vex;
	cout << numVexes << endl;
	return true;
}

template <typename T>
bool Graph<T>::InsertEdge(const T &fromVex, const T &endVex, int cost) {
	if (IsGraphFull()) {
		cout << "Full!!" << endl;
		return false;
	}
	int row = GetLocation(fromVex), col = GetLocation(endVex);
	cout << row << endl << col << endl;

	if (row == -1 || col == -1) {
		cout << "Failure" << endl;
		return false;
	}

	//if (arcs[row][col] <= maxWeight) {
		arcs[row][col] = arcs[col][row] = cost;
		cout << arcs[row][col] << endl;
		cout << "ok!ok!ok!" << endl;
		numArcs++;		
		return true;
//	}
}


template <typename T>
bool Graph<T>::RemoveVex(const T &vex) {
	if (IsGraphEmpty()) {
		return false;
	}
	int pos = GetLocation(vex);
	if (pos == -1) {
		return false;
	}
	vexs[pos] = vexs[numVexes - 1];
	int i = 0;
	for (i = 0; i < numVexes; ++i) {
		arcs[pos][i] = arcs[numVexes - 1][i];
	}
	for (i = 0; i < numVexes - 1; ++i) {
		arcs[i][pos] = arcs[i][numVexes - 1];
	}
	numVexes--;
}


template <typename T>
bool Graph<T>::RemoveEdge(const T &fromVex, const T &endVex) {
	int from = GetLocation(fromVex), end = GetLocation(endVex);
	if (end == -1 || from == -1) {
		return false;
	}
	arcs[from][end] = arcs[end][from] = maxWeight;
	return true;
}



template <typename T>
Graph<T>::Graph(int sz) {
	maxVexes = sz;
	numVexes = 0;
	numArcs = 0;
	int i, j;
	vexs = new T[sz];
	arcs = (int**)new int*[sz];
	for (i = 0; i < maxVexes; ++i) {
		arcs[i] = new int[maxVexes];
	}
	for (i = 0; i < maxVexes; ++i) {
		for (j = i; j < maxVexes; ++j) {
			if (i == j) {
				arcs[i][j] = 0;
				continue;
			}
			arcs[i][j] = arcs[j][i] = maxWeight;
		}
	}
}

template <typename T>
void Graph<T>::CreateGraph() {
	numVexes = 9;
	numArcs = 15;
	for (int i = 0; i < 9; i++) {
		vexs[i] = i+1;
	}
	arcs[0][1] = arcs[1][0] = 2;
	arcs[0][6] = arcs[6][0] = 1;
	arcs[0][5] = arcs[5][0] = 1;
	arcs[1][2] = arcs[2][1] = 2;
	arcs[1][3] = arcs[3][1] = 4;
	arcs[2][5] = arcs[5][2] = 3;
	arcs[2][6] = arcs[6][2] = 2;
	arcs[2][3] = arcs[3][2] = 1;
	arcs[3][6] = arcs[6][3] = 6;
	arcs[3][4] = arcs[4][3] = 1;
	arcs[3][7] = arcs[7][3] = 5;
	arcs[3][8] = arcs[8][3] = 2;
	arcs[4][5] = arcs[5][4] = 5;
	arcs[5][6] = arcs[6][5] = 1;
	arcs[6][7] = arcs[7][6] = 3;
	arcs[7][8] = arcs[8][7] = 2;
}

template <typename T>
void Graph<T>::PrintGraph() {
	cout << "The vertexes : " << endl;

	int i = 0, n = numVexes, e = numArcs;

	for (i = 0; i < n; i++) {
		cout << vexs[i] << " ";
	}

	cout << endl;
	int j = 0;
	for (i = 0; i < n; ++i) {
		cout << GetValue(i) << "\t:\t";
		for (j = 0; j < n; ++j) {
			if (arcs[i][j] > 0 && arcs[i][j] < maxWeight) {
				cout << "(" << GetValue(j) << " , " << arcs[i][j] << ")\t";
			}
		}
		cout << endl;
	}
}
