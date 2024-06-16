#include "Stopwatch.h"

Stopwatch::Stopwatch(QObject* parent):QObject{parent}
{

time0=new QTimer(this);
time = new QTimer(this);
time->setInterval(1);
startTimer(1000);
time0->setInterval(1);
connect (time0, &QTimer::timeout, this, &Stopwatch::time_sl);
connect (time, &QTimer::timeout, this, &Stopwatch::time_sl);
}

void Stopwatch::Nooling(){
   time1_2=0; time1=0; time2=0; time21=0;
}
/*
QString Stopwatch::return_funk0()
{
    return time_now0;
}
QString Stopwatch::return_funk()
{
   return time_now;
}*/
QString Stopwatch::return_funk()
{
if(ag2=true)
    return time_now0;
else
   return time_now;
}

Stopwatch::~Stopwatch()
{
    qDebug()<<"Деструктор Stopwatch. ";
}

void Stopwatch::time_sl()
{  if(ag1==true) {time21++; time1++;}   //стоп не нажата
    int t=time1;
    QString s;
    if(ag2==true) t=time21; else t=time1;
    qDebug()<<"diff="<<diff<<"   "<<time1;
        int a, b, c, d;
        a=t%1000; //milliseconds
        b=t/1000%60; //seconds
        c=t/60000%60; //minutes
        d=t/3600000%60; //hours
        s=(QString::number(d)+" "
                      +QString::number(c)+" "
                      +QString::number(b)+" "
                      +QString::number(a)+" ");
    if(ag2==true) time_now0=s; else {time_now=s;
    }
 //qDebug()<<"RRRR"<<time_now0; //выводит
}


void Stopwatch::SendSignal_string(bool agv1, bool agv2)
{

    if(agv1) {time0->start();
    ag1=true;}
    else {time0->stop(); ag1=false;
        }
    if(agv2) { ag2=true;}
   // else {time->stop(); ag2=false; time1=0; //круг
    else {if (diff==false){time1_2=time21; time1=time1_2-time2; diff=true;}
        else {time2=time21; time1=time2-time1_2; diff=false;} //круг
        ag2=false;}
//qDebug()<<"diff="<<ag2<<"   "<<time1;
}
