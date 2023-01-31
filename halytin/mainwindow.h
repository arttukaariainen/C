#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum states
{
    configuring,     //when user is setting clock and other parameters
    notArmed,        //when user is inside and can either configure or arm the system
    armed,           //when waiting for door to open
    goingToAlarm,    //when door has opened and timer is running for uset PIN input
    alarm            //when timeout or incorrect PIN
};

enum events
{
    programStart,       //Program started
    configure,          //User enters configuration info from GUI
    storeConfig,        //User stores config and doneConfiguring signal is emitted
    doneConfiguring,    //User stores cinfiguration
    armTheSystem,       //User initiates armed system
    startMonitoring,    //User gives monitoring command
    userGaveCorrectPin, //User gives correct PIN
    userGaveWrongPin,   //User gives wrong PIN
    pinCorrect,         //User gives 4 digit pin and it's correct
    doorOpened,         //The door that system monitors is opened
    startAlarmTimer,    //Door opened and time to start timer
    timerExpires,       //15 second timer expires
    startAlarm          //Timer expires and alarm signal is sent
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void runStateMachine(states, events);
    void handleTimeout();

signals:
    void doneConfiguring_signal(states, events);
    void pinCorrect_signal(states, events);
    void startMonitoring_signal(states, events);
    void startAlarmTimer_signal(states, events);
    void startAlarm_signal(states, events);

private slots:
    void on_programStart_clicked();

    void on_configure_clicked();

    void on_storeConfig_clicked();

    void on_armTheSystem_clicked();

    void on_doorOpened_clicked();

    void on_userGaveCorrectPin_clicked();

    void on_userGaveWrongPin_clicked();

private:
    Ui::MainWindow *ui;
    states State = configuring;
    events Event;
    QTimer timer;

    void configuringHandler(events e);
    void notArmedHandler(events e);
    void armedHandler(events e);
    void alarmHandler(events e);
    void goingToAlarmHandler(events e);
};
#endif // MAINWINDOW_H
