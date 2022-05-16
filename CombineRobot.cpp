#include "CombineRobot.h"
#include <iostream>

CombineRobot::CombineRobot(GLfloat x, GLfloat y, GLfloat z) {
	pos = { x,y,z };
	size = { 320,220,200 };

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

	Position headerLeftBottomPos = { 20,0,7 };
	Position headerLeftMiddlePos = { 33,0,25 };
	Position headerLeftTopPos = { 49,0,41 };
	Position headerLeftFrontPos = { 0,0,14 };
	Position headerRightBottomPos = { 20,size.y - headerBottomSize.y,7 };
	Position headerRightMiddlePos = { 33,size.y - headerMiddleSize.y,25 };
	Position headerRightTopPos = { 49,size.y - headerTopSize.y,41 };
	Position headerRightFrontPos = { 0,size.y - headerMiddleSize.y,14 };
	Position headerBackPos = { headerLeftMiddlePos.x + headerMiddleSize.x - headerBackSize.x ,(size.y - headerBackSize.y) / 2,7 };
	Position headerKnifesPos = { headerBackPos.x - headerKnifesSize.x,(size.y - headerKnifesSize.y) / 2,7 };
	Position headerBayonetsPos = { headerLeftMiddlePos.x + 2,(size.y - headerBayonetsSize.h) / 2,35 };
	Position headerHandlerPos = { headerBackPos.x,(size.y - headerHandlerSize.y) / 2,headerLeftMiddlePos.z + frontInterWheelSize.z/8};

	Position frontInterWheelPos = { 73 + frontSubFloorSize.x - frontInterWheelSize.x,(size.y - frontInterWheelSize.y) / 2,22 };
	Position frontSubFloorPos = { 73,(size.y - frontSubFloorSize.y) / 2,49 };
	Position frontFloorPos = { 65,(size.y - frontFloorSize.y) / 2,62 };
	Position frontCabinePos = { 69,(size.y - frontCabineSize.y) / 2,72 };
	Position frontRoofPos = { 63,(size.y - frontRoofSize.y) / 2,125 };
	Position frontFrontGlassPos = { frontCabinePos.x - frontFrontGlassSize.x,(size.y - frontFrontGlassSize.y) / 2,frontCabinePos.z };
	Position frontLeftFirstGlassPos = { frontCabinePos.x + 7 ,frontCabinePos.y - frontSideGlassSize.y,frontCabinePos.z };
	Position frontLeftSecondGlassPos = { frontLeftFirstGlassPos.x + frontSideGlassSize.x + 6,frontLeftFirstGlassPos.y,frontCabinePos.z };
	Position frontRightFirstGlassPos = { frontCabinePos.x + 7 ,frontCabinePos.y + frontCabineSize.y,frontCabinePos.z };
	Position frontRightSecondGlassPos = { frontRightFirstGlassPos.x + frontSideGlassSize.x + 6,frontRightFirstGlassPos.y,frontCabinePos.z };

	Position middleFrontPos = { frontFloorPos.x + frontFloorSize.x,(size.y - middleFrontSize.y) / 2,62 };
	Position middleStoragePos = { middleFrontPos.x + middleFrontSize.x,(size.y - middleStorageSize.y) / 2,22 };
	Position middleRoofPos = { 125,(size.y - middleRoofSize.y) / 2,142 };

	Position backInterWheelPos = { middleStoragePos.x + middleStorageSize.x + backFirstLayerSize.x/2,(size.y - backInterWheelSize.y) / 2,13 };
	Position backFirstLayerPos = { middleStoragePos.x + middleStorageSize.x,(size.y - backFirstLayerSize.y) / 2,backInterWheelPos.z + backInterWheelSize.z };
	Position backSecondLayerPos = { backFirstLayerPos.x,(size.y - backSecondLayerSize.y) / 2,backFirstLayerPos.z + backFirstLayerSize.z };
	Position backThirdLayerPos = { backFirstLayerPos.x,(size.y - backThirdLayerSize.y) / 2,backSecondLayerPos.z + backSecondLayerSize.z };
	Position backFourthLayerPos = { backFirstLayerPos.x,(size.y - backFourthLayerSize.y) / 2,backThirdLayerPos.z + backThirdLayerSize.z };
	Position backFifthLayerPos = { backFirstLayerPos.x,(size.y - backFifthLayerSize.y) / 2,backFourthLayerPos.z + backFourthLayerSize.z };

	Position frontLeftWheelPos = { frontInterWheelPos.x + frontInterWheelSize.x - frontInterWheelSize.x / 3,frontInterWheelPos.y - frontWheelSize.h, frontWheelSize.r };
	Position frontRightWheelPos = { frontLeftWheelPos.x,frontInterWheelPos.y + frontInterWheelSize.y, frontWheelSize.r };

	Position backLeftWheelPos = { backInterWheelPos.x + backInterWheelSize.x / 2,backInterWheelPos.y - backWheelSize.h, backWheelSize.r };
	Position backRightWheelPos = { backLeftWheelPos.x,backInterWheelPos.y + backInterWheelSize.y, backWheelSize.r };

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
void CombineRobot::draw() {
	glPushMatrix();
	glTranslatef(-size.x / 2, -size.y / 2, 0);
	for (auto& headerSingle : headerPart) headerSingle -> draw(pos);
	for (auto& frontSingle : frontPart) frontSingle -> draw(pos);
	for (auto& middleSingle : middlePart) middleSingle -> draw(pos);
	for (auto& backSingle : backPart) backSingle -> draw(pos);
	for (auto& frontWheelSingle : frontWheelPart) frontWheelSingle -> draw(pos);
	for (auto& backWheelSingle : backWheelPart) backWheelSingle -> draw(pos);
	glPopMatrix();
}
void CombineRobot::move(GLdouble x, GLdouble y) {
	pos.x -= x;
	pos.y += y;
}