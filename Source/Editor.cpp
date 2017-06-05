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

//[Headers] You can add your own extra header files here...

#include "ComponentList.h"
//[/Headers]

#include "Editor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Editor::Editor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtLeft));
    tabbedComponent->setTabBarDepth (41);
    tabbedComponent->addTab (TRANS("vertex"), Colours::lightgrey, new CodeEditorComponent (vertexDocument, nullptr), true);
    tabbedComponent->addTab (TRANS("fragment"), Colours::lightgrey, new CodeEditorComponent (fragmentDocument, nullptr), true);
    tabbedComponent->setCurrentTabIndex (0);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("label text")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	tabbedComponent->setName("tabShader");
	label->setName("labelShader");
	tabbedComponent->getTabNames();



	CodeEditorComponent * vertexEditorComp = (CodeEditorComponent *)tabbedComponent->getTabContentComponent(0);
	CodeEditorComponent * fragmentEditorComp = (CodeEditorComponent *)tabbedComponent->getTabContentComponent(1);
	if (vertexEditorComp)
	{
		CodeDocument & v = vertexEditorComp->getDocument();
		v.insertText(0, STRINGIFY(
						#version 130\n

						attribute vec2 position; \n

						void main()\n
						{ \n
						    gl_Position.xy = position; \n
							gl_Position.z = 0.0; \n
							gl_Position.w = 1.0; \n
						}\n

					));
	}

	if (fragmentEditorComp)
	{
		CodeDocument & v = fragmentEditorComp->getDocument();
		v.insertText(0, STRINGIFY(
			#version 130\n

			out vec3 color; \n

			void main()\n
			{ \n
				color = vec3(1.0, 0.0, 0.0); \n
			}\n


		));
	}



	 //vertexEditorComp = tabbedComponent->getTabContentComponent(0);
	 //fragmentEditorComp = tabbedComponent->getTabContentComponent(1);
	//vertexEditorComp (vertexDocument, nullptr), fragmentEditorComp (fragmentDocument, nullptr)
    //[/Constructor]
}

Editor::~Editor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tabbedComponent = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Editor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Editor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    tabbedComponent->setBounds (16, 16, 712, 216);
    label->setBounds (56, 256, 664, 80);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//static ComponentList<Editor> td((const String)("Editor"));
static ComponentList<Editor> td((const String)(String("Editor")));



//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Editor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TABBEDCOMPONENT name="tabShader " id="86091f7ab4d0dd38" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="16 16 712 216" orientation="left"
                   tabBarDepth="41" initialTab="0">
    <TAB name="vertex" colour="ffd3d3d3" useJucerComp="0" contentClassName="CodeEditorComponent"
         constructorParams="vertexDocument, nullptr" jucerComponentFile=""/>
    <TAB name="fragment" colour="ffd3d3d3" useJucerComp="0" contentClassName="CodeEditorComponent"
         constructorParams="fragmentDocument, nullptr" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <LABEL name="new label" id="ea8f0f5080e894a1" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="56 256 664 80" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
