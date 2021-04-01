#include <stdio.h>
#include <GLFW/glfw3.h> 

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main(void) {
    if(!glfwInit()) {
        printf("Error during initialization of GLFW");
        return -1;
    }

    glfwSetErrorCallback(error_callback);
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if(!window) {
        glfwTerminate();
        printf("Error opening window");
        return -1;
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
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}