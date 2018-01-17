/*******************************************************************************
* Copyright (C) 2017, 上海蔚来汽车有限公司
* All rights reserved.
* 产品号 :
* 所属组件 :
* 模块名称 :
* 文件名称 : NHAL_4G_tc.h
* 概要描述 : 4G module type header file
* 历史记录 :
* 版本      日期        作者    内容
* 1.0    2017-12-21     张炜   新建
******************************************************************************/
#ifndef NHAL_4G_TC_H_
#define NHAL_4G_TC_H_

/*****************************************************************************
* Includes
*****************************************************************************/
#include "NIO.h"

/*****************************************************************************
* MIRCO definition
*****************************************************************************/
/*
* Component Id Definition
*/
#ifndef COMPONENT_ID_4G
#define COMPONENT_ID_4G "4G"
#endif

/*
* Error Code Definition
*/
#define NHAL_4G_BASE_ERR     (0x04470000)
#define NHAL_4G_SYUSTEM_ERR  ((NHAL_4G_BASE_ERR) + 0x01)
#define NHAL_4G_FAILED       ((NHAL_4G_BASE_ERR) + 0x02)
// TBD ...

/*
* Other Definition
*/
#define NHAL_4G_INVALID_HANDLE (0xFF)
#define NHAL_4G_BUFFER_LENGTH  (1024)

/*****************************************************************************
* Enum Type Definitions
*****************************************************************************/
/**
 * @brief NHAL_4G_STATUS_ENUM
 */
typedef enum
{
	NHAL_STATUS_MIN = 0,
	NHAL_STATUS_FAILED,
	NHAL_STATUS_ALREADY_INIT,
	NHAL_STATUS_NOT_INIT,
	NHAL_STATUS_INTERNAL_ERROR,
	NHAL_STATUS_BAD_PARAMETER,
	NHAL_STATUS_BAD_LENGTH,
	NHAL_STATUS_NOT_SUPPORTED,
	NHAL_STATUS_INVALID,
	NHAL_STATUS_INVALID_STATE,
	NHAL_STATUS_BAD_SIZE,
	NHAL_STATUS_RESOURCE_ERROR,
	NHAL_STATUS_BUSY,
	NHAL_STATUS_IN_USE,
	NHAL_STATUS_CANCELLED,
	NHAL_STATUS_UNDEFINED,
	NHAL_STATUS_UNKNOWN,
	NHAL_STATUS_NOT_FOUND,
	NHAL_STATUS_NOT_AVAILABLE,
	NHAL_STATUS_NOT_COMPATIBLE,
	NHAL_STATUS_NOT_IMPLEMENTED,
	NHAL_STATUS_EMPTY,
	NHAL_STATUS_FULL,
	NHAL_STATUS_FAILURE,
	NHAL_STATUS_ALREADY_DONE,
	NHAL_STATUS_COMPLETE,
	NHAL_STATUS_STOPPED,
	NHAL_STATUS_SUSPENDED,
	NHAL_STATUS_TERMINATED,
	NHAL_STATUS_NOT_STOPPED,
	NHAL_STATUS_NOT_ALLOWED,
	NHAL_STATUS_INT_HANDLED,
	NHAL_STATUS_INT_NOT_HANDLED,
	NHAL_STATUS_TIMEOUT,
	NHAL_STATUS_DESTROYED,
	NHAL_STATUS_NOT_SET,
	NHAL_STATUS_MAX
} NHAL_4G_STATE_ENUM;

/**
 * @brief NHAL_4G_INFORMATION_STRUCT
 */
typedef struct
 {
    char identity[NHAL_4G_BUFFER_LENGTH];     		/**<  ID       */
	char vendor[NHAL_4G_BUFFER_LENGTH];/*opertaor*/
    char net_mode[NHAL_4G_BUFFER_LENGTH];   /**<  module     */
	NIO_UINT32 signal_strength;  /**<  signal strength      */
} NHAL_4G_INFORMATION_STRUCT;

/**
 * @brief NHAL_4G_STATUS_STRUCT
 */
typedef struct
 {
	NIO_BOOL on_line; // on-line or off-line
	NHAL_4G_STATE_ENUM state; // 4g state
	NHAL_4G_INFORMATION_STRUCT info; // informations
} NHAL_4G_STATUS_STRUCT;

#endif /* NHAL_4G_TC_H_ */
