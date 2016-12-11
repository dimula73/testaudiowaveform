#include "mainwindow.h"
#include <QApplication>

#include "KisWaveformGenerator.h"

int main(int argc, char *argv[])
{
    // please download a test file and put into you build directory
    // https://ia600402.us.archive.org/29/items/MLKDream/MLKDream_64kb.mp3

    KisWaveformGenerator generator("MLKDream_64kb.mp3", QSize(1200, 80));
    generator.setInterestRange(1000, 60000);
    QImage result = generator.fetchWaveformImage();
    result.save("result.png");

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
}
