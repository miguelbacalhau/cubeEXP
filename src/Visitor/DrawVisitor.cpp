#include <iostream>
#include <vector>
#include <stdlib.h>
#include <GL/freeglut.h>
#include "DrawVisitor.h"
#include "../Model/CompositeModel.h"
#include "../Model/Solid/Solid.h"
#include "../Model/Solid/Cube.h"

void DrawVisitor::visit(CompositeModel *compModel) {
    //TODO check stupid matrix stuff
    Position position = compModel->getPosition();
    std::vector<Model*> subModels = compModel->getSubModels();
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);

    Model* model;
    for (std::vector<Model*>::iterator it = subModels.begin() ; it != subModels.end(); ++it) {
        model = *it;
        model->accept(this);
    }

    glPopMatrix();
}
void DrawVisitor::visit(Solid *solid) {
    //TODO get the fak out wtf is diz why iz even here
}

void DrawVisitor::visit(Cube *cube) {
    //TODO check stupid matrix stuff
    double baseCoordinate = cube->getSideLenght() / 2;
    //TODO improve this shit, wodafak had this idea
    double faces[6][4][3] = {
        {
            //Front Face
            {  baseCoordinate, -baseCoordinate, -baseCoordinate },
            {  baseCoordinate,  baseCoordinate, -baseCoordinate },
            { -baseCoordinate,  baseCoordinate, -baseCoordinate },
            { -baseCoordinate, -baseCoordinate, -baseCoordinate },
        },
        {
            //Back Face
            {  baseCoordinate, -baseCoordinate,  baseCoordinate },
            {  baseCoordinate,  baseCoordinate,  baseCoordinate },
            { -baseCoordinate,  baseCoordinate,  baseCoordinate },
            { -baseCoordinate, -baseCoordinate,  baseCoordinate },
        },
        {
            // Right Face
            {  baseCoordinate, -baseCoordinate, -baseCoordinate },
            {  baseCoordinate,  baseCoordinate, -baseCoordinate },
            {  baseCoordinate,  baseCoordinate,  baseCoordinate },
            {  baseCoordinate, -baseCoordinate,  baseCoordinate },

        },
        {
            // Left Face
            { -baseCoordinate, -baseCoordinate,  baseCoordinate },
            { -baseCoordinate,  baseCoordinate,  baseCoordinate },
            { -baseCoordinate,  baseCoordinate, -baseCoordinate },
            { -baseCoordinate, -baseCoordinate, -baseCoordinate },
        },
        {
            // Top Face
            {  baseCoordinate,  baseCoordinate,  baseCoordinate },
            {  baseCoordinate,  baseCoordinate, -baseCoordinate },
            { -baseCoordinate,  baseCoordinate, -baseCoordinate },
            { -baseCoordinate,  baseCoordinate,  baseCoordinate },

        },
        {
            // Bottom Face
            {  baseCoordinate, -baseCoordinate, -baseCoordinate },
            {  baseCoordinate, -baseCoordinate,  baseCoordinate },
            { -baseCoordinate, -baseCoordinate,  baseCoordinate },
            { -baseCoordinate, -baseCoordinate, -baseCoordinate },
        }
    };

    Color color = cube->getColor();
    Position position = cube->getPosition();
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glColor3f(color.red, color.green, color.blue);
    for (int i = 0; i < 6; i++) {
        glBegin(GL_POLYGON);
        for(int j = 0; j < 4; j++) {
            glVertex3f( faces[i][j][0], faces[i][j][1], faces[i][j][2]);
        }
        glEnd();
    }
    glPopMatrix();
}
