// أقسم بالله أن هذا الكود من عمل الفريق 100٪ بلا نسخ من اي مصدر أو تخليق ب Ai
// Alsayed Mahamed Mahmoud Ahmed - 20250087 - filter-> 1,5
// Youssef Adel Hussein Mohamed  - 20250774 - filter-> 2,6
// Youssef Mohamed Abdul Hafeez  - 20250789 - filter-> 3,7
// Ahmad Hany Ibrahim Akrab      - 20250800 - filter-> 4,8


#include <iostream>
#include <string>
#include "Image_Class.h" 

using namespace std;

//filter 1
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

//filter 2
void blackAndWhite(Image& img){
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            unsigned int avg = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            if(avg >=127){
                img(i, j, 0) = 255;
                img(i, j, 1) = 255;
                img(i, j, 2) = 255;
            }
            else{
                img(i, j, 0) = 0;
                img(i, j, 1) = 0;
                img(i, j, 2) = 0;
            }
        }
    }
}

//filter 3
void invert(Image& img){
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for(int k=0;k<3;k++){
                img(i,j,k)=255-img(i,j,k);
            }
        }
    }
}

//filter 4
void applyFrameFilter(Image& img,int r,int g,int b) {
	
	int borderWidth = 15;


	for (int i = 0; i < img.height; ++i) {
		for (int j = 0; j < img.width; ++j) {

			
			if (i < borderWidth || i >= img.height - borderWidth ||
				j < borderWidth || j >= img.width - borderWidth) {

				img(j, i, 0) = r;
				img(j, i, 1) = g;
				img(j, i, 2) = b;
			}
		}
	}
}

//filter 5
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

//filter 5
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

//filter 6
void rotated90(Image& img){
    Image rotated(img.height,img.width);
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for(int k=0;k<3;k++){
                rotated(img.height-1-j,i,k)=img(i,j,k);
            }
        }
    }
    img=rotated;
}

//filter 6
void rotated180(Image& img){
    rotated90(img);
    rotated90(img);
}

//filter 6
void rotated270(Image& img){
    rotated90(img);
    rotated90(img);
    rotated90(img);
}

//filter 7
void Darken(Image& img){
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for(int k=0;k<3;k++){
                img(i,j,k)=img(i,j,k) * 0.5;
            }
        }
    }
}

//filter 7
void Lighten(Image& img){
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for(int k=0;k<3;k++){
                int val=255-img(i,j,k);
                img(i,j,k)=img(i,j,k) +(val/2);
            }
        }
    }
}

//filter 8
Image  resizeImage(const Image& oldImg, int newWidth, int newHeight) {
    Image newImg(newWidth, newHeight);

    float scaleX = (float)oldImg.width / newWidth;
    float scaleY = (float)oldImg.height / newHeight;

    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            
            int oldX = i * scaleX;
            int oldY = j * scaleY;

            for (int k = 0; k < 3; ++k) {
                newImg(i, j, k) = oldImg(oldX, oldY, k);
            }
        }
    }return newImg;
}

//filter 9
void Merge (Image& img1 , Image& img2){
    
    int minW=min(img1.width , img2.width);
    int minH=min(img1.height , img2.height);
    Image newMerge(minW , minH);
    for (int i = 0; i < minW; ++i) {
        for (int j = 0; j < minH; ++j) {
            for(int k=0;k<3;k++){
                newMerge(i,j,k)=(img1(i,j,k) + img2(i,j,k) ) /2;
            }
        }
    }
    img1=newMerge;
}

//filter 10
void Detect(Image& img){
    blackAndWhite(img);
    Image DetectImg(img.width, img.height);
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for(int k=0; k<3; k++){
                if(i == 0 || j == 0 || i == img.width - 1 || j == img.height - 1){
                    DetectImg(i,j,k) = 255;
                }
                else{
                    int count = abs(img(i-1,j-1,k) - img(i,j,k));
                    if(count > 20){
                        DetectImg(i,j,k) = 0;
                    }
                    else{
                        DetectImg(i,j,k) = 255;
                    }
                }
            }
        }
    }
    img = DetectImg;
}

//filter 11
void cropImage(Image& img, int startX, int startY, int targetW, int targetH) {
    Image cropped(targetW, targetH);

    for (int i = 0; i < targetW; ++i) {
        for (int j = 0; j < targetH; ++j) {
            for (int k = 0; k < 3; ++k) {
                cropped(i, j, k) = img(startX + i, startY + j, k);
            }
        }
    }

    img = cropped;
}

//filter 12
void horizontal_blur(Image& current_image, int radius) {

    for (int j = 0; j < current_image.height; j++) {
        for (int i = 0; i < current_image.width; i++) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;
            
            for (int k= -radius; k <= radius; k++){
                int x = i + k;
                if (x >= 0 && x < current_image.width) {
                    sumR += current_image(x, j, 0);
                    sumG += current_image(x, j, 1);
                    sumB += current_image(x, j, 2);
                    count++;
                }
            }
            current_image(i, j, 0) = sumR / count;
            current_image(i, j, 1) = sumG / count;
            current_image(i, j, 2) = sumB / count;
        }
    }

}

void vertical_blur(Image& current_image, int radius) {

    for (int j = 0; j < current_image.height; j++) {
        for (int i = 0; i < current_image.width; i++) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;
            
            for (int l= -radius; l <= radius; l++){
                int y = j + l;
                if (y >= 0 && y < current_image.height) {
                    sumR += current_image(i, y, 0);
                    sumG += current_image(i, y, 1);
                    sumB += current_image(i, y, 2);
                    count++;
                }
            }
            current_image(i, j, 0) = sumR / count;
            current_image(i, j, 1) = sumG / count;
            current_image(i, j, 2) = sumB / count;
        }
    }

}

void blur_image(Image& current_image,int radius) {


    vertical_blur(current_image, radius);
    horizontal_blur(current_image, radius);

}

//filter 13 
void sunlight(Image& img){
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
                // increse red
                int r=(img(i,j,0) +45);
                // red + green =dark yellow
                int g=(img(i,j,1) +35);
                int b=img(i,j,2) -30;
                img(i,j,0)=min(max(r,0),255);
                img(i,j,1)=min(max(g,0),255);
                img(i,j,2)=min(max(b,0),255);
        }
    }
}

//filter 14
void applyOldTVEffect(Image& image) {
    for (int j = 0; j < image.height; ++j) {
        for (int i = 0; i < image.width; ++i) {
            for (int c = 0; c < 3; ++c) {
                int color = image(i, j, c);

                if (j % 2 == 0) {
                    color = color * 0.6;
                }

                image(i, j, c) = color;
            }
        }
    }
}

// filter 15
void applyPurpleFilter(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int r = img(i, j, 0) * 1.2;

            int g = img(i, j, 1) * 0.1;

            int b = img(i, j, 2) * 1.2;

            img(i, j, 0) = min(255,r);
            img(i, j, 1) = min(255,g);
            img(i, j, 2) = min(255,b);
        }
    }
}

/*  Filter 16____"Infrared Photography"  */ 

void Xray(Image& image) {
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            image(j, i, 0) = 255; 

            image(j, i, 1) = 255 - image(j, i, 1);

            image(j, i, 2) = 255 - image(j, i, 2);
        }
    }
}


int main() {
    string filename;
    cout << "Enter image file name to load: ";
    cin >> filename;

    Image originalImage(filename);
    Image currentImage=originalImage;
    int choice;
    bool run=true;

    while(run)
        for(int i=0;i<1;i++){
            cout << "\n--- Image Processing Menu ---\n";
            cout << "1 . Apply Grayscale Filter\n";
            cout << "2 . Apply Black and White Filter\n";
            cout << "3 . Apply Invert Image\n";
            cout << "4 . Apply Adding a Frame to the Picture\n";
            cout << "5 . Apply Flip Image\n";
            cout << "6 . Apply Rotate Image\n";
            cout << "7 . Apply Darken and Lighten Image\n";
            cout << "8 . Apply Resizing Images\n";
            cout << "9 . Apply Merge Images\n";
            cout << "10. Apply Detect Images\n";
            cout << "11. Apply cropped Images\n";
            cout << "12. Apply Blur Images\n";
            cout << "13. Apply sunlight Images\n";
            cout << "14. Apply Old TV Effect Images\n";
            cout << "15. Apply Purple Filter Images\n";
            cout << "16. Apply X-Ray Images\n";
            cout << "17. Save Image\n";
            cout << "18. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:{
                    currentImage.loadNewImage(filename);
                    applyGrayscale(currentImage);
                    cout << "Grayscale applied successfully!\n";
                    break;
                }
                case 2:{
                    currentImage.loadNewImage(filename);
                    blackAndWhite(currentImage);
                    cout << "black and white applied successfully!\n";
                    break;
                }
                case 3:{
                    currentImage.loadNewImage(filename);
                    invert(currentImage);
                    cout << "Invert applied successfully!\n";
                    break;
                }
                case 4:{
                    currentImage.loadNewImage(filename);
                    int r, g, b;
                    cout << "Enter frame color RGB values (0 to 255):\n";
                    cout << "Red: ";
                    cin >> r;
                    if( !(r>=0 && r<=255) ){
                        cout<<"input error\n";
                        break;
                    }
                    cout << "Green: ";
                    cin >> g;
                    if( !(g>=0 && g<=255) ){
                        cout<<"input error\n";
                        break;
                    }
                    cout << "Blue: ";
                    cin >> b;
                    if( !(b>=0 && b<=255) ){
                        cout<<"input error\n";
                        break;
                    }
                    applyFrameFilter(currentImage,r,g,b);
                   break;
                }
                case 5:{
                    currentImage.loadNewImage(filename);
                    int ans;
                    cout<<"1. Apply Flipped Vertical\n";
                    cout<<"2. Apply Flipped Horizontally\n";
                    cout<<"enter choice: ";
                    cin>>ans;
                    cout<<endl;
                    if(ans==1){
                        FlippedVertical(currentImage);
                        cout << "Flipped Vertical applied successfully!\n";
                        break;
                    }
                    else if(ans==2){
                        FlippedHorizontally(currentImage);
                        cout << "Flipped Horizontally Vertical applied successfully!\n";
                        break;
                    }
                    else{
                        cout<<"input error.\n";
                        break;
                    }
                }
                case 6:{
                    currentImage.loadNewImage(filename);
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
                    else if(ans2==3){
                        rotated270(currentImage);
                        cout<<"Apply rotated 270 \n";
                    }
                    else{
                        cout<<"input error\n";
                        break;
                    }
                    cout<<"rotated applied successfully!\n";
                    break;
                }
                case 7:{
                    currentImage.loadNewImage(filename);
                    int ans3;
                    cout<<"1. Darken image\n";
                    cout<<"2. Lighten image\n";
                    cout<<"enter choice: ";
                    cin>>ans3;
                    cout<<endl;
                    if(ans3==1){
                        Darken(currentImage);
                        cout << "Darken applied successfully!\n";
                        break;
                    }
                    else if(ans3==2){
                        Lighten(currentImage);
                        cout << "Lighten applied successfully!\n";
                        break;
                    }
                    else{
                        cout<<"input error.\n";
                        break;
                    }
                }

                case 8:{
                    currentImage.loadNewImage(filename);
                    int newWidth, newHeight;
                    cout << "Enter new width: ";
                    cin >> newWidth;
                    if( !(newWidth>0) ){
                        cout<<"input error.\n";
                        break;
                    }
                    cout << "\nEnter new height: ";
                    cin >> newHeight;
                    if( !(newHeight>0) ){
                        cout<<"input error.\n";
                        break;
                    }
                    cout<<endl;
                    currentImage = resizeImage(currentImage, newWidth, newHeight);
                    cout<<"resize applied successfully!\n";
                    break;
                }

                case 9:{
                    currentImage=originalImage;
                    string filename2;
                    cout<<"Enter image 2 file name to load: ";
                    cin>>filename2;
                    cout<<endl;
                    Image img2(filename2);
                    Merge(currentImage,img2);
                    cout<<"Merge applied successfully!\n";
                    break;
                    
                }
                case 10:{
                    currentImage=originalImage;
                    Detect(currentImage);
                    cout << "Image Detect successfully!\n";
                    break;
                }

                case 11: {
                    currentImage=originalImage;
                    int x, y, w, h;

                    cout << "Enter the starting X coordinate (upper left X): ";
                    cin >> x;

                    cout << "Enter the starting Y coordinate (upper left Y): ";
                    cin >> y;

                    cout << "Enter the target Width to crop to: ";
                    cin >> w;

                    cout << "Enter the target Height to crop to: ";
                    cin >> h;

                    if (x < 0 || y < 0 || w <= 0 || h <= 0 || (x + w) > currentImage.width || (y + h) > currentImage.height) {
                        cout << "Error: Crop area is out of bounds!\n";
                    }
                    else {
                        cropImage(currentImage, x, y, w, h);
                        cout << "Image cropped successfully!\n";
                    }
                    break;
                }

                case 12:{
                    currentImage=originalImage;
                    int r;
                    cout<<"enter radius: ";
                    cin>>r;
                    cout<<endl;
                    blur_image(currentImage,r);
                    cout << "Image Blur successfully!\n";
                    break;
                }

                case 13:{
                    currentImage=originalImage;
                    sunlight(currentImage);
                    cout<<"sunlight applied successfully!\n";
                    break;
                }

                case 14:{
                    currentImage=originalImage;
                    applyOldTVEffect(currentImage);
                    cout<<"apply Old TV Effect applied successfully!\n";
                    break;
                }

                case 15:{
                    currentImage=originalImage;
                    applyPurpleFilter(currentImage);
                    cout<<"apply Purple Filter applied successfully!\n";
                    break;
                }

                case 16:{
                    currentImage=originalImage;
                    Xray(currentImage);
                    cout<<"X-Ray applied successfully!\n";
                    break;
                }
                    
                case 17:{
                    string saveName;
                    cout << "Enter filename to save (e.g., output.jpg): ";
                    cin >> saveName;
                    currentImage.saveImage(saveName);
                    cout << "Image saved successfully!\n";
                    break;
                }
                case 18:{
                    cout << "Exiting program...\n";
                    run=false;
                    break;
                }
                default:{
                    cout << "Invalid choice! Try again.\n";
                }
            }
        }

    return 0;
}