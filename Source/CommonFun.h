#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

Component* getChildComponentByName(Component* parent, String name);

struct ShaderPreset
{
	String name;
	String vertexShader;
	String fragmentShader;
};



struct ShaderData {
	Array<ShaderPreset*> _shaderPreset;

	ShaderData() 
	{

		ShaderPreset * p1 = new ShaderPreset{
			"shader1",
			"\
//1\
#version 120\n\
attribute vec2 position; \n\
attribute vec2 textureCoordIn; \n\
varying vec2 textureCoordOut; \n\
void main()\n\
{ \n\
	gl_Position.xy = position; \n\
	gl_Position.z = -1.0; \n\
	gl_Position.w = 1.0; \n\
	textureCoordOut = textureCoordIn;\n\
}\n\
",
"\
//1\
#version 120\n\
uniform vec4 lightPosition; \n\
varying vec2 textureCoordOut; \n\
uniform sampler2D demoTexture; \n\
vec3 color; \n\
void main()\n\
{ \n\
	gl_FragColor = texture2D(demoTexture, textureCoordOut);\n\
	//gl_FragColor = lightPosition* texture2D (demoTexture, textureCoordOut);\n\
	//gl_FragColor = lightPosition;//vec4(1.0, 0.0, 0.0, 1.0); \n\
}\n\
"
		};





		ShaderPreset * p2 = new ShaderPreset
		{
			"shader2",
			"\
//2\
#version 120\n\
attribute vec2 position; \n\
attribute vec2 textureCoordIn; \n\
varying vec2 textureCoordOut; \n\
void main()\n\
{ \n\
	gl_Position.xy = position; \n\
	gl_Position.z = -1.0; \n\
	gl_Position.w = 1.0; \n\
	textureCoordOut = textureCoordIn;//the second vertex shader\n\
}\n\
",
"\
//2\
#version 120\n\
uniform vec4 lightPosition; \n\
varying vec2 textureCoordOut; \n\
uniform sampler2D demoTexture; \n\
vec3 color; \n\
void main()\n\
{ \n\
	gl_FragColor = texture2D(demoTexture, textureCoordOut);\n\
	//gl_FragColor = lightPosition* texture2D (demoTexture, textureCoordOut);\n\
	//gl_FragColor = lightPosition;//vec4(1.0, 0.0, 0.0, 1.0); //the second fragment shader\n\
}\n\
"
		};

		_shaderPreset.add(p1);
		_shaderPreset.add(p2);


		
	}

};