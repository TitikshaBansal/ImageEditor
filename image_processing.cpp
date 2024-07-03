// Implementation file for image processing functions.

#include "image_processing.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void Gray(Mat& address) {
    cvtColor(address, address, COLOR_BGR2GRAY);
    imshow("Grayscale Image", address);
    waitKey(0);
    destroyWindow("Grayscale Image");
}

void Blur(Mat& address) {
    int kernelSize;
    cout << "Enter the kernel size (odd value): ";
    cin >> kernelSize;
    if (kernelSize % 2 == 0) {
        cout << "Kernel size must be an odd value. Please try again." << endl;
        return;
    }
    GaussianBlur(address, address, Size(kernelSize, kernelSize), 0);
    imshow("Blurred Image", address);
    waitKey(0);
    destroyWindow("Blurred Image");
}

void Sharp(Mat& address) {
    double sharpenFactor;
    cout << "Enter sharpening factor (0.0 to 1.0): ";
    cin >> sharpenFactor;

    Mat blurred;
    GaussianBlur(address, blurred, Size(0, 0), 25);
    addWeighted(address, 1.0 + sharpenFactor, blurred, -sharpenFactor, 0, address);

    imshow("Sharpened", address);
    waitKey(0);
    destroyWindow("Sharpened");
}

void AdjustColor(Mat& address) {
    int r, g, b;
    cout << "Enter RGB values for the desired color (0-255): ";
    cin >> r >> g >> b;

    Mat lut(1, 256, CV_8UC3);
    for (int i = 0; i < 256; ++i) {
        lut.at<Vec3b>(i) = Vec3b(b, g, r);
    }

    Mat grayImage;
    cvtColor(address, grayImage, COLOR_BGR2GRAY);
    Mat colorImage;
    LUT(grayImage, lut, colorImage);

    address = colorImage.clone();
    imshow("Color Adjusted", address);
    waitKey(0);
    destroyWindow("Color Adjusted");
}

void Brightness(Mat& address) {
    double alpha;
    int beta;
    cout << "Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;
    cout << "Enter the beta value [0-100]: ";
    cin >> beta;

    address.convertTo(address, -1, alpha, beta);

    imshow("Brightness Adjusted", address);
    waitKey(0);
    destroyWindow("Brightness Adjusted");
}

void Contrast(Mat& address) {
    double alpha;
    cout << "Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;

    address.convertTo(address, -1, alpha, 0);

    imshow("Contrast Adjusted", address);
    waitKey(0);
    destroyWindow("Contrast Adjusted");
}
