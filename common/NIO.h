/*******************************************************************************
* Copyright (C) 2017, 上海蔚来汽车有限公司
* All rights reserved.
* 产品号 :
* 所属组件 :
* 模块名称 :
* 文件名称 : nio.h
* 概要描述 : 该文件总的包括了NIO各方面通用类型定义。
* 历史记录 :
* 版本      日期        作者    内容
* 1.0    2017-12-21     孙伟旺   新建
******************************************************************************/
#ifndef NIO_H_
#define NIO_H_

#include "NIO_station.h"
#include "NIO_type.h"

/* 函数声明中用于表示输入参数 */
#ifndef IN
    #define IN
#endif
/* 函数声明中用于表示输出参数 */
#ifndef OUT
    #define OUT
#endif
/* 函数声明中用于表示既是输入又是输出参数 */
#ifndef INOUT
    #define INOUT
#endif
/* 函数声明中用于表示既是重载函数 */
#ifndef OVERRIDE
    #define OVERRIDE
#endif

/*! 定义函数返回值OK */
#ifndef OK
    #define OK          0
#endif

/* 当未定义NULL时，定义NULL */
#ifndef NULL
    #define NULL        0
#endif


/* 获取当前的函数名*/
#if TARGET_OS == LINUX32_OS || TARGET_OS == LINUX64_OS
/* 定义统一的函数名宏 */
#ifdef __cplusplus
#define __NIO_FUNC__  (char*)__PRETTY_FUNCTION__
#else
    #define __NIO_FUNC__  (char*)__func__
#endif
#elif TARGET_OS == WIN32_OS || TARGET_OS == WIN64_OS
/* 定义统一的函数名宏 */
    #define __NIO_FUNC__  __FUNCTION__
#endif


/* 接口函数限定符前缀 */
#if TARGET_OS == LINUX32_OS || TARGET_OS == LINUX64_OS
    #ifdef  __cplusplus
        #define NIO_EXPORT extern "C"
    #else
    /*! \brief
    * \~chinese 当操作系统是SUN或VxWorks且编程语言为C时，定义外部接口的限定符。
    * \~english When OS is Solaris or VxWorks, and program language is C,
    define export directive as extern. */
        #define NIO_EXPORT extern
    #endif

    #define NIO_VAR_EXPORT
#elif TARGET_OS == WIN32_OS || TARGET_OS == WIN64_OS
    #ifdef __cplusplus
        /*! \brief
        * \~chinese 当操作系统是WIN32且编程语言为C++时，定义外部接口的限定符。
        * \~english When OS is WIN32, and program language is C++, define export
        directive as extern "C" __declspec (dllexport). */
        #define NIO_EXPORT extern "C" __declspec ( dllexport )
        #define NIO_IMPORT extern "C" __declspec ( dllimport )
    #else
    /*! \brief
    * \~chinese 当操作系统是WIN32且编程语言为C+时，定义外部接口的限定符。
    * \~english When OS is WIN32, and program language is C, define export
    directive as __declspec (dllexport). */
        #define NIO_EXPORT extern __declspec ( dllexport )
        #define NIO_IMPORT extern __declspec ( dllimport )
    #endif

    #define NIO_VAR_EXPORT __declspec ( dllexport )
#endif

#endif
