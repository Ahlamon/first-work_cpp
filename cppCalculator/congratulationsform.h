#ifndef CONGRATULATIONSFORM_H
#define CONGRATULATIONSFORM_H

#include <QDialog>

namespace Ui {
class CongratulationsForm;
}

class CongratulationsForm : public QDialog
{
    Q_OBJECT

public:
    explicit CongratulationsForm(QWidget *parent = nullptr);
    ~CongratulationsForm();

    void setUserName(const QString &userName);

private slots:
    void on_okButton_clicked();

private:
    Ui::CongratulationsForm *ui;
};

#endif
