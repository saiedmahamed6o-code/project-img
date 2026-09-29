#include <iostream>
#include <string>
#include "Image_Class.h" 

using namespace std;

void applyGrayscale(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            unsigned int avg = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            img(i, j, 0) = avg;
            img(i, j, 1) = avg;
            img(i, j, 2) = avg;
        }
    }
}


void FlippedVertical(Image& img){
    Image flipped(img.width,img.height);
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for(int k=0;k<3;k++){
                flipped(i,img.height-1-j,k)=img(i,j,k);
            }
        }
    }
    img=flipped;
}

void FlippedHorizontally(Image& img){
    Image flipped(img.width,img.height);
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for(int k=0;k<3;k++){
                flipped(img.width-1-i,j,k)=img(i,j,k);
            }
        }
    }
    img=flipped;
}


int main() {
    string filename;
    cout << "Enter image path/filename to load: ";
    cin >> filename;

    Image originalImage(filename);
    Image currentImage=originalImage;
    int choice;
    bool run=true;

    while(run)
        for(int i=0;i<1;i++){
            cout << "\n--- Image Processing Menu ---\n";
            cout << "1. Apply Grayscale Filter\n";
            cout << "2. Apply Black and White Filter\n";
            cout << "3. Apply Invert Image\n";
            cout << "4. Apply Adding a Frame to the Picture\n";
            cout << "5. Apply Flip Image\n";
            cout << "6. Apply Rotate Image\n";
            cout << "7. Apply Darken and Lighten Image\n";
            cout << "8. Apply Resizing Images\n";
            cout << "9. Save Image\n";
            cout << "10. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    currentImage=originalImage;
                    applyGrayscale(currentImage);
                    cout << "Grayscale applied successfully!\n";
                    break;
                case 2:
                    currentImage=originalImage;
                    blackAndWhite(currentImage);
                    cout << "black and white applied successfully!\n";
                    break;
                case 3:
                    currentImage=originalImage;
                    invert(currentImage);
                    cout << "Invert applied successfully!\n";
                    break;
                case 4:
                    currentImage=originalImage;
                    applyFrameFilter(currentImage);
                   break;
                case 5:
                    currentImage=originalImage;
                    int ans;
                    cout<<"1. Apply Flipped Vertical\n";
                    cout<<"2. Apply Flipped Horizontally\n";
                    cout<<"enter choice: ";
                    cin>>ans;
                    cout<<endl;
                    if(ans==1){
                        FlippedVertical(currentImage);
                        cout << "Flipped Vertical applied successfully!\n";
                    }
                    else{
                        FlippedHorizontally(currentImage);
                        cout << "Flipped Horizontally Vertical applied successfully!\n";
                    }
                    break;
                case 6:
                    currentImage=originalImage;
                    int ans2;
                    cout<<"1.Rotate 90\n";
                    cout<<"2.Rotate 180\n";
                    cout<<"3.Rotate 270\n";
                    cout<<"enter choice: ";
                    cin>>ans2;
                    cout<<endl;
                    if(ans2==1){
                        rotated90(currentImage);
                        cout<<"Apply rotated 90 \n";
                    }
                    else if(ans2==2){
                        rotated180(currentImage);
                        cout<<"Apply rotated 180 \n";
                    }
                    else{
                        rotated270(currentImage);
                        cout<<"Apply rotated 270 \n";
                    }
                    break;
                case 7:
                    currentImage=originalImage;
                    int ans3;
                    cout<<"1. Darken image\n";
                    cout<<"2. Lighten image\n";
                    cout<<"enter choice: ";
                    cin>>ans3;
                    cout<<endl;
                    if(ans3==1){
                        Darken(currentImage);
                        cout << "Darken applied successfully!\n";
                    }
                    else{
                        Lighten(currentImage);
                        cout << "Lighten applied successfully!\n";
                    }
                    break;


                //case 8:
                    
                    
                case 9: {
                    string saveName;
                    cout << "Enter filename to save (e.g., output.jpg): ";
                    cin >> saveName;
                    currentImage.saveImage(saveName);
                    cout << "Image saved successfully!\n";
                    break;
                }
                case 10:
                    cout << "Exiting program...\n";
                    run=false;
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
            }
        }

    return 0;
}