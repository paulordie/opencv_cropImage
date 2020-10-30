#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
    int i = 0;
    const static cv::Scalar colors[] =  { CV_RGB(0,0,255),
                                      CV_RGB(0,128,255),
                                      CV_RGB(0,255,255),
                                      CV_RGB(0,255,0),
                                      CV_RGB(255,128,0),
                                      CV_RGB(255,255,0),
                                      CV_RGB(255,0,0),
                                      CV_RGB(255,0,255)} ;
    cv::Scalar color = colors[i%8];
    /* Set Region of Interest DTU*/

//    cv::Rect roiDtu(11,179,280,160);
    cv::Rect roiDtu(60,260,745,415);
//    cv::Rect roiDtu_bench(343,179,280,160);
    cv::Rect roiDtu_bench(1100,260,730,415);
//    std::string image_path = cv::samples::findFile("/home/pcorrea/Documents/projetos/TPV-OrionPax/cropImage/fotos-ftaS/479.14_5_27_10_2020_10_20_45.jpg");
    cv::Mat imgDtu = cv::imread("/home/pcorrea/Documents/projetos/TPV-OrionPax/cropImage/saved.jpg");
    cv::Mat imgBench = imgDtu.clone();

    cv::Mat imgRect = imgDtu.clone();



    if (imgBench.empty()){
        std::cout << "Erro image benchmark" << std::endl;
    }
    cv::imshow("benchmark", imgBench);

    if (imgDtu.empty())
    {
        std::cout << "!!! imread() failed to open target image" << std::endl;
    }

    cv::imshow("img full", imgDtu);



    cv::Mat cropDtu = imgDtu(roiDtu);
//    cv::rectangle(cropDtu, roiDtu, color, 3, 8, 0);
    cv::imshow("Image DTU", cropDtu);

    cv::Mat cropBench = imgBench(roiDtu_bench);
    cv::imshow("Image BenchMark", cropBench);

//    cv::rectangle(imgRect, cvPoint(cvRound(60), cvRound(260)), cvPoint(cvRound(745), cvRound(430)),
//                  color, 3, 8, 0);

    cv::imshow("image with rectangle",imgRect);
    cv::waitKey(0);
    //remove("/home/pcorrea/Documents/projetos/TPV-OrionPax/cropImage/fotos-fta/479.14_5_27_10_2020_10_20_45.jpg");
    remove("noises_cropped.jpg");

    cv::imwrite("noises_cropped.jpg", cropDtu);

    return 0;
}