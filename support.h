#pragma once
#include<iostream>
#include<vector>
#include<unordered_set>
#include<fstream>
#include<ctime>
#include<sstream>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
/* support engine class.Acts as Wrapper class.*/
class support
{
private:
	//variables
	//window
	sf::RenderWindow* window;
	sf::Event eevee;
	sf::VideoMode videoMode;
	//Mouse position
	sf::Vector2i MousePosWindow;
	sf::Vector2f mousePosView;
	//Resources
	sf::Font font;
	//Text
	sf::Text T1,T2;
	sf::Text w1, w2, w3;
	//Images
	sf::Texture txs[8];
	sf::Sprite sps[8];
	//Variables
	bool stop;
	long double timer;
	int inds[3];
	std::vector<std::string> iwords, words;
	void initWindow();
	void initVar();
	void initFonts();
	void initText();
public:
	support();//Constructor
	virtual ~support();//Destructor
	//Accessors
	const bool running() const;
	//Functions
	void pollEvents();
	void updateMousePositions();
	void update();
	void updateText();
	void updateSprite();
	void renderText(sf::RenderTarget& target);
	void render();
};

