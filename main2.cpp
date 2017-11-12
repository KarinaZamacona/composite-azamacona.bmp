#include <string>
#include <iostream>
#include <vector>
#include "bitmap.h"

using namespace std;

bool validDimensions(Bitmap image1, Bitmap image2);

void averageImage(vector<Bitmap> imageFiles, Bitmap &avgImage);

int main()
{ 
  string imageName;
  vector<Bitmap>imageFiles;
  Bitmap avgImage;
  int i = 0;
  cout << "Upload a file in the format bmp or select <DONE> if desired images have been selected" << endl;
  while(i<10)
  {
    cin >> imageName;
    if(imageName == "DONE")
    {
      break;
    }
    imageFiles[i].open(imageName);
    if(!imageFiles[i].isImage())
    {
      cout << "Error" << endl;
      imageFiles.pop_back();
    }
    if((validDimensions(imageFiles[0], imageFiles[i])) == false)
    {
      cout << "Error, worng size of image" << endl;
      imageFiles.pop_back();
    }
    i++;
  }
  if(imageFiles.size() < 2)
  {
    cout << "Error, not enough files" << endl;
    return 0;
  }
  avgImage.open(imageName);
  averageImage(imageFiles, avgImage);
  avgImage.save("composite-azamacona.bmp");
  return 0;
}

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
      for(int k=0; bmp2[0].size(); k++)
      {
        rgb1 = bmp1[j][k];
        rgb2 = bmp2[j][k];
        int avg1 = (rgb1.red + rgb1.green + rgb1.blue)/3;
        int avg2 = (rgb2.red + rgb2.green + rgb2.blue)/3;
        int totalAvg = (avg1 + avg2)/2;
        rgb1.red = totalAvg;
        rgb1.green = totalAvg;
        rgb1.blue = totalAvg;
        bmp1[j][k] = rgb1;
      }
    }
    imageFiles[i].fromPixelMatrix(bmp2);
  }
  avgImage.fromPixelMatrix(bmp1);
}
