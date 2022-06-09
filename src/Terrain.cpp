#include "Terrain.h"

Terrain::Terrain()
{
	events = Events::getEvents();
}

Terrain::~Terrain()
{
	delete ground;
	for (Model* tree : trees) delete tree;
}

void Terrain::update()
{
	
}

void Terrain::render()
{
	/*
	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
	*/
	//for (Model* tree : trees) tree->render();
}
