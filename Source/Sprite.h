#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Sprite
{
public:
	Sprite::Sprite(OpenGLContext& openGLContext) :_vboID(0),
		_openGLContext(openGLContext)
	{
	}


	Sprite::~Sprite()
	{
	}



	void init(int x, int y, int width, int height)
	{
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		if (0 == _vboID)
		{
			_openGLContext.extensions.glGenBuffers(1, &_vboID);
			
		}

	}

	void draw()
	{

	}

private:
	int _x;
	int _y;
	int _width;
	int _height;
	GLuint _vboID;

	OpenGLContext& _openGLContext;
};

