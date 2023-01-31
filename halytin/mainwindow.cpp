#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    State = configuring;
    Event = programStart;

    runStateMachine(State, Event);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::runStateMachine(states s, events e)
{
    switch (s) {
        case configuring:
            configuringHandler(e);
        break;

        case notArmed:
            notArmedHandler(e);
        break;

        case armed:
            armedHandler(e);
        break;

        case goingToAlarm:
            goingToAlarmHandler(e);
        break;

        case alarm:
            alarmHandler(e);
        break;

        default:
            qDebug()<<"State = "<<State<<" and event ="<< e;
    }
}

void MainWindow::handleTimeout()
{
    State = goingToAlarm;
    Event = timerExpires;
    runStateMachine(State, Event);
}


void MainWindow::configuringHandler(events e)
{
    qDebug()<<"State = "<<State<<" and event = "<< e;
    if(e == programStart)
    {
        State = configuring;
        qDebug()<<"Entered to configure state";
        ui->label->setText("Entry to CONFIGURING state");
    }
    else if(e == configure)
    {
        //just staying in this state
        qDebug()<<"Staying at configuring state";
        ui->label->setText("Staying at CONFIGURING state!");
    }
    else if(e == storeConfig)
    {
        qDebug()<<"Exiting from configuring state, emitting doneConfiguring";
        State = notArmed;
        Event = doneConfiguring;
        emit doneConfiguring_signal(State, Event);
        //runStateMachine(State, Event);
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<"Event = "<< e;
    }
}

void MainWindow::notArmedHandler(events e)
{

    if(e == armTheSystem)
    {
        qDebug()<<"Exiting from notArmed State emitting startMonitoring signal";
        ui->label->setText("Changing to ARMED state");
        State = armed;
        Event = startMonitoring;
        emit startMonitoring_signal(State, Event);
        //runStateMachine(State, Event);
    }
    else if(e == doneConfiguring)
    {
        qDebug()<<"Entering to notArmed State";
        ui->label->setText("Entry NOTARMED state with pinCorrect");
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" = "<< e;
    }
}

void MainWindow::armedHandler(events e)
{
    if(e ==startMonitoring)
    {
        qDebug()<<"Entering to Armed State";
        ui->label->setText("Entry to ARMED State");
    }
    else if(e == userGaveCorrectPin)
    {
        qDebug()<<"User gave correct pin in ARMED state";
        ui->label->setText("Entering to NOTARMED state");
        State = notArmed;
        Event = pinCorrect;
        emit pinCorrect_signal(State, Event);
        //runStateMachine(State, Event);
    }
    else if(e == userGaveWrongPin)
    {
        qDebug()<<"Staying at Armed State, userGaveWrongPin";
        ui->label->setText("Staing at ARMED State!");
    }
    else if(e == doorOpened)
    {
        qDebug()<<"Going to goingToAlarm, doorOpened";
        ui->label->setText("Going to GOINGTOALARM State!");
        State = goingToAlarm;
        Event = startAlarmTimer;
        emit startAlarmTimer_signal(State, Event);
        //runStateMachine(State, Event);
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<< e;
    }
}

void MainWindow::goingToAlarmHandler(events e)
{
    if(e == startAlarmTimer)
    {
        qDebug()<<"Entering to GOINGTOALARM state";
        ui->label->setText("Entry to GOINGTOALARM state!");
        timer.start(5000);
    }
    else if(e == userGaveCorrectPin)
    {
        qDebug()<<"userGaveCorrectPin in GOINGTOALARM state";
        ui->label->setText("Entering to NOTARMED State!");
        timer.stop();
        State = notArmed;
        Event = pinCorrect;
        emit pinCorrect_signal(State, Event);
    }
    else if(e == timerExpires)
    {
        timer.stop();
        qDebug()<<"TimerExpires in GOINGTOALARM state!";
        ui->label->setText("Going to ALARM state!");
        State = alarm;
        Event = startAlarm;
        emit startAlarm_signal(State, Event);
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<< e;
    }
}

void MainWindow::alarmHandler(events e)
{
    if(e == startAlarm)
    {
        qDebug()<<"Entering to ALARM State";
        ui->label->setText("Entry to ALARM state!");
    }
    else if(e == userGaveCorrectPin)
    {
        qDebug()<<"UserGaveCorrectPin in ALARM state";
        ui->label->setText("Entering to NOTARMED state!");
        State = notArmed;
        Event = pinCorrect;
        emit pinCorrect_signal(State, Event);
    }
    else
    {
        qDebug()<<"Wrong event int this state = "<<State<<" Event = "<< e;
    }

}


/*
    CLick Handlers
*/

void MainWindow::on_storeConfig_clicked()
{
    //State = configuring;
    //Event = storeConfig;
    runStateMachine(State, storeConfig);
}
void MainWindow::on_configure_clicked()
{
    State = configuring;
    Event = configure;
    runStateMachine(State, Event);
}

void MainWindow::on_doorOpened_clicked()
{
    //State should alreary be ARMED
    Event = doorOpened;
    runStateMachine(State, Event);
}

void MainWindow::on_armTheSystem_clicked()
{
    //State = notArmed;
    Event = armTheSystem;
    runStateMachine(State, Event);
}

void MainWindow::on_userGaveCorrectPin_clicked()
{
    //State can be either Armed, goingToAlarm or Alarm
    Event = userGaveCorrectPin;
    runStateMachine(State, Event);
}


void MainWindow::on_userGaveWrongPin_clicked()
{
    //State = armed; This way WrongPin can be given at any state
    Event = userGaveCorrectPin;
    runStateMachine(State, Event);
}

void MainWindow::on_programStart_clicked()
{
    State = configuring;
    Event = configure;
    runStateMachine(State, Event);
}















