#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;


float xTriangulo = 0.0f;
float yTriangulo = 0.0f;

float velocidad = 0.05f;

void dibujarTriangulos() {

	glPushMatrix();

	//Trnsformaciones
	glTranslatef(xTriangulo, yTriangulo, 0.0f);

	 glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0);

	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);



	glEnd();

}

 







void dibujar() {
	dibujarTriangulos();
	//dibujarPuntos();
	//dibujarLineas();
	//dibujarLineaContinua();
	//dibujarTringuloContinuo();
	//dibujarPoligono();
}



void actualizar() {

}

void teclado_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

	if (key == GLFW_KEY_RIGHT && action = GLFW_PRESS) {

		xTriangulo += velocidad;

	}

}


int main()
{
	//Creamos una ventana
	GLFWwindow *window;

	//Si no se puede inicializar glfw
	//Iniciamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//entonces inicializamosla ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	//Si nopodemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	glfwSetKeyCallback(window, teclado_callback);

	// ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(0, 181, 252, 0);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}