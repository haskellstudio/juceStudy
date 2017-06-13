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
//[/Headers]

#include "OverLay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include "ComponentList.h"
//[/MiscUserDefs]

//==============================================================================
OverLay::OverLay ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	setOpaque(true);
    //[/Constructor_pre]

    addAndMakeVisible (toggleButton = new ToggleButton ("new toggle button"));
    toggleButton->addListener (this);
    toggleButton->setColour (ToggleButton::textColourId, Colour (0xffcb1212));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OverLay::~OverLay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    toggleButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OverLay::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	return;
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OverLay::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    toggleButton->setBounds (24, 808, 150, 24);
    //[UserResized] Add your own custom resize handling here..


	FlexBox masterbox;
	masterbox.flexDirection = FlexBox::Direction::row;// column;// : FlexBox::Direction::row;
	masterbox.alignItems = FlexBox::AlignItems::center;
	masterbox.alignContent = FlexBox::AlignContent::center;
	masterbox.flexWrap = juce::FlexBox::Wrap::noWrap;
	masterbox.justifyContent = FlexBox::JustifyContent::center;


	int num = getNumChildComponents();
	for (auto i = 0; i < num; i++)
	{
		auto c = getChildComponent(i);
		if (c)
		{
			masterbox.items.add
			(
				juce::FlexItem(1, 1).withFlex(1)
				//.withMargin(10)
				.withMaxHeight(200)
				.withMaxHeight(200)
				.withMinHeight(100)
				.withMinHeight(100)

			);
			auto& flexitem = masterbox.items.getReference(masterbox.items.size() - 1);
			flexitem.associatedComponent = c;
		}
	}
	Rectangle<float> r = getLocalBounds().toFloat();
	//	r.reduce(10.0f, 10.0f);
	masterbox.performLayout(r);

	toggleButton->setBounds(0, 0, 0, 0);
    //[/UserResized]
}

void OverLay::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
        //[/UserButtonCode_toggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//const String & s = String("OverLay");
//static ComponentList<OverLay> td(s);
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OverLay" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TOGGLEBUTTON name="new toggle button" id="82a4765ef10657c8" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="24 808 150 24" txtcol="ffcb1212"
                buttonText="new toggle button" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
