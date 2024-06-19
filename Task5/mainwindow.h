#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "Stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int round=1;
    bool started0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void time_sl0_mw();


private slots:
     void on_pb_round_clicked();

private slots:
    void on_pb_t_toggled(bool checked);
    void get_string(QString str);

    void on_pb_ss_toggled(bool checked);

    void on_pb_clear_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch *stw;
QTimer *time_mw;
};
#endif // MAINWINDOW_H
