// Copyright (c) 2012-2020 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef THREADENTROPY_H
#define THREADENTROPY_H

#include <QObject>
#include "../../binary.h"

class ThreadEntropy : public QObject
{
    Q_OBJECT
public:
    explicit ThreadEntropy(QObject *parent=nullptr);
    void setData(Binary *_binary,unsigned int nOffset,unsigned int nSize,double *pXEntropy,double *pYEntropy,double *pXHistogram,double *pYHistogram,int nPunkts);

    bool isCompleted();
    double getEntropy(unsigned int nDataOffset,unsigned int nDataSize,bool nProgressBar=true);
    void getHistogram(unsigned int nDataOffset,unsigned int nDataSize,double *pX,bool bProgressBar=true);

signals:
    void setProgressBar(int nMax,int nValue);
    void setEntropy(double dEntropy);
    void reloadGraph();
    void _finished();

public slots:
    void process();
    void _stop();

private:
    Binary *_binary;
    unsigned int nOffset;
    unsigned int nSize;
    bool bIsRun;
    bool bIsCompleted;
    double *pXEntropy;
    double *pYEntropy;
    double *pXHistogram;
    double *pYHistogram;
    int nPunkts;
};

#endif // THREADENTROPY_H
