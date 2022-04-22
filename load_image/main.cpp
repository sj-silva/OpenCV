#include<iostream>
#include<locale>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

	setlocale(LC_ALL, "Portuguese");
	std::string filePath = "imagens/carro.jpg";
	
	Mat img = imread(filePath,0);

	if (img.data == nullptr) {
		cerr << "ERRO::Não foi possível carregar a imagem "<< filePath<<" \n\n";
	}

	imshow("Imagem", img);

	waitKey(0);

	return 0;
}
