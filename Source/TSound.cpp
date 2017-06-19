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

#include "TSound.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TSound::TSound ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (btnPlay = new TextButton ("btnPlay"));
    btnPlay->setExplicitFocusOrder (1);
    btnPlay->setButtonText (TRANS("Play"));
    btnPlay->addListener (this);

    addAndMakeVisible (btnOpen = new TextButton ("btnOpen"));
    btnOpen->setButtonText (TRANS("Open"));
    btnOpen->addListener (this);

    addAndMakeVisible (btnStop = new TextButton ("btnStop"));
    btnStop->setButtonText (TRANS("Stop"));
    btnStop->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	formatManager.registerBasicFormats();
	audioTransportSource.addChangeListener(this);
	setAudioChannels(2, 2);


    //[/Constructor]
}

TSound::~TSound()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    btnPlay = nullptr;
    btnOpen = nullptr;
    btnStop = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	//audioTransportSource.setSource(nullptr);
	shutdownAudio();
    //[/Destructor]
}

//==============================================================================
void TSound::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TSound::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    btnPlay->setBounds (80, 112, 150, 24);
    btnOpen->setBounds (56, 32, 150, 24);
    btnStop->setBounds (72, 192, 150, 24);
    //[UserResized] Add your own custom resize handling here..

	FlexBox masterbox;
	masterbox.flexDirection = FlexBox::Direction::column;// column;// : FlexBox::Direction::row;
	masterbox.alignItems = FlexBox::AlignItems::center;
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
	masterbox.performLayout(r);

    //[/UserResized]
}

void TSound::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == btnPlay)
    {
        //[UserButtonCode_btnPlay] -- add your button handler code here..
		audioTransportSource.start();
        //[/UserButtonCode_btnPlay]
    }
    else if (buttonThatWasClicked == btnOpen)
    {
        //[UserButtonCode_btnOpen] -- add your button handler code here..
		//FileChooser chooser("Select a Wave file to play...",
		//	File::nonexistent,
		//	"*.wav");

		//if (chooser.browseForFileToOpen())
		//{
		//	File file(chooser.getResult());
		//	AudioFormatReader* reader = formatManager.createReaderFor(file);

		//	if (reader != nullptr)
		//	{
		//		ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource(reader, true);
		//		audioTransportSource.setSource(newSource, 0, nullptr, reader->sampleRate);
		//		btnPlay->setEnabled(true);
		//		audioReaderSource = newSource.release();
		//	}
		//}
		/**/
		FileChooser chooser("Select a Wave file to play...",
		File::nonexistent,
		"*.*");

		if (chooser.browseForFileToOpen())
		{
		File file(chooser.getResult());
		if (file.existsAsFile())
		{
		AudioFormatReader* reader = formatManager.createReaderFor(file);

		if (reader != nullptr)
		{
		ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource(reader, true);
		audioTransportSource.setSource(newSource, 0, nullptr, reader->sampleRate);
		audioReaderSource = newSource.release();

		btnPlay->setEnabled(true);
		}
		else
		{
		AlertWindow::showMessageBox(AlertWindow::AlertIconType::InfoIcon, "title", "not support this format", "exit");
		}
		}
		else
		{
		AlertWindow::showMessageBox(AlertWindow::AlertIconType::InfoIcon, "title", "not a file", "exit");
		}
		}
		else
		{
		AlertWindow::showMessageBox(AlertWindow::AlertIconType::InfoIcon, "title", "you cancel the file choose dialog", "exit");
		}



        //[/UserButtonCode_btnOpen]
    }
    else if (buttonThatWasClicked == btnStop)
    {
        //[UserButtonCode_btnStop] -- add your button handler code here..
		audioTransportSource.stop();
		audioTransportSource.setPosition(0.0);

        //[/UserButtonCode_btnStop]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
static ComponentList<TSound> td((const String)("TSound"));
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TSound" componentName=""
                 parentClasses="public AudioAppComponent, public ChangeListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="btnPlay" id="67e474c8e35b2c15" memberName="btnPlay" virtualName=""
              explicitFocusOrder="1" pos="80 112 150 24" buttonText="Play"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="btnOpen" id="9899f3e37f7d2bd4" memberName="btnOpen" virtualName=""
              explicitFocusOrder="0" pos="56 32 150 24" buttonText="Open" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="btnStop" id="8be202d774945a20" memberName="btnStop" virtualName=""
              explicitFocusOrder="0" pos="72 192 150 24" buttonText="Stop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
