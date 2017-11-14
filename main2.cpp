#include <string>
#include <iostream>
#include <vector>
#include "bitmap.h"

using namespace std;

//FUNCTION PROTOTYPES
bool validDimensions(Bitmap image1, Bitmap image2);//checks that all following images are the same dimensions as the first valid file

void averageImage(vector<Bitmap> imageFiles, Bitmap &avgImage);// 



//INT MAIN CALLS THE FUNCTION
int main()
{ 
  Bitmap image;
  string imageName;
  vector<Bitmap>imageFiles;//creating a vector of bitmap images
  Bitmap avgImage;
  int i = 0;
  int inVector;
  cout << "Upload a file in the format bmp or select <DONE> if desired images have been selected" << endl;
  while(i<10)
  {
    cin >> imageName;
    i++;
    if(imageName == "DONE")
    {
      break;//exit while loop/ stop asking for files after DONE has been selected
    }
    //imageFiles[i].open();

    image.open(imageName); //opens image file
    imageFiles.push_back(image); // creating a spot in the vector for the image being opened
    if(!imageFiles[inVector].isImage()) 
    {
      cout << "Error" << endl;
      imageFiles.pop_back();
    }
    else if((validDimensions(imageFiles[0], imageFiles[inVector])) == false)
    {
      cout << "Error, worng size of image" << endl;
      imageFiles.pop_back();
    }
    else
    {
        inVector ++;
    }
  }
  if(imageFiles.size() < 2)
  {
    cout << "Error, not enough files" << endl;
    return 0;
  }
  averageImage(imageFiles, avgImage);
  avgImage.save("composite-azamacona.bmp");
  return 0;
}



//DEFINING THE FUNCTIONS

bool validDimensions(Bitmap image1, Bitmap image2)
{
  vector< vector <Pixel> > bmp1;
  vector< vector <Pixel> > bmp2;
  bmp1 = image1.toPixelMatrix();
  bmp2 = image2.toPixelMatrix();
  int width1 = bmp1.size();
  int length1 = bmp1[0].size();
  int width2 = bmp2.size();
  int length2 = bmp2[0].size();
  if(width1 != width2)
  {
    if(length1 != length2)
    {
      return false;
    }
  }
  return true;
}




/*{
Bitmap image;
image.open(imageFiles);
  Pixel rgb1;
vector< vector<Pixel> > AvgImg;
AvgImg=image.toPixelMatrix();
//bmp=image.toPixelMatrix();
vector<Bitmap>imageFiles;
vector< vector < vector < Pixel > > >all;
imageFiles.toPixelMatrix();
 for (int i=0; i<imageFiles.size(); i++); //loop through each pixel
 {
    
    for(int j=0; j<image[0].size();j++) <//loop through each image
    {
     AvgImg.red=avgred;
     AvgImg.blue=avgblue;
     AvgImg.green=avggreen;*/
/* Avg.Img[rows][cols].red=avgred;
 Avg.Img[rows][cols].blue=avgblue;
 Avg.Img[rows][cols].green=avggreen;
    }
  NumImg
  Avg.Img[rows][cols].red=avgred;
  Avg.Img[rows][cols].blue=avgblue;
  Avg.Img[rows][cols].green=avggreen;
}*/

/*
Bitmap image;
v<v<p>>bmp
bmp=imagetoPixelMatrix()
________________________
v(bitmap>imageFiles
v<v<V<p>>>all;
loop through each B in imageFiles
    get PixelMatrix of current Bitmap
    push PixelMatrix onto all;
*/


/* vector< vector<Pixel> > AvgImg;
  for (int i=0; i<imageFiles.size(); i++); //loop through each pixel
 {
int avgred, avgblue, avggreen;
 for(int j=0; j <//loop through each image
 {

 }NumImg;
 AvgImg.red=avgred;
 AvgImg.blue=avgblue;
 AvgImg.green=avggreen;
 Avg.Img[rows][cols].red=avgred
*/
void averageImage(vector<Bitmap> imageFiles, Bitmap &avgImage)

{ 
 vector< vector <Pixel> > bmp1;
 vector< vector <Pixel> > bmp2;
  Pixel rgb1;
  bmp1 = avgImage.toPixelMatrix();
  for(int i=0; i < imageFiles.size(); i++)
  {
    Pixel rgb2;
    bmp2 = imageFiles[i].toPixelMatrix();
    for(int j=0; bmp2.size(); j++)
    {
      for(int k=0; bmp2[i].size(); k++)
      {
        rgb1 = bmp1[j][k];
        rgb2 = bmp2[j][k];
        int avg1 =  (rgb1.red + rgb1.green + rgb1.blue)/3;
        int avg2 = (rgb2.red + rgb2.green + rgb2.blue)/3;
        int totalAvg = (avg1 + avg2)/2;
        rgb1.red = totalAvg;
        rgb1.green = totalAvg;
        rgb1.blue = totalAvg;
        bmp1[j][k] = rgb1;
      }
    }
}
imageFiles[i].fromPixelMatrix(bmp2);
  }
  avgImage.fromPixelMatrix(bmp1);
}
