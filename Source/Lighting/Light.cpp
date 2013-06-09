#include "Light.h"

Light::Light(GLenum LIGHT_NAME, const GLfloat* Ambiant, const GLfloat* Diffuse, const GLfloat* Specular, 
	  const GLfloat* Position, const GLfloat* SpotDirection, 
	  const GLfloat& Exponent, const GLfloat& Cutoff,
	  const GLfloat& ConstantAttenuation, const GLfloat& LinearAttenuation, const GLfloat& QuadraticAttenuation)
	  : LIGHT_GL_ID(LIGHT_NAME), exponent(Exponent), cutoff(Cutoff),
		constantAttenuation(ConstantAttenuation), linearAttenuation(LinearAttenuation), 
		quadraticAttenuation(QuadraticAttenuation)
{
	glEnable(LIGHT_NAME);
	for (int i = 0; i < 4; ++i)
	{
		ambiant[i] = Ambiant[i];
		diffuse[i] = Diffuse[i];
		specular[i] = Specular[i];
		position[i] = Position[i];
		if (i != 3) 
			spotDirection[i] = SpotDirection[i];
	}
}


void Light::refresh() const
{
	glLightfv( LIGHT_GL_ID, GL_AMBIENT, ambiant );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
	glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
	glLightfv( GL_LIGHT0, GL_POSITION, position );
	glLightfv( GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection );
	glLightf ( GL_LIGHT0, GL_SPOT_EXPONENT, exponent );
	glLightf ( GL_LIGHT0, GL_SPOT_CUTOFF, cutoff );
}