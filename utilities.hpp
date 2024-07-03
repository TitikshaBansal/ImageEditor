// Header file declaring utility functions like loadImage, saveImage, etc.

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <opencv2/opencv.hpp>

cv::Mat loadImage();
void saveImage(const cv::Mat& address);
void FilterImage(cv::Mat& address);
void colorImage(cv::Mat& address);
void cropImage(cv::Mat& address);
void resizeImage(cv::Mat& address);

#endif
