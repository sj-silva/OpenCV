#include<iostream>
#include<opencv2/opencv.hpp>


int main() {


	cv::Mat src = cv::imread("images/dali.jpg");
	
	cv::Size ksize(35, 35);
	cv::Point anchor(-1, -1);
	int borda = cv::BORDER_CONSTANT;
	double sigma = 5.5;

	cv::Mat box, gauss, median;
	
	cv::blur(src, box, ksize, anchor, borda);
	cv::GaussianBlur(src, gauss, ksize, sigma, 0, borda);
	cv::medianBlur(src, median, 35);


	std::string janela[] = { "Imagem", "Box", "Gauss", "Median"};
	cv::namedWindow(janela[0], cv::WINDOW_GUI_NORMAL); // Imagem
	cv::namedWindow(janela[1], cv::WINDOW_GUI_NORMAL); // Box
	cv::namedWindow(janela[2], cv::WINDOW_GUI_NORMAL); // Gauss
	cv::namedWindow(janela[3], cv::WINDOW_GUI_NORMAL); // Median

	cv::imshow(janela[0], src);
	cv::imshow(janela[1], box);
	cv::imshow(janela[2], gauss);
	cv::imshow(janela[3], median);
	
	cv::waitKey(0);

	cv::destroyAllWindows();


	return 0;
}



