#pragma once

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	void flip();

	void clear();

	void setColor(int r, int g, int b);

	void fillRect(SDL_Rect _rect);

	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

