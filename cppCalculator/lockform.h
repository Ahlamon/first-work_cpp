#ifndef LOCKFORM_H
#define LOCKFORM_H

#include <QDialog>
class QLineEdit;

class LockForm : public QDialog
{
    Q_OBJECT

public:
    LockForm(QWidget *parent = nullptr);

signals:
    void unlockSuccessful();

private slots:
    void checkPassword();

private:
    QLineEdit *passwordLineEdit;
    QPushButton *okButton;
};

#endif
