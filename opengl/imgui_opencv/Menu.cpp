#include "Menu.h"
#include"imgui/imgui.h"
#include<opencv2/core/opengl.hpp>
#include<opencv2/opencv.hpp>

extern cv::ogl::Texture2D image_tex;
extern cv::Mat image;

const int IMG_GRAY = 1;
const int  IMG_COLOR = 2;

bool ButtonCenteredOnLine(const char* label, float alignment = 0.5f)
{
    ImGuiStyle& style = ImGui::GetStyle();

    float size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.0f;
    float avail = ImGui::GetContentRegionAvail().x;

    float off = (avail - size) * alignment;
    if (off > 0.0f)
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

    return ImGui::Button(label);
}

void Menu::Theme()
{

    ImVec2 menuWindowSize(250, 200);
    ImVec2 menuWindowPos(690, 140);
    ImGui::SetNextWindowSize(menuWindowSize);
    ImGui::SetNextWindowPos(menuWindowPos);

    ImGuiStyle* style = &ImGui::GetStyle();
    style->WindowTitleAlign = ImVec2(0.5, 0.5);
    style->WindowPadding = ImVec2(8, 8);
    style->FramePadding = ImVec2(8, 6);
    style->WindowRounding = 10.f;

    // Colors
    ImVec4* colors = style->Colors;
    ImColor primaryColor(92, 107, 192, 255);
    ImColor darkColor(38, 65, 143, 255);
    ImColor textColor(200, 200, 200, 255);

    colors[ImGuiCol_WindowBg] = primaryColor;
    colors[ImGuiCol_TitleBgActive] = darkColor;
    colors[ImGuiCol_Header] = darkColor;

    colors[ImGuiCol_Text] = textColor;

}


void Menu::Render()
{

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
    ImGui::Begin("Menu::Image Type", nullptr, flags);

    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    
    // 
    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    static int imageType=IMG_COLOR;
    
    ImGui::RadioButton("Grayscale Image", &imageType, IMG_GRAY); 
    ImGui::RadioButton("Color Image", &imageType, IMG_COLOR);
    

    ImGui::Dummy(ImVec2(0.0f, 5.0f));
    ImGui::Separator();

    // Botão para Interpolar
    ImGui::Dummy(ImVec2(0.0f, 10.0f));

    if (ButtonCenteredOnLine("Update Image")) {
        
        if (imageType==IMG_GRAY) {
            cv::Mat img_gray;
            cv::cvtColor(image, img_gray, cv::COLOR_BGR2GRAY);
            image_tex = cv::ogl::Texture2D(img_gray);
        }
        else if (imageType == IMG_COLOR) {
            image_tex = cv::ogl::Texture2D(image);
        }
    }

    ImGui::End();
}

