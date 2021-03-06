/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//#include <OpenGL/gl.h>
//#include <OpenGL/glu.h>
#include "CommonFun.h"
#include "Attributes.h"
#include "Sprite.h"
#include "OverLay.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <../Source/glm/glm.hpp>
//#include <../Source/glm/gtc/quaternion.hpp>
#include <../Source/glm/gtx/quaternion.hpp>
//#include <../Source/glm/gtx/transform.hpp>
#include "Ray.h"
extern ShaderData g_shaderData;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
                                                                    //[/Comments]
*/
class ThreeDTest  : public Component,
                    private OpenGLRenderer,
                    private Timer,
					private CodeDocument::Listener
{
public:
    //==============================================================================
    ThreeDTest ();
    ~ThreeDTest();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void newOpenGLContextCreated() override
	{
		freeAllContextObjects();
	}
	void openGLContextClosing() override
	{
		freeAllContextObjects();
	}
	void freeAllContextObjects()
	{
		_shader = nullptr;
		_shader2 = nullptr;
		texture.release();
	}
	inline Colour getUIColourIfAvailable(LookAndFeel_V4::ColourScheme::UIColour uiColour, Colour fallback = Colour(0xff4d4d4d))
	{
		if (auto* v4 = dynamic_cast<LookAndFeel_V4*> (&LookAndFeel::getDefaultLookAndFeel()))
			return v4->getCurrentColourScheme().getUIColour(uiColour);

		return fallback;
	}

	void drawSprite(OpenGLShaderProgram* s,  Sprite&  sp , Attributes* atrr, Uniforms* uf, int itime_ , float winw, float winh) {

        float itime = float(itime_%1000);
		s->use();
		sp.bind();
		if (uf)
		{
			if (uf->lightPosition)
			{
				if(sp.isClicked==0)
					uf->lightPosition->set(1.0f, 1.0f, 1.0f, 1.0f);
				else if(sp.isClicked == 1)
					uf->lightPosition->set(0.0f, 1.0f, 0.0f, 1.0f);

			}

			if (uf->projectionMatrix != nullptr)
				uf->projectionMatrix->setMatrix4(getProjectionMatrix().mat, 1, false);

			if (uf->viewMatrix != nullptr)
				uf->viewMatrix->setMatrix4( (getViewMatrix() * getModelMatrix()).mat, 1, false);

            if(uf->texture)
            {
				uf->texture->set(0);
            }
			if (uf->iGlobalTime)
			{
			
				uf->iGlobalTime->set(itime);
			}
			if (uf->x)
			{
				uf->x->set(sp._x);
			}
			
			if (uf->y)
			{
				uf->y->set(sp._y);
			}

			if (uf->w)
			{
				uf->w->set(sp._width);
			}

			if (uf->h)
			{
				uf->h->set(sp._height);
			}

			if (uf->winW)
			{
				uf->winW->set(winw);
			}

			if (uf->winH)
			{
				uf->winH->set(winh);
			}
		}

		atrr->enable(openGLContext);
		sp.draw();
		atrr->disable(openGLContext);
		openGLContext.extensions.glUseProgram(0);

	}
	void renderOpenGL() override
	{
		if (o)
		{
			o->setText(juce::String(juce::Time::getApproximateMillisecondCounter()));
		}
		if (false == isInit)
		{
			if (openGLContext.isActive())
			{
				_sprite.init(0., .0, .2, .2);
				_sprite2.init(-1, -1, 1.0, 1.0);
				isInit = true;
				dt.applyTo(texture);

				const GLubyte* version = glGetString(GL_VERSION); //返回负责当前OpenGL实现厂商的名字  
				DBG(juce::String((char*)version));
				const GLubyte* vender = glGetString(GL_VENDOR); //返回负责当前OpenGL实现厂商的名字  
				DBG(juce::String((char*)vender));
				const GLubyte* render = glGetString(GL_RENDERER); //返回一个渲染器标识符，通常是个硬件平台  
				DBG(juce::String((char*)render));
				

			}
			else
				return;

		}
		bool b = OpenGLHelpers::isContextActive();
		if (!b)
		{
			return;
		}

		//openGLContext.setOpenGLVersionRequired(juce::OpenGLContext::OpenGLVersion::openGL3_2);

		//juce::String s((char*)glGetString(GL_VERSION));
		//DBG(s);

		// OpenGLHelpers::getExtensionFunction



		jassert(OpenGLHelpers::isContextActive());

		const float desktopScale = (float)openGLContext.getRenderingScale();
		//  glEnableClientState(GL_VERTEX_ARRAY);
		//	glEnableClientState(GL_COLOR_ARRAY);


		updateShader();


		if (_shader == nullptr || _shader2 == nullptr)
			return;


	/*	glClearDepth(1.0);

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glColor3f(0.f, 1.f, 0.f);*/
	/*	OpenGLHelpers::clear(getUIColourIfAvailable(LookAndFeel_V4::ColourScheme::UIColour::windowBackground,
			Colours::lightblue));*/

		/*OpenGLHelpers::clear(Colours::lightpink);*/
		//OpenGLHelpers::clear(getUIColourIfAvailable(LookAndFeel_V4::ColourScheme::UIColour::windowBackground,
		//	Colours::lightblue));

		OpenGLHelpers::clear(Colour(Colours::black.withAlpha(0.0f)));

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		openGLContext.extensions.glActiveTexture(GL_TEXTURE0);
		glEnable(GL_TEXTURE_2D);

		texture.bind();

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//
		
		drawSprite(_shader, _sprite, attributes, uniforms, (float)(Time::getMillisecondCounter()/140), getWidth(), getHeight());
		//_shader->use();
		//_sprite.bind();
		//attributes->enable(openGLContext);
		//_sprite.draw();
		//attributes->disable(openGLContext);


		drawSprite(_shader2, _sprite2, attributes2, uniforms2, (float)(Time::getMillisecondCounter()/ 140), getWidth(), getHeight());

		//_shader2->use();
		//_sprite2.bind();
		//attributes->enable(openGLContext);
		//_sprite2.draw();
		//attributes->disable(openGLContext);


		//_shader2->use();
		//_sprite2.draw(_shader2);


		//glBegin(GL_TRIANGLES);
		//glVertex2f(-1, -1);
		//glVertex2f(0, -1);
		//glVertex2f(0, 0);
		//glEnd();

	//	glEnableClientState(GL_COLOR_ARRAY);
		//glColor3f(1.f, 0.f, 0.f);

		//glBegin(GL_QUADS);
		//glVertex2f(-0.5f, -1.0f);
		//glVertex2f(1.0f, -1.0f);
		//glVertex2f(1.0f, 1.0f);
		//glVertex2f(-1.0f, 1.0f);
		//glEnd();

	}





	void timerCallback() override
	{


		if (!find)
		{
			Component *editor = getChildComponentByName(getParentComponent(), "Editor");
			Component *tabShader = getChildComponentByName(editor, "tabShader");

			combobox = (juce::ComboBox*)getChildComponentByName(getParentComponent(), "combobox");



			if (tabShader && combobox)
			{


				TabbedComponent* tc = (TabbedComponent*)tabShader;
				//int n = tc->getNumChildComponents();


				juce::CodeEditorComponent * vertexEditorComp = (juce::CodeEditorComponent *)tc->getTabContentComponent(0);
				juce::CodeEditorComponent * fragmentEditorComp = (juce::CodeEditorComponent *)tc->getTabContentComponent(1);
				if (vertexEditorComp)
				{
					v = &vertexEditorComp->getDocument();
					f = &fragmentEditorComp->getDocument();

					v->addListener(this);
					f->addListener(this);
					find = true;
					stopTimer();
				}
			}
		}

		if (!find)
			return;

		int i = combobox->getSelectedItemIndex();
		if (i == 0)
		{
			_strVertex = v->getAllContent();
			_strFragment = f->getAllContent();
		}
		else if (i == 1)
		{
			_strVertex2 = v->getAllContent();
			_strFragment2 = f->getAllContent();
		}

		stopTimer();


	}

	void updateShader1()
	{
		if (_strVertex.isNotEmpty() || _strFragment.isNotEmpty())
		{

			bool b = OpenGLHelpers::isContextActive();
			if (!b)
			{
				return;
			}

			{
				ScopedPointer<OpenGLShaderProgram> newShader(new OpenGLShaderProgram(openGLContext));
				Component *editor = getChildComponentByName(getParentComponent(), "Editor");
				Component *labelShader = getChildComponentByName(editor, "labelShader");
				Label *l = nullptr;
				if (labelShader)
				{
					l = (Label*)labelShader;
				}
				if (newShader->addVertexShader(OpenGLHelpers::translateVertexShaderToV3(_strVertex))
					&& newShader->addFragmentShader(OpenGLHelpers::translateFragmentShaderToV3(_strFragment))
					&& newShader->link())
				{
					_shader = nullptr;
					_shader = newShader;

					attributes = nullptr;
					attributes = new Attributes(openGLContext, *_shader);

					uniforms = nullptr;
					uniforms = new Uniforms(openGLContext, *_shader);


					//_sprite.setShader(_shader);

					if (l)
					{
						_compileResult = "GLSL: v" + String(juce::OpenGLShaderProgram::getLanguageVersion(), 2);
						const MessageManagerLock mmLock;
						if (mmLock.lockWasGained())
						{
							l->setText(_compileResult, dontSendNotification);
						}

					}


				}
				else
				{
					String s = newShader->getLastError();
					if (l)
					{
						_compileResult = s;

						const MessageManagerLock mmLock;
						if (mmLock.lockWasGained())
						{
							l->setText(_compileResult, dontSendNotification);
						}

					}


					//statusText = newShader->getLastError();
				}

			}
			g_shaderData._shaderPreset[0]->vertexShader = _strVertex;
			g_shaderData._shaderPreset[0]->fragmentShader = _strFragment;


		}

		_strVertex = String();
		_strFragment = String();

	}

	void updateShader()
	{
		updateShader1();
		updateShader2();
	}

	void updateShader2()
	{
		if (_strVertex2.isNotEmpty() || _strFragment2.isNotEmpty())
		{

			bool b = OpenGLHelpers::isContextActive();
			if (!b)
			{
				return;
			}

			{
				ScopedPointer<OpenGLShaderProgram> newShader(new OpenGLShaderProgram(openGLContext));
				Component *editor = getChildComponentByName(getParentComponent(), "Editor");
				Component *labelShader = getChildComponentByName(editor, "labelShader");
				Label *l = nullptr;
				if (labelShader)
				{
					l = (Label*)labelShader;
				}
				if (newShader->addVertexShader(OpenGLHelpers::translateVertexShaderToV3(_strVertex2))
					&& newShader->addFragmentShader(OpenGLHelpers::translateFragmentShaderToV3(_strFragment2))
					&& newShader->link())
				{

					_shader2 = nullptr;
					_shader2 = newShader;

					attributes2 = nullptr;
					attributes2 = new Attributes(openGLContext, *_shader2);

					uniforms2 = nullptr;
					uniforms2 = new Uniforms(openGLContext, *_shader2);
					if (l)
					{
						_compileResult = "GLSL: v" + String(juce::OpenGLShaderProgram::getLanguageVersion(), 2);
						const MessageManagerLock mmLock;
						l->setText(_compileResult, dontSendNotification);
					}
				}
				else
				{
					String s = newShader->getLastError();
					if (l)
					{
						_compileResult = s;
						const MessageManagerLock mmLock;
						l->setText(_compileResult, dontSendNotification);
					}
					//statusText = newShader->getLastError();
				}
			}
			g_shaderData._shaderPreset[1]->vertexShader = _strVertex2;
			g_shaderData._shaderPreset[1]->fragmentShader = _strFragment2;/*
			String s = g_shaderData._shaderPreset[1]->vertexShader;
			DBG(s);*/

		}



		_strVertex2 = String();
		_strFragment2 = String();

	}
	void codeDocumentTextInserted(const String& /*newText*/, int /*insertIndex*/) override
	{

		startTimer(1000);
	}

	void codeDocumentTextDeleted(int /*startIndex*/, int /*endIndex*/) override
	{
		startTimer(1000);
	}
	glm::mat4  getProjectionMatrix_() const
	{
		float w = 1.0f / (scale);
		float h = w * getLocalBounds().toFloat().getAspectRatio(false);
		//glm::mat4 projectionMatrix = glm::perspective(glm::radians(30.0f), h/*1.0f*/, 0.1f, 1000.0f);
		glm::mat4 projectionMatrix = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 100.0f);
		return projectionMatrix;
	}
	Matrix3D<float> getProjectionMatrix() const
	{
	//	float w = 1.0f / (scale + 0.1f);
	//	float h = w * getLocalBounds().toFloat().getAspectRatio(false);
        //return Matrix3D<float>::fromFrustum(-w, w, -h, h, -114.0f, -130.0f);
    
        //   glm::mat4 projectionMatrix = glm::perspective(
        //    glm::radians(60.0f),,         // The horizontal Field of View, in degrees : the amount of "zoom". Think "camera lens". Usually between 90&deg; (extra wide) and 30&deg; (quite zoomed in)
        //   h,//4.0f / 3.0f, // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
        //  0.1f,        // Near clipping plane. Keep as big as possible, or you'll get precision issues.
        // 100.0f       // Far clipping plane. Keep as little as possible.
        //);
    
        //  glm::mat4 proj = glm::perspective(60.0f, h, 0.3f, 1000.0f);
		glm::mat4 projectionMatrix = getProjectionMatrix_();// glm::perspective(glm::radians(45.0f), h/* h 1.0f*/, 0.1f, 1000.0f);
		Matrix3D<float> r(
						  projectionMatrix[0][0], projectionMatrix[0][1], projectionMatrix[0][2], projectionMatrix[0][3],
						  projectionMatrix[1][0], projectionMatrix[1][1], projectionMatrix[1][2], projectionMatrix[1][3],
						  projectionMatrix[2][0], projectionMatrix[2][1], projectionMatrix[2][2], projectionMatrix[2][3],
						  projectionMatrix[3][0], projectionMatrix[3][1], projectionMatrix[3][2], projectionMatrix[3][3]);
		return r;
	}
	glm::mat4 getModelMatrix_() const
	{
		glm::mat4 model; // 构造单位矩阵
		model = glm::translate(model, glm::vec3(0.2f, 0.0f, 0.0f));

		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		
		return model;
	}

	Matrix3D<float> getModelMatrix() const
	{
		//glm::mat4 model; // 构造单位矩阵
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));

		glm::mat4 model = getModelMatrix_();// glm::translate(model, glm::vec3(0.2f, 0.0f, 0.0f));
		Matrix3D<float> r(
			model[0][0], model[0][1], model[0][2], model[0][3],
			model[1][0], model[1][1], model[1][2], model[1][3],
			model[2][0], model[2][1], model[2][2], model[2][3],
			model[3][0], model[3][1], model[3][2], model[3][3]);

		return r;
	}
	glm::mat4 getViewMatrix_() const
	{
		glm::mat4 CameraMatrix = glm::lookAt(
			glm::vec3(0, 0, 0), // the position of your camera, in world space
			glm::vec3(0, 0, -1),   // where you want to look at, in world space
			glm::vec3(0, 1, 0)        // probably glm::vec3(0,1,0), but (0,-1,0) would make you looking upside-down, which can be great too
		);
		return CameraMatrix;
	}
	Matrix3D<float> getViewMatrix() const
	{
		//Matrix3D<float> viewMatrix = draggableOrientation.getRotationMatrix()
		//	* Vector3D<float>(0.f, 0.0f,-19.0f);// -19.0f);

		//Matrix3D<float> rotationMatrix = viewMatrix.rotated(Vector3D<float>(0.0,0.0, 0.0 ));

		//glm::mat4 CameraMatrix = glm::lookAt(
		//	glm::vec3(0, 0, 3), // the position of your camera, in world space
		//	glm::vec3(0, 0, -1),   // where you want to look at, in world space
		//	glm::vec3(0, 1, 0)        // probably glm::vec3(0,1,0), but (0,-1,0) would make you looking upside-down, which can be great too
		//);
		glm::mat4 model_view = getViewMatrix_();// CameraMatrix;// *model;

		Matrix3D<float> r(
			model_view[0][0], model_view[0][1], model_view[0][2], model_view[0][3],
			model_view[1][0], model_view[1][1], model_view[1][2], model_view[1][3],
			model_view[2][0], model_view[2][1], model_view[2][2], model_view[2][3],
			model_view[3][0], model_view[3][1], model_view[3][2], model_view[3][3]);

		return r;//
		//return rotationMatrix * viewMatrix;
			//	return model_view;
	}

	


	void mouseDown(const MouseEvent& event) override
	{
    float mx =event.getPosition().getX();
    float my =event.getPosition().getY();
    
    glm::mat4 v = this->getViewMatrix_();
    glm::mat4 p = this->getProjectionMatrix_();
    glm::mat4 m = this->getModelMatrix_();
    
	if (isSpriteClicked(mx, my, this->getWidth(), this->getHeight(), _sprite, v, p, m))
	{
		DBG("_sprite is clicked");
		_sprite.isClicked = 1;
	 }
	else
	{
		_sprite.isClicked = 0;
	}
		

	if (isSpriteClicked(mx, my, this->getWidth(), this->getHeight(), _sprite2, v, p, m))
	{
		_sprite2.isClicked = 1;
		DBG("_sprite2 is clicked");
	}
	else
	{
		_sprite2.isClicked = 0;
	}

	//glm::vec3 ray_origin;
	//glm::vec3 ray_direction;
	//ScreenPosToWorldRay(
	//	mx,
	//	my,
	//	this->getWidth(),
	//	this->getHeight(),
	//	this->getViewMatrix_(),
	//	this->getProjectionMatrix_(),
	//	ray_origin,
	//	ray_direction
	//);


	//float intersection_distance;
	////_sprite.init(0, 0, 0.5, 0.5);

	//float halfWidth = _sprite._width / 2.0f;
	//float halfHeight = _sprite._height / 2.0f;
	//float minx = halfWidth*(-1.0f);
	//float miny = halfHeight*(-1.0f);

	//float maxx = halfWidth;
	//float maxy = halfHeight;

	//glm::vec3 aabb_min(minx, miny, -1.0f);
	//glm::vec3 aabb_max(maxx, maxy, 1.0f);

	//// The ModelMatrix transforms :
	//// - the mesh to its desired position and orientation
	//// - but also the AABB (defined with aabb_min and aabb_max) into an OBB

	//float centerx = _sprite._x + halfWidth;
	//float centery = _sprite._y + halfHeight*-1.0f;

	//glm::vec3 positions = glm::vec3(centerx, centery, 0);
	//glm::quat orientations = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);


	//glm::mat4 RotationMatrix = glm::toMat4(orientations);
	//glm::mat4 TranslationMatrix = glm::translate(glm::mat4(), positions);
	//glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix;


	//if (TestRayOBBIntersection(
	//	ray_origin,
	//	ray_direction,
	//	aabb_min,
	//	aabb_max,
	//	ModelMatrix,
	//	intersection_distance)
	//	) {
	//	DBG("click");
	//	//std::ostringstream oss;
	//	//oss << "mesh " << i;
	//	//message = oss.str();
	//	//break;
	//}

	}
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void mouseMove (const MouseEvent& e) override;
    bool keyPressed (const KeyPress& key) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	juce::CodeDocument * v;
	juce::CodeDocument * f;
	juce::ComboBox *combobox;
	OpenGLContext openGLContext;
	juce::Draggable3DOrientation draggableOrientation;
	float scale, rotation;;
	bool find ;

	bool isInit;
	Sprite _sprite;
	Sprite _sprite2;

	String _strVertex;
	String _strFragment;

	String _strVertex2;
	String _strFragment2;


	String _compileResult;
	ScopedPointer<OpenGLShaderProgram> _shader;
	ScopedPointer<OpenGLShaderProgram> _shader2;

	ScopedPointer<Attributes> attributes;
	ScopedPointer<Uniforms> uniforms;

	ScopedPointer<Attributes> attributes2;
	ScopedPointer<Uniforms> uniforms2;

	OpenGLTexture texture;
	DynamicTexture dt;
	ScopedPointer<OverLay> o;


    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ThreeDTest)
};

//[EndFile] You can add extra defines here...

/*

如何向GLSL中传入多个纹理
原创 2014年11月18日 13:49:17 标签：opengl /glsl /多纹理 6607
如何向GLSL中传入多个纹理
这几天在研究如何实现用GLSL对多个纹理进行融合处理，发现除了第一个纹理之外其它的纹理参数都无法传递到GLSL中去，在网上找了很久终于是发现了问题所在，记录一下供大家参考。
如下程序，我们在GLSL的fragment着色程序中定义了3个sample2D作为纹理参数。


[cpp] view plain copy
uniform sampler2D BaseMap;
uniform sampler2D ReflectMap;
uniform sampler2D RefractMap;


在主程序中，我们生成3个纹理ID
[cpp] view plain copy
glBindTexture(GL_TEXTURE_2D, BaseID);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, BaseData);

glBindTexture(GL_TEXTURE_2D, ReflectionID);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, ReflectionData);

glBindTexture(GL_TEXTURE_2D, RefractionID);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, RefractionData);

glUseProgram(ShaderID);


//　设定纹理参数的数值，这里是关键，很多时候我们会以为要把纹理ID作为sampler2D参数的值传给GLSL，
// 我们可能会这样写glUniform1i(texLoc, BaseID,但这做法是错的，GLSL的sample2D 只接受纹理单元的索引号，GL_TEXTURE0+i
// 还有一个要注意的地方就是要用glUniform1i函数，而不要用glUniform1ui();

GLint texLoc;
texLoc = glGetUniformLocation(ShaderID, "BaseMap");
glUniform1i(texLoc, 0); //GL_TEXTURE0,
//这里我觉得是opengl做得最不人性化的地方，你只能输入0，1，2来代表纹理单元的索引，不直观，让人摸不着头脑。

texLoc = glGetUniformLocation(ShaderID, "ReflectMap");
glUniform1i(texLoc, 1); //GL_TEXTURE1

texLoc = glGetUniformLocation(ShaderID, "RefractMap");
glUniform1i(texLoc, 2); //GL_TEXTURE2

Then in further down in my draw() function:

//　把纹理ID和纹理单元绑定在一起。
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, BaseID);

glActiveTexture(GL_TEXTURE1);
glBindTexture(GL_TEXTURE_2D, ReflectionID);

glActiveTexture(GL_TEXTURE2);
glBindTexture(GL_TEXTURE_2D, RefractionID);

// 用了GLSL，glEnable(GL_TEXTURE_2D);glDisable(GL_TEXTURE_2D);就不起作用了，一切由着色代码来控制。  

*/
//[/EndFile]
