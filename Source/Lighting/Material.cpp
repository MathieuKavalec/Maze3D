#include "Material.h"

Material::Material(GLfloat* Ambiant, GLenum AmbiantFace, GLfloat* Diffuse, GLenum DiffuseFace,
	GLfloat* Specular, GLenum SpecularFace, GLfloat Shininess, GLenum ShininessFace)
	: ambiantFace(AmbiantFace), diffuseFace(DiffuseFace), specularFace(SpecularFace),
	shininess(Shininess), shininessFace(ShininessFace)
{
	for (int i = 0; i < 4; ++i)
	{
		ambiant[i] = Ambiant[i];
		diffuse[i] = Diffuse[i];
		specular[i] = Specular[i];
	}
}

Material::Material(const Material& mat)
	: ambiantFace(mat.ambiantFace), diffuseFace(mat.diffuseFace), specularFace(mat.specularFace),
	shininess(mat.shininess), shininessFace(mat.shininessFace)
{
	for (int i = 0; i < 4; ++i)
	{
		ambiant[i] = mat.ambiant[i];
		diffuse[i] = mat.diffuse[i];
		specular[i] = mat.specular[i];
	}
}

void Material::apply() const
{
	glMaterialfv(ambiantFace, GL_AMBIENT, ambiant);
	glMaterialfv(diffuseFace, GL_DIFFUSE, diffuse);
	glMaterialfv(specularFace, GL_SPECULAR, specular);
	glMaterialf(shininessFace, GL_SHININESS, shininess);
}