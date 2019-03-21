#pragma once
#include <iostream>
#include <fstream> 
#include <string>
struct CellNode
{
	char item;
	int x; 
	int y;
	bool isPoint;
	CellNode * up;
	CellNode * down;
	CellNode * left;
	CellNode * right;
	CellNode * prev;
	CellNode * next;


};
class List
{
public:
	List();
	~List();
	void loadLevel(std::string);
	void insert(char, int, int );
	void deleteList();
	void setY();
	void setX();
	void showList(int);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	bool isEmpty();
	CellNode * search(int, int);

	bool nivelGanado();
	CellNode * first;
	CellNode * character;
	int rows;
	int cols;
	int boxes;
	int count;
};