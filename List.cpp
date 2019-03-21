#include "List.h"


List::List()
{
	first = nullptr;
	character = nullptr;
	boxes = 0;
	rows = 0;
	cols = 0;
	count = 0;
}
List::~List() 
{
	deleteList();
}
void List::loadLevel(std::string name)
{
	CellNode * tmp;
	int x = 0;
	int y = 0;
	std::string line;
	std::ifstream read;
	read.open(name);
	while (!read.eof())
	{
		x = 0;
		getline(read, line);
		cols = line.length();
		for (int i = 0; i < line.length(); i++)
		{
			x = i;
			insert(line[i],x,y);
		}
		y++;

	}
	rows = y;
	tmp = first;
	while (tmp->next != nullptr)
	{
		if (tmp->item == '@')
		{
			character = tmp;
			
		
		}
		if (tmp->item == '.')
		{
			tmp->isPoint = true;
			++boxes;
		
		}
		tmp = tmp->next;
	}
	tmp = nullptr;

}
CellNode *  List::search(int x, int y)
{
	CellNode * tmp;
	tmp = first;
	while (tmp->next != NULL)
	{
		if (tmp->x == x && tmp->y == y)
			return tmp;
		else tmp = tmp->next;
	}
}
void List::insert(char item, int x, int y)
{
	CellNode * nuevo;

	try
	{
		nuevo = new CellNode;
	}
	catch (std::bad_alloc exception)
	{
		return;
	}

	nuevo->item = item;
	nuevo->x = x;
	nuevo->y = y;



	if (isEmpty()) {
		first = nuevo;
		first->next = nullptr;
		first->prev = nullptr;
		first->up = nullptr;
		first->down = nullptr;
		first->right = nullptr;
		first->left = nullptr;
	}
	else {
		CellNode * tmp;
		tmp = first;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo;
		nuevo->prev = tmp;
		nuevo->next = nullptr;
		tmp = nullptr;
	}
	nuevo = nullptr;
}

bool List::isEmpty() {
	if (first == nullptr)
		return true;
	return false;
}
void List::deleteList() {
	CellNode* tmp;
	while (first != nullptr) {
		tmp = first;
		first = first->next;
		delete tmp;
	}
	boxes = 0;
	count = 0;
}
void List::showList(int cont) {
	int contador = 0;
	if (isEmpty()) {
		std::cout << std::endl << std::endl << "The list is empty..." << std::endl;
	}
	else
	{
		CellNode * tmp;
		tmp = first;
		while (tmp != nullptr)
		{
			contador++;
			std::cout << tmp->item << " ";
			if (contador%cont == 0)
				std::cout << std::endl;
			tmp = tmp->next;
		}
	}
}
void List::setY()
{
	CellNode * tmp;
	tmp = first;
	while (tmp->next != NULL)
	{
		if (tmp->y > 0 && tmp->y <= rows)
		{
			tmp->up = search(tmp->x, (tmp->y) - 1);
			tmp->down = search(tmp->x, (tmp->y) + 1);

		}

		tmp = tmp->next;
	}
	tmp = nullptr;

}

void List::setX()
{

	CellNode *tmp;
	tmp = first;
	while (tmp->next != NULL)
	{
		if (tmp->x > 0 && tmp->x <= cols)
		{
			tmp->right = search((tmp->x) + 1, tmp->y);
			tmp->left = search((tmp->x)  - 1, tmp->y);


		}

		tmp = tmp->next;
	}
	tmp = nullptr;
}
void List::moveUp()
{

	CellNode * tmp;
	CellNode * tmp2;
	if (character->up->item == '#')
	{
		return;
	}
	else
	{
		if (character->up->item == '$')
		{
			if (character->up->isPoint == true)
			{
				--count;
			}
			if (character->up->up->item == '#' || character->up->up->item == '$')
				return;
			else
			{
				tmp = character;
				tmp2 = character->up;
				if (character->up->up->item == '.')
				{
					++count;
				}
				tmp2->up->item = '$';
				tmp2->item = '@';
				if (tmp->isPoint == true)
				{
					tmp->item = '.';
				}
				else
					tmp->item = '0';
				character = tmp2;
			}


		}
		if (character->up->item == '0' || character->up->item == '.')
		{
			tmp = character;
			tmp2 = character->up;
			tmp2->item = '@';
			if (tmp->isPoint == true)
			{
				tmp->item = '.';
			}
			else
				tmp->item = '0';
			    character = tmp2;

		}

	}


}

void List::moveDown()
{

	CellNode * tmp;
	CellNode * tmp2;
	if (character->down->item == '#')
	{
		return;
	}
	else
	{
		if (character->down->item == '$')
		{
			if (character->down->isPoint == true)
			{
				--count;
			}
			if (character->down->down->item == '#' || character->down->down->item == '$')
				return;
			else
			{
				tmp = character;
				tmp2 = character->down;
				if (character->down->down->item == '.')
				{
					++count;
				}
				tmp2->down->item = '$';
				tmp2->item = '@';
				if (tmp->isPoint == true)
				{
					tmp->item = '.';
				}
				else
					tmp->item = '0';
				character = tmp2;
			}


		}
		if (character->down->item == '0' || character->down->item == '.')
		{
			tmp = character;
			tmp2 = character->down;
			tmp2->item = '@';
			if (tmp->isPoint == true)
			{
				tmp->item = '.';
			}
			else
				tmp->item = '0';
			character = tmp2;

		}

	}


}
void List::moveLeft()
{

	CellNode * tmp;
	CellNode * tmp2;
	if (character->left->item == '#')
	{
		return;
	}
	else
	{
		if (character->left->item == '$')
		{
			if (character->left->isPoint == true)
			{
				--count;
			}
			if (character->left->left->item == '#' || character->left->left->item == '$')
				return;
			else
			{
				tmp = character;
				tmp2 = character->left;
				if (character->left->left->item == '.')
				{
					++count;
				}
				tmp2->left->item = '$';
				tmp2->item = '@';
				if (tmp->isPoint == true)
				{
					tmp->item = '.';
				}
				else
					tmp->item = '0';
				character = tmp2;
			}


		}
		if (character->left->item == '0'|| character->left->item == '.')
		{
			tmp = character;
			tmp2 = character->left;
			tmp2->item = '@';
			if (tmp->isPoint == true)
			{
				tmp->item = '.';
			}
			else
				tmp->item = '0';
			character = tmp2;

		}

	}

}
void List::moveRight()
{
	

	CellNode * tmp;
	CellNode * tmp2;
	if (character->right->item == '#')
	{
		return;
	}
	else
	{
		if (character->right->item == '$')
		{
			if (character->right->isPoint == true)
			{
				--count;
			}
			if (character->right->right->item == '#' || character->right->right->item == '$')
				return;
			else
			{
				tmp = character;
				tmp2 = character->right;
				if (character->right->right->item == '.')
				{
					++count;
				}
				tmp2->right->item = '$';
				tmp2->item = '@';
				if (tmp->isPoint == true)
				{
					tmp->item = '.';
				}
				else
					tmp->item = '0';
				character = tmp2;
			}


		}
		if (character->right->item == '0' || character->right->item == '.')
		{
			tmp = character;
			tmp2 = character->right;
			tmp2->item = '@';
			if (tmp->isPoint == true)
			{
				tmp->item = '.';
			}
			else
				tmp->item = '0';
			character = tmp2;

		}

	}


}
bool List::nivelGanado()
{
	if ((count == boxes) && (count>0 && boxes >0))
		return true;
	else return false;
}