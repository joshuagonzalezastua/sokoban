#pragma once
#include "List.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Window
{
private:
	sf::Font font;
	sf::Text p_text;
	sf::Text l_text;
	sf::Text s_text;
	sf::Text e_text;
	sf::Text c_text;
	sf::Text r_text;
	sf::Text mm_text;
	sf::Text rs_text;
	sf::Text sv_text;
	sf::Text ps_text;
	sf::Text lw_text;

	sf::RenderWindow window;
	sf::Vector2u w_size;
	std::string w_title;

	sf::Sprite m_sprite;
	sf::Sprite mario_sprite;
	sf::Sprite box_sprite;
	sf::Sprite point_sprite;
	sf::Sprite grass_sprite;
	sf::Sprite wall_sprite;

	sf::Texture m_texture;
	sf::Texture mario_texture;
	sf::Texture box_texture;
	sf::Texture point_texture;
	sf::Texture wall_texture;
	sf::Texture  grass_texture;

	//bool haTerminado;
	bool nivelGanado;
	int nivelActual;
	int m_index;

	int menuIndex;
	int replayIndex;
	int pauseIndex;

	bool haIniciado;
	bool replayOpc;
	bool pauseOpc;
	List list;
public:
	bool haTerminado;
	Window();
	Window(const std::string &,const sf::Vector2u&);
	~Window();
	void clear();
	void loadSprites();
	void create();
	void deleteWindow();
	void draw(sf::Drawable &);
	void update();
	void display();
	void render();
	void m_events();
	void iniciar();
	sf::Vector2u getWindowSize();
	sf::RenderWindow * getWindow();
	void setting(const std::string & title, const sf::Vector2u&);
	void menu_events();
	void guardarPartida();

	void menuRender();
	void replayRender();
	void replayEvents();
	void pauseRender();
	int nivelCont;
	int getNumCajas();
	void cargarPartida();
	int p_modo;
	std::string nivelGuardado;

};