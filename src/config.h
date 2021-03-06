﻿/////////////////////////////////////////////////////////////////////////
///@file config.h
///@brief	配置文件读写
///@copyright	上海信易信息科技股份有限公司 版权所有 
/////////////////////////////////////////////////////////////////////////

#pragma once

struct BrokerConfig
{
    std::string broker_type;
    std::string ctp_broker_id;
    std::vector<std::string> trading_fronts;
    std::string product_info;
};

struct Config
{
    Config();
    //服务IP及端口号
    std::string host;
    int port;
    //https证书文件
    std::string ca_file;
    //user配置
    std::string user_file_path;
    //broker配置
    std::map<std::string, BrokerConfig> brokers;
    //合约文件保存位置
    std::string ins_file_path;
};

extern Config g_config;

bool LoadConfig();
