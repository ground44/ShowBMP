#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h> //makes things crossplatform
#include <GLFW/glfw3.h>//GLFW API(opengl)
#include <glm/glm.hpp>//shading shit

#include "gfx.hpp"

using namespace glm;

GLFWwindow* window;

bool glInit(){
	bool result=false;

	if(!glfwInit()){
		goto Exit;
	}

	if(glewInit()!=GLEW_OK){
		goto Exit;
	}

	result=true;
	Exit:
	return result;
}

bool createWindow(char *title,int width, int height){
	bool result=false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);//max API to use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);//min API to use (version of OpenGl)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//use the standard OpenGL profile(settings)

	window = glfwCreateWindow(width,height,title,NULL,NULL);//create and show te actual window
	
	glfwMakeContextCurrent(window); 

	if(window!=NULL)result=true;
	return result;
}

void imageShow(){
	while(glfwWindowShouldClose(window)==0){
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}