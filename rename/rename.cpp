//
// Created by tr on 7/16/19.
//

//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include<stdio.h>
//using namespace std;
//using namespace cv;
//int main()
//{
//    Mat outImage;
//    String src_imagePath="/home/tr/Documents/practice/rgb/";
//    String out_imagePath= src_imagePath+"out/";
//    char newName[10];
//    vector<string> filenames;
//    cv::glob(src_imagePath, filenames);
//    cout<<"image_path.size: "<<filenames.size()<<endl;
//    return 0;
//}
#include <iostream>
#include <opencv2/opencv.hpp>
#include<stdio.h>

using namespace std;
using namespace cv;

int main()
{
    Mat outImage;
    String src_path =  "/home/tr/Documents/practice/rgb/";
    String newName_path = src_path + "output/";
    char newName[10];
    vector<string> filenames;
    glob(src_path, filenames, false);
    cout << "filenames.size:" << filenames.size() << endl;
    for(int i = 0; i < filenames.size(); i++)
    {
        String ImgName = filenames[i];
        if(ImgName.find(".png") != String::npos)
        {
            outImage = imread(ImgName,CV_LOAD_IMAGE_UNCHANGED);

            sprintf(newName, "%04d.png", i);
            imwrite(newName_path+newName, outImage);
            cout << newName_path+newName << endl;
        }
        else
        {
            cout << "NOT A PNG IMAGE" << endl;
        }
    }
    return 0;
}