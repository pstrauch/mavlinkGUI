#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QuadActionCmdPubSubTypes.h"
#include "default_participant.h"
#include "default_publisher.h"
#include "quadcopter_msgs/msgs/QuadActionCmd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_takeoff_released();

    void on_pB_flightControls_released();

    void on_pB_status_released();

    void on_pB_arm_released();

    void on_pB_disarm_released();

    void on_pB_land_released();

private:
    Ui::MainWindow *ui;

    DefaultParticipant* dp;
    DDSPublisher* action_cmd_pub;
    idl_msg::QuadActionCmd action_cmd;

};
#endif // MAINWINDOW_H
