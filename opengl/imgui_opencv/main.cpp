#include"main.hpp"

cv::ogl::Texture2D image_tex;
cv::Mat image;

int main()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(990, 480, "OpenGL+OpenCV+IMGUI", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    init_OPENGL(window);

    image = cv::imread("images/onça.jpg");
    cv::flip(image, image, 0);
    image_tex = cv::ogl::Texture2D(image);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    std::string fontPath = "font/Roboto-Medium.ttf";
    io.Fonts->AddFontFromFileTTF(fontPath.c_str(), 14.0f);

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Poll for and process events */
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        Menu::Theme();
        {
            Menu::Render();

        }

        /* Render here */
        glClearColor(0.0, 0.15, 0.25, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, 640, 480);
        desenha();
        ImGui::Render();
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);


    }


    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}

void init_OPENGL(GLFWwindow* window)
{

    glfwSetKeyCallback(window, teclado_callback);
    glClearColor(0.0, 0.15, 0.25, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 640.0, 0.0, 480.0, 1.0, -1.0);
    
}

void desenha()
{

    glEnable(GL_TEXTURE_2D);

    image_tex.bind();
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex2d(0.0, 0.0);
    glTexCoord2d(+1.0, 0.0); glVertex2d(640.0, 0.0);
    glTexCoord2d(+1.0, +1.0); glVertex2d(640.0, 480.0);
    glTexCoord2d(0.0, +1.0); glVertex2d(0.0, 480.0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    glDisable(GL_TEXTURE_2D);
}

void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

}

