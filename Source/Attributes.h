#pragma once

struct Attributes
{
	Attributes(OpenGLContext& openGLContext, OpenGLShaderProgram& shader)
	{
		position = createAttribute(openGLContext, shader, "position");
		/*normal = createAttribute(openGLContext, shader, "normal");
		sourceColour = createAttribute(openGLContext, shader, "sourceColour");
		textureCoordIn = createAttribute(openGLContext, shader, "textureCoordIn");*/
	}

	void enable(OpenGLContext& openGLContext)
	{
		if (position != nullptr)
		{
			openGLContext.extensions.glEnableVertexAttribArray(position->attributeID);
			openGLContext.extensions.glVertexAttribPointer(position->attributeID, 2, GL_FLOAT, GL_FALSE, 0, 0);
			
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

		if (textureCoordIn != nullptr)
		{
		openGLContext.extensions.glVertexAttribPointer(textureCoordIn->attributeID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 10));
		openGLContext.extensions.glEnableVertexAttribArray(textureCoordIn->attributeID);
		}*/
	}

	void disable(OpenGLContext& openGLContext)
	{
		if (position != nullptr)       openGLContext.extensions.glDisableVertexAttribArray(position->attributeID);
		/*	if (normal != nullptr)         openGLContext.extensions.glDisableVertexAttribArray(normal->attributeID);
		if (sourceColour != nullptr)   openGLContext.extensions.glDisableVertexAttribArray(sourceColour->attributeID);
		if (textureCoordIn != nullptr)  openGLContext.extensions.glDisableVertexAttribArray(textureCoordIn->attributeID);*/
	}

	bool getStatus()
	{
		if (position == nullptr)
			return false;
		else
			return true;
	}
	ScopedPointer<OpenGLShaderProgram::Attribute> position;

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
		//texture = createUniform(openGLContext, shader, "demoTexture");
		lightPosition = createUniform(openGLContext, shader, "lightPosition");
	//	bouncingNumber = createUniform(openGLContext, shader, "bouncingNumber");
	}
	bool getStatus()
	{
		if (lightPosition == nullptr)
			return false;
		else
			return true;
	}
	//ScopedPointer<OpenGLShaderProgram::Uniform> projectionMatrix, viewMatrix, texture, lightPosition, bouncingNumber;
	ScopedPointer<OpenGLShaderProgram::Uniform> lightPosition;

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
