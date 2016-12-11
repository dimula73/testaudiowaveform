#ifndef KISWAVEFORMGENERATOR_H
#define KISWAVEFORMGENERATOR_H

#include <QScopedPointer>

class QSize;
class QImage;

class KisWaveformGenerator
{
public:
    KisWaveformGenerator(const QString &fileName, const QSize &imageSize);
    ~KisWaveformGenerator();

    /**
     * @brief setInterestRange set the range of the audio, for which the
     *        waveform should be generated
     * @param start beginning of the range (in ms)
     * @param end end of the range (in ms)
     */
    void setInterestRange(qint64 start, qint64 end);

    /**
     * @brief fetchWaveformImage fetches the waveform image form the internal cache
     * @return the waveform image of the size passed to the constructor
     */
    QImage fetchWaveformImage() const;

private:
    struct Private;
    QScopedPointer<Private> m_d;
};

#endif // KISWAVEFORMGENERATOR_H
