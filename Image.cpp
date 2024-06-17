#include<bits/stdc++.h>
using namespace std;

// functions to perform tasks
void loadImage(){

}
void displayImage(){
    
}
void filterImage(){
    
}
void colorImage(){
    
}
void cropImage(){
    
}
void resizeImage(){
    
}
void saveImage(){
    
}
int main(){
    int perform=1;
    while(perform=1){
        // Displaying use all the functions available.
        cout<<"\n \n Choose one option from the following:\n";
        cout<<"1. Load Image.\n";
        cout<<"2. Display Image.\n";
        cout<<"3. Apply filters to image.\n";
        cout<<"4. Adjust color of Image.\n";
        cout<<"5. Crop Image.\n";
        cout<<"6. Resize Image\n";
        cout<<"7. Save Image\n";
        cout<<"8. EXIT\n";

        // taking choice input from user.
        int choice;
        cin>> choice;

        //Calling functions according to the choice made.
        switch (choice){
            case 1:
                loadImage();
                break;
            case 2:
                displayImage();
                break;
            case 3:
                filterImage();
                break;
            case 4:
                colorImage();
                break;
            case 5:
                cropImage();
                break;
            case 6:
                resizeImage();
                break;
            case 7:
                saveImage();
                break;
            case 8:
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