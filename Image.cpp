#include<bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// functions to perform tasks
Mat loadImage(){
    string str;
    cout<< "Enter the path to  your image.\n";
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
    
}
void colorImage(Mat& address){
    
}
void cropImage(Mat& address){
    
}
void resizeImage(Mat& address){
    
}
void saveImage(Mat& address){
    cout<< "Enter the location where you want your edited image to be saved. \n example: path/to/save/MyImage.jpg\n ";
    string str;
    getline(cin,str);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
    while(perform=1){
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