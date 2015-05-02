#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTimer>

#include "source/QCircularProgressBar.h"

class example : public QWidget
{
    Q_OBJECT

public:
    example();
    ~example();

private:
    QHBoxLayout *m_layout;

    QCircularProgressBar *m_progress_1;
    QCircularProgressBar *m_progress_2;
    QCircularProgressBar *m_progress_3;

    QTimer *m_timer_1;
    QTimer *m_timer_2;
    QTimer *m_timer_3;

    int m_val1, m_val2, m_val3;

private slots:
    void updateProgress1();
    void updateProgress2();
    void updateProgress3();

};

#endif // EXAMPLE_H
