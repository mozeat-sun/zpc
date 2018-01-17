/*******************************************************************************
* Copyright (C) 2017, 上海蔚来汽车有限公司
* All rights reserved.
* 产品号 :
* 所属组件 :
* 模块名称 :
* 文件名称 : NIO_type.h
* 概要描述 : 该文件定义了基于C/C++语言的基本类型
* 历史记录 :
* 版本      日期        作者    内容
* 1.0    2017-12-7      孙伟旺   新建
******************************************************************************/

#ifndef NIO_TYPE_H_
#define NIO_TYPE_H_

#include "NIO_station.h"

#define NIO_CHAR_BIT   8                   /* max # of bits in a “char” */
#define NIO_CHAR_MIN   (-128)              /* min value of a “signed char” */
#define NIO_CHAR_MAX   127                 /* max value of a “signed char” */
#define NIO_SHRT_MIN   (-32768)            /* min value of a “short int” */
#define NIO_SHRT_MAX   32767               /* max value of a “short int” */
#define NIO_USHRT_MAX  65535               /* max value of “unsigned short int” */
#define NIO_INT_MIN    (-2147483647-1)     /* min value of an “int” */
#define NIO_INT_MAX    2147483647          /* max value of an “int” */
#define NIO_UINT_MAX   4294967295U         /* max value of an “unsigned int” */
#define NIO_LONG_MIN   (-2147483647L-1L)
#define NIO_LONG_MAX   2147483647L         /* max value of a “long int” */
#define NIO_ULONG_MAX  4294967295UL        /* max value of “unsigned long int” */
#define NIO_LLONG_MIN  (-9223372036854775807LL-1LL)
#define NIO_LLONG_MAX  9223372036854775807LL
#define NIO_ULLONG_MAX 18446744073709551615ULL

#define NIO_INT8_MAX (127)
#define NIO_INT16_MAX (32767)
#define NIO_INT32_MAX (2147483647)
#define NIO_INT64_MAX (9223372036854775807LL)
#define NIO_INT8_MIN (-128)
#define NIO_INT16_MIN (-32767-1)
#define NIO_INT32_MIN (-2147483647-1)
#define NIO_INT64_MIN (-9223372036854775807LL-1)

#define NIO_UINT8_MAX (255U)
#define NIO_UINT16_MAX (65535U)
#define NIO_UINT32_MAX (4294967295U)
#define NIO_UINT64_MAX (18446744073709551615ULL)

#define  NIO_SIZEOF_CHAR               1
#define  NIO_SIZEOF_SHORT              2
#define  NIO_SIZEOF_INT                4
#define  NIO_SIZEOF_LLONG              8
#define  NIO_SIZEOF_DOUBLE             8

#if TARGET_OS == LINUX32_OS
#define  NIO_SIZEOF_LONG               4
#define  NIO_SIZEOF_VOID_P             4
#elif TARGET_OS == LINUX64_OS
#define  NIO_SIZEOF_LONG               8
#define  NIO_SIZEOF_VOID_P             8
#endif
#if TARGET_MACHINE == NIO_X86_32 || TARGET_MACHINE == NIO_X86_64
#define  NIO_SIZEOF_LONG_DOUBLE        12
#endif

typedef char                        NIO_CHAR;
typedef char                        NIO_INT8;
typedef unsigned char               NIO_UINT8;
typedef short                       NIO_INT16;
typedef unsigned short              NIO_UINT16;
typedef int                         NIO_INT32;
typedef unsigned int                NIO_UINT32;
typedef long long                   NIO_INT64;
typedef unsigned long long          NIO_UINT64;
typedef float                       NIO_FLOAT;
typedef double                      NIO_DOUBLE;
typedef long double                 NIO_LDOUBLE;
typedef unsigned long               NIO_ULONG32;
typedef char*                       NIO_STRING;
typedef long                        NIO_LONG;
typedef void                        *NIO_LPVOID;
typedef NIO_LONG                   NIO_TIME_T;//time_t
typedef NIO_INT32 NIO_BOOL;
#define NIO_TRUE 1
#define NIO_FALSE 0

/*
为了使各平台代码趋于统一，除了上面的环境宏开关外，
下面将定义一组全局性宏，替代各平台功能相同而名称不同的系统函数和变量类型，
各编程人员应注意在所有代码中严格使用下列宏定义，而不是非统一的系统函数名！
*/

/* Other different in different platform */
#if TARGET_OS==WIN_OS
    typedef NIO_ULONG32    NIO_TIMER_ID;
    typedef NIO_LPVOID     NIO_HANDLE;
    typedef NIO_HANDLE     NIO_FD;
    typedef NIO_UINT32     NIO_SOCKET;
    typedef NIO_HANDLE     NIO_PID;
    typedef NIO_HANDLE     NIO_SEM_ID;
    typedef NIO_INT32      NIO_DWORD;
#elif TARGET_OS == LINUX_OS
    typedef NIO_INT32      NIO_TIMER_ID;
    typedef NIO_INT32      NIO_HANDLE;
    typedef NIO_INT32      NIO_FD;
    typedef NIO_INT32      NIO_SOCKET;
    typedef NIO_INT32      NIO_PID;
    typedef NIO_INT32      NIO_SEM_ID;
    typedef NIO_INT32      NIO_DWORD;
#endif


#endif //NIO_TYPE_H_
