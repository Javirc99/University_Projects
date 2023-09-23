#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
    // Load an image from file
    cv::Mat image = cv::imread("/home/javier/Downloads/uav.png");

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cout << "Error: Could not open or find the image!" << std::endl;
        return -1;
    }

    // Create a window to display the image
    cv::namedWindow("Image", cv::WINDOW_NORMAL);

    // Display the image
    cv::imshow("Image", image);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    // Close the image window
    cv::destroyWindow("Image");

    return 0;
}
