/*******************************************************************************
* Copyright (C) 2017, 上海蔚来汽车有限公司
* All rights reserved.
* 产品号 :
* 所属组件 :
* 模块名称 :
* 文件名称 : NIO_station.h
* 概要描述 : 该文件定义了工作站的机器类型
* 历史记录 :
* 版本      日期        作者    内容
* 1.0    2017-12-7      孙伟旺   新建
******************************************************************************/

#ifndef NIO_STATION_H_
#define NIO_STATION_H_

/*--------------------------------- 机器类型定义-----------------------------*/
/* 机器类型决定了使用CPU的指令集，该定义为不同平台编译的重要区别 */

/* 下面机器类型宏只能定义到Makefile中 */
/* 定义处理器类型 */
#define NIO_ARM_32     0
#define NIO_ARM_64     1
#define NIO_X86_32     2
#define NIO_X86_64     3

/*! \brief
* \~chinese 如果未在Makefile中定义目标机类型，默认定义目标机为sparcb类型。
* \~english target Machine. */
#ifndef TARGET_MACHINE
/*NOTE!: PLEASE CHANGE THE DEFINATION VALUE TO YOUR PLATFORM*/
/*注意： 若不打算在Makefile里预定义，则必须确保此处定义与编译所在机器的类型完全匹配*/
#define TARGET_MACHINE  NIO_ARM_32
#endif

/*编译宏*/
/* OS definition 操作系统定义, 对应COMPILE_OS宏*/
/* 操作系统决定了系统函数及类型的使用，该定义为不同平台编译的重要区别 */
#define WIN32_OS        0
#define WIN64_OS        1
#define LINUX32_OS      2
#define LINUX64_OS      3

/*! \brief
* \~chinese 如果未在Makefile中定义目标操作系统，默认定义为Solaris。
* \~english compile OS. */
#ifndef COMPILE_OS
/*NOTE!: PLEASE CHANGE THE DEFINATION VALUE TO YOUR PLATFORM*/
/*注意： 若不打算在Makefile里预定义，则必须确保此处定义与编译所在机器的类型完全匹配*/
#define COMPILE_OS LINUX32_OS
#endif

/*Checking between Macro TARGET_MACHINE and COMPILE_OS*/
#if TARGET_MACHINE == NIO_ARM_32 && COMPILE_OS != LINUX32_OS
    #error "TARGET_MACHINE(NIO_ARM) must match COMPILE_OS(LINUX32_OS)."
#elif TARGET_MACHINE == NIO_ARM_64 && (COMPILE_OS != LINUX32_OS || COMPILE_OS != LINUX64_OS)
    #error "TARGET_MACHINE(NIO_ARM_64) must match COMPILE_OS(LINUX32_OS or LINUX64_OS)."
#elif TARGET_MACHINE == NIO_X86_32 && COMPILE_OS != WIN32_OS
    #error "TARGET_MACHINE(NIO_X86_32) must match COMPILE_OS(WIN32_OS)."
#elif TARGET_MACHINE == NIO_X86_64 && (COMPILE_OS != WIN32_OS || COMPILE_OS != WIN64_OS)
    #error "The TARGET_MACHINE(NIO_X86_64) must match COMPILE_OS(WIN32_OS or WIN64_OS)."
#endif

/* 下面机器类型宏只能用于代码中 */
/*开发宏, 对应TARGET_OS宏*/
#define  SUN_OS         0
#define  VXWORKS_OS     1
#define  WIN_OS         2
#define  LINUX_OS       3

#if COMPILE_OS == WIN32_OS || COMPILE_OS == WIN64_OS
#define TARGET_OS WIN_OS
#elif COMPILE_OS == LINUX32_OS || COMPILE_OS == LINUX64_OS
#define TARGET_OS LINUX_OS
#endif

#if TARGET_MACHINE == NIO_ARM_32 || TARGET_MACHINE == NIO_ARM_64
/* 如果目标机为arm，定义小字节顺序 */
#define NIO_LITTLE_ENDIAN
#elif TARGET_MACHINE == NIO_X86_32 ||  TARGET_MACHINE == NIO_X86_64
/* 如果目标机为X86 32位机，定义小字节顺序 */
#define NIO_LITTLE_ENDIAN
#endif


#endif
