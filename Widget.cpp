#include "Widget.h"
#include "./ui_Widget.h"

#include <QPushButton>

#include <QDebug>
#include "ReplBridge.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    auto bridge = new ReplBridge();
    this->pBridge = bridge;
    bridge->initLua();
    bridge->bingBridge();

    // Qt bind button event
    ui->setupUi(this);
    connect(ui->btnSend, &QPushButton::clicked, this, &Widget::sendLua);
}

Widget::~Widget()
{
    // optimize please!
    delete (ReplBridge*)this->pBridge;
    delete ui;
}

void Widget::initLua()
{

}

void Widget::bingBridge()
{
    if(!this->pBridge) return;
    auto bridge = (ReplBridge*)(this->pBridge);
    bridge->bingBridge();
}

void Widget::sendLua()
{
    if(!this->pBridge) return;
    auto bridge = (ReplBridge*)(this->pBridge);

    const char* str = ui->textEdit->toPlainText().toLocal8Bit().data();
    bridge->sendLua(str);
}

