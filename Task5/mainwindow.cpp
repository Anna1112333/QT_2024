    #include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QListWidgetItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stw = new Stopwatch(this);
    this->setWindowTitle("Таймер кругов");
    ui->pb_ss->toggle();
    ui->pb_ss->setCheckable(true);
    ui->pb_round->setDisabled(true);
    ui->tbr->setText("Начало");
    bool started0=false;
    time_mw=new QTimer(this);
    time_mw->setInterval(1);
    startTimer(1000);
    connect (time_mw, &QTimer::timeout, this, &MainWindow::time_sl0_mw);

connect(stw, &Stopwatch::sig_to_mw_label
        , this, &MainWindow::get_string);   //параметры не пишутся
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_t_toggled(bool checked)
{
    if(ui->pb_t->isChecked())
        ui->tbr->setStyleSheet("color: white; background-color: rgb(50,100,100)");
    else
        ui->tbr->setStyleSheet("background-color: white");
}

void MainWindow::time_sl0_mw()
{
   ui->lb_time->setText("Время: "+stw->return_funk0());
}



void MainWindow::get_string(QString str)
{
   ui->tbr->append("Круг "+QString::number(round)+" время "+str);
   round++;
}

void MainWindow::on_pb_ss_toggled(bool agv1)
{

    if(agv1 && started0==false)
    {started0=true;
    time_mw->start();}
    else {time_mw->stop();
    started0=false;}   
    if(agv1)
    {      
        ui->pb_ss->setText("стоп");
        stw->Stopwatch::SendSignal_string(agv1);
    }
    else
    {
        stw->Stopwatch::SendSignal_string(agv1);
        ui->pb_ss->setText("продолжить");}
}

void MainWindow::on_pb_clear_clicked()
{   started0=false;
    time_mw->stop();
    ui->lb_time->setText("Время");
    ui->pb_ss->setText("старт");
    stw->Nooling();
    round=1;
}

void MainWindow::on_pb_round_clicked()
{
stw->to_me_label();
}



