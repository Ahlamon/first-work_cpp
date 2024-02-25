#include "congratulationsform.h"
#include "ui_congratulationsform.h"

CongratulationsForm::CongratulationsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CongratulationsForm)
{
    ui->setupUi(this);
}

CongratulationsForm::~CongratulationsForm()
{
    delete ui;
}

void CongratulationsForm::setUserName(const QString &userName)
{
    ui->label->setText(tr("Вітаю! цією працею я забов’язаний, %1, дякую!!").arg(userName));
}

void CongratulationsForm::on_okButton_clicked()
{

    close();
}
