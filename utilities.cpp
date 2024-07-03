// Implementation file for utility functions.

#include "utilities.hpp"
#include "image_processing.hpp"
#include <iostream>
#include <limits>

using namespace cv;
using namespace std;

Mat loadImage() {
    string str;
    cout << "Enter the path to your image: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);
    Mat img = imread(str, IMREAD_COLOR);

    if (img.empty()) {
        cout << "Image file not found or couldn't be loaded." << endl;
    } else {
        imshow("Display window", img);
        waitKey(0);
        destroyWindow("Display window");
    }

    return img;
}

void saveImage(const Mat& address) {
    string str;
    cout << "Enter the location where you want your edited image to be saved (e.g., path/to/save/MyImage.jpg): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);

    bool check = imwrite(str, address);
    if (check) {
        cout << "Successfully saved the modified image." << endl;
    } else {
        cout << "Failed to save the image." << endl;
    }

    imshow("Modified Image", address);
    waitKey(0);
    destroyWindow("Modified Image");
}

void FilterImage(Mat& address) {
    if (address.empty()) {
        cout << "No image loaded. Please load an image first." << endl;
        return;
    }

    cout << "\n\nChoose one filter option from the following to be applied:\n";
    cout << "1. Gray Scale\n";
    cout << "2. Blur\n";
    cout << "3. Sharpen\n";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            Gray(address);
            break;
        case 2:
            Blur(address);
            break;
        case 3:
            Sharp(address);
            break;
        default:
            cout << "Enter a valid choice.\n";
            break;
    }
}

void colorImage(Mat& address) {
    if (address.empty()) {
        cout << "No image loaded. Please load an image first." << endl;
        return;
    }

    cout << "\n\nChoose one color adjusting option from the following to be applied:\n";
    cout << "1. Adjust Colors\n";
    cout << "2. Adjust Brightness\n";
    cout << "3. Adjust Contrast\n";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            AdjustColor(address);
            break;
        case 2:
            Brightness(address);
            break;
        case 3:
            Contrast(address);
            break;
        default:
            cout << "Enter a valid choice.\n";
            break;
    }
}

void cropImage(Mat& address) {
    if (address.empty()) {
        cout << "No image loaded. Please load an image first." << endl;
        return;
    }

    int startX, startY, width, height;
    cout << "Enter the starting X-coordinate: ";
    cin >> startX;
    cout << "Enter the starting Y-coordinate: ";
    cin >> startY;
    cout << "Enter the width of the ROI (Region of Interest): ";
    cin >> width;
    cout << "Enter the height of the ROI (Region of Interest): ";
    cin >> height;

    if (startX < 0 || startY < 0 || width <= 0 || height <= 0 ||
        startX + width > address.cols || startY + height > address.rows) {
        cout << "Invalid ROI parameters." << endl;
        return;
    }

    address = address(Rect(startX, startY, width, height));
    imshow("Cropped Image", address);
    waitKey(0);
    destroyWindow("Cropped Image");
}

void resizeImage(Mat& address) {
    if (address.empty()) {
        cout << "No image loaded. Please load an image first." << endl;
        return;
    }

    int newWidth, newHeight;
    cout << "Enter the new width: ";
    cin >> newWidth;
    cout << "Enter the new height: ";
    cin >> newHeight;

    resize(address, address, Size(newWidth, newHeight), INTER_LINEAR);
    imshow("Resized Image", address);
    waitKey(0);
    destroyWindow("Resized Image");
}