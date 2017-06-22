#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#define STRINGIFY(A) #A
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
			STRINGIFY(
		#version 120 \n
		attribute vec2 position;
		attribute vec2 textureCoordIn;
		varying vec2 textureCoordOut;
		varying vec2 _uv;
		uniform mat4 projectionMatrix;
		uniform mat4 viewMatrix;
		uniform float _x;
		uniform float _y;
		uniform float _w;
		uniform float _h;
		uniform float winW;
		uniform float winH;
		float getx()
		{
			return (position.x - _x) / _w;
		}
		float gety()
		{
			return (position.y - _y) / _h;
		}
		vec2 getUV()
		{
			return vec2(getx(), gety());
		}
		void main()
		{
			gl_Position = projectionMatrix *viewMatrix * vec4(position, 0.0, 1.0);
			textureCoordOut = textureCoordIn;
			_uv = getUV();
		}
)
			,

STRINGIFY(
#version 120 \n
uniform vec4 lightPosition;
varying vec2 textureCoordOut;
varying vec2 _uv;
uniform sampler2D demoTexture;
uniform float iGlobalTime;
uniform float _w;
uniform float _h;
uniform float winW;
uniform float winH;
float Circle(vec2 uv, float r, float blur)
{
	float d = length(uv);
	float c = smoothstep(r, r - blur, d);
	return c;
}
void main()
{
	vec2 uv = _uv;
	uv -= 0.5;
	uv.x *= _w / _h;
	uv.x *= winW / winH;


	float c = Circle(uv, .4, .05);
	gl_FragColor = vec4(vec3(c), 1.0f);
}
)
/*
"\
//1\n\
#version 120\n\
uniform vec4 lightPosition; \n\
varying vec2 textureCoordOut; \n\
varying vec2 _uv;\n\
uniform sampler2D demoTexture; \n\
uniform float iGlobalTime;\n\
uniform float _w; \n\
uniform float _h; \n\
uniform float winW;\n\
uniform float winH;\n\
void main()\n\
{ \n\
	vec2 uv = _uv;\n\
	uv -= 0.5;\n\
	uv.x *= _w / _h;\n\
	uv.x *= winW / winH;\n\
	float d = length(uv);\n\
	float r = 0.3; \n\
	float c = smoothstep(r, r-0.01, d);\n\
	gl_FragColor = vec4(vec3(c), 1.0f); \n\
}\n\
"*/
};

		//uniform float _x; \n\
		//	uniform float _y; \n\


		//float getx()\n\
		//{\n\
		//	return (uv.x - _x) / _w; \n\
		//}\n\
		//	float gety()\n\
		//{\n\
		//	return (uv.y - _y) / _h; \n\
		//}\n\
		//	vec2 _uv()\n\
		//{\n\
		//	return vec2(getx(), gety()); \n\
		//}\n\
		//	vec3 color; \n\

	//gl_FragColor = texture2D(demoTexture, textureCoordOut);\n\
		//float c = 0.0;\n\
				//if (d < 0.3)\n\
		//	c = 1.;\n\
		//else\n\
		//	c = 0.;\n\
	//gl_FragColor = lightPosition* texture2D (demoTexture, textureCoordOut);\n\
	//gl_FragColor = vec4(uv.x, uv.y ,0.f ,1.0f);\n\
	//gl_FragColor = lightPosition;//vec4(1.0, 0.0, 0.0, 1.0); \n\


		ShaderPreset * p2 = new ShaderPreset
		{
			"shader2",

			STRINGIFY(
				#version 120 \n
				attribute vec2 position;
		attribute vec2 textureCoordIn;
		varying vec2 textureCoordOut;
		varying vec2 _uv;
		uniform mat4 projectionMatrix;
		uniform mat4 viewMatrix;
		uniform float _x;
		uniform float _y;
		uniform float _w;
		uniform float _h;
		float getx()
		{
			return (position.x - _x) / _w;
		}
		float gety()
		{
			return (position.y - _y) / _h;

		}
		vec2 getUV()
		{
			return vec2(getx(), gety());

		}
		void main()
		{
			gl_Position = projectionMatrix * viewMatrix * vec4(position, 0.0, 1.0);
			textureCoordOut = textureCoordIn;
			_uv = getUV();
		}
		)
			,

			STRINGIFY(
		#version 120 \n
		uniform vec4 lightPosition;
		varying vec2 textureCoordOut;
		varying vec2 _uv;
		uniform sampler2D demoTexture;
		vec3 color;
		uniform float iGlobalTime;
		uniform float _x;
		uniform float _y;
		uniform float _w;
		uniform float _h;
		void main()
		{
			//gl_FragColor = texture2D(demoTexture, textureCoordOut);
			//gl_FragColor = vec4(sin (iGlobalTime), cos(iGlobalTime), 1, 1)  * lightPosition* texture2D (demoTexture, textureCoordOut);
			//gl_FragColor = vec4(uv.x,uv.y,0.,1.);
			gl_FragColor = vec4(_uv.x,1.0,1.0,1.);
			//gl_FragColor = lightPosition;
			//vec4(1.0, 0.0, 0.0, 1.0);
			//the second fragment shader
		}
		)
		};

		_shaderPreset.add(p1);
		_shaderPreset.add(p2);


		
	}

};

/*




*/