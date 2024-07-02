#include <iostream>
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
    destroyWindow("Grayscale Image");
}
void Blur(Mat& address){
    // Take input for kernel size (blur intensity)
    int kernelSize;
    cout << "Enter the kernel size (odd value): ";
    cin >> kernelSize;
    if (kernelSize % 2 == 0) {
        cout << "Kernel size must be an odd value. Please try again." << endl;
        return;
    }

    // Apply Gaussian blur
    GaussianBlur(address, address, Size(kernelSize, kernelSize), 0);

    // Display the blurred image
    imshow("Blurred Image", address);
    waitKey(0);
    destroyWindow("Blurred Image");
}
void Sharp(Mat& address){
    double sharpenFactor;
    cout << "Enter sharpening factor (0.0 to 1.0): ";
    cin >> sharpenFactor;

    // Gaussian blur
    Mat blurred;
    GaussianBlur(address, blurred, Size(0, 0), 25);
    addWeighted(address, 1.0 + sharpenFactor, blurred, -sharpenFactor, 0, address);

    // Display results
    imshow("Sharpened", address);
    waitKey(0);
    destroyWindow("Sharpened");
}
void AdjustColor(Mat& address){
    // Create a palette (user-defined color)
    int r, g, b;
    cout << "Enter RGB values for the desired color (0-255): ";
    cin >> r >> g >> b;

    Mat lut(1, 256, CV_8UC3);
    for (int i = 0; i < 256; ++i) {
        lut.at<Vec3b>(i) = Vec3b(b, g, r);  // BGR order
    }

    // Convert the colored image to grayscale
    Mat grayImage;
    cvtColor(address, grayImage, COLOR_BGR2GRAY);

    // Create a lookup table (LUT) based on the palette
    Mat colorImage;
    LUT(grayImage, lut, colorImage);

    address = colorImage.clone();
    imshow("Color Adjusted", address);
    waitKey(0);
    destroyWindow("Color Adjusted");

}
void Brightness(Mat& address){
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
void Contrast(Mat& address){
    double alpha;
    cout << "Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;

    address.convertTo(address, -1, alpha, 0);

    imshow("Contrast Adjusted", address);
    waitKey(0);
    destroyWindow("Contrast Adjusted");
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
    else{
        // Show the image inside a window with the specified name
        imshow("Display window", img);
        // Wait for a keystroke in the window
        waitKey(0);
        destroyWindow("Display window");
    }

    return img;
}
void FilterImage(Mat& address){
    cout<<"\n \n Choose one filter option from the following to be applied:\n";
    cout<<"1. Gray Scale\n";
    cout<<"2. Blur\n";
    cout<<"3. Sharpen\n";

    int choice;
    cin>> choice;

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
    if (address.empty()) {
        cout << "No image loaded. Please load an image first." << endl;
        return;
    }
    cout<<"\n \n Choose one color adjusting option from the following to be applied:\n";
    cout<<"1. Colors\n";
    cout<<"2. Brightness\n";
    cout<<"3. Contrast\n";

    int choice;
    cin>> choice;

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
    // Crop the image
    address = address(Rect(startX, startY, width, height));
    imshow("Cropped Image", address);
    waitKey(0);
    destroyWindow("Cropped Image");
}
void resizeImage(Mat& address){
    if (address.empty()) {
        cout << "No image loaded. Please load an image first." << endl;
        return;
    }
    int newWidth, newHeight;
    cout << "Enter the new width: ";
    cin >> newWidth;
    cout << "Enter the new height: ";
    cin >> newHeight;

    // Resize the image
    resize(address, address, Size(newWidth, newHeight), INTER_LINEAR);
    imshow("Resized Image", address);
    waitKey(0);
    destroyWindow("Resized Image");
}
void saveImage(Mat& address){
    if (address.empty()) {
        cout << "No image loaded. Please load an image first." << endl;
        return;
    }
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
    destroyWindow("Modified Image");
    return ;
    
}
int main(){
    Mat address;
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