#include <string>
#include <iostream>
#include <vector>
#include "bitmap.h"

using namespace std;

//Function Prototypes-  returnType functionName(parameters);  
bool validDimensions(string,int,int); //Prototype 1: create a function that will check if uploaded images are same size as first image       
vector < vector <int> > averageImages(vector < vector < vector <int> > >); //Prototype 2: create a funciton for pixel matrix aka make a 3d vector into a 2d vector

int main()
    {
      int width, length; //variables for rows and columns to create vector
      vector<string>imageFile;
      //vector<string>files;
      Bitmap image;//
      do{
      vector < vector <int> > imageFile;
      cout<<"Upload a file in the format bmp or select 'Done' if desired images have been selected."<<endl;//need at least 2 and <= 10 images
      cin>> imageFile;
      image.open(imageFile)//open the image
         if (image.isImage())
         {
             cout<<"Error"<<endl;
         }
         else
         {
            if (Bitmap.size()==0)
            {
                Bitmap push_back(imageFile)
             }
         } while (imageFile!="Done"|| max<10)
        if( file.size()!=0)
        { image.open(files[0])
          width=image.sice();
          length=image[0].size;
        }
        if(width!=0 && length!=0)
        {
           // for(int i=0; i<file.size(); i++)
            if( (validDimensions(imageFile, width, length)))
            {
                push_back
           // if(!(validDimensions(file[i],width,length)))
           // {//delete invalid dimension images
           // files.erase(files.begin()+i);
            }
            else
            {
            cout<< "Error"<<endl;
            }
            
        }
//      bool valifBmp=true;call function #1// check if the uploaded image is in the correct format
//      int counter=0;//counter for do while loop. cannot exceed 10
//      do {
//          determine size of rows and columns
//          call function 2: returnType fileName(variables) /create a vector of vectors/matrix from images uploaded
//          run through image rows and columns/pixels and change
//          cout new image
//          counter ++;
//          }while(counter is not 10 or cin is not "Done")
//      bool valiBmp=false
//          cout<<"Error";
//    return 0;
//    }

//Create the functions
bool validDimension(string fileName,int width,int length)//checking if the image uploaded is the correct length and width
    {
    Bitmap image;
    int row,col=0;
    image.open(fileName);
        if(image.isImage())
        {
         row=image.size();
         col=image[0].size;
         if(row==width && col==length)
            {
             return True;
             //covert image to pixel matrix (not sure if this is where i would do it?)
             bmp=image.toPixelMatrix();
            }
        }
        return false;
//  {
//  if (run through rows)
//  {
//      if(run through columns)
//      {
//         Pixel
//      }
/
//returnType functionName2 (parameter variables)
//for (int row=0; row<image[0].size;row++) // loop for row
// {
//  for (int column=0; column<imagr[0].size(); column++)//loop for columns
//    {
//      take  average of valid impage pixels
//      add up your valid image pixels and divide by number of pixels
//      cout "image "<<number<<" of "<<total valid images<<" done."
//    }
//  }
//   image.Name(bmp);// final image
//   save your new image// coposite-azamacona.bmp
