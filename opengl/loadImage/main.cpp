#include<GLFW/glfw3.h>
#include<opencv2/opencv.hpp>

static unsigned int tex_id;

void loadTexture(unsigned int id, cv::Mat* img);
void desenha(void* dados);
void initOpenGL();

int main() {

	cv::Mat background_img = cv::imread("images/walk.jpg", cv::IMREAD_COLOR);

	std::string mainWindow = "OpenGL Window";
	cv::namedWindow(mainWindow, cv::WINDOW_OPENGL);
	cv::setOpenGlContext(mainWindow);


	initOpenGL();
	cv::setOpenGlDrawCallback(mainWindow, desenha);

	glGenTextures(1, &tex_id);
	loadTexture(tex_id, &background_img);

	cv::updateWindow(mainWindow);
	cv::waitKey(0);

	cv::destroyWindow(mainWindow);

	return 0;
}

void desenha(void* dados)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_id);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0); glVertex2d(-10.0, -10.0);
	glTexCoord2d(+1.0, 0.0); glVertex2d(+10.0, -10.0);
	glTexCoord2d(+1.0, +1.0); glVertex2d(+10.0, +10.0);
	glTexCoord2d(0.0, +1.0); glVertex2d(-10.0, +10.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_TEXTURE_2D);

}

void initOpenGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, +10.0, -10.0, +10.0, -1.0, +1.0);
}



void loadTexture(unsigned int id, cv::Mat* img)
{

	glBindTexture(GL_TEXTURE_2D, id);
	cv::flip(*img, *img, 0);
	glTexImage2D(
		GL_TEXTURE_2D, 0, 
		GL_RGB, img->cols, img->rows, 0, 
		GL_BGR_EXT, GL_UNSIGNED_BYTE, img->data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

}

