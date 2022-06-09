#include "Terrain.h"

Terrain::Terrain()
{
	events = Events::getEvents();
	ground = new Model("assets/mapa-bmp/untitled.obj", 1);
	
	house = new Model("assets/house/domek.obj", 0.3, {4,0,8});
	house->forceColor(true); house->color.rgb(255, 255, 0);

	const char* treePath = "assets/drzewo.obj";
	double treeScale = 0.4;
	trees.push_back(new Model(treePath, treeScale, { 10,0,10 }));
	trees.push_back(new Model(treePath, treeScale, { 10,0,10 }));


	const char* fence1Path = "assets/test1/test1.obj";
	double fence1Scale = 0.3;
	for (double i = 9.5; i > -10; i -= 0.9) {
		fences1.push_back(new Model(fence1Path, fence1Scale, { -9.5,0,i }));
	}
	for (Model* fence1 : fences1) { fence1->forceColor(true); fence1->color.rgb(255,0,0); }

	const char* fence2Path = "assets/test1/test1.obj";
	double fence2Scale = 0.3;
	for (double i = 9; i > -9.5; i -= 0.9) {
		fences2.push_back(new Model(fence2Path, fence2Scale, { 9.5,0,i }));
	}
	for (Model* fence2 : fences2) { fence2->forceColor(true); fence2->color.rgb(255, 0, 0); }

	const char* fence3Path = "assets/test2/plot1_jeden_slupek.obj";
	double fence3Scale = 0.3;
	for (double i = 9.05; i > -9.5; i -= 0.9) {
		fences3.push_back(new Model(fence3Path, fence3Scale, { i,0,-9.45 }));
	}
	for (Model* fence3 : fences3) { fence3->forceColor(true); fence3->color.rgb(0, 255, 0); }

	const char* fence4Path = "assets/test2/plot1_jeden_slupek.obj";
	double fence4Scale = 0.3;
	for (double i = 9.05; i > -9.5; i -= 0.9) {
		fences4.push_back(new Model(fence4Path, fence4Scale, { i,0,9.45 }));
	}
	for (Model* fence4 : fences4) { fence4->forceColor(true); fence4->color.rgb(0, 255, 0); }
}

Terrain::~Terrain()
{
	delete ground;
	delete house;
	for (Model* tree : trees) delete tree;
	for (Model* fence1 : fences1) delete fence1;
	for (Model* fence2 : fences2) delete fence2;
	for (Model* fence3 : fences3) delete fence3;
	for (Model* fence4 : fences4) delete fence4;
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
	house->render();
	for (Model* tree : trees) tree->render();
	for (Model* fence1 : fences1) fence1->render();
	for (Model* fence2 : fences2) fence2->render();
	for (Model* fence3 : fences3) fence3->render();
	for (Model* fence4 : fences4) fence4->render();
}
