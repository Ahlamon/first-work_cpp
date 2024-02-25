#include "lockform.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

LockForm::LockForm(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Enter password:", this);
    layout->addWidget(label);

    QLineEdit *passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordInput);

    QPushButton *unlockButton = new QPushButton("Unlock", this);
    layout->addWidget(unlockButton);

    connect(unlockButton, &QPushButton::clicked, this, &LockForm::checkPassword);
}

void LockForm::checkPassword() {
    QString password = passwordLineEdit->text();
    if (password == "1488") {
        emit unlockSuccessful();
        accept();
    } else {
        QMessageBox::critical(this, "Error", "Invalid password");
    }
}
