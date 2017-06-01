#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class flextest
{
public:
	flextest();
	~flextest();
};


#pragma once

class controlgrouppanel : public Component
{

public:
	controlgrouppanel(const String & name) :
		Component(name) {};

	~controlgrouppanel() {};

	void addcontrol(Component* control) {
		controls_.add(control);
		addAndMakeVisible(control);
	}

	void paint(Graphics& g) override {
		// omitted: draw outline & name
	}


	void resized() override {
		Rectangle<float> r = getLocalBounds().toFloat();

		bool isportrait = r.getHeight()>r.getWidth();

		float reduce = isportrait ? r.getWidth()*0.05f : r.getHeight()*0.05f;
		r.reduce(reduce, reduce);

		FlexBox  masterbox;
		masterbox.flexDirection = isportrait ? FlexBox::Direction::column : FlexBox::Direction::row;
		masterbox.alignItems = FlexBox::AlignItems::stretch;
		masterbox.alignContent = FlexBox::AlignContent::stretch;
		masterbox.flexWrap = FlexBox::Wrap::noWrap;
		masterbox.justifyContent = FlexBox::JustifyContent::center;

		for (int i = 0; i < controls_.size(); i++) {
			masterbox.items.add(FlexItem(1, 1).withWidth(1));
			auto& flexitem = masterbox.items.getReference(masterbox.items.size() - 1);
			flexitem.associatedComponent = controls_[i];
		}
		masterbox.performLayout(r);

	}


private:
	Array<Component*> controls_; // it's not owned since my parent will create the components and own them...

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(controlgrouppanel)
};