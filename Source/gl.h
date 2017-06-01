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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class sampleUI  : public Component,
                  private OpenGLRenderer
{
public:
    //==============================================================================
    sampleUI ();
    ~sampleUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void newOpenGLContextCreated() override
	{

	}

	void renderOpenGL() override
	{

	}

	void openGLContextClosing() override
	{

	}

	static OpenGLShaderProgram::Uniform* createUniform(OpenGLContext& openGLContext,
		OpenGLShaderProgram& shader,
		const char* uniformName)
	{
		if (openGLContext.extensions.glGetUniformLocation(shader.getProgramID(), uniformName) < 0)
			return nullptr;

		return new OpenGLShaderProgram::Uniform(shader, uniformName);
	}

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    OpenGLContext openGLContext;
	ScopedPointer<OpenGLGraphicsContextCustomShader> shader;
	ScopedPointer<OpenGLShaderProgram::Uniform> color;

	char* fragmentCode =
		"uniform vec4 color;\n"
		"void main()\n"
		"{\n"
		"  vec4 color1 = vec4 (1.0, 1.0, 0.0, 1.0);\n"
		"  gl_FragColor = color;\n"
		"}\n";

	bool isCodeChange = true;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> label;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (sampleUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
