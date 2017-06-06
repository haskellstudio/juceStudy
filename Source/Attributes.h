#pragma once

struct Vertex {
	float x;
	float y;
	float u;
	float v;

};


struct Attributes
{
	Attributes(OpenGLContext& openGLContext, OpenGLShaderProgram& shader)
	{
		position = createAttribute(openGLContext, shader, "position");
		/*normal = createAttribute(openGLContext, shader, "normal");
		sourceColour = createAttribute(openGLContext, shader, "sourceColour");*/
		textureCoordIn = createAttribute(openGLContext, shader, "textureCoordIn");
	}

	void enable(OpenGLContext& openGLContext)
	{
		if (position != nullptr)
		{
			openGLContext.extensions.glEnableVertexAttribArray(position->attributeID);
			openGLContext.extensions.glVertexAttribPointer(position->attributeID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
			
		}

		/*	if (normal != nullptr)
		{
		openGLContext.extensions.glVertexAttribPointer(normal->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 3));
		openGLContext.extensions.glEnableVertexAttribArray(normal->attributeID);
		}

		if (sourceColour != nullptr)
		{
		openGLContext.extensions.glVertexAttribPointer(sourceColour->attributeID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 6));
		openGLContext.extensions.glEnableVertexAttribArray(sourceColour->attributeID);
		}
		*/
		if (textureCoordIn != nullptr)
		{
			openGLContext.extensions.glVertexAttribPointer(textureCoordIn->attributeID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 2));
			openGLContext.extensions.glEnableVertexAttribArray(textureCoordIn->attributeID);
		}
	}

	void disable(OpenGLContext& openGLContext)
	{
		if (position != nullptr)       openGLContext.extensions.glDisableVertexAttribArray(position->attributeID);
		/*	if (normal != nullptr)         openGLContext.extensions.glDisableVertexAttribArray(normal->attributeID);
		if (sourceColour != nullptr)   openGLContext.extensions.glDisableVertexAttribArray(sourceColour->attributeID);*/
		if (textureCoordIn != nullptr)  openGLContext.extensions.glDisableVertexAttribArray(textureCoordIn->attributeID);
	}

	bool getStatus()
	{
		return true;
		if (position == nullptr)
			return false;
		else
			return true;
	}
	ScopedPointer<OpenGLShaderProgram::Attribute> position, textureCoordIn;

private:
	static OpenGLShaderProgram::Attribute* createAttribute(OpenGLContext& openGLContext,
		OpenGLShaderProgram& shader,
		const char* attributeName)
	{
		if (openGLContext.extensions.glGetAttribLocation(shader.getProgramID(), attributeName) < 0)
			return nullptr;

		return new OpenGLShaderProgram::Attribute(shader, attributeName);
	}
};



struct Uniforms
{
	Uniforms(OpenGLContext& openGLContext, OpenGLShaderProgram& shader)
	{
		//projectionMatrix = createUniform(openGLContext, shader, "projectionMatrix");
		//viewMatrix = createUniform(openGLContext, shader, "viewMatrix");
		texture = createUniform(openGLContext, shader, "demoTexture");
		lightPosition = createUniform(openGLContext, shader, "lightPosition");
	//	bouncingNumber = createUniform(openGLContext, shader, "bouncingNumber");
	}
	bool getStatus()
	{
		return true;
		if (lightPosition == nullptr || texture == nullptr)
			return false;
		else
			return true;
	}
	//ScopedPointer<OpenGLShaderProgram::Uniform> projectionMatrix, viewMatrix, texture, lightPosition, bouncingNumber;
	ScopedPointer<OpenGLShaderProgram::Uniform> lightPosition, texture;

private:
	static OpenGLShaderProgram::Uniform* createUniform(OpenGLContext& openGLContext,
		OpenGLShaderProgram& shader,
		const char* uniformName)
	{
		if (openGLContext.extensions.glGetUniformLocation(shader.getProgramID(), uniformName) < 0)
			return nullptr;

		return new OpenGLShaderProgram::Uniform(shader, uniformName);
	}
};





struct DynamicTexture  
{
	DynamicTexture() {  }

	Image image;


	bool applyTo(OpenGLTexture& texture) 
	{
		const int size = 16*16;

		if (!image.isValid())
			image = Image(Image::ARGB, size, size, true);

		{
			Graphics g(image);
			g.fillAll(Colours::white);

			//g.setColour(Colours::black);
			//g.drawRect(10, 10, size/2, size/2, 2);


			//g.fillEllipse(0, 0, 16, 16);
			g.setColour(Colours::red);
			g.setFont(40);
			g.drawFittedText(String("Release my soul"), image.getBounds(), Justification::centred, 1);

		}

		texture.loadImage(image);
		return true;
	}
};