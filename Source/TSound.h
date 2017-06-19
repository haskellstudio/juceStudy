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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TSound  : public AudioAppComponent,
                public ChangeListener,
                public ButtonListener
{
public:
    //==============================================================================
    TSound ();
    ~TSound();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.



	//==============================================================================
	// Audio Callbacks

	/** Called before rendering Audio.
	*/
	void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override
	{
		// Setup Audio Source
		audioTransportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
/*
		// Setup Ring Buffer of GLfloat's for the visualizer to use
		ringBuffer = new RingBuffer<GLfloat>(samplesPerBlockExpected * 10, 2);  // Set default of 2 channels in the RingBuffer


																				// Allocate all Visualizers

		oscilloscope2D = new Oscilloscope2D(ringBuffer);
		addChildComponent(oscilloscope2D);
		//addAndMakeVisible (oscilloscope2D);
		//oscilloscope3D->start();

		oscilloscope3D = new Oscilloscope(ringBuffer);
		addChildComponent(oscilloscope3D);
		//addAndMakeVisible (oscilloscope3D);
		//oscilloscope3D->start();

		spectrum = new Spectrum(ringBuffer);
		addChildComponent(spectrum);
		addAndMakeVisible (spectrum);
		spectrum->start();
		*/
	}

	/** Called after rendering Audio.
	*/
	void releaseResources() override
	{
		// Delete all visualizer allocations
	/*	if (oscilloscope2D != nullptr)
		{
			oscilloscope2D->stop();
			delete oscilloscope2D;
		}

		if (oscilloscope3D != nullptr)
		{
			oscilloscope3D->stop();
			delete oscilloscope3D;
		}

		if (spectrum != nullptr)
		{
			spectrum->stop();
			delete spectrum;
		}*/

		audioTransportSource.releaseResources();
		//delete ringBuffer;
	}

	/** The audio rendering callback.
	*/
	void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override
	{
		if (audioReaderSource == nullptr)
		{
			bufferToFill.clearActiveBufferRegion();
			return;
		}

		audioTransportSource.getNextAudioBlock(bufferToFill);

		// Write to Ring Buffer
		/*
		int numChannels = bufferToFill.buffer->getNumChannels();
		for (int i = 0; i < numChannels; ++i)
		{
			const float * audioData = bufferToFill.buffer->getReadPointer(i, bufferToFill.startSample);
			ringBuffer->writeSamples(audioData, bufferToFill.numSamples, i);
		}
		*/
	}

	void changeListenerCallback(ChangeBroadcaster* source) override
	{
		if (source == &audioTransportSource)
		{
			//if (audioTransportSource.isPlaying())
			//	changeAudioTransportState(Playing);
			//else if ((audioTransportState == Stopping) || (audioTransportState == Playing))
			//	changeAudioTransportState(Stopped);
			//else if (audioTransportState == Pausing)
			//	changeAudioTransportState(Paused);
		}
	}

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	AudioFormatManager formatManager;
	juce::AudioTransportSource audioTransportSource;
	ScopedPointer<AudioFormatReaderSource> audioReaderSource;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> btnPlay;
    ScopedPointer<TextButton> btnOpen;
    ScopedPointer<TextButton> btnStop;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TSound)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
