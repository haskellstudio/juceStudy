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
#include "CommonFun.h"
//[/Headers]

#include "ThreeDTest.h"
#include "Editor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ShaderEditor  : public Component,
                      public ComboBoxListener
{
public:
    //==============================================================================
    ShaderEditor ();
    ~ShaderEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
//	static Array<ShaderPreset> getPresets()
//	{
//		ShaderPreset presets[] =
//		{
//			{
//				"shader1",
//				"\
//\\1\
//#version 120\n\
//attribute vec2 position; \n\
//attribute vec2 textureCoordIn; \n\
//varying vec2 textureCoordOut; \n\
//void main()\n\
//{ \n\
//	gl_Position.xy = position; \n\
//	gl_Position.z = -1.0; \n\
//	gl_Position.w = 1.0; \n\
//	textureCoordOut = textureCoordIn;\n\
//}\n\
//",
//"\
//\\1\
//#version 120\n\
//uniform vec4 lightPosition; \n\
//varying vec2 textureCoordOut; \n\
//uniform sampler2D demoTexture; \n\
//vec3 color; \n\
//void main()\n\
//{ \n\
//	gl_FragColor = texture2D(demoTexture, textureCoordOut);\n\
//	//gl_FragColor = lightPosition* texture2D (demoTexture, textureCoordOut);\n\
//	//gl_FragColor = lightPosition;//vec4(1.0, 0.0, 0.0, 1.0); \n\
//}\n\
//"
//			},
//
//
//
//		{
//			"shader2",
//				"\
//\\2\
//#version 120\n\
//attribute vec2 position; \n\
//attribute vec2 textureCoordIn; \n\
//varying vec2 textureCoordOut; \n\
//void main()\n\
//{ \n\
//	gl_Position.xy = position; \n\
//	gl_Position.z = -1.0; \n\
//	gl_Position.w = 1.0; \n\
//	textureCoordOut = textureCoordIn;//the second vertex shader\n\
//}\n\
//",
//"\
//\\2\
//#version 120\n\
//uniform vec4 lightPosition; \n\
//varying vec2 textureCoordOut; \n\
//uniform sampler2D demoTexture; \n\
//vec3 color; \n\
//void main()\n\
//{ \n\
//	gl_FragColor = texture2D(demoTexture, textureCoordOut);\n\
//	//gl_FragColor = lightPosition* texture2D (demoTexture, textureCoordOut);\n\
//	//gl_FragColor = lightPosition;//vec4(1.0, 0.0, 0.0, 1.0); //the second fragment shader\n\
//}\n\
//"
//		}
//
//
//
//		};
//
//		return Array<ShaderPreset>(presets, numElementsInArray(presets));
//	}

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ThreeDTest> ThreedScene;
    ScopedPointer<Editor> editor;
    ScopedPointer<ComboBox> comboBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShaderEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
