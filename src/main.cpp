/////////////////////////////////////////////////////////////////////
//@file main.cpp
//@brief	主程序
//@copyright	上海信易信息科技股份有限公司 版权所有
/////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include <signal.h>
#include "trade_server.h"
#include "md_service.h"
#include "config.h"

static int interrupted = 0;

void sigint_handler(int sig)
{
	interrupted = 1;
}

int main() {
    openlog("open-trade-gateway", LOG_CONS|LOG_NDELAY|LOG_PID, LOG_USER);
    syslog(LOG_NOTICE, "server init");
    if (!LoadConfig()) {
        return 0;
    }
    signal(SIGINT, sigint_handler);
    TraderServer t;
    t.InitBrokerList();
    //加载合约文件
    if (!md_service::Init())
        return 0;
    //提供交易服务
    int n = 0;
    while (n >= 0 && !interrupted)
        n = t.RunOnce();
    //服务结束
    md_service::CleanUp();
    t.CleanUp();
    syslog(LOG_NOTICE, "server exit");
    closelog();
    return interrupted != 2;
}

