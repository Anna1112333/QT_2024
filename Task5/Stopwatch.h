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
QString return_funk0();
QString time_now0="00:00:00";  //круг
    ~Stopwatch();
int  time1=0,  time21=0;
bool ag1=false;
int ret_time1=0, ret_time2=0, ret_time21=0;

void SendSignal_string(bool);
void to_me_label();
QString time_string(int);

void Nooling();
public slots:
void time_sl();

signals:
void sig_to_mw_label(QString);//+++++

public:

QTimer  *time0;
};
#endif // STOPWATCH_H
