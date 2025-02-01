#include "support.h"
//Private functions
void support::initWindow()
{
	this->videoMode.height = 640;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Happy_New_Year_2025", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void support::initVar()
{
	this->stop = false;
	this->timer = 8.f;
	for(int i=0;i<3;i++)this->inds[i]=i;
	std::fstream file("wordf.txt",std::ios::in);
	std::string word;
	//std::cout << file.is_open();
	while (std::getline(file, word))
	{
		//std::cout << word<<"\n";
		this->words.push_back(word);
	}
	file.close();
	std::vector<std::string>str = { "crown","diamond","fire","pheart","rheart","ribbon","ring","star" };
	for (auto& a : str)
	{
		this->iwords.push_back(a);
	}
}

void support::initFonts()
{
	if (this->font.loadFromFile("fonts/Raleway-Bold.ttf"))
	{
		std::cout << "ERROR:support::::INITFONTS::Failed to load font" << "\n";
	}
}

void support::initText()
{
	this->T1.setFont(this->font);
	this->T1.setCharacterSize(100);
	this->T1.setFillColor(sf::Color::White);
	this->T1.setString("Happy New");
	this->T1.setPosition(sf::Vector2f(120.f, 5.f));
	this->T2.setFont(this->font);
	this->T2.setCharacterSize(100);
	this->T2.setFillColor(sf::Color::White);
	this->T2.setString("Year 2025");
	this->T2.setPosition(sf::Vector2f(120.f, 165.f));
	this->w1.setFont(this->font);
	this->w1.setCharacterSize(30);
	this->w1.setFillColor(sf::Color::White);
	this->w1.setPosition(sf::Vector2f(60.f, 325.f));
	this->w2.setFont(this->font);
	this->w2.setCharacterSize(30);
	this->w2.setFillColor(sf::Color::White);
	this->w2.setPosition(sf::Vector2f(290.f, 325.f));
	this->w3.setFont(this->font);
	this->w3.setCharacterSize(30);
	this->w3.setFillColor(sf::Color::White);
	this->w3.setPosition(sf::Vector2f(520.f, 325.f));
	int n = this->words.size();
	int ind = rand() % n;
	//std::cout << this->words.size();
	this->w1.setString(this->words[ind]);
	this->words.erase(this->words.begin() + ind, this->words.begin() + ind);
	n = this->words.size();
	ind = rand() % n;
	this->w2.setString(this->words[ind]);
	this->words.erase(this->words.begin() + ind, this->words.begin() + ind);
	n = this->words.size();
	ind = rand() % n;
	this->w3.setString(this->words[ind]);
	this->words.erase(this->words.begin() + ind, this->words.begin() + ind);
	std::string strt;
	n = this->iwords.size();
	for (long long unsigned int i = 0; i < this->iwords.size(); i++)
	{
		strt = this->iwords[i];
		this->txs[i].loadFromFile(strt + ".jpg");
		this->sps[i].setTexture(this->txs[i]);
		this->sps[i].setPosition(sf::Vector2f(60.f+230.f*i, 485.f));
		this->sps[i].setScale(0.5, 0.5);
	}
}


support::support()
{
	this->initWindow();
	this->initFonts();
	this->initVar();
	this->initText();	
}

support::~support()
{
	delete this->window;
}
//Accessors
const bool support::running() const
{
	return this->window->isOpen();
}

//Functions
void support::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->eevee))
	{
		switch (this->eevee.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->eevee.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}
		}
	}
}
void support::updateMousePositions()
{
	/*return void
	Updates the mouse position:
	Mouse pos relative to window(vector2i)*/
	this->MousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->MousePosWindow);
}

//ctrl + . or > key on function in h file to auto define in cpp file
void support::update()
{
	this->pollEvents();
	this->updateMousePositions();
		//Update mouse position
		//Relative to the window
	if (!stop)
	{
		//std::cout << "hello "<< this->eevee.key.code<<" "<< this->timer << "\n";
		if (this->timer > 0.f)
		{
			this->timer -= 1.f;
			//for (int i = 0; i < 50000000; i++);
		}
		else
		{
			this->timer = 8.f;
			this->updateText();
			this->updateSprite();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))stop = true;
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))stop = false;
	}
		//this->updateText();
		//this->updateSprite();

}

void support::updateText()
{
	if (this->words.size() == 0)
	{
		std::fstream file("wordf.txt", std::ios::in);
		std::string word;
		//std::cout << file.is_open();
		while (std::getline(file, word))
		{
			//std::cout << word<<"\n";
			this->words.push_back(word);
		}
		file.close();
	}
	int n = this->words.size();
	int ind = rand() % n;
	//std::cout << this->words.size();
	this->w1.setString(this->words[ind]);
	this->words.erase(this->words.begin() + ind, this->words.begin() + ind);
	n = this->words.size();
	ind = rand() % n;
	this->w2.setString(this->words[ind]);
	this->words.erase(this->words.begin() + ind, this->words.begin() + ind);
	n = this->words.size();
	ind = rand() % n;
	this->w3.setString(this->words[ind]);
	this->words.erase(this->words.begin() + ind, this->words.begin() + ind);
}

void support::updateSprite()
{
	int sz = this->iwords.size();
	std::unordered_set<int>st;
	for (int i = 0; i < 3; i++)
	{
		int n;
		n = rand() % sz;
		while (st.find(n) != st.end())n = rand() % sz;
		st.insert(n);
		this->inds[i] = n;
	}
	for (int i = 0; i < 3; i++)
	{
		this->sps[this->inds[i]].setPosition(sf::Vector2f(60.f + 230.f * i, 485.f));
	}
}


void support::renderText(sf::RenderTarget& target)
{
	target.draw(this->T1);
	target.draw(this->T2);
	target.draw(this->w1);
	target.draw(this->w2);
	target.draw(this->w3);
	for (int i = 0; i < 3; i++)
	{
		std::cout << this->inds[i] << " ";
		target.draw(this->sps[this->inds[i]]);
	}
	std::cout << "\n";
}



void support::render()
{
	/*
	* return void
	 -clear old frame
	 -render objects
	 -display the new window

	renders the support objects

	*/
	//color(r,g,b,transparency(alpha))
	this->window->clear(sf::Color());
	//Draw support
	this->renderText(*this->window);
	this->window->display();
}
