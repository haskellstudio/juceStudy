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
varying vec2 uv;\n\
uniform mat4 projectionMatrix; \n\
uniform mat4 viewMatrix;\n\
uniform float _x;\n\
uniform float _y;\n\
uniform float _w;\n\
uniform float _h;\n\
uniform float winW;\n\
uniform float winH;\n\
float getx()\n\
{\n\
	return (position.x - _x) / _w; \n\
}\n\
float gety()\n\
{\n\
	return (position.y - _y) / _h; \n\
}\n\
vec2 _uv()\n\
{\n\
	return vec2(getx(), gety());\n\
}\n\
void main()\n\
{ \n\
	gl_Position = projectionMatrix *viewMatrix * vec4(position, 0.0, 1.0);\n\
	textureCoordOut = textureCoordIn;\n\
	uv = _uv();\n\
}\n\
",
"\
//1\
#version 120\n\
uniform vec4 lightPosition; \n\
varying vec2 textureCoordOut; \n\
varying vec2 uv;\n\
uniform sampler2D demoTexture; \n\
uniform float iGlobalTime;\n\
uniform float _x;\n\
uniform float _y;\n\
uniform float _w;\n\
uniform float _h;\n\
uniform float winW;\n\
uniform float winH;\n\
float getx()\n\
{\n\
	return (uv.x - _x) / _w; \n\
}\n\
float gety()\n\
{\n\
	return (uv.y - _y) / _h; \n\
}\n\
vec2 _uv()\n\
{\n\
	return vec2(getx(), gety());\n\
}\n\
vec3 color; \n\
void main()\n\
{ \n\
	//gl_FragColor = texture2D(demoTexture, textureCoordOut);\n\
	uv -= 0.5;\n\
	uv.x *= _w / _h;\n\
	uv.x *= winW / winH;\n\
	float d = length(uv);\n\
		float c = 0.0;\n\
		if (d < 0.3)\n\
			c = 1.;\n\
		else\n\
			c = 0.;\n\
		gl_FragColor = vec4(vec3(c), 1.0f); \n\
	//gl_FragColor = lightPosition* texture2D (demoTexture, textureCoordOut);\n\
	//gl_FragColor = vec4(uv.x, uv.y ,0.f ,1.0f);\n\
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
varying vec2 uv;\n\
uniform mat4 projectionMatrix; \n\
uniform mat4 viewMatrix;\n\
uniform float _x;\n\
uniform float _y;\n\
uniform float _w;\n\
uniform float _h;\n\
float getx()\n\
{\n\
	return (position.x - _x) / _w; \n\
}\n\
float gety()\n\
{\n\
	return (position.y - _y) / _h; \n\
}\n\
vec2 _uv()\n\
{\n\
	return vec2(getx(), gety());\n\
}\n\
void main()\n\
{ \n\
	gl_Position =projectionMatrix * viewMatrix * vec4(position, 0.0, 1.0);\n\
	//gl_Position.xy = position; \n\
	//gl_Position.z = -1.0; \n\
	//gl_Position.w = 1.0; \n\
	textureCoordOut = textureCoordIn;//the second vertex shader\n\
	uv = _uv();\n\
}\n\
",
"\
//2\
#version 120\n\
uniform vec4 lightPosition; \n\
varying vec2 textureCoordOut; \n\
varying vec2 uv;\n\
uniform sampler2D demoTexture; \n\
vec3 color; \n\
uniform float iGlobalTime;\n\
uniform float _x;\n\
uniform float _y;\n\
uniform float _w;\n\
uniform float _h;\n\
float getx()\n\
{\n\
	return (uv.x - _x) / _w; \n\
}\n\
float gety()\n\
{\n\
	return (uv.y - _y) / _h; \n\
}\n\
vec2 _uv()\n\
{\n\
	return vec2(getx(), gety());\n\
}\n\
void main()\n\
{ \n\
	//gl_FragColor = texture2D(demoTexture, textureCoordOut);\n\
	//gl_FragColor = vec4(sin (iGlobalTime), cos(iGlobalTime), 1, 1)  * lightPosition* texture2D (demoTexture, textureCoordOut);\n\
	//gl_FragColor = vec4(uv.x,uv.y,0.,1.);\n\
     gl_FragColor = vec4(1.0,1.0,1.0,1.);\n\
	//gl_FragColor = lightPosition;//vec4(1.0, 0.0, 0.0, 1.0); //the second fragment shader\n\
}\n\
"
		};

		_shaderPreset.add(p1);
		_shaderPreset.add(p2);


		
	}

};
