﻿/////////////////////////////////////////////////////////////////////////
///@file utility.h
///@brief	工具函数
///@copyright	上海信易信息科技股份有限公司 版权所有
/////////////////////////////////////////////////////////////////////////
#pragma once

std::string GenerateUniqFileName();

template<size_t N>
inline char* strcpy_x(char(&dest)[N], const char* src)
{
    return strncpy(dest, src, N - 1);
}
template<size_t N>
inline char* strcpy_x(char(&dest)[N], const std::string& src)
{
    return strncpy(dest, src.c_str(), N - 1);
}
