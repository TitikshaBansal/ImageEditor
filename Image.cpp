#include<bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

// functions for more specific tasks.
void Gray(Mat& address){
    cvtColor(address, address, COLOR_BGR2GRAY);
    imshow("Grayscale Image", address);
    waitKey(0);
}
void Blur(Mat& address){
    // Take input for kernel size (blur intensity)
    int kernelSize;
    cout << "Enter the kernel size (odd value): ";
    cin >> kernelSize;

    // Apply Gaussian blur
    GaussianBlur(address, address, Size(kernelSize, kernelSize), 0);

    // Display the blurred image
    imshow("Blurred Image", address);
    waitKey(0);
}
void Sharp(Mat& address){
    double sharpenFactor;
    std::cout << "Enter sharpening factor (0.0 to 1.0): ";
    std::cin >> sharpenFactor;

    // Gaussian blur
    Mat blurred;
    GaussianBlur(address, blurred, Size(0, 0), 25);

    addWeighted(address, 1.0 + sharpenFactor, blurred, -sharpenFactor, 0, address);

    // Display results
    imshow("Sharpened", address);
    waitKey(0);
}
void AdjustColor(Mat& address){
    // Create a palette (user-defined color)
    Mat palette(256, 1, CV_8UC3);
    
    int r, g, b;
    cout << "Enter RGB values for the desired color (0-255): ";
    cin >> r >> g >> b;
    for (int i = 0; i < 256; ++i) {
        palette.at<Vec3b>(i, 0) = Vec3b(b, g, r);  // BGR order
    }

    // Convert the colored image to grayscale
    Mat grayImage;
    cvtColor(address, grayImage, COLOR_BGR2GRAY);

    // Create a lookup table (LUT) based on the palette
    Mat lut;
    merge(&palette, 3, lut);

    // Apply the LUT to the grayscale image
    LUT(grayImage, lut, address);

    // Display results
    imshow("Color Adjusted", address);
    waitKey(0);

}
void Brightness(Mat& address){
    
}
void Contrast(Mat& address){
    
}

// functions to perform tasks
Mat loadImage(){
    string str;
    cout<< "Enter the path to  your image.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);
    Mat img = imread(str, IMREAD_COLOR);

    // Error handling: Check if the image was loaded successfully
    if (img.empty()) {
        cout << "Image file not found or couldn't be loaded." << endl;
    }

    // Show the image inside a window with the specified name
    imshow("Display window", img);

    // Wait for a keystroke in the window
    waitKey(0);

    return img;
}
void FilterImage(Mat& address){
    cout<<"\n \n Choose one filter option from the following to be applied:\n";
    cout<<"1. Gray Scale\n";
    cout<<"2. Blur\n";
    cout<<"3. Sharpen\n";

    int choice;
    cin>> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    //Calling functions according to the choice made.
    switch (choice){
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
            cout<<"Enter a valid choice.\n";
            break;
        }   
}
void colorImage(Mat& address){
    cout<<"\n \n Choose one color adjusting option from the following to be applied:\n";
    cout<<"1. Colors\n";
    cout<<"2. Brightness\n";
    cout<<"3. Contrast\n";

    int choice;
    cin>> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    //Calling functions according to the choice made.
    switch (choice){
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
            cout<<"Enter a valid choice.\n";
            break;
        }
}
void cropImage(Mat& address){
    int startX, startY, width, height;
    cout << "Enter the starting X-coordinate: ";
    cin >> startX;
    cout << "Enter the starting Y-coordinate: ";
    cin >> startY;
    cout << "Enter the width of the ROI (Region of Interest): ";
    cin >> width;
    cout << "Enter the height of the ROI (Region of Interest): ";
    cin >> height;

    // Crop the image
    address = address(Rect(startX, startY, width, height));
}
void resizeImage(Mat& address){
    int newWidth, newHeight;
    cout << "Enter the new width: ";
    cin >> newWidth;
    cout << "Enter the new height: ";
    cin >> newHeight;

    // Resize the image
    resize(address, address, Size(newWidth, newHeight), INTER_LINEAR);
}
void saveImage(Mat& address){
    cout<< "Enter the location where you want your edited image to be saved. \n example: path/to/save/MyImage.jpg\n ";
    string str;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,str);

    bool check = imwrite(str, address);

    if (check) {
        cout << "Successfully saved the modified image." << endl;
    } else {
        cout << "Failed to save the image." << endl;
    }

    // Display the modified image
    imshow("Modified Image", address);
    waitKey(0);

    return ;
    
}
int main(){
    int perform=1;
    while(perform == 1){
        // Displaying use all the functions available.
        // Each of these functions perform their task and display the image in the end.
        cout<<"\n \n Choose one option from the following:\n";
        cout<<"1. Load Image.\n";
        cout<<"2. Apply filters to image.\n";
        cout<<"3. Adjust color of Image.\n";
        cout<<"4. Crop Image.\n";
        cout<<"5. Resize Image\n";
        cout<<"6. Save Image\n";
        cout<<"7. EXIT\n";

        // taking choice input from user.
        int choice;
        cin>> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Mat address;

        //Calling functions according to the choice made.
        switch (choice){
            case 1:
                address = loadImage();
                break;
            case 2:
                FilterImage(address);
                break;
            case 3:
                colorImage(address);
                break;
            case 4:
                cropImage(address);
                break;
            case 5:
                resizeImage(address);
                break;
            case 6:
                saveImage(address);
                break;
            case 7:
                // this will break the loop and exit the code.
                perform=0;
                break;
            default:
                cout<<"Enter a valid choice.\n";
                break;
        }

    }
    return 0;
}