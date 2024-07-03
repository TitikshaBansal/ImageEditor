// The main file containing the main loop and user interface.


#include "utilities.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat address;        // Holds the image data
    int perform = 1;    // Controls the main loop

    while (perform == 1) {
        // Display menu options to the user
        cout << "\n\nChoose one option from the following:\n";
        cout << "1. Load Image\n";
        cout << "2. Apply filters to image\n";
        cout << "3. Adjust color of Image\n";
        cout << "4. Crop Image\n";
        cout << "5. Resize Image\n";
        cout << "6. Save Image\n";
        cout << "7. EXIT\n";

        int choice;
        cin >> choice;  // Read user choice

        switch (choice) {
            case 1:
                address = loadImage();  // Load an image
                break;
            case 2:
                FilterImage(address);   // Apply filters to the image
                break;
            case 3:
                colorImage(address);    // Adjust color of the image
                break;
            case 4:
                cropImage(address);     // Crop the image
                break;
            case 5:
                resizeImage(address);   // Resize the image
                break;
            case 6:
                saveImage(address);     // Save the modified image
                break;
            case 7:
                perform = 0;            // Exit the program
                break;
            default:
                cout << "Enter a valid choice.\n";
                break;
        }
    }

    return 0;
}
