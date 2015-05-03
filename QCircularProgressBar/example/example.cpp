#include "example.h"

example::example() : QWidget(), m_val1(0), m_val2(0), m_val3(0){

    m_layout = new QHBoxLayout;

    m_progress_1 = new QCircularProgressBar;
    m_progress_1->setFixedSize(150, 150);

    m_progress_2 = new QCircularProgressBar;
    m_progress_2->setFixedSize(100, 100);

    m_progress_3 = new QCircularProgressBar;
    m_progress_3->setBacgroundProgressColor(Qt::red);
    m_progress_3->setProgressColor(Qt::green);
    m_progress_3->setForegroundColor(Qt::blue);
    m_progress_3->setTextColor(Qt::magenta);
    m_progress_3->setBorderColor(Qt::darkBlue);

    m_layout->addWidget(m_progress_1,0,Qt::AlignTop);
    m_layout->addWidget(m_progress_2,0,Qt::AlignTop);
    m_layout->addWidget(m_progress_3);

    this->setStyleSheet("QWidget {background-color: white;}");
    setLayout(m_layout);

    m_timer_1 = new QTimer;
    m_timer_2 = new QTimer;
    m_timer_3 = new QTimer;

    QObject::connect(m_timer_1, SIGNAL(timeout()), this, SLOT(updateProgress1()));
    QObject::connect(m_timer_2, SIGNAL(timeout()), this, SLOT(updateProgress2()));
    QObject::connect(m_timer_3, SIGNAL(timeout()), this, SLOT(updateProgress3()));

    m_timer_1->start(100);
    m_timer_2->start(100);
    m_timer_3->start(100);

}

example::~example(){

    delete m_progress_1;
    delete m_progress_2;
    delete m_progress_3;

    delete m_layout;

    m_timer_1->stop();
    m_timer_2->stop();
    m_timer_3->stop();

    delete m_timer_1;
    delete m_timer_2;
    delete m_timer_3;
}

void example::updateProgress1(){
    m_val1++;
    if(m_val1 > 100)
        m_val1 = 0;

    m_progress_1->setValue(m_val1);
}

void example::updateProgress2(){
    m_val2++;
    if(m_val2 > 100)
        m_val2 = 0;

    m_progress_2->setValue(m_val2);
}

void example::updateProgress3(){
    m_val3++;
    if(m_val3 > 100)
        m_val3 = 0;

    m_progress_3->setValue(m_val3);
}
