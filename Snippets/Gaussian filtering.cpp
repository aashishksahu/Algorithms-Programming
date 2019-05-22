#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

class img_proc
{
private:

public:
    cv::Mat smooth_img(const cv::Mat &);
};

cv::Mat img_proc::smooth_img(const cv::Mat &img)
{
    cv::imshow("input", img);

    cv::Mat output;

    cv::GaussianBlur(img, output, cv::Size(3,3), 3,3);

    return output;
}

int main()
{
    cv::Mat input, output;
    cv::namedWindow("output", cv::WINDOW_NORMAL);
    std::string file_path = "/home/aashish/Documents/Projects/test/image.jpg";

    input = cv::imread(file_path);

    img_proc obj;
    output = obj.smooth_img(input);

    cv::imshow("output", output);
    cv::waitKey(0);
}
