#include<stdio.h>
#include<opencv2/opencv.hpp>

int main(int argc ,char **argv){
    //ここから改善していくよ
    //ここを修正しました
    if(argc != 2){
        printf("usage:build/test1.exe <Image Path>\n");
        return -1;
    }

    cv::Mat im_in = cv:: imread(argv[1],0);
    if(!im_in.data){
        printf("No data\n");
        return -1;
    }

    int height = im_in.rows;
    int width = im_in.cols;
    printf("height = %d\n",height);
    printf("width = %d\n",width);

    //--------------Image Processing----------

    cv::Mat im_out =im_in.clone();

    int i,j;

    for( j = 0 ; j < height ; j++){
        for( i = 0 ; i < width ; i++){
            im_out.at<uchar>(j,i) = im_in.at<uchar>(height-1-j,width-1-i);
        }
    }



    cv::namedWindow("Image/practice/test1.bmp", cv::WINDOW_AUTOSIZE );
    imshow("Image/practice/test1.bmp", im_out );
    cv::imwrite( "Image/practice/test1.bmp", im_out );
    cv::waitKey(0);



    return 0;
}