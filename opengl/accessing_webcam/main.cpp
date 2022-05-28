#include<GLFW/glfw3.h>
#include<opencv2/opencv.hpp>
#include<opencv2/core/opengl.hpp>

static cv::ogl::Texture2D img_tex, video_tex;

void desenha(void* dados);
void initOpenGL();

int main() {

	cv::Mat background_img = cv::imread("images/walk.jpg", cv::IMREAD_COLOR);
	
	std::string mainWindow = "OpenCV+OpenGL accessing my webcam";
	cv::namedWindow(mainWindow, cv::WINDOW_OPENGL);
	cv::setOpenGlContext(mainWindow);

	cv::flip(background_img, background_img, 0);
	img_tex = cv::ogl::Texture2D(background_img);

	initOpenGL();

	cv::setOpenGlDrawCallback(mainWindow, desenha);
	
	cv::VideoCapture cap(0);

	while (cv::waitKey(25)!=27) {// ESC=27

		cv::Mat frame;
		cap.read(frame);
		cv::flip(frame, frame, 1);
		cv::flip(frame,frame, 0);
		video_tex = cv::ogl::Texture2D(frame);
		cv::updateWindow(mainWindow);
	}
	
	cv::destroyWindow(mainWindow);

	return 0;
}

void desenha(void* dados)
{
	glEnable(GL_TEXTURE_2D);

	img_tex.bind();
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0); glVertex2d(-10.0, -10.0);
	glTexCoord2d(+1.0, 0.0); glVertex2d(+10.0, -10.0);
	glTexCoord2d(+1.0, +1.0); glVertex2d(+10.0, +10.0);
	glTexCoord2d(0.0, +1.0); glVertex2d(-10.0, +10.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	video_tex.bind();
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0);  glVertex2d(+5.0, -10.0);
	glTexCoord2d(+1.0, 0.0); glVertex2d(+10.0, -10.0);
	glTexCoord2d(+1.0, +1.0); glVertex2d(+10.0, -5.0);
	glTexCoord2d(0.0, +1.0); glVertex2d(+5.0, -5.0);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

}

void initOpenGL()
{
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, +10.0, -10.0, +10.0, -1.0, +1.0);
}

