#include <iostream>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "DrawVisitor.h"
#include "../Solid/Solid.h"
#include "../Solid/Cube.h"

void DrawVisitor::visit(Solid *solid) {
    std::cout << "drawing Solid..." << solid->getName() << std::endl;
}

void DrawVisitor::visit(Cube *cube) {
    double baseCoordinate = cube->getSideLenght() / 2;
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

    for (int i = 0; i < 6; i++) {
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0);
        for(int j = 0; j < 4; j++) {
            glVertex3f( faces[i][j][0], faces[i][j][1], faces[i][j][2]);
        }
        glEnd();
    }
}
