#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTimer>
#include <KisSyncedAudioPlayback.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>

boost::random::mt19937 rng;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_currentTime(0)
{
    ui->setupUi(this);
    m_playback.reset(new KisSyncedAudioPlayback("../TestAudioPlayback/01_01_Boytsy.mp3"));

    connect(ui->dblSpeed, SIGNAL(valueChanged(qreal)), m_playback.data(), SLOT(setSpeed(qreal)));

    m_timer = new QTimer(this);
    m_timer->setInterval(500);

    connect(m_timer, SIGNAL(timeout()), SLOT(slotTimerTimeout()));

    m_timer->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimerTimeout()
{
    boost::random::normal_distribution<qreal> norm(500, 50);

    const int newValue = norm(rng);
    m_currentTime += newValue;

    qDebug() << "offset" << newValue;

    m_playback->syncWithVideo(m_currentTime);
}
