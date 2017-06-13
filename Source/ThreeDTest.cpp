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
#include "Sprite.h"


//[/Headers]

#include "ThreeDTest.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ThreeDTest::ThreeDTest ()
    : _sprite(openGLContext),_sprite2(openGLContext), isInit(false),find(false),combobox(nullptr)
{
    //[Constructor_pre] You can add your own custom stuff here..
	//if (MainAppWindow* mw = MainAppWindow::getMainAppWindow())
	//    mw->setRenderingEngine (0);
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	//addKeyListener(this);

	//addAndMakeVisible(controlsOverlay = new DemoControlsOverlay(*this));

	//setOpaque(true);
	//TStringLst * s = TStringLst::getDemoTypeList()["OverLay"];
	//if (s)
	//{
	//	addAndMakeVisible(s->createComponent());
	//}
	addAndMakeVisible(o = new OverLay());
	if (o)
		o->addMouseListener((MouseListener*)this,false);
	openGLContext.setComponentPaintingEnabled(true);  // if false , the overlay component can not see.


	openGLContext.setRenderer(this);

	openGLContext.setContinuousRepainting(true);
	openGLContext.attachTo(*this);



	openGLContext.setContinuousRepainting(true);  // true  fps may be high.


	startTimer(100);
	scale = 1.0f;
	rotation = 1.0f;

	_strVertex = g_shaderData._shaderPreset[0]->vertexShader;
	_strFragment = g_shaderData._shaderPreset[0]->fragmentShader;

	_strVertex2 = g_shaderData._shaderPreset[1]->vertexShader;;
	_strFragment2 = g_shaderData._shaderPreset[1]->fragmentShader;

	resized();

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



    //[Destructor]. You can add your own custom destruction code here..
	openGLContext.detach();
	stopTimer();
	o = nullptr;
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
	//if (o)
	//	o->setBounds(0, 0, getParentWidth(), getParentHeight());
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
//	DBG("width is " + String(getWidth()));

	draggableOrientation.setViewport(getLocalBounds());
	FlexBox masterbox;
	masterbox.flexDirection = FlexBox::Direction::row;// column;// : FlexBox::Direction::row;
	masterbox.alignItems = FlexBox::AlignItems::stretch;
	masterbox.alignContent = FlexBox::AlignContent::stretch;
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
				//.withMaxHeight(200)
				//.withMaxHeight(200)
				//.withMinHeight(100)
				//.withMinHeight(100)

			);
			auto& flexitem = masterbox.items.getReference(masterbox.items.size() - 1);
			flexitem.associatedComponent = c;
		}
	}
	Rectangle<float> r = getLocalBounds().toFloat();
//	r.reduce(10.0f, 10.0f);
	masterbox.performLayout(r);
    //[/UserResized]
}

void ThreeDTest::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
	//rotation += 0.1;
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
//const String & s1 = String("ThreeDTest");
////const String & s2 = String("ThreeDTest2");
//static ComponentList<ThreeDTest> td(s1);

//static ComponentList<ThreeDTest> td2(s2);
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ThreeDTest" componentName=""
                 parentClasses="public Component, private OpenGLRenderer, private Timer, private CodeDocument::Listener"
                 constructorParams="" variableInitialisers="_sprite(openGLContext),_sprite2(openGLContext), isInit(false),find(false),combobox(nullptr)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
