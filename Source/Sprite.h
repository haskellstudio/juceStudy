#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Attributes.h"
    //#include "windows.h"


class Sprite
{
public:
	Sprite(OpenGLContext& openGLContext) :_vboID(0),
		_openGLContext(openGLContext), isClicked(0)
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
		//first triangle
		_vertexData[0].x = x + width;
		_vertexData[0].y = y + height;
		_vertexData[0].u = 1.0f;
		_vertexData[0].v = 1.0f;

		_vertexData[1].x = x;
		_vertexData[1].y = y + height;
		_vertexData[1].u = 0.0f;
		_vertexData[1].v = 1.0f;

		_vertexData[2].x = x;
		_vertexData[2].y = y ;
		_vertexData[2].u = 0.0f;
		_vertexData[2].v = 0.0f;

		//second triangle

		_vertexData[3].x = x;
		_vertexData[3].y = y;
		_vertexData[3].u = 0.0f;
		_vertexData[3].v = 0.0f;

		_vertexData[4].x = x+width;
		_vertexData[4].y = y;
		_vertexData[4].u = 1.0f;
		_vertexData[4].v = 0.0f;

		_vertexData[5].x = x + width;
		_vertexData[5].y = y + height;
		_vertexData[5].u = 1.0f;
		_vertexData[5].v = 1.0f;
		//first triangle
		//vertexData[0] = x + width;
		//vertexData[1] = y + height;

		//vertexData[2] = x;
		//vertexData[3] = y + height;

		//vertexData[4] = x ;
		//vertexData[5] = y ;

		//second triangle
		//vertexData[6] = x;
		//vertexData[7] = y;

		//vertexData[8] = x + width;
		//vertexData[9] = y;

		//vertexData[10] = x + width;
		//vertexData[11] = y + height;
        //int i = ::GetLastError();
		_openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, _vboID);
        // i = ::GetLastError();
		 //int len = sizeof(vertexData);

		_openGLContext.extensions.glBufferData(GL_ARRAY_BUFFER, sizeof(_vertexData), &_vertexData[0], GL_STATIC_DRAW);
        //i = ::GetLastError();
		_openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
        //i = ::GetLastError();
	}

	//void setShader(OpenGLShaderProgram * shader)
	//{
	//	attributes = nullptr;
	//	attributes = new Attributes(_openGLContext, *shader);

	//	uniforms = new Uniforms(_openGLContext, *shader);
	//}

	//void setColor(float r, float g, float b, float a)
	//{
	//	if (uniforms)
	//	{
	//		if (uniforms->lightPosition != nullptr)
	//			uniforms->lightPosition->set(r, g, b, a);
	//	}
	//}
	//void setTexture(GLint i)
	//{
	//	if (uniforms)
	//	{
	//		if (uniforms->texture != nullptr)
	//			uniforms->texture->set(i);
	//	}
	//}
	void bind()
	{
		_openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	}
	void draw()
	{
		if (0 == _vboID)
		{
			AlertWindow::showMessageBox(AlertWindow::AlertIconType::InfoIcon, "Error", "0 == _vboID", "EXIT");
			return;
		}
		//if (attributes == nullptr || uniforms == nullptr)
		//	return;
		//if (!attributes->getStatus() || !uniforms->getStatus())
		//	return;
		

		//attributes->enable(_openGLContext);
		//double curTime = Time::getMillisecondCounterHiRes();

		//setColor(sin(curTime), 0, 1, 1);

		//setTexture(0);
        //	i = ::GetLastError();
	//	_openGLContext.extensions.glEnableVertexAttribArray(0);

	//	_openGLContext.extensions.glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glDrawArrays(GL_TRIANGLES, 0, 6);// sizeof(vertexData)/sizeof(float)/2

	//	_openGLContext.extensions.glDisableVertexAttribArray(0);
	//	attributes->disable(_openGLContext);
        //	i = ::GetLastError();
		_openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
        //	i = ::GetLastError();
	}

public:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;
	int isClicked;
	OpenGLContext& _openGLContext;
	OpenGLShaderProgram * _shader;


	
	Vertex _vertexData[6] = { 0 };
};

