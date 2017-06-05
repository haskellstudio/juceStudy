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
#include "Sprite.h"
//[/Headers]

#include "ThreeDTest.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ThreeDTest::ThreeDTest ()
    : _sprite(openGLContext), isInit(false)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	//addKeyListener(this);

	openGLContext.setRenderer(this);
	openGLContext.setComponentPaintingEnabled(false);
	openGLContext.attachTo(*this);



	openGLContext.setContinuousRepainting(true);  // true  fps may be high.


	startTimer(3000);

	
	//


        //glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	//glClearDepth(1.0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	//AlertWindow::showMessageBox(AlertWindow::AlertIconType::InfoIcon, "title", "msg", "exit");
    //[/Constructor]
}

ThreeDTest::~ThreeDTest()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	openGLContext.detach();
	stopTimer();
    //[/Destructor]
}

//==============================================================================
void ThreeDTest::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ThreeDTest::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (proportionOfWidth (0.3141f), proportionOfHeight (0.1860f), 150, 24);
    //[UserResized] Add your own custom resize handling here..
	DBG("width is " + String(getWidth()));
    //[/UserResized]
}

void ThreeDTest::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        //[/UserButtonCode_textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ThreeDTest::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
	//if (owner == nullptr)
	//{
	//	owner = getParentComponent();
	//}

	//if (owner)
	//{
	//	auto pos = e.getEventRelativeTo(owner).position.toInt();
	//	DBG("mouseMove x: " + String(pos.getX()) + " y: " + String(pos.getY()));
	//}
	//DBG("mouseMove x: " + String(e.getPosition().getX()) + " y: " + String(e.getPosition().getY()));
    //[/UserCode_mouseMove]
}

bool ThreeDTest::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
	DBG("ThreeDTest keyPressed");
	//DBG(key.getKeyCode());

	if (key == KeyPress::upKey)
		DBG("upKey");

	if (key == KeyPress::leftKey)
		DBG("leftKey");


	if (key == KeyPress::downKey )
		DBG("downKey");

	if (key == KeyPress::rightKey)
		DBG("rightKey");

	if (key == KeyPress::pageUpKey)
		DBG("pageUpKey");

	if (key == KeyPress::pageDownKey)
		DBG("pageDownKey");
	if (key == KeyPress::homeKey)
		DBG("homeKey");
	if (key == KeyPress::endKey)
		DBG("endKey");

    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
const String & s1 = String("ThreeDTest");
const String & s2 = String("ThreeDTest2");
static ComponentList<ThreeDTest> td(s1);

static ComponentList<ThreeDTest> td2(s2);
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ThreeDTest" componentName=""
                 parentClasses="public Component, private OpenGLRenderer, private Timer"
                 constructorParams="" variableInitialisers="_sprite(openGLContext), isInit(false)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="new button" id="3d7ed1a37e136823" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="31.405% 18.6% 150 24"
              buttonText="new button" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
