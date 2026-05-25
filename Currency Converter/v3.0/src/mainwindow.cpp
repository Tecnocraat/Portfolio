#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CurrencyAPI.h"
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>
#include <QHeaderView>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initial UI Setup
    ui->stackedWidget->setCurrentIndex(0);
    setWindowIcon(QIcon("app_icon.ico"));

    QStringList currencies = {"USD", "BRL", "EUR", "GBP", "BTC"};
    ui->comboFrom->addItems(currencies);
    ui->comboTo->addItems(currencies);
    ui->comboFrom->setCurrentText("USD");
    ui->comboTo->setCurrentText("BRL");

    // Main Menu Navigation
    connect(ui->btnConverter, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btnDatabase, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
        updateTable();
    });

    connect(ui->btnAbout, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    // Converter Page Logic
    connect(ui->btnConvert, &QPushButton::clicked, [=](){
        double amount = ui->editAmount->text().toDouble();
        QString from = ui->comboFrom->currentText();
        QString to = ui->comboTo->currentText();

        ExchangeCache cache;
        CurrencyAPI::updateCache(cache);

        double sourceRate = 1.0;
        double targetRate = 1.0;

        if (from == "BRL") sourceRate = cache.brl;
        else if (from == "EUR") sourceRate = cache.eur;
        else if (from == "GBP") sourceRate = cache.gbp;
        else if (from == "BTC") sourceRate = cache.btc;

        if (to == "BRL") targetRate = cache.brl;
        else if (to == "EUR") targetRate = cache.eur;
        else if (to == "GBP") targetRate = cache.gbp;
        else if (to == "BTC") targetRate = cache.btc;

        // Cross-rate calculation based on USD base payload
        double finalRate = targetRate / sourceRate;
        double result = amount * finalRate;

        ui->lblResult->setText(QString::number(result, 'f', 2));

        DatabaseManager::saveConversion(from.toStdString(), to.toStdString(), amount, finalRate, result);
    });

    connect(ui->btnSwap, &QPushButton::clicked, [=](){
        QString from = ui->comboFrom->currentText();
        QString to = ui->comboTo->currentText();

        ui->comboFrom->setCurrentText(to);
        ui->comboTo->setCurrentText(from);

        if (!ui->editAmount->text().isEmpty()) {
            ui->btnConvert->click();
        }
    });

    // About Page Logic
    ui->tableAbout->verticalHeader()->setVisible(false);
    ui->tableAbout->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    QString exePath = QCoreApplication::applicationFilePath();
    ui->tableAbout->setItem(4, 1, new QTableWidgetItem(exePath));

    connect(ui->tableAbout, &QTableWidget::cellClicked, [=](int row, int column) {
        if (row == 2 && column == 1) {
            QDesktopServices::openUrl(QUrl("https://github.com/Tecnocraat"));
        }
    });

    if (ui->tableAbout->item(2, 1)) {
        ui->tableAbout->item(2, 1)->setToolTip("Click to visit my GitHub");
    }
}

void MainWindow::updateTable() {
    qDebug() << "Scheduling database table refresh...";
    QTimer::singleShot(10, this, [this]() {
        try {
            DatabaseManager::fillHistoryTable(ui->tableHistory);
        } catch (const std::exception &e) {
            qDebug() << "History Table Update Error:" << e.what();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
