/****************************************************************************
* File Name : VFB_CanIf.h
*
* Modules : Virtual Function Bus base on CAN Interface Layer
*
* Summary : 1.The module user encapsulates the Can Driver Layer APIs.
*
* Reference Documents :
*
/****************************************************************************
* Author : Mingfen XIAO
* Version : V0.1
* Date	: 2018-09-26
* Description : 1.Create the modules
* 				2.Initialization Version
****************************************************************************/
#ifndef	_VFB_CAN_IF_H
#define	_VFB_CAN_IF_H

/*Include head files AREA*/
#include "..\Common\Common.h"
#include "CanIf_Cfg_Define.h"
#include "..\..\..\config\inc.h"
#include "..\CanTp\CanTp.h"




/*Macro definition AREA*/
/****************************************************************************
 * @function	CanIf_InitController
 * @brief		the CAN Controller Init function.
 * @param  		ChNo : input parameters,CAN channel index(if the mcu only one Can controller,the param shall setting to 0)
 * @retval 		null
 * @attention   null
****************************************************************************/
#if (CANIF_INITCONTROLLER_API == ENABLE)
#define CanIf_InitController(ChNo)	CANbus_Init(ChNo)
#else
#define CanIf_InitController(ChNo)
#endif

/****************************************************************************
 * @function	CanIf_DefaultInitController
 * @brief		the CAN Controller default init function.
 * @param  		ChNo : input parameters,CAN channel index(if the mcu only one Can controller,the param shall setting to 0)
 * @retval 		null
 * @attention   null
****************************************************************************/
#if (CANIF_DEFAULTINITCONTROLLER_API == ENABLE)
#define CanIf_DefaultInitController(ChNo)	CANbus_DefaultInit(ChNo)
#else
#define CanIf_DefaultInitController(ChNo)
#endif

/****************************************************************************
 * @function	CanIf_GetControllerHwMsgBuffIndex
 * @brief		get can controller hardware message buffer index.
 * @param  		ChNo : input parameters,CAN channel index(if the mcu only one Can controller,the param shall setting to 0)
 * @retval 		ret_value : the buffer index,the value range depend on mcu types.
 * @attention   null
****************************************************************************/
#if (CANIF_READCONTROLLERHWMSGBUFFINDEX_API == ENABLE)
#define CanIf_GetControllerHwMsgBuffIndex(ChNo)	CANbus_GetIntBuffNumber(ChNo)
#else
#define CanIf_GetControllerHwMsgBuffIndex(ChNo)
#endif

/****************************************************************************
 * @function	CanIf_GetControllerMsgInfo
 * @brief		get can controller hardware message buffer data,include Can message id,dlc and data.
 * @param  		ChNo :  input parameters , CAN channel index(if the mcu only one Can controller,the param shall setting to 0)
 *				BuffNo : input parameters ,the buffer index,the user shall use API of CanIf_GetControllerMsgBuffIndex to get.
 *				ptr_MsgId : output parameters, the receive can message id.
 *				ptr_Data : output parameters, the receive can message data
 *				ptr_Dlc : output parameters, the receive can message dlc.
 * @retval 		ret_value : the buffer index,the value range depend on mcu types.
 * @attention   null
****************************************************************************/
#if (CANIF_READCONTROLLERMSGINFO_API == ENABLE)
#define CanIf_GetControllerMsgInfo(ChNo,BufNo,ptr_MsgId,ptr_Data,ptr_Dlc)	CANbus_MsgGetIdDataDlc(ChNo,BufNo,ptr_MsgId,ptr_Data,ptr_Dlc)
#else
#define CanIf_GetControllerMsgInfo(ChNo,BufNo,ptr_MsgId,ptr_Data,ptr_Dlc)
#endif

/****************************************************************************
 * @function	CanIf_SetControllerMsgData
 * @brief		set can controller hardware message buffer data,include Can message id,dlc and data.
 * @param  		ChNo :  input parameters , CAN channel index(if the mcu only one Can controller,the param shall setting to 0)
 *				BuffNo : input parameters ,the buffer index,the user shall use API of CanIf_GetControllerMsgBuffIndex to get.
 *				ptr_Data : input parameters, the receive can message data
 * @retval 		ret_value : the buffer index,the value range depend on mcu types.
 * @attention   null
****************************************************************************/
#if (CANIF_WRITECONTROLLERMSGDATA_API == ENABLE)
#define CanIf_SetControllerMsgData(ChNo,BufNo,ptr_Data)		CANbus_MsgSetDat(ChNo,BufNo,ptr_Data)
#else
#define CanIf_SetControllerMsgData(ChNo,BufNo,ptr_Data)
#endif

/****************************************************************************
 * @function	CanIf_SetControllerMsgInfo
 * @brief		set can controller hardware message buffer data,include Can message id,dlc and data.
 * @param  		ChNo :  input parameters , CAN channel index(if the mcu only one Can controller,the param shall setting to 0)
 *				BuffNo : input parameters ,the buffer index,the user shall use API of CanIf_GetControllerMsgBuffIndex to get.
 *				ptr_MsgId : input parameters, the receive can message id.
 *				ptr_Data : input parameters, the receive can message data
 *				ptr_Dlc : input parameters, the receive can message dlc.
 * @retval 		ret_value : the function operate result.
 * @attention   null
****************************************************************************/
#if (CANIF_WRITECONTROLLERMSGINFO_API == ENABLE)
#define CanIf_SetControllerMsgInfo(ChNo,BufNo,ptr_MsgId,ptr_Data,ptr_Dlc)	CANbus_MsgSetIdDataDlc(ChNo,BufNo,ptr_MsgId,ptr_Data,ptr_Dlc)
#else
#define CanIf_SetControllerMsgInfo(ChNo,BufNo,ptr_MsgId,ptr_Data,ptr_Dlc)
#endif

/****************************************************************************
 * @function	CanIf_ReqControllerTxMsg
 * @brief		Request can controller send the hardware buffer data to extended can bus
 * @param  		ChNo :  input parameters , CAN channel index(if the mcu only one Can controller,the param shall setting to 0)
 *				BuffNo : input parameters ,the buffer index,the user shall use API of CanIf_GetControllerMsgBuffIndex to get.
 * @retval 		ret_value : the function operate result.
 * @attention   null
****************************************************************************/
#if (CANIF_REQUESRCONTROLLERTXMSG_API == ENABLE)
#define CanIf_ReqControllerTxMsg(ChNo,BufNo)	CANbus_MsgTxReq(ChNo,BufNo)
#else
#define CanIf_ReqControllerTxMsg(ChNo,BufNo)
#endif


/****************************************************************************
 * @function	CanIf_CanTp_RecvNotificationFunction
 * @brief		transmit diagnostic message to can transport layer
 * @param  		ChNo :  input parameters , CAN channel index(if the mcu only one Can controller,the param shall setting to 0)
 *				ptr_MsgId : output parameters, the receive can message id.
 *				ptr_Data : output parameters, the receive can message data
 *				ptr_Dlc : output parameters, the receive can message dlc.
 * @retval 		ret_value : the buffer index,the value range depend on mcu types.
 * @attention   null
****************************************************************************/
#if (CANIF_CANTP_RECVNOTIFICATION_API == ENABLE)
#define CanIf_CanTp_RecvNotificationFunction(ChNo,MsgId,ptr_Data,Dlc)	CanTp_RxIndicationFunction(ChNo,MsgId,ptr_Data,Dlc)
#else
#define CanIf_CanTp_RecvNotificationFunction(ChNo,MsgId,ptr_Data,Dlc)
#endif





/****************************************************************************
 * @function	CanIf_MemSetValue
 * @brief		set value to ptr_DestData
 * @param  		ptr_DestData :  output parameters , target data pointer
 *				Value : input parameters , needs to be set values
 *				DataLength : input parameters, data length.
 * @retval 		NULL
 * @attention   NULL
****************************************************************************/
#define CanIf_MemSetValue(ptr_DestData,Value,DataLength)		CommFunc_MemSetValue(ptr_DestData,Value,DataLength)

/****************************************************************************
 * @function	CanIf_MemCopyData
 * @brief		set value to ptr_DestData
 * @param  		ptr_DestData :  output parameters , target data pointer
 *				ptr_SoureData : output parameters , source data pointer
 *				DataLength : input parameters, data length.
 * @retval 		NULL
 * @attention   NULL
****************************************************************************/
#define CanIf_MemCopyData(ptr_DestData,ptr_SoureData,DataLength)		CommFunc_MemCopyData(ptr_DestData,ptr_SoureData,DataLength)



/*Function declaration AREA*/






#endif /*_VFB_CAN_IF_H*/
/*********************************File End*********************************/