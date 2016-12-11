#include "KisWaveformGenerator.h"

#include <QAudioDecoder>

#include <QSize>
#include <QImage>

// Desired waveform: http://manual.audacityteam.org/man/audacity_waveform.html


struct KisWaveformGenerator::Private
{
    QSize imageSize;
    QAudioDecoder audioDecoder;
};

KisWaveformGenerator::KisWaveformGenerator(const QString &fileName, const QSize &imageSize)
    : m_d(new Private)
{
    m_d->imageSize = imageSize;
    m_d->audioDecoder.setSourceFilename(fileName);
}

KisWaveformGenerator::~KisWaveformGenerator()
{
}

void KisWaveformGenerator::setInterestRange(qint64 start, qint64 end)
{

}

QImage KisWaveformGenerator::fetchWaveformImage() const
{
    return QImage();
}
