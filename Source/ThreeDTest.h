/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.2

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

//[/Headers]



//==============================================================================
/**
																	//[Comments]
																	//[/Comments]
*/
class ThreeDTest : public Component,
	private OpenGLRenderer,
	private Timer,
	private CodeDocument::Listener,
	public ButtonListener
{
public:
	//==============================================================================
	ThreeDTest();
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
	void renderOpenGL() override
	{
		if (false == isInit)
		{
			if (openGLContext.isActive())
			{
				_sprite.init(0, 0, 0.5, 0.5);
				_sprite2.init(-1, -1, 0.3, 0.3);
				isInit = true;
				dt.applyTo(texture);
			}
			else
				return;

		}
		bool b = OpenGLHelpers::isContextActive();
		if (!b)
		{
			return;
		}

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
		OpenGLHelpers::clear(getUIColourIfAvailable(LookAndFeel_V4::ColourScheme::UIColour::windowBackground,
			Colours::lightblue));

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		openGLContext.extensions.glActiveTexture(GL_TEXTURE0);
		glEnable(GL_TEXTURE_2D);

		texture.bind();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		_shader->use();



		//_sprite.setShader(_shader);
		_sprite.draw(_shader);

		_shader2->use();
		//_sprite2.setShader(_shader2);
		_sprite2.draw(_shader2);

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



	Component* getChildComponentByName(Component* parent, String name)
	{
		if (parent)
		{
			int n = parent->getNumChildComponents();
			for (int i = 0; i < n; i++)
			{
				Component * c = parent->getChildComponent(i);

				if (c)
				{
					String s = c->getName();
					if (s == name)//tabShader
					{
						return c;
					}
				}
			}
		}

		return nullptr;
	}

	void timerCallback() override
	{
		bool find = false;

		if (!find)
		{
			Component *editor = getChildComponentByName(getParentComponent(), "Editor");
			Component *tabShader = getChildComponentByName(editor, "tabShader");


			if (tabShader)
			{
				TabbedComponent* tc = (TabbedComponent*)tabShader;
				int n = tc->getNumChildComponents();


				CodeEditorComponent * vertexEditorComp = (CodeEditorComponent *)tc->getTabContentComponent(0);
				CodeEditorComponent * fragmentEditorComp = (CodeEditorComponent *)tc->getTabContentComponent(1);
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
		_strVertex = v->getAllContent();
		_strFragment = f->getAllContent();
		stopTimer();

		//	DBG("timer call back");

	}

	void updateShader()
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
				_strVertex = v->getAllContent();
				_strFragment = f->getAllContent();
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
					_sprite.setShader(_shader);

					if (l)
					{
						_compileResult = "GLSL: v" + String(juce::OpenGLShaderProgram::getLanguageVersion(), 2);
						l->setText(_compileResult, dontSendNotification);
					}


				}
				else
				{
					String s = newShader->getLastError();
					if (l)
					{
						_compileResult = s;
						l->setText(_compileResult, dontSendNotification);
					}


					//statusText = newShader->getLastError();
				}

			}
			{
				ScopedPointer<OpenGLShaderProgram> newShader(new OpenGLShaderProgram(openGLContext));
				_strVertex = v->getAllContent();
				_strFragment = f->getAllContent();
				Component *editor = getChildComponentByName(getParentComponent(), "Editor");
				Component *labelShader = getChildComponentByName(editor, "labelShader");
				Label *l = nullptr;
				if (labelShader)
				{
					l = (Label*)labelShader;
				}
				if (newShader->addVertexShader(OpenGLHelpers::translateVertexShaderToV3(_strVertex))
					&& newShader->addFragmentShader(OpenGLHelpers::translateFragmentShaderToV3("\
							#version 120\n\
							uniform vec4 lightPosition; \n\
							varying vec2 textureCoordOut; \n\
							uniform sampler2D demoTexture; \n\
							vec3 color; \n\
							void main()\n\
							{ \n\
										//gl_FragColor = lightPosition;//vec4(1.0, 0.0, 0.0, 1.0); \n\
										//gl_FragColor = lightPosition* texture2D (demoTexture, textureCoordOut);\n\
										gl_FragColor =  texture2D (demoTexture, textureCoordOut);\n\
							}\n\
						"
					))
					&& newShader->link())
				{

					_shader2 = nullptr;


					_shader2 = newShader;
					_sprite2.setShader(_shader2);

					if (l)
					{
						_compileResult = "GLSL: v" + String(juce::OpenGLShaderProgram::getLanguageVersion(), 2);
						l->setText(_compileResult, dontSendNotification);
					}


				}
				else
				{
					String s = newShader->getLastError();
					if (l)
					{
						_compileResult = s;
						l->setText(_compileResult, dontSendNotification);
					}


					//statusText = newShader->getLastError();
				}

			}

		}

		_strVertex = String();
		_strFragment = String();

	}

	void codeDocumentTextInserted(const String& /*newText*/, int /*insertIndex*/) override
	{

		startTimer(1000);
	}

	void codeDocumentTextDeleted(int /*startIndex*/, int /*endIndex*/) override
	{
		startTimer(1000);
	}



	//[/UserMethods]

	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* buttonThatWasClicked) override;
	void mouseMove(const MouseEvent& e) override;
	bool keyPressed(const KeyPress& key) override;



private:
	//[UserVariables]   -- You can add your own custom variables in this section.
	juce::CodeDocument * v;
	juce::CodeDocument * f;

	OpenGLContext openGLContext;



	bool isInit;
	Sprite _sprite;
	Sprite _sprite2;

	String _strVertex;
	String _strFragment;
	String _compileResult;
	ScopedPointer<OpenGLShaderProgram> _shader;
	ScopedPointer<OpenGLShaderProgram> _shader2;
	OpenGLTexture texture;
	DynamicTexture dt;

	//[/UserVariables]

	//==============================================================================
	ScopedPointer<TextButton> textButton;


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ThreeDTest)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
