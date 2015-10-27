#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "MasterManager.h"

double rotate_x = 0, rotate_y = 0;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    //  Right arrow - increase rotation by 5 degree
    if (key == GLFW_KEY_RIGHT)
        rotate_y += 2.5;
    //  Left arrow - decrease rotation by 5 degree
    else if (key == GLFW_KEY_LEFT)
        rotate_y -= 2.5;
    else if (key == GLFW_KEY_UP)
        rotate_x += 2.5;
    else if (key == GLFW_KEY_DOWN)
        rotate_x -= 2.5;
    //  Request display update
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

        glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glEnable(GL_DEPTH_TEST);
        glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 5.f, -5.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRotatef( rotate_x, 1.0, 0.0, 0.0 );
        glRotatef( rotate_y, 0.0, 1.0, 0.0 );

        glPushMatrix();
        MasterManager *manager = new MasterManager();
        manager->gameGo();
        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
