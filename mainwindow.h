#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QTimer;
class KisSyncedAudioPlayback;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private Q_SLOTS:
    void slotTimerTimeout();

private:
    Ui::MainWindow *ui;
    QScopedPointer<KisSyncedAudioPlayback> m_playback;
    QTimer *m_timer;
    int m_currentTime;
};

#endif // MAINWINDOW_H
