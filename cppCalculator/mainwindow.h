
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "ui_mainwindow.h"
#include <cmath>
#include "lockform.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNumberButtonClicked(const QString &number);
    void onOperationButtonClicked(const QString &operation);
    void onEqualsButtonClicked();
    void onTrigonometricButtonClicked(const QString &function);
    double evalExpression(const QString &expression);
    void onDotButtonClicked();
    void onCloseBracketButtonClicked();
    void onOpenBracketButtonClicked();
    void onClearButtonClicked();
    void onSecureEqualsButtonClicked ();
    void showMainWindow();

private:
    QLineEdit *lineEdit;

    QLabel *resultLabel;
    Ui::MainWindow *ui;
    LockForm lockForm;

    void showError(const QString &errorMessage);
};

#endif
