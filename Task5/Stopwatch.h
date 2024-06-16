#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QTime>

class Stopwatch: public QObject
{
    Q_OBJECT
public:
explicit Stopwatch(QObject *parent = nullptr);
QString return_funk();
QString return_funk0();
QString time_now="00:00:00";  //стоп-старт
QString time_now0="00:00:00";  //круг
    ~Stopwatch();
int  time1_2=0, time1=0, time2=0, time21=0;
bool ag1=false, ag2=false, diff=false;

void SendSignal_string(bool, bool); //Передать строку обычным методом

void Nooling();
public slots:
void time_sl();

signals:
void sig_to_mw_label(QString);//+++++

public:
QTimer *time, *time0;

};
#endif // STOPWATCH_H
