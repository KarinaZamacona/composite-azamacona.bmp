#include <string>
#include <iostream>
#include <vector>
#include "bitmap.h"

using namespace std;

//FUNCTION PROTOTYPES
bool validDimensions(Bitmap image1, Bitmap image2);//checks that all following images are the same dimensions as the first valid file

//void averageImage(vector<Bitmap> imageFiles, Bitmap &avgImage);// 
vector<int>Avg(vector <vector <Pixel> > all);


//INT MAIN CALLS THE FUNCTION
int main()
{ 
        Bitmap image;
        string imageName;
        vector<Bitmap>imageFiles;//creating a vector of bitmap images
        Bitmap avgImage;
        int i = 0;
        int inVector;
        invector=0;
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
        vector < vector <Pixel> >bmp;
        vector <string> imageFiles;
        vector < vector < int > > all;
        vector < int > temp;
        Pixel bmp;
        for (int i=0; i < imageFiles.size() ; i++)
        {
                bmp=image[i].toPixelMatrix;
                temp=Avg(bmp);
                all.push_back(temp);
                cout<<"File "<<i+1<<" of "<<imageFiles.size()<<" is done."<<endl;
        }
        int columnSum;
        for(int row=0; row<all.size();row++)
        {
                for(int column=0; column<all[0].size(); column++)
                {
                        columnSum=columbSum + all[row][column]
                }
                total.push_back( columnSum/all.size() );
        }
        bmp=imageFiles[0].toPixelMatrix();
        int counter=0;
        
        for(int j=0; j<bmp.size();j++)
        {
        for(int k=0; k<bmp[0].size(); c++)
        {
        rgb=bmp[j][k];
        rgb.red=total[counter];
        rgb.blue=total[counter];
        rgb.green=total[counter];
        bmp[j][k]=rgb;
        counter++;
        }
        }


        averageImage(imageFiles, avgImage);
        bmp.save("composite-azamacona.bmp");
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

vector<int> Avg (vector <vector <pixel> >all)
{
        Pixel rgb;
        vector<int>columnSum;
        int total;
        for(int row=0; row<all.size(); row++)
        {
                for(int column=0; column<all[0].size(); column++)
                {
                        rgb=all[row][column];
                        total+=all[row][column];
                }
                columnSum.push_back( total/all.size() )
        }
        return columnSum;

