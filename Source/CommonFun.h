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
			STRINGIFY(\
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

STRINGIFY(\
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

float getR(float x, float min1 , float max1, float min2, float max2)
{
	return (x-min1)/(max1-min1)*(max2-min2)+min2;
}
float Circle(vec2 uv, vec2 p,  float r, float blur)
{
	float d = length(uv-p);
	float c = smoothstep(r, r - blur, d);
	return c;
}

float Smiley(vec2 uv, vec2 p, float size)
{
	uv = uv - p;
	uv /= size;
	float mask = Circle(
		uv,
		vec2(.0, .0),
		.4,
		.03
	);

	mask -= Circle(
		uv,
		vec2(-.13, .2),
		.07,
		.03
	);


	mask -= Circle(
		uv,
		vec2(.13, .2),
		.07,
		.03
	);

	float mouth = Circle(uv, vec2(0.0, 0.0), .3, .02);
	mouth -= Circle(uv, vec2(0., 0.1), .3, .02);

	mask -= mouth;
	return mask;
}


void main()
{
	vec2 uv = _uv;
	uv -= 0.5;
	uv.x *= _w / _h;
	uv.x *= winW / winH;
	float mask = 0;
	mask = Smiley(uv, 
						vec2(getR(sin(iGlobalTime), -1.0, 1.0, -0.5, 0.5),
							 getR(sin(iGlobalTime), -1.0, 1.0, -0.5, 0.5)),
						getR(sin(iGlobalTime), -1.0, 1.0, 0.5, 1.5));
	/**/

	//vec3 col = vec3(sin(iGlobalTime), cos(iGlobalTime), sin(iGlobalTime) * cos(iGlobalTime)) * mask;
	//mask = smoothstep(-.1, .1, uv.x);


	vec3 col = vec3(1., 0., 0.);//*mask;
	gl_FragColor = vec4(col, 1.0f);
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

			STRINGIFY(\
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

			STRINGIFY(\
		#version 120 \n
		//uniform vec4 lightPosition;
		//varying vec2 textureCoordOut;
		//varying vec2 _uv;
		//uniform sampler2D demoTexture;
		//vec3 color;
		//uniform float iGlobalTime;
		//uniform float _x;
		//uniform float _y;
		//uniform float _w;
		//uniform float _h;
		//void main()
		//{
		//	//textureCoordOut.x += .5;
		//	gl_FragColor = texture2D(demoTexture, textureCoordOut /*+ vec2(.5, .0)*/ );
		//	//gl_FragColor = vec4(sin (iGlobalTime), cos(iGlobalTime), 1, 1)  * lightPosition* texture2D (demoTexture, textureCoordOut);
		//	//gl_FragColor = vec4(uv.x,uv.y,0.,1.);
		//	//gl_FragColor = vec4(_uv.x,1.0,1.0,1.);
		//	//gl_FragColor = lightPosition;
		//	//vec4(1.0, 0.0, 0.0, 1.0);
		//	//the second fragment shader
		//}

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
		float pxRange = 2.0;
		vec4 bgColor = vec4(0.0, 0.0, 0.0, 1.0f);
		vec4 fgColor = vec4(1.0, 1.0, 0.0, 1.0f);

		float median(float r, float g, float b) {
			return max(min(r, g), min(max(r, g), b));
		}

		void main()
		{
			vec2 msdfUnit = pxRange / vec2(32.0, 32.0);

			vec3 sample = texture2D(demoTexture, textureCoordOut).rgb;

			float sigDist = median(sample.r, sample.g, sample.b) - 0.5;

			sigDist *= dot(msdfUnit, 0.5 / fwidth(textureCoordOut));

			float opacity = clamp(sigDist + 0.5, 0.0, 1.0);
			// gl_FragColor = texture2D(demoTexture, textureCoordOut );

			gl_FragColor = mix(bgColor, fgColor, opacity);
		}


		)
		};

		_shaderPreset.add(p1);
		_shaderPreset.add(p2);


		
	}

};

/*




*/
