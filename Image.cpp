#include<bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// functions to perform tasks
string loadImage(){
    string str;
    getline(cin, str);
    Mat img = imread("path/to/image", IMREAD_COLOR);

    // Error handling: Check if the image was loaded successfully
    if (img.empty()) {
        cout << "Image file not found or couldn't be loaded." << endl;
        return "";
    }

    // Show the image inside a window with the specified name
    imshow("Display window", img);

    // Wait for a keystroke in the window
    waitKey(0);

    return str;
}
void filterImage(string address){
    
}
void colorImage(string address){
    
}
void cropImage(string address){
    
}
void resizeImage(string address){
    
}
void saveImage(string address){
    
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

        string address;

        //Calling functions according to the choice made.
        switch (choice){
            case 1:
                address = loadImage();
                break;
            case 2:
                filterImage(address);
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