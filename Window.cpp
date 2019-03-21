#include "Window.h"
Window::Window() {}
void Window::create() 
{

	window.create({ w_size.x, w_size.y, 32 }, w_title, sf::Style::Default);

	window.display();



}
Window::Window(const std::string & title,const sf::Vector2u &size) {
	setting(title,size);
}
Window::~Window()
{
	deleteWindow();
}
void Window::deleteWindow() 
{
	window.close();
}
void Window::loadSprites()
{

	m_texture.loadFromFile("background.jpg");
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(sf::Vector2f(0.4, 0.4));

	mario_texture.loadFromFile("@.jpg");
	mario_sprite.setTexture(mario_texture);
	mario_sprite.setScale(sf::Vector2f(0.079, 0.103));

	box_texture.loadFromFile("$.jpg");
	box_sprite.setTexture(box_texture);
	box_sprite.setScale(sf::Vector2f(0.33, 0.33));

	grass_texture.loadFromFile("0.jpg");
	grass_sprite.setTexture(grass_texture);
	grass_sprite.setScale(sf::Vector2f(0.08, 0.08));

	wall_texture.loadFromFile("#.jpg");
	wall_sprite.setTexture(wall_texture);
	wall_sprite.setScale(sf::Vector2f(0.05, 0.05));

	point_texture.loadFromFile("p.jpg");
	point_sprite.setTexture(point_texture);
	point_sprite.setScale(sf::Vector2f(0.055, 0.089));






	font.loadFromFile("perfect_dark.ttf");

	s_text.setFont(font);
	s_text.setString("SOKOBAN");
	s_text.setScale(sf::Vector2f(1.5, 1.5));
	s_text.setPosition(sf::Vector2f(180, 70));
	s_text.setColor(sf::Color::White);

	p_text.setFont(font);
	p_text.setString("Play");
	p_text.setPosition(sf::Vector2f(250, 200));
	p_text.setColor(sf::Color::Cyan);

	e_text.setFont(font);
	e_text.setString("Exit");
	e_text.setPosition(sf::Vector2f(250, 300));
	e_text.setColor(sf::Color::White);



	l_text.setFont(font);
	l_text.setString("Load");
	l_text.setPosition(sf::Vector2f(250, 250));
	l_text.setColor(sf::Color::White);

	r_text.setFont(font);
	r_text.setString("Replay");
	r_text.setPosition(sf::Vector2f(180, 75));
	r_text.setColor(sf::Color::White);

	c_text.setFont(font);
	c_text.setString("Continue");
	c_text.setPosition(sf::Vector2f(180, 125));
	c_text.setColor(sf::Color::White);

	rs_text.setFont(font);
	rs_text.setString("Restart level");
	rs_text.setPosition(sf::Vector2f(180, 175));
	rs_text.setColor(sf::Color::White);

	mm_text.setFont(font);
	mm_text.setString("Main menu");
	mm_text.setPosition(sf::Vector2f(180, 375));
	mm_text.setColor(sf::Color::White);

	sv_text.setFont(font);
	sv_text.setString("Save");
	sv_text.setColor(sf::Color::White);

	ps_text.setFont(font);
	ps_text.setScale(sf::Vector2f(1.5,1.5));
	ps_text.setString("PAUSE");
	ps_text.setColor(sf::Color::White);

	lw_text.setFont(font);
	lw_text.setScale(sf::Vector2f(1.5, 1.5));
	lw_text.setString("LEVEL WON");
	lw_text.setColor(sf::Color::White);
	lw_text.setPosition(sf::Vector2f(140,40));


	setting("Main Menu",sf::Vector2u(640,480));

}
void Window::update()
{

	loadSprites();
	while (window.isOpen())
	{
		iniciar();
	}
}
	

void Window::display()
{
	window.display();
}
void Window::m_events()
{
	sf::Event evnt;
	while (window.pollEvent(evnt))
	{
		if (p_modo == 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))

			{
				list.moveUp();
				render();

			}
			else
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					list.moveDown();
					render();
				}
				else
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						list.moveLeft();
						render();

					}
					else
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						{
							list.moveRight();
							render();

						}
						else
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
							{
								p_modo = 1;
								setting("Pause", sf::Vector2u(560, 440));
								pauseRender();


							}
							else
								if (evnt.type == sf::Event::Closed)
								{
									window.close();
								}

		}
		if (p_modo == 1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (pauseIndex == 1)
				{
					pauseIndex = 0;
					pauseRender();
				}
				else
				if (pauseIndex == 2)
				{
					pauseIndex = 1;
					pauseRender();
				}
				else
				if (pauseIndex == 3)
				{
					pauseIndex = 2;
					pauseRender();
				}



			}
			else
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (pauseIndex == 0)
					{
						pauseIndex = 1;
						pauseRender();
					}
					else
						if (pauseIndex == 1)
						{
							pauseIndex = 2;
							pauseRender();
						}
						else
							if (pauseIndex == 2)
							{
								pauseIndex = 3;
								pauseRender();
							}

				}
				else
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
					{
						if (pauseIndex == 0)
						{
							switch (nivelCont)
							{
							case 1:
							{


								setting("Level 1", sf::Vector2u(list.cols * 40, list.rows * 40));

								break;
							}
							case 2:
							{


								setting("Level 2", sf::Vector2u(list.cols * 40, list.rows * 40));
								break;
							}
							case 3:
							{

								setting("Level 3", sf::Vector2u(list.cols * 40, list.rows * 40));
								break;
							}
							case 4:
							{

								setting("Level 4", sf::Vector2u(list.cols * 40, list.rows * 40));
								break;
							}
							case 5:
							{

								setting("Level 5", sf::Vector2u(list.cols * 40, list.rows * 40));
								break;
							}
							}
							render();
							pauseOpc = true;
							p_modo = 0;
						}
						else
						if (pauseIndex == 1)
						{
							
							switch (nivelCont)
							{
							case 1:
							{

								list.deleteList();
								list.loadLevel("level_1.txt");
								list.setX();
								list.setY();
								setting("Level 1", sf::Vector2u(list.cols * 40, list.rows * 40));
								nivelActual = 1;
								render();
								break;
							}
							case 2:
							{
								list.deleteList();
								list.loadLevel("level_2.txt");
								list.setX();
								list.setY();
								setting("Level 2", sf::Vector2u(list.cols * 40, list.rows * 40));
								nivelActual = 2;
								render();
						
								break;
							}
							case 3:
							{
								list.deleteList();
								list.loadLevel("level_3.txt");
								list.setX();
								list.setY();
								setting("Level 3", sf::Vector2u(list.cols * 40, list.rows * 40));
								nivelActual = 3;
								render();
								break;
							}
							case 4:
							{
								list.deleteList();
								list.loadLevel("level_4.txt");
								list.setX();
								list.setY();
								setting("Level 4", sf::Vector2u(list.cols * 40, list.rows * 40));
								nivelActual = 4;
								render();
								break;
							}
							case 5:
							{
								list.deleteList();
								list.loadLevel("level_5.txt");
								list.setX();
								list.setY();
								setting("Level 5", sf::Vector2u(list.cols * 40, list.rows * 40));
								nivelActual = 5;
								render();
								break;
							}
							}
							
							p_modo = 0;
							pauseOpc = true;
						}
						if (pauseIndex == 2)
						{

							p_modo = 2;
							pauseIndex = 0;
							pauseOpc = true;

							

						}
						if (pauseIndex == 3)
						{
							guardarPartida();
						}


					}

		}

    }
}
void Window::clear() 
{
	window.clear(sf::Color::Black);	
}
void Window::setting(const std::string &title,const sf::Vector2u &size)
{
	w_title = title;
	w_size.x = size.x;
	w_size.y = size.y;
	create();
}
void Window::draw(sf::Drawable  &element)
{
	window.draw(element);
}
sf::RenderWindow * Window::getWindow()
{
	return &window;
}
sf::Vector2u Window::getWindowSize()
{
	return w_size;
}

void Window::render()
{
	CellNode *tmp;
	tmp = list.first;
	while (tmp != nullptr)
	{
		switch (tmp->item)
		{
		case '@':
		{
			mario_sprite.setPosition(sf::Vector2f(tmp->x * 40, tmp->y * 40));
			window.draw(mario_sprite);
			break;
		}
		case '$':
		{
			box_sprite.setPosition(sf::Vector2f(tmp->x * 40, tmp->y * 40));
			window.draw(box_sprite);
			break;
		}
		case '#':
		{
			wall_sprite.setPosition(sf::Vector2f(tmp->x * 40, tmp->y * 40));
			window.draw(wall_sprite);
			break;
		}
		case '.':
		{
			point_sprite.setPosition(sf::Vector2f(tmp->x * 40, tmp->y * 40));
			window.draw(point_sprite);
			break;
		}
		case '0':
		{
			grass_sprite.setPosition(sf::Vector2f(tmp->x * 40, tmp->y * 40));
			window.draw(grass_sprite);	
			break;
		}
		}

		tmp = tmp->next;
	}
	window.display();

 
}
void Window::iniciar()
{
	haTerminado = false;
	haIniciado = false;
	replayOpc = false;
	nivelActual = 0;
	menuIndex = 0;
	replayIndex = 0;
	nivelCont = 0;
	pauseIndex = 0;
	p_modo = 0;
	pauseOpc = false;
	nivelGuardado = "";
	while (!haTerminado)
	{
		if (nivelActual == 0)
		{
			nivelGuardado = "";
			list.deleteList();
			nivelCont = 0;
			replayOpc = false;
			replayIndex = 0;
			pauseOpc = false;
			pauseIndex = 0;
			setting("Main Menu",sf::Vector2u(640,480));
			haIniciado = false;
			menuRender();
			while (!haIniciado)
			{
				menu_events();
			}
			++nivelActual;
			++nivelCont;
	
		}
		if (nivelActual == 1)
		{
			p_modo = 0;
			pauseOpc = false;
			pauseIndex = 0;
			replayOpc = false;
			replayIndex = 0;
			list.deleteList();
			list.loadLevel("level_1.txt");
			list.setX();
			list.setY();
			setting("Level 1",sf::Vector2u(list.cols*40,list.rows*40));

			render();
			while (!list.nivelGanado() && p_modo != 2)
			{
				m_events();

			}

			if(list.nivelGanado())
			{
				setting("Level Won", sf::Vector2u(560, 440));
				replayRender();
				while (!replayOpc)
				{
					replayEvents();
				}
			}
			else
			if (p_modo == 2)
			{
				
				nivelCont = 0;
				nivelActual = 0;
				

			}
		}
		if (nivelActual == 2)
		{
			p_modo = 0;
			replayOpc = false;
			replayIndex = 0;
			list.deleteList();
			list.loadLevel("level_2.txt");
			list.setX();
			list.setY();
			setting("Level 2", sf::Vector2u(list.cols * 40, list.rows * 40));
			render();
			while (!list.nivelGanado() && p_modo != 2)
			{
				m_events();

			}
			if (list.nivelGanado())
			{
				setting("Level Won", sf::Vector2u(560, 440));
				replayRender();
				while (!replayOpc)
				{
					replayEvents();
				}
			}
			else
				if (p_modo == 2)
				{
					nivelCont = 0;
					nivelActual = 0;


				}

		}
		if (nivelActual == 3)
		{
			p_modo = 0;
			replayOpc = false;
			replayIndex = 0;
			list.deleteList();
			list.loadLevel("level_3.txt");
			list.setX();
			list.setY();
			setting("Level 3", sf::Vector2u(list.cols * 40, list.rows * 40));

			render();
			while (!list.nivelGanado() && p_modo != 2)
			{
				m_events();

			}
			if (list.nivelGanado())
			{
				setting("Level Won", sf::Vector2u(560, 440));
				replayRender();
				while (!replayOpc)
				{
					replayEvents();
				}
				
			}
			else
				if (p_modo == 2)
				{
					nivelCont = 0;
					nivelActual = 0;


				}



		}
		if (nivelActual == 4)
		{
			p_modo = 0;
			replayOpc = false;
			replayIndex = 0;
			list.deleteList();
			list.loadLevel("level_4.txt");
			list.setX();
			list.setY();
			setting("Level 4", sf::Vector2u(list.cols * 40, list.rows * 40));
			render();
			while (!list.nivelGanado() && p_modo != 2)
			{
				m_events();

			}
			if (list.nivelGanado())
			{
				setting("Level Won", sf::Vector2u(560, 440));
				replayRender();
				while (!replayOpc)
				{
					replayEvents();
				}
			}
			else
				if (p_modo == 2)
				{
					nivelCont = 0;
					nivelActual = 0;


				}

		}
		if (nivelActual == 5)
		{
			p_modo = 0;
			replayOpc = false;
			replayIndex = 0;
			list.deleteList();
			list.loadLevel("level_5.txt");
			list.setX();
			list.setY();
			setting("Level 5", sf::Vector2u(list.cols * 40, list.rows * 40));
			
			while (!list.nivelGanado() && p_modo != 2)
			{
				m_events();

			}
			if (list.nivelGanado())
			{
				setting("Level Won", sf::Vector2u(560, 440));
				replayRender();
				while (!replayOpc)
				{
					replayEvents();
				}
			}
			else
				if (p_modo == 2)
				{
					nivelCont = 0;
					nivelActual = 0;


				}
		}
	}
	window.clear();
	window.display();
	window.close();
}
void Window::menuRender()
{
	switch (menuIndex)
	{
	case 0:
	{
		p_text.setColor(sf::Color::Cyan);
		l_text.setColor(sf::Color::White);
		e_text.setPosition(sf::Vector2f(250, 300));
		e_text.setColor(sf::Color::White);
		window.draw(m_sprite);
		window.draw(s_text);
		window.draw(p_text);
		window.draw(l_text);
		window.draw(e_text);
		break;
	}
	case 1:
	{
		l_text.setColor(sf::Color::Cyan);
		p_text.setColor(sf::Color::White);
		e_text.setColor(sf::Color::White);
		window.draw(m_sprite);
		window.draw(s_text);
		window.draw(p_text);
		window.draw(l_text);
		window.draw(e_text);
		break;
	}
	case 2:
	{
		e_text.setColor(sf::Color::Cyan);
		p_text.setColor(sf::Color::White);
		l_text.setColor(sf::Color::White);
		window.draw(m_sprite);
		window.draw(s_text);
		window.draw(p_text);
		window.draw(l_text);
		window.draw(e_text);
		break;
	}
	}
	window.display();

}
void Window::menu_events()
{

	sf::Event evnt;
	while (window.pollEvent(evnt))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (menuIndex == 1)
			{
				menuIndex = 0;
				menuRender();
			}
			if (menuIndex == 2)
			{
				menuIndex = 1;
				menuRender();
			}

		}
		else
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (menuIndex == 0)
				{
					menuIndex = 1;
					menuRender();
				}
				else
				if (menuIndex == 1)
				{
					menuIndex = 2;
					menuRender();
				}

			}
			else
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					if (menuIndex == 0)
					{
						haIniciado = true;
					}
					if (menuIndex == 1)
					{
						cargarPartida();
						menuIndex = 0;
						haIniciado = true;
					}
					else
					if (menuIndex == 2)
					{
						window.close();
					}
				}
				else
						if (evnt.type == sf::Event::Closed)
						{
							window.close();
						}
	}
}
void Window::replayRender()
{
	c_text.setPosition(sf::Vector2f(180, 125));
	r_text.setPosition(sf::Vector2f(180, 175));
	rs_text.setPosition(sf::Vector2f(180, 225));
	mm_text.setPosition(sf::Vector2f(180, 275));
	e_text.setPosition(sf::Vector2f(180, 325));


	switch (replayIndex)
	{
	case 0:
	{
		c_text.setColor(sf::Color::Cyan);
		r_text.setColor(sf::Color::White);
		rs_text.setColor(sf::Color::White);
		mm_text.setColor(sf::Color::White);
		e_text.setColor(sf::Color::White);

		window.draw(m_sprite);
		window.draw(lw_text);
		window.draw(r_text);
		window.draw(c_text);
		window.draw(rs_text);
		window.draw(mm_text);
		window.draw(e_text);

		break;
	}
	case 1:
	{
		c_text.setColor(sf::Color::White);
		r_text.setColor(sf::Color::Cyan);
		rs_text.setColor(sf::Color::White);
		mm_text.setColor(sf::Color::White);
		e_text.setColor(sf::Color::White);

		window.draw(m_sprite);
		window.draw(lw_text);
		window.draw(r_text);
		window.draw(c_text);
		window.draw(rs_text);
		window.draw(mm_text);
		window.draw(e_text);

		break;
	}
	case 2:
	{
		r_text.setColor(sf::Color::White);
		c_text.setColor(sf::Color::White);
		rs_text.setColor(sf::Color::Cyan);
		mm_text.setColor(sf::Color::White);
		e_text.setColor(sf::Color::White);

		window.draw(m_sprite);
		window.draw(lw_text);
		window.draw(r_text);
		window.draw(c_text);
		window.draw(rs_text);
		window.draw(mm_text);
		window.draw(e_text);

		break;
	}
	case 3:
	{
		r_text.setColor(sf::Color::White);
		c_text.setColor(sf::Color::White);
		rs_text.setColor(sf::Color::White);
		mm_text.setColor(sf::Color::Cyan);
		e_text.setColor(sf::Color::White);

		window.draw(m_sprite);	
		window.draw(lw_text);
		window.draw(r_text);
		window.draw(c_text);
		window.draw(rs_text);
		window.draw(mm_text);
		window.draw(e_text);

		break;
	}
	case 4:
	{
		r_text.setColor(sf::Color::White);
		c_text.setColor(sf::Color::White);
		rs_text.setColor(sf::Color::White);
		mm_text.setColor(sf::Color::White);
		e_text.setColor(sf::Color::Cyan);

		window.draw(m_sprite);
		window.draw(lw_text);
		window.draw(r_text);
		window.draw(c_text);
		window.draw(rs_text);
		window.draw(mm_text);
		window.draw(e_text);

		break;
	}

	}
	window.display();

}
void Window::replayEvents()
{
	sf::Event evnt;
	while (window.pollEvent(evnt))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (replayIndex == 1)
			{
				replayIndex = 0;
				replayRender();
			}
			if (replayIndex == 2)
			{
				replayIndex = 1;
				replayRender();
			}
			if (replayIndex == 3)
			{
				replayIndex = 2;
				replayRender();
			}
			if (replayIndex == 4)
			{
				replayIndex = 3;
				replayRender();
			}

		}
		else
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (replayIndex == 0)
				{
					replayIndex = 1;
					replayRender();
				}
				else
				if (replayIndex == 1)
				{
					replayIndex = 2;
					replayRender();
				}
				else
				if (replayIndex == 2)
				{
					replayIndex = 3;
					replayRender();
				}
				else
				if (replayIndex == 3)
				{
					replayIndex = 4;
					replayRender();
				}

			}
			else
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					if (replayIndex == 0)
					{
						if (nivelActual == 5)
						{
							haTerminado = true;
						}
						else
						{
							++nivelActual;
							++nivelCont;
						}

						replayOpc = true;
						break;
					}
					if (replayIndex == 2)
					{
						nivelActual = nivelCont;
						replayOpc = true;
						break;
					}
					if (replayIndex == 3)
					{
						nivelCont = 0;
						nivelActual = 0;
						replayOpc = true;
					}
					if (replayIndex == 4)
					{
						window.close();
					}

				}
				else
					if (evnt.type == sf::Event::Closed)
					{
						window.close();
					}
	}
}
void Window::pauseRender()
{
	ps_text.setPosition(180,40);
	c_text.setPosition(180, 125);
	rs_text.setPosition(180, 175);
	mm_text.setPosition(180,225);
	sv_text.setPosition(180,275);

	switch (pauseIndex)
	{
	case 0:
	{
		c_text.setColor(sf::Color::Cyan);
		rs_text.setColor(sf::Color::White);
		mm_text.setColor(sf::Color::White);
		sv_text.setColor(sf::Color::White);
		window.draw(m_sprite);
		window.draw(ps_text);
		window.draw(rs_text);
		window.draw(c_text);
	    window.draw(mm_text);
		window.draw(sv_text);
		
		break;
	}
	case 1:
	{
		c_text.setColor(sf::Color::White);
		rs_text.setColor(sf::Color::Cyan);
		mm_text.setColor(sf::Color::White);
		sv_text.setColor(sf::Color::White);
		window.draw(m_sprite);
		window.draw(ps_text);
		window.draw(rs_text);
		window.draw(c_text);
		window.draw(mm_text);
		window.draw(sv_text);
		break;
	}
	case 2:
	{
		rs_text.setColor(sf::Color::White);
		c_text.setColor(sf::Color::White);
		mm_text.setColor(sf::Color::Cyan);
		sv_text.setColor(sf::Color::White);
		window.draw(m_sprite);
		window.draw(ps_text);
		window.draw(rs_text);
		window.draw(c_text);
		window.draw(mm_text);
		window.draw(sv_text);
		break;
	}
	case 3:
	{
		rs_text.setColor(sf::Color::White);
		c_text.setColor(sf::Color::White);
		mm_text.setColor(sf::Color::White);
		sv_text.setColor(sf::Color::Cyan);
		window.draw(m_sprite);
		window.draw(ps_text);
		window.draw(rs_text);
		window.draw(c_text);
		window.draw(mm_text);
		window.draw(sv_text);
		break;
	}

	}
	window.display();
}

int Window::getNumCajas() {
	return list.boxes;
}

void Window::guardarPartida() {
	
	CellNode *aux;

	std::ofstream write;
	write.open("partidaGuardada.txt");
	write << nivelActual << std::endl;
	aux = list.first;
	while (aux!=nullptr)
	{
		
		if (aux->item == '@')
		{

			write << aux->x << aux->y;
			write << std::endl;
		}// guarda mario
		aux = aux->next;
		
	}
	aux = list.first;

	while (aux != nullptr)
	{
		if (aux->isPoint == true)
		{
			write << aux->x << aux->y; // guarda cajas
			write << std::endl;
		}
		aux = aux->next;
		
	}
	write.close();

}
void Window::cargarPartida() {

	
	std::ifstream read;
	read.open("partidaGuardada.txt");
    read >> nivelGuardado;
	nivelActual = atoi(nivelGuardado.c_str()) - 1;
	
	/*switch (nivelActual)
	{
	case 1: {
		list.loadLevel("level_1.txt");
		list.setX();
		list.setY();
		break;

	}
	case 2: {
		list.loadLevel("level_2.txt");
		list.setX();
		list.setY();
		break;

	}
	case 3: {
		list.loadLevel("level_3.txt");
		list.setX();
		list.setY();
		break;
	}case 4: {
		list.loadLevel("level_4.txt");
		list.setX();
		list.setY();
		break;

	}case 5: {
		list.loadLevel("level_5.txt");
		list.setX();
		list.setY();
		break;

	}
	}*/


	read.close();
}


