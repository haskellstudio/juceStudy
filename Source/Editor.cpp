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
    : vertexEditorComp (vertexDocument, nullptr), fragmentEditorComp (fragmentDocument, nullptr)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtLeft));
    tabbedComponent->setTabBarDepth (80);
    tabbedComponent->addTab (TRANS("vertex"), Colours::lightgrey, new CodeEditorComponent (vertexDocument, nullptr), true);
    tabbedComponent->addTab (TRANS("fragment"), Colours::lightgrey, new CodeEditorComponent (fragmentDocument, nullptr), true);
    tabbedComponent->setCurrentTabIndex (0);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	//tabbedComponent->getTabContentComponent(0);
    //[/Constructor]
}

Editor::~Editor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tabbedComponent = nullptr;


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

    tabbedComponent->setBounds (32, 88, 992, 784);
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
                 parentClasses="public Component" constructorParams="" variableInitialisers="vertexEditorComp (vertexDocument, nullptr), fragmentEditorComp (fragmentDocument, nullptr)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TABBEDCOMPONENT name="new tabbed component" id="86091f7ab4d0dd38" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="32 88 992 784" orientation="left"
                   tabBarDepth="80" initialTab="0">
    <TAB name="vertex" colour="ffd3d3d3" useJucerComp="0" contentClassName="CodeEditorComponent"
         constructorParams="vertexDocument, nullptr" jucerComponentFile=""/>
    <TAB name="fragment" colour="ffd3d3d3" useJucerComp="0" contentClassName="CodeEditorComponent"
         constructorParams="fragmentDocument, nullptr" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
