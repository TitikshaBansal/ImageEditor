// The main file containing the main loop and user interface.


#include "utilities.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat address;
    int perform = 1;

    while (perform == 1) {
        cout << "\n\nChoose one option from the following:\n";
        cout << "1. Load Image\n";
        cout << "2. Apply filters to image\n";
        cout << "3. Adjust color of Image\n";
        cout << "4. Crop Image\n";
        cout << "5. Resize Image\n";
        cout << "6. Save Image\n";
        cout << "7. EXIT\n";

        int choice;
        cin >> choice;

        switch (choice) {
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
                perform = 0;
                break;
            default:
                cout << "Enter a valid choice.\n";
                break;
        }
    }

    return 0;
}
