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
#include "Editor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
                                                                    //[/Comments]
*/
class ThreeDTest  : public Component,
                    private OpenGLRenderer,
                    public ButtonListener
{
public:
    //==============================================================================
    ThreeDTest ();
    ~ThreeDTest();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void newOpenGLContextCreated() override
	{

	}

	void renderOpenGL() override
	{


		if (false == isInit  )
		{
			if (openGLContext.isActive())
			{
				_sprite.init(0, 0, 0.5, 0.5);
				isInit = true;

			}
			else
				return;
			
		}


		jassert(OpenGLHelpers::isContextActive());

		const float desktopScale = (float)openGLContext.getRenderingScale();
		//_sprite.init(0, 0, 0.5, 0.5);
		glClearDepth(1.0);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);



		glEnableClientState(GL_COLOR_ARRAY);
		glColor3f(0.f, 1.f, 0.f);

	//	_sprite.draw();

		


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

	void openGLContextClosing() override
	{

	}





    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void mouseMove (const MouseEvent& e) override;
    bool keyPressed (const KeyPress& key) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	OpenGLContext openGLContext;

	Editor ed;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> textButton;

	Sprite _sprite;
	bool isInit;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ThreeDTest)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
