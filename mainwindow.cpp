#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create participant
    dp = new DefaultParticipant(0, "selva");
    // create publisher
    action_cmd_pub = new DDSPublisher(idl_msg::QuadActionCmdPubSubType(),
        "action_cmd", dp->participant());
    // initialize publisher
    action_cmd_pub->init();
}

MainWindow::~MainWindow()
{
    // delete all dynamically allocated instances
    delete action_cmd_pub;
    delete dp;
    delete ui;
}

void MainWindow::on_pB_takeoff_released()
{
    action_cmd.cmd(3);
    action_cmd_pub->publish(action_cmd);    //if pub->init() needed?
    std::cout << "Takeoff cmd sent. \n";   //DEBUG
    // proposal for action_cmd:
    // 0: disarm
    // 1: arm
    // 2: reboot
    // 3: takeoff
    // 4: land
}
void MainWindow::on_pB_flightControls_released()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pB_status_released()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pB_arm_released()
{
    action_cmd.cmd(1);
    action_cmd_pub->publish(action_cmd);
    std::cout << "Arm cmd sent. \n";
}


void MainWindow::on_pB_disarm_released()
{
    action_cmd.cmd(0);
    action_cmd_pub->publish(action_cmd);
    std::cout << "Disarm cmd sent. \n";
}


void MainWindow::on_pB_land_released()
{
    action_cmd.cmd(4);
    action_cmd_pub->publish(action_cmd);
    std::cout << "Land cmd sent. \n";
}

