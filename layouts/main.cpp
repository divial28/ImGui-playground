/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-05
 *
 * @copyright Copyright (c) 2023
 *
 * @todo
 * 1) implement grid with shader
 * 2) simple triangulation
 */

#include "glfwapp.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "renderer.h"
#include "camera.h"
#include "glshader.h"
#include "gui.h"

#include <ImGuizmo.h>
#include <iostream>


int main(int, char**)
{
    GLApp app;
    Camera camera(vec3(0.0f, 0.0f, 0.0f), 
                  vec3(0.0f, -1.0f, -1.0f));

    // Setup Dear ImGui context
    GUI::init(app.getWindow(), app.getAppData(), &camera);

    Renderer renderer{*app.getAppData(), camera};

    ImVec4 clear_color = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);

    while (!glfwWindowShouldClose(app.getWindow())) {
        GUI::prepare();

        int display_w, display_h;
        glfwGetFramebufferSize(app.getWindow(), &display_w, &display_h);
        
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        camera.update(display_w, display_h);
        renderer.update();

        // ImGuizmo::DrawGrid(glm::value_ptr(camera.getViewMatrix()), glm::value_ptr(camera.getProjection()), identityMatrix, 100.f);
        renderer.render();
        GUI::render();
        app.swapBuffers();
    }

    // Cleanup
    GUI::cleanup();

    return 0;
}