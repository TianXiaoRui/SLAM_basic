/****************************
 * 题目：现有一个运动着的相机拍摄的连续两张图片，其中特征点匹配部分已经完成。
 * 请根据两帧图像对应的匹配点计算基础矩阵，并利用该矩阵绘制出前10个特征点对应的极线。
 *
* 本程序学习目标：
 * 理解掌握对极约束的原理
 * 熟悉OpenCV编程
 *
 * 公众号：计算机视觉life。发布于公众号旗下知识星球：从零开始学习SLAM
 * 时间：2018.11
****************************/
#include<iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>

using namespace std;
using namespace cv;
int main( int argc, char** argv ) {

    Mat rgb1 = imread("../rgb1.ppm");
    Mat rgb2 = imread("../rgb2.ppm");

//    Ptr<FeatureDetector> detector;
//    Ptr<DescriptorExtractor> descriptor;
//
//    detector = FeatureDetector::create("ORB");
//    descriptor = DescriptorExtractor::create("ORB");

    Ptr<ORB> orb = ORB::create();
    vector<KeyPoint> kp1, kp2;
//    detector->detect( rgb1, kp1 );
//    detector->detect( rgb2, kp2 );
    orb->detect(rgb1, kp1);
    orb->detect(rgb2, kp2);

    // 计算描述子
    Mat desp1, desp2;
//    descriptor->compute( rgb1, kp1, desp1 );
//    descriptor->compute( rgb2, kp2, desp2 );
    orb->compute(rgb1, kp1, desp1);
    orb->compute(rgb2, kp2, desp2);

    // 匹配描述子
    vector<DMatch> matches;
    BFMatcher matcher;
    matcher.match(desp1, desp2, matches);
    cout << "Find total " << matches.size() << " matches." << endl;

    // 筛选匹配对
    vector<DMatch> goodMatches;
    double minDis = 9999;
    for (size_t i = 0; i < matches.size(); i++) {
        if (matches[i].distance < minDis)
            minDis = matches[i].distance;
    }

    for (size_t i = 0; i < matches.size(); i++) {
        if (matches[i].distance < 10 * minDis)
            goodMatches.push_back(matches[i]);
    }


    vector<Point2f> pts1, pts2;
    for (size_t i = 0; i < goodMatches.size(); i++) {
        pts1.push_back(kp1[goodMatches[i].queryIdx].pt);
        pts2.push_back(kp2[goodMatches[i].trainIdx].pt);
    }

    // 请先计算基础矩阵并据此绘制出前10个匹配点对应的对极线，可以调用opencv函数
    // ----------- 开始你的代码 --------------//
    Mat fundamental_matrix = findFundamentalMat(pts1, pts2, CV_FM_8POINT);
    cout<<fundamental_matrix<<endl;
   /**因为之后有循环十次，所以需要创建一个容器vector来保存每次得到的ｅｐｉｌｉｎｅ,创建容器后，访问其中的元素需要两个索引，第一个索引为ｉ代表
    * 第ｉ个元素，之后的epiline[0]...分别代表　直线的a b c　三个变量。
    * std::vector<cv::Vec<float,3>> epilines1, epilines2;
    */
    std::vector<cv::Vec3f> epilines1, epilines2;
    cv::computeCorrespondEpilines(pts1, 1, fundamental_matrix, epilines1);
    cv::computeCorrespondEpilines(pts2, 2, fundamental_matrix, epilines2);
    cv::RNG &rng = theRNG();
    for (int i = 0; i < 10; ++i)
    {
        Scalar color = Scalar(rng(255),rng(255),rng(255));
        circle(rgb1,pts1[i],5,color,3);
        /**
         * 两点法确定直线
         * 注意到ｅpiline2是第二幅图在第一幅图上的极线，因此在绘制第一幅图像上的极线时，需要使用epiline2的参数
         *
         */
    cv::line(rgb1,cv::Point(0,-epilines2[i][2]/epilines2[i][1]),cv::Point(-epilines2[i][2]/epilines2[i][0]),color);
       // cv::line(rgb1,cv::Point(0,-epilines2[i][2]/epilines2[i][1]),cv::Point(rgb1.cols,-(epilines2[i][2] + epilines2[i][0] * rgb1.cols)/epilines2[i][1]),color);

        circle(rgb2,pts2[i],5,color,3);
        cv::line(rgb2,cv::Point(0,-epilines1[i][2]/epilines1[i][1]),cv::Point(rgb2.cols,-(epilines1[i][2] + epilines1[i][0] * rgb2.cols)/epilines1[i][1]),color);
    }
    // ----------- 结束你的代码 --------------//
    imshow("img1", rgb1);
    imshow("img2", rgb2);

//    if( rgb1.size() == rgb2.size() && rgb1.type() == rgb2.type())
//    {
//        Mat result(Size(rgb1.cols * 2, rgb1.rows),rgb1.type(),Scalar(0));
//        result(Rect(0,0,rgb1.cols,rgb1.rows)) += rgb1;
//        result(Rect(rgb1.cols,0,rgb1.cols,rgb1.rows)) += rgb2;
//        imwrite("./re.png",result);
//        imshow("re",result);
//    }

    waitKey(0);
    return 0;
}
