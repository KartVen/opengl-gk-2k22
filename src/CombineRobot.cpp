#include "CombineRobot.h"
#include <iostream>
#include "DEFINES.H"

CombineRobot::CombineRobot(double scale, Vec3 pos) {
	events = Events::getEvents();
	this->absolutePos = this->relativePos = pos;
	rotate = { 0,0,0 };
	size = { 320,220,200 };
	this->scale = scale;
	basicColor.rgb(0,52,0);
	darkBasicColor.rgb(0,26,0);
	wheelColor.rgb(26);
	headerFrontColor.rgb(0, 77, 0);
	bayonetsColor.rgb(80);
	cabineColor = headerFrontColor;
	roofColor = cabineColor;
	glassColor.rgb(168,204,215);

	Size headerBottomSize = { 45,10,18 };
	Size headerMiddleSize = { 32,10,16 };
	Size headerTopSize = { 16,10,11 };
	Size headerFrontSize = { 20,10,10 };
	Size headerBackSize = { 10,size.y - headerMiddleSize.y * 2,headerBottomSize.z + headerMiddleSize.z + headerTopSize.z };
	Size headerKnifesSize = { 15,size.y - headerMiddleSize.y * 2,5 };
	Size2 headerBayonetsSize = { 23, headerKnifesSize.y };
	Size headerHandlerSize = { 28,70,15 };

	Size frontInterWheelSize = { 50,85,28 };
	Size frontSubFloorSize = { 60,85,13 };
	Size frontFloorSize = { 54,98,10 };
	Size frontCabineSize = { 50,90,53 };
	Size frontRoofSize = { 56,100,14 };
	Size frontFrontGlassSize = { 2,76,frontCabineSize.z };
	Size frontSideGlassSize = { 18,2,frontCabineSize.z };

	Size middleFrontSize = { 28,140,80 };
	Size middleStorageSize = { 68,140,120 };
	Size middleRoofSize = { 67,125,10 };

	Size backInterWheelSize = { 15,82,18 };
	Size backFirstLayerSize = { 50,65,9 };
	Size backSecondLayerSize = { 93,110,43 };
	Size backThirdLayerSize = { 86,110,8 };
	Size backFourthLayerSize = { 79,100,9 };
	Size backFifthLayerSize = { 72,90,9 };

	Size2 frontWheelSize = { 28,25 };
	Size2 backWheelSize = { 20,16 };

	Vec3 size_2 = { size.x / 2, size.y / 2, size.z / 2 };
	Vec3 headerLeftBottomPos = { 20,0,7 };
	Vec3 headerLeftMiddlePos = { 33,0,25 };
	Vec3 headerLeftTopPos = { 49,0,41 };
	Vec3 headerLeftFrontPos = { 0,0,14 };
	Vec3 headerRightBottomPos = { 20,size.y - headerBottomSize.y,7 };
	Vec3 headerRightMiddlePos = { 33,size.y - headerMiddleSize.y,25 };
	Vec3 headerRightTopPos = { 49,size.y - headerTopSize.y,41 };
	Vec3 headerRightFrontPos = { 0,size.y - headerMiddleSize.y,14 };
	Vec3 headerBackPos = { headerLeftMiddlePos.x + headerMiddleSize.x - headerBackSize.x,(size.y - headerBackSize.y) / 2,7 };
	Vec3 headerKnifesPos = { headerBackPos.x - headerKnifesSize.x,(size.y - headerKnifesSize.y) / 2,7 };
	Vec3 headerBayonetsPos = { headerLeftMiddlePos.x + 2,(size.y - headerBayonetsSize.h) / 2,35 };
	Vec3 headerHandlerPos = { headerBackPos.x,(size.y - headerHandlerSize.y) / 2,headerLeftMiddlePos.z + frontInterWheelSize.z/8};

	Vec3 frontInterWheelPos = { 73 + frontSubFloorSize.x - frontInterWheelSize.x,(size.y - frontInterWheelSize.y) / 2,22 };
	Vec3 frontSubFloorPos = { 73,(size.y - frontSubFloorSize.y) / 2,49 };
	Vec3 frontFloorPos = { 65,(size.y - frontFloorSize.y) / 2,62 };
	Vec3 frontCabinePos = { 69,(size.y - frontCabineSize.y) / 2,72 };
	Vec3 frontRoofPos = { 63,(size.y - frontRoofSize.y) / 2,125 };
	Vec3 frontFrontGlassPos = { frontCabinePos.x - frontFrontGlassSize.x,(size.y - frontFrontGlassSize.y) / 2,frontCabinePos.z };
	Vec3 frontLeftFirstGlassPos = { frontCabinePos.x + 7 ,frontCabinePos.y - frontSideGlassSize.y,frontCabinePos.z };
	Vec3 frontLeftSecondGlassPos = { frontLeftFirstGlassPos.x + frontSideGlassSize.x + 6,frontLeftFirstGlassPos.y,frontCabinePos.z };
	Vec3 frontRightFirstGlassPos = { frontCabinePos.x + 7 ,frontCabinePos.y + frontCabineSize.y,frontCabinePos.z };
	Vec3 frontRightSecondGlassPos = { frontRightFirstGlassPos.x + frontSideGlassSize.x + 6,frontRightFirstGlassPos.y,frontCabinePos.z };

	Vec3 middleFrontPos = { frontFloorPos.x + frontFloorSize.x,(size.y - middleFrontSize.y) / 2,62 };
	Vec3 middleStoragePos = { middleFrontPos.x + middleFrontSize.x,(size.y - middleStorageSize.y) / 2,22 };
	Vec3 middleRoofPos = { 125,(size.y - middleRoofSize.y) / 2,142 };

	Vec3 backInterWheelPos = { middleStoragePos.x + middleStorageSize.x + backFirstLayerSize.x/2,(size.y - backInterWheelSize.y) / 2,13 };
	Vec3 backFirstLayerPos = { middleStoragePos.x + middleStorageSize.x,(size.y - backFirstLayerSize.y) / 2,backInterWheelPos.z + backInterWheelSize.z };
	Vec3 backSecondLayerPos = { backFirstLayerPos.x,(size.y - backSecondLayerSize.y) / 2,backFirstLayerPos.z + backFirstLayerSize.z };
	Vec3 backThirdLayerPos = { backFirstLayerPos.x,(size.y - backThirdLayerSize.y) / 2,backSecondLayerPos.z + backSecondLayerSize.z };
	Vec3 backFourthLayerPos = { backFirstLayerPos.x,(size.y - backFourthLayerSize.y) / 2,backThirdLayerPos.z + backThirdLayerSize.z };
	Vec3 backFifthLayerPos = { backFirstLayerPos.x,(size.y - backFifthLayerSize.y) / 2,backFourthLayerPos.z + backFourthLayerSize.z };

	Vec3 frontLeftWheelPos = { frontInterWheelPos.x + frontInterWheelSize.x - frontInterWheelSize.x / 3,frontInterWheelPos.y - frontWheelSize.h, frontWheelSize.r };
	Vec3 frontRightWheelPos = { frontLeftWheelPos.x,frontInterWheelPos.y + frontInterWheelSize.y, frontWheelSize.r };

	Vec3 backLeftWheelPos = { backInterWheelPos.x + backInterWheelSize.x / 2,backInterWheelPos.y - backWheelSize.h, backWheelSize.r };
	Vec3 backRightWheelPos = { backLeftWheelPos.x,backInterWheelPos.y + backInterWheelSize.y, backWheelSize.r };

	headerPart.push_back(new Cuboid(headerLeftBottomPos, headerBottomSize, basicColor));
	headerPart.push_back(new Cuboid(headerLeftMiddlePos, headerMiddleSize, basicColor));
	headerPart.push_back(new Cuboid(headerLeftTopPos, headerTopSize, basicColor));
	headerPart.push_back(new Cuboid(headerLeftFrontPos, headerFrontSize, headerFrontColor));
	headerPart.push_back(new Cuboid(headerRightBottomPos, headerBottomSize, basicColor));
	headerPart.push_back(new Cuboid(headerRightMiddlePos, headerMiddleSize, basicColor));
	headerPart.push_back(new Cuboid(headerRightTopPos, headerTopSize, basicColor));
	headerPart.push_back(new Cuboid(headerRightFrontPos, headerFrontSize, headerFrontColor));
	headerPart.push_back(new Cuboid(headerBackPos, headerBackSize, basicColor));
	headerPart.push_back(new Cuboid(headerKnifesPos, headerKnifesSize, basicColor));
	headerPart.push_back(new Cylinder(headerBayonetsPos, headerBayonetsSize, bayonetsColor, 'y'));
	headerPart.push_back(new Cuboid(headerHandlerPos, headerHandlerSize, darkBasicColor));

	frontPart.push_back(new Cuboid(frontInterWheelPos, frontInterWheelSize, darkBasicColor));
	frontPart.push_back(new Cuboid(frontSubFloorPos, frontSubFloorSize, darkBasicColor));
	frontPart.push_back(new Cuboid(frontFloorPos, frontFloorSize, basicColor));
	frontPart.push_back(new Cuboid(frontCabinePos, frontCabineSize, cabineColor));
	frontPart.push_back(new Cuboid(frontRoofPos, frontRoofSize, basicColor));
	frontPart.push_back(new Cuboid(frontFrontGlassPos, frontFrontGlassSize, glassColor));
	frontPart.push_back(new Cuboid(frontLeftFirstGlassPos, frontSideGlassSize, glassColor));
	frontPart.push_back(new Cuboid(frontLeftSecondGlassPos, frontSideGlassSize, glassColor));
	frontPart.push_back(new Cuboid(frontRightFirstGlassPos, frontSideGlassSize, glassColor));
	frontPart.push_back(new Cuboid(frontRightSecondGlassPos, frontSideGlassSize, glassColor));

	middlePart.push_back(new Cuboid(middleFrontPos, middleFrontSize, basicColor));
	middlePart.push_back(new Cuboid(middleStoragePos, middleStorageSize, basicColor));
	middlePart.push_back(new Cuboid(middleRoofPos, middleRoofSize, roofColor));

	backPart.push_back(new Cuboid(backInterWheelPos, backInterWheelSize, darkBasicColor));
	backPart.push_back(new Cuboid(backFirstLayerPos, backFirstLayerSize, darkBasicColor));
	backPart.push_back(new Cuboid(backSecondLayerPos, backSecondLayerSize, basicColor));
	backPart.push_back(new Cuboid(backThirdLayerPos, backThirdLayerSize, basicColor));
	backPart.push_back(new Cuboid(backFourthLayerPos, backFourthLayerSize, basicColor));
	backPart.push_back(new Cuboid(backFifthLayerPos, backFifthLayerSize, roofColor));

	frontWheelPart.push_back(new Wheel(frontLeftWheelPos, frontWheelSize, wheelColor, 'y'));
	frontWheelPart.push_back(new Wheel(frontRightWheelPos, frontWheelSize, wheelColor, 'y'));

	backWheelPart.push_back(new Wheel(backLeftWheelPos, backWheelSize, wheelColor, 'y'));
	backWheelPart.push_back(new Wheel(backRightWheelPos, backWheelSize, wheelColor, 'y'));
}

CombineRobot::~CombineRobot() {
	for (auto& headerSingle : headerPart) delete headerSingle;
	for (auto& frontSingle : frontPart) delete frontSingle;
	for (auto& middleSingle : middlePart) delete middleSingle;
	for (auto& backSingle : backPart) delete backSingle;
	for (auto& frontWheelSingle : frontWheelPart) delete frontWheelSingle;
	for (auto& backWheelSingle : backWheelPart) delete backWheelSingle;
}

void CombineRobot::drive(double v) {
	relativePos.x -= v;
	if (v < 0) mode = 0;
	if (v > 0) mode = 1;
}

void CombineRobot::turnY(double v)
{
	rotate.y += v;
}

bool moveUp = 0, moveDown = 0;
bool turnLeft = 0, turnRight = 0;

void CombineRobot::update(){

	switch (events->basicKey.key) {
	case 'w':
		if (events->basicKey.state == GLUT_UP) {
			moveUp = 0;
			std::cout << 'w\n';
		}
		else if (events->basicKey.state == GLUT_DOWN) {
			moveUp = 1;
			moveDown = 0;
		}
		break;
	case 's':
		if (events->basicKey.state == GLUT_UP) {
			moveDown = 0;
		}
		else if (events->basicKey.state == GLUT_DOWN) {
			moveDown = 1;
			moveUp = 0;
		}
		break;
	case 'a':
		if (events->basicKey.state == GLUT_UP) {
			turnLeft = 0;
		}
		else if (events->basicKey.state == GLUT_DOWN) {
			turnLeft = 1;
			turnRight = 0;
		}
		break;
	case 'd':
		if (events->basicKey.state == GLUT_UP) {
			turnRight = 0;
		}
		else if (events->basicKey.state == GLUT_DOWN) {
			turnRight = 1;
			turnLeft = 0;
		}
		break;
	}

	if (moveUp && !moveDown) { drive(DRIVE_UNIT); }
	if (moveDown && !moveUp) { drive(-DRIVE_UNIT); }
	if (turnLeft && !turnRight) { turnY(-TURN_UNIT); }
	if (turnRight && !turnLeft) { turnY(TURN_UNIT); }
}

void CombineRobot::render() {
	glPushMatrix();

	glRotatef(270, 1, 0, 0);

	glTranslatef(-size.x * scale / 2, -size.y * scale / 2, 0 * scale); // adaptation to the camera layout

	glPushMatrix();

	glRotatef(-rotate.y, 0, 0, 1);
	glTranslatef(-relativePos.x, relativePos.y, relativePos.z);

	glScalef(scale, scale, scale);

	//// xAxis
	//glBegin(GL_LINES);
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glVertex3d(0, 0, 0);
	//glVertex3d(5000, 0, 0);
	//glEnd();

	//// yAxis
	//glBegin(GL_LINES);
	//glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex3d(0, 0, 0);
	//glVertex3d(0, 5000, 0);
	//glEnd();

	// zAxis
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 5000);
	glEnd();

	Vec3 shiftPos = { -size.x / 2, -size.y / 2 , 0 };
	for (auto& headerSingle : headerPart) headerSingle->render(absolutePos + shiftPos);
	for (auto& frontSingle : frontPart) frontSingle->render(absolutePos + shiftPos);
	for (auto& middleSingle : middlePart) middleSingle->render(absolutePos + shiftPos);
	for (auto& backSingle : backPart) backSingle->render(absolutePos + shiftPos);
	for (auto& frontWheelSingle : frontWheelPart) frontWheelSingle->render(absolutePos + shiftPos);
	for (auto& backWheelSingle : backWheelPart) backWheelSingle->render(absolutePos + shiftPos);

	glPopMatrix();
	glPopMatrix();
}