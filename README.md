# testaudiowaveform

TestAudioWaveform is a test application for generating a waveform image from a particular audio file

## How to build

1. mkdir ../build
2. cd ../build
3. cmake ../testaudiowaveform
4. make -j2
5. wget https://ia600402.us.archive.org/29/items/MLKDream/MLKDream_64kb.mp3
6. ./TestAudioWaveform
7. Check the result in 'result.png'

## What need to be done

1. We need a waveform like described in http://manual.audacityteam.org/man/audacity_waveform.html
2. That is peaks + RMS
3. The waveform is generated in `KisWaveformGenertor` on any state change and cache in an internal structure. The result is returned by `fetchWaveformImage()` call.
4. `KisWaveformGenerator` handles any kind of wave data format, like int, float and etc.
5. The waveform is normalized by the maximum value of the provided waveform

