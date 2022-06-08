#include "Terrain.h"
#include "OBJInterpreter.h"

Terrain::Terrain()
{
	events = Events::getEvents();
	ground = new Model("assets/mapa.obj", 1);

	const char* treePath = "assets/drzewo.obj";
	double treeScale = .4;
	trees.push_back(new Model(treePath, treeScale, { 10,0,10 }));
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
	ground->render();
	for (Model* tree : trees) tree->render();
}
