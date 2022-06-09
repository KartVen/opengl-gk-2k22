#include "Terrain.h"

Terrain::Terrain()
{
	events = Events::getEvents();
	ground = new Model("assets/map1/", "map.obj", 1);

	//house = new Model("assets/building1/", "building1.obj", 0.3, { 4,0,8 });

	const char* tree1FolderPath = "assets/tree1/";
	const char* tree1FileName = "tree1.obj";
	double tree1Scale = 0.3;
	const char* tree2FolderPath = "assets/tree2/";
	const char* tree2FileName = "tree2.obj";
	double tree2Scale = 0.3;
	trees.push_back(new Model(tree1FolderPath, tree1FileName, tree1Scale, { 9.7,0,9.7 }));
	trees.push_back(new Model(tree2FolderPath, tree2FileName, tree2Scale, { 9.7,0,-9.7 }));
	trees.push_back(new Model(tree2FolderPath, tree2FileName, tree2Scale, { -8.2,2.5,-8.2 }));

	const char* fence1FolderPath = "assets/fence1/";
	const char* fence1FileName = "fence1.obj";
	double fence1Scale = 0.3;
	for (double i = 1; i > -5; i -= 0.9) {//i = 9.5; i > -10; i -= 0.9) {
		fences1.push_back(new Model(fence1FolderPath, fence1FileName, fence1Scale, { -9.5,0,i }));
	}

	const char* fence2FolderPath = "assets/fence1/";
	const char* fence2FileName = "fence1.obj";
	double fence2Scale = 0.3;
	for (double i = 9; i > -9.5; i -= 0.9) {
		fences2.push_back(new Model(fence2FolderPath, fence2FileName, fence2Scale, { 9.5,0,i }));
	}

	const char* fence3FolderPath = "assets/fence2/";
	const char* fence3FileName = "fence2.obj";
	double fence3Scale = 0.3;
	for (double i = 9.05; i > -5; i -= 0.9) {
		fences3.push_back(new Model(fence3FolderPath, fence3FileName, fence3Scale, { i,0,-9.45 }));
	}

	const char* fence4FolderPath = "assets/fence2/";
	const char* fence4FileName = "fence2.obj";
	double fence4Scale = 0.3;
	for (double i = 9.05; i > -1; i -= 0.9) {
		fences4.push_back(new Model(fence4FolderPath, fence4FileName, fence4Scale, { i,0,9.45 }));
	}
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

void Terrain::update() {}

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
	//house->render();
	for (Model* tree : trees) tree->render();
	for (Model* fence1 : fences1) fence1->render();
	for (Model* fence2 : fences2) fence2->render();
	for (Model* fence3 : fences3) fence3->render();
	for (Model* fence4 : fences4) fence4->render();
}
