#include "KisSyncedAudioPlayback.h"

#include <QtMultimedia/QAudioDecoder>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QMediaPlayer>
#include <QFileInfo>

struct KisSyncedAudioPlayback::Private
{
    QMediaPlayer player;
    qint64 tolerance = 40;
};


KisSyncedAudioPlayback::KisSyncedAudioPlayback(const QString &fileName)
    : QObject(0),
      m_d(new Private)
{
    QFileInfo fileInfo(fileName);
    Q_ASSERT(fileInfo.exists());
    qDebug() << "Ex:" <<fileInfo.exists();

    m_d->player.setMedia(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
    m_d->player.setVolume(50);
    m_d->player.play();
}

KisSyncedAudioPlayback::~KisSyncedAudioPlayback()
{
}

void KisSyncedAudioPlayback::setSoundOffsetTolerance(qint64 value)
{
    m_d->tolerance = value;
}

void KisSyncedAudioPlayback::syncWithVideo(qint64 position)
{
    if (qAbs(position - m_d->player.position()) > m_d->tolerance) {
        m_d->player.setPosition(position);
    }
}

void KisSyncedAudioPlayback::setSpeed(qreal value)
{
    const qint64 oldPosition = m_d->player.position();

    m_d->player.stop();
    m_d->player.setPlaybackRate(value);
    m_d->player.setPosition(oldPosition);
    m_d->player.play();
}

void KisSyncedAudioPlayback::play(qint64 startPosition)
{
    m_d->player.setPosition(startPosition);
    m_d->player.play();
}

void KisSyncedAudioPlayback::stop()
{
    m_d->player.stop();
}
