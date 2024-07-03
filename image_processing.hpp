// Header file declaring all image processing functions.

#ifndef IMAGE_PROCESSING_HPP
#define IMAGE_PROCESSING_HPP
#include <opencv2/opencv.hpp>

void Gray(cv::Mat& address);
void Blur(cv::Mat& address);
void Sharp(cv::Mat& address);
void AdjustColor(cv::Mat& address);
void Brightness(cv::Mat& address);
void Contrast(cv::Mat& address);

#endif