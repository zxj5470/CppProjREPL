#include "ReplBridge.h"

#include "MyLib.h"

extern "C" {
# include "lua/lua.h"
# include "lua/lauxlib.h"
# include "lua/lualib.h"
}
#include <LuaBridge.h>

ReplBridge::ReplBridge()
{

}

void ReplBridge::initLua()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_pcall(L, 0, 0, 0);
    this->pLua = L;
}

void ReplBridge::bingBridge()
{
    if(!this->pLua) return;
    auto L = (lua_State*)(this->pLua);

    luabridge::getGlobalNamespace(L)
//            .addFunction("MSMessageBox", MSMessageBox)
            .beginClass<MyLib>("MyLib")
                .addConstructor <void (*) (void)> ()
                .addFunction("run", &MyLib::run)
            .endClass();


}

void ReplBridge::sendLua(const char* str)
{
    if(!this->pLua) return;
    auto L = (lua_State*)(this->pLua);
    luaL_dostring(L, str);
}
