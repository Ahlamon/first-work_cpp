#include <QApplication>
#include "mainwindow.h"
#include "congratulationsform.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    CongratulationsForm congratsForm;
    congratsForm.setUserName("Валентин Валерійович");
    congratsForm.exec();

    return a.exec();
}
