#include "Stopwatch.h"
#include "mainwindow.h"
Stopwatch::Stopwatch(QObject* parent):QObject{parent}
{
time0=new QTimer(this);
startTimer(1000);
time0->setInterval(1);
connect (time0, &QTimer::timeout, this, &Stopwatch::time_sl);
}

void Stopwatch::Nooling(){
   time21=0; ret_time1=0; ret_time2=0; ret_time21=0;
}

QString Stopwatch::return_funk0()
{
    return time_now0;
}


Stopwatch::~Stopwatch()
{
    qDebug()<<"Деструктор Stopwatch. ";
}

QString Stopwatch::time_string(int t){
    int a, b, c, d;
    QString s;
    a=t%1000; //milliseconds
    b=t/1000%60; //seconds
    c=t/60000%60; //minutes
    d=t/3600000%60; //hours
    s=(QString::number(d)+" "
                  +QString::number(c)+" "
                  +QString::number(b)+" "
                  +QString::number(a)+" ");
    return s;
}


void Stopwatch::time_sl()
{
    if(ag1==true) time21++;   //старт  нажата
time_now0=time_string(time21);
}


void Stopwatch::SendSignal_string(bool agv1)
{ag1=agv1;
    if(agv1) time0->start();
}

void Stopwatch::to_me_label()
{
        ret_time1=ret_time2; ret_time2=time21;
        ret_time21=ret_time2-ret_time1;//}

    QString str=time_string(ret_time21);
   QString str1=time_string(ret_time1);
   QString str2=time_string(ret_time2);
 qDebug()<<"diff======"<<str1<<"   "<<str2;
    emit sig_to_mw_label(str);
}

