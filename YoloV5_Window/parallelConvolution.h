#pragma once

#ifndef PARALLEL_CONVLUTION_H
#define PARALLEL_CONVLUTION_H


#include <opencv2/core.hpp>


using namespace cv;

/**

    @class   parallelConvolution
    @brief   ���о������˳���������١�
    @details ~

**/
class parallelConvolution :
    public ParallelLoopBody
{
private:
    Mat m_src, &m_dst;
    Mat m_kernel;
    int sz;

public:
    parallelConvolution(Mat src, Mat& dst, Mat kernel);

    virtual void operator()(const Range& range) const CV_OVERRIDE;
};

#endif