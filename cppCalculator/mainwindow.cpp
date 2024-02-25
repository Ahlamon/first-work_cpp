
#include <QInputDialog>
#include "mainwindow.h"
#include "congratulationsform.h"

#include "ui_mainwindow.h"
#include "lockform.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QJSEngine>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lineEdit = ui->lineEdit;

    connect(&lockForm, &LockForm::unlockSuccessful, this, &MainWindow::showMainWindow);

    connect(ui->pushButton_5, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("1"); });
    connect(ui->pushButton_6, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("2"); });
    connect(ui->pushButton_7, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("3"); });
    connect(ui->pushButton_8, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("4"); });
    connect(ui->pushButton_9, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("5"); });
    connect(ui->pushButton_10, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("6"); });
    connect(ui->pushButton_11, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("7"); });
    connect(ui->pushButton_12, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("8"); });
    connect(ui->pushButton_13, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("9"); });
    connect(ui->pushButton_15, &QPushButton::clicked, this, [this](){ onNumberButtonClicked("0"); });

    connect(ui->pushButton_Divide, &QPushButton::clicked, this, [this](){ onOperationButtonClicked("/"); });
    connect(ui->pushButton_Multiply, &QPushButton::clicked, this, [this](){ onOperationButtonClicked("*"); });
    connect(ui->pushButton_Subtract, &QPushButton::clicked, this, [this](){ onOperationButtonClicked("-"); });
    connect(ui->pushButton_Add, &QPushButton::clicked, this, [this](){ onOperationButtonClicked("+"); });
    connect(ui->pushButton_Equals, &QPushButton::clicked, this, &MainWindow::onEqualsButtonClicked);

    connect(ui->pushButton_Sin, &QPushButton::clicked, this, [this](){ onTrigonometricButtonClicked("sin"); });
    connect(ui->pushButton_Cos, &QPushButton::clicked, this, [this](){ onTrigonometricButtonClicked("cos"); });
    connect(ui->pushButton_Tan, &QPushButton::clicked, this, [this](){ onTrigonometricButtonClicked("tan"); });
    connect(ui->pushButton_Dot, &QPushButton::clicked, this, &MainWindow::onDotButtonClicked);
    connect(ui->pushButton_Clear, &QPushButton::clicked, this, &MainWindow::onClearButtonClicked);
    connect(ui->openBracketButton, &QPushButton::clicked, this, &MainWindow::onOpenBracketButtonClicked);
    connect(ui->closeBracketButton, &QPushButton::clicked, this, &MainWindow::onCloseBracketButtonClicked);

    resultLabel = ui->resultLabel;
    onSecureEqualsButtonClicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMainWindow()
{
    this->show();
}
void MainWindow::onSecureEqualsButtonClicked()
{
    bool ok;
    QString password = QInputDialog::getText(this, tr("Password"), tr("Enter password:"), QLineEdit::Password, QString(), &ok);

    if (ok) {
        if (password == "1488") {
            QString expression = lineEdit->text();
            try {
                double result = evalExpression(expression);
                lineEdit->setText(QString::number(result));

                CongratulationsForm congratsForm;
                congratsForm.setUserName("Валентин Валерійович"); // Замените на имя пользователя
                congratsForm.exec();
            } catch (const std::exception &e) {
                QMessageBox::critical(this, "Error", e.what());
            }
        } else {
            QMessageBox::critical(this, "Error", "Invalid password");
        }
    }
}

/*//
void MainWindow::showError(const QString &errorMessage)
{
    QMessageBox::critical(this, "Error", errorMessage);
}
double MainWindow::evalExpression(const QString &expression)
{

    QJSEngine engine;
    QJSValue result = engine.evaluate(expression);
    if (result.isError()) {
        throw std::runtime_error(result.toString().toStdString().c_str());
    }

    return result.toNumber();
}*/

void MainWindow::onNumberButtonClicked(const QString &number)
{
    QString currentText = ui->lineEdit->text();
    ui->lineEdit->setText(currentText + number);
}
double MainWindow::evalExpression(const QString &expression)
{
    QJSEngine engine;
    QJSValue result = engine.evaluate(expression);
    if (result.isError()) {
        throw std::runtime_error("Ошибка при вычислении выражения: " + result.toString().toStdString());
    }

    return result.toNumber();
}
void MainWindow::onOpenBracketButtonClicked()
{

    lineEdit->insert("(");
}

void MainWindow::onCloseBracketButtonClicked()
{

    lineEdit->insert(")");
}

void MainWindow::onDotButtonClicked()
{
    QString currentText = lineEdit->text();

    if (currentText.isEmpty() || !currentText.contains('.'))
    {
        lineEdit->setText(currentText + ".");
    }
}


void MainWindow :: onOperationButtonClicked ( const QString &operation)
{
    QString currentText = ui->lineEdit->text();
    if (!currentText.isEmpty())
    {
        ui->lineEdit->setText(currentText + " " + operation + " ");
    }
}


void MainWindow::onEqualsButtonClicked()
{
    QString expression = lineEdit->text();


    try {

        double result = evalExpression(expression);

        lineEdit->setText(QString::number(result));
    } catch (const std::exception &e) {

        QMessageBox::critical(this, "Error", e.what());
    }
    try {
        double result = evalExpression(expression);
        lineEdit->setText(QString::number(result));
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }

}
void MainWindow::onClearButtonClicked()
{

    lineEdit->clear();
}

void MainWindow::showError (const QString &errorMessage)
{
    QMessageBox::critical (this, "Error", errorMessage);
}

void MainWindow::onTrigonometricButtonClicked (const QString &function)
{
    QString currentText = ui->lineEdit->text();
    if (!currentText.isEmpty()) {
        ui->lineEdit->setText(currentText + function + "(");
    }
}


