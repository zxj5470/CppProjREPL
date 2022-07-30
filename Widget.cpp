#include "Widget.h"
#include "./ui_Widget.h"

#include <QPushButton>
#include <QDebug>

#include "MyLib.h"

extern "C" {
# include "lua/lua.h"
# include "lua/lauxlib.h"
# include "lua/lualib.h"
}
#include <LuaBridge.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    initLua();
    bingBridge();
    ui->setupUi(this);
    connect(ui->btnSend, &QPushButton::clicked, this, &Widget::sendLua);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initLua()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_pcall(L, 0, 0, 0);
    this->pLua = L;
}

void Widget::bingBridge()
{
    if(!this->pLua) return;
    auto L = (lua_State*)(this->pLua);
    luabridge::getGlobalNamespace(L).addFunction("MSMessageBox", MSMessageBox);

}

void Widget::sendLua()
{
    if(!this->pLua) return;
    auto L = (lua_State*)(this->pLua);
    const char* str = ui->textEdit->toPlainText().toLocal8Bit().data();
    luaL_dostring(L, str);
}

