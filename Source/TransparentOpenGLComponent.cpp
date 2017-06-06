#include "TransparentOpenGLComponent.h"

using namespace juce;

TransparentOpenGLComponent::TransparentOpenGLComponent()
{
	openGLContext.setComponentPaintingEnabled(true);
	openGLContext.setRenderer(this);
	openGLContext.setContinuousRepainting(true);
	openGLContext.attachTo(*this);
}

TransparentOpenGLComponent::~TransparentOpenGLComponent()
{
	openGLContext.detach();
}

static Point<int> getGlViewPortSize()
{
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	return Point<int>(viewport[2], viewport[3]);
}

void TransparentOpenGLComponent::renderOpenGL()
{
	{
		const Point<int> newViewportSize = getGlViewPortSize();
		if (viewportSize != newViewportSize)
		{
			viewportSize = newViewportSize;
			backgroundTexture.loadImage(renderBackground());
		}
	}
	backgroundTexture.bind();
	Rectangle<int> textureSize(backgroundTexture.getWidth(), backgroundTexture.getHeight());
	openGLContext.copyTexture(textureSize, textureSize, viewportSize.getX(), viewportSize.getY(), false);
	renderOverBackground(viewportSize);
}

void TransparentOpenGLComponent::newOpenGLContextCreated()
{
	viewportSize = Point<int>(0, 0);
}

void TransparentOpenGLComponent::openGLContextClosing()
{
	backgroundTexture.release();
}

Image TransparentOpenGLComponent::renderBackground()
{
	Image backgroundImage(Image::ARGB, viewportSize.getX(), viewportSize.getY(), false);
	{
		Graphics g(backgroundImage);
		g.addTransform(AffineTransform::scale((float)viewportSize.getX() / (float)getWidth(), (float)viewportSize.getY() / (float)getHeight()));
		renderParentsToBackground(g, *this);
	}
	return backgroundImage;
}

void TransparentOpenGLComponent::renderParentsToBackground(Graphics &g, Component& component)
{
	Component* parent = component.getParentComponent();
	if (parent == nullptr)
	{
		component.paintEntireComponent(g, false);
		return;
	}

	Graphics::ScopedSaveState saveState(g);
	g.addTransform(AffineTransform::translation(-component.getBounds().getTopLeft()));
	g.addTransform(component.getTransform().inverted());

	renderParentsToBackground(g, *parent);
}