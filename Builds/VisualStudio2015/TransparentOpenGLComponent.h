#pragma once


#include "../JuceLibraryCode/JuceHeader.h"




class TransparentOpenGLComponent : public juce::Component, public juce::OpenGLRenderer
{
public:
	TransparentOpenGLComponent();
	virtual ~TransparentOpenGLComponent();

	virtual void renderOverBackground(juce::Point<int> viewportSize) = 0;

	// Sub-classes overriding this must call these in their overrides.
	void newOpenGLContextCreated() override;
	void openGLContextClosing() override;

	juce::OpenGLContext openGLContext;

protected:
	juce::Image renderBackground();

private:
	void renderOpenGL() override;

	void renderParentsToBackground(juce::Graphics& g, juce::Component&);

	juce::Point<int> viewportSize;
	juce::OpenGLTexture backgroundTexture;
};
