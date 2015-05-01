#ifndef QCIRCULARPROGRESSBAR_H
#define QCIRCULARPROGRESSBAR_H

#include <QWidget>

class QCircularProgressBar : public QWidget
{
    Q_OBJECT

public:
    QCircularProgressBar(QWidget *parent = 0);
    ~QCircularProgressBar();
};

#endif // QCIRCULARPROGRESSBAR_H
