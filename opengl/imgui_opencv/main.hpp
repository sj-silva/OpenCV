#pragma once
#include<GLFW/glfw3.h>
#include<opencv2/opencv.hpp>
#include<opencv2/core/opengl.hpp>

#include"imgui/imgui.h"
#include"imgui/imgui_impl_glfw.h"
#include"imgui/imgui_impl_opengl2.h"
#include"Menu.h"



void init_OPENGL(GLFWwindow* window);
void desenha();
void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods);