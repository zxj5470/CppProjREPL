#ifndef REPLBRIDGE_H
#define REPLBRIDGE_H


class ReplBridge
{
public:
    ReplBridge();
    void initLua();
    void bingBridge();
    void sendLua(const char*);
private:
    void* pLua;
};

#endif // REPLBRIDGE_H
