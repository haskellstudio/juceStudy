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

//[Headers] You can add your own extra header files here...
#include "ComponentList.h"
//[/Headers]

#include "gl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
sampleUI::sampleUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("label text")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0xffa81414));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	openGLContext.setRenderer(this);
	openGLContext.attachTo(*this);
	openGLContext.setContinuousRepainting(true);


    //[/Constructor]
}

sampleUI::~sampleUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void sampleUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]
	OpenGLContext * context = OpenGLContext::getCurrentContext();
    g.fillAll (Colours::aliceblue);

    //[UserPaint] Add your own custom painting code here..
	if (isCodeChange)
	{
		isCodeChange = !isCodeChange;

		shader = new OpenGLGraphicsContextCustomShader(fragmentCode);
		Result result(shader->checkCompilation(g.getInternalContext()));

		if (result.failed())
		{
			label->setText(result.getErrorMessage(), dontSendNotification);
			shader = nullptr;
		}
		else
		{
			label->setText("compilation success", dontSendNotification);

			//shader->getProgram(g.getInternalContext())->use();
			//GLint i = shader->getProgram(g.getInternalContext())->getUniformIDFromName("color");
			////getUniformIDFromName
			color = new OpenGLShaderProgram::Uniform(*shader->getProgram(g.getInternalContext()), "color");

			//color->set(vec4(1.0, 1.0, 0.0, 1.0));
			color->set(1.0f, 1.0f, 0.0f, 1.0f);
			
			//color = createUniform(shader->getProgram(g.getInternalContext())->context, *(shader->getProgram(g.getInternalContext())), "color");
			//color = createUniform(openGLContext, *( shader->getProgram(g.getInternalContext())), "color");

			if (color)
			{
				label->setText("success to create uniform ", dontSendNotification);
				shader->fillRect(g.getInternalContext(), getLocalBounds());
				color->set(1.0f, 1.0f, 0.0f, 1.0f);
			}
			else
			{
				label->setText("fail to create uniform ", dontSendNotification);
				shader->fillRect(g.getInternalContext(), getLocalBounds());
			}


		}
	}
    //[/UserPaint]
}

void sampleUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (24, 40, 288, 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//static ComponentList<sampleUI> lbs(String("sampleUI"));
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="sampleUI" componentName=""
                 parentClasses="public Component, private OpenGLRenderer" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <LABEL name="new label" id="8cc6714263cdda56" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="24 40 288 48" bkgCol="ffa81414" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
