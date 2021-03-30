#include <stdio.h>
#include <GLFW/glfw3.h> 

int main(int argc, const char** argv) {
    GLFWwindow* window;
    if(!glfwInit()) {
        printf("Error during initialization of GLFW");
        return 1;
    }
    
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if(!window) {
        printf("Error opening window");
        return 1;
    }

    unsigned char* data = new unsigned char[100 * 100 * 3];
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
             data[i * 100 * 3 + j * 3] = 0xff;
             data[i * 100 * 3 + j * 3 + 1] = 0x00;
             data[i * 100 * 3 + j * 3 + 2] = 0x00;
        }
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, data);
        glfwSwapBuffers(window);

        glfwWaitEvents();
    }

    return 0;
}