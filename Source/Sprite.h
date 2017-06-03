#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Sprite
{
public:
	Sprite(OpenGLContext& openGLContext) :_vboID(0),
		_openGLContext(openGLContext)
	{
	}


	~Sprite()
	{
		if (0 != _vboID)
		{
			_openGLContext.extensions.glDeleteBuffers(1, &_vboID);
		}
	}



	void init(float x, float y, float width, float height)
	{
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		if (0 == _vboID)
		{
			_openGLContext.extensions.glGenBuffers(1, &_vboID);
			 
		}
		if (0 == _vboID)
		{
			AlertWindow::showMessageBox(AlertWindow::AlertIconType::InfoIcon, "Error", "0 == _vboID in init", "EXIT");
			return;
		}
			
		float vertexData[12] = { 0 };


		//first triangle
		vertexData[0] = x + width;
		vertexData[1] = y + height;

		vertexData[2] = x;
		vertexData[3] = y + height;

		vertexData[4] = x ;
		vertexData[5] = y ;

		//second triangle
		vertexData[6] = x;
		vertexData[7] = y;

		vertexData[8] = x + width;
		vertexData[9] = y;

		vertexData[10] = x + width;
		vertexData[11] = y + height;

		_openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, _vboID);
		_openGLContext.extensions.glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

		_openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void draw()
	{
		if (0 == _vboID)
		{
			AlertWindow::showMessageBox(AlertWindow::AlertIconType::InfoIcon, "Error", "0 == _vboID", "EXIT");
			return;
		}
		_openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, _vboID);


		_openGLContext.extensions.glEnableVertexAttribArray(0);


		_openGLContext.extensions.glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);


		glDrawArrays(GL_TRIANGLES, 0, 6);// sizeof(vertexData)/sizeof(float)/2

		_openGLContext.extensions.glDisableVertexAttribArray(0);


		_openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

private:
	int _x;
	int _y;
	int _width;
	int _height;
	GLuint _vboID;

	OpenGLContext& _openGLContext;
};

