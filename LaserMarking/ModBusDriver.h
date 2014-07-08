// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__0575946C_CDF9_417A_83AB_015C80670D41__INCLUDED_)
#define AFX_STDAFX_H__0575946C_CDF9_417A_83AB_015C80670D41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

/*動態與靜態宣告*/
 //#define DLLACT __declspec(dllimport)
// #define DLLACT __declspec(dllexport)

/*宣告定義 */
typedef short I16;
typedef unsigned short U16;
typedef int I32;
typedef unsigned int U32 ;

/*RS-485　驅動載入*/
	#include "DMT.h"					// Static load: Step 1/2
	#pragma comment(lib, "DMT.lib")		// Static load: Step 2/2
#define ModbusConType 0 //連接線類型

/*A2馬達相關參數設定*/

//幾乎用不到的暫存器
#define GoHome_HSPD1 "050A00020400640000" //找尋零點模式第一段速度設定位址，用第#1組，P5-05 050AH-050BH 16bit DEC 0.1r/min 0-2000
#define GoHome_HSPD2 "050C00020400140000" //找尋零點模式第二段速度設定位址，用第#1組，P5-06 050CH-050DH 16bit DEC 0.1r/min 0-2000

//特殊暫存器
#define INH "023C0005" //初始設定暫存器 P2-30，023CH-203DH 必須設定5所有參數不寫入永久保存記憶體
#define PRCM "050E" //命令下達暫存器 P5-07，0=歸零 1=絕對定位 2=相對定位 3=回原點 4=速度正轉 5=速度反轉 6=速度歸0
#define TSL "014800020400140000" //S曲線加減速常數(共用) P1-36，0148H-0149H 16bit DEC ms 0-65500
#define MFPN "05200002" //ENCODE回傳值，現在位置
#define DICF "030C0001" //控制INPUT由內部或外部控制
#define Input_Status "040E0000" //INPUT讀寫暫存器
#define Output_Status "04120001" //OUTPUT讀取暫存器
//設定暫存器
#define POSITION_h_PDEF1 "060400020400320000" //絕對移動定位模式參數設定位址，用第#1組，P6-02，0604H-0605H ABS 32bit (位置)
#define POSITION_i_PDEF2 "060800020400B20000" //增量移動定位模式參數設定位址，用第#2組，P6-04 INC 32bit HEX 值000(SPD)(DEA)(ACC)B2H  
#define POSITION_a_PDEF3 "060C00020400720000" //原點復歸參數設定位址，用第#3組，P06-06
#define Constant_speed_p_PDEF4 "061000020400110000" //速度模式正轉參數設定位址，用第#4組，P6-08，0610H-0611H
#define Constant_speed_n_PDEF5 "061400020400110000"//速度模式反轉參數設定位址，用第#5組，P6-10
// #define Constant_speed_0_PDEF6 "0618"//速度模式速度0參數設定位址，用第#6組，P6-12
#define POSITION_r_PDEF7 "061C00020400320000" //相對移動定位模式參數設定位址，用第#2組，P6-04 INC 32bit HEX 值000(SPD)(DEA)(ACC)72H  
//變數值暫存器
#define Position_h_CMD_PDAT1 "0606000204" //絕對移動定位模式位址設定位址，用第#1組，P6-03，0606H-0607H 32bit (位置) -2147483648 ~ +2147483647
#define Position_i_CMD_PDAT2 "060A000204" //增量移動定位模式位址設定位址，用第#2組，P6-05
#define Position_a_CMD_PDAT3 "060E000204" //原點復歸位址設定位址，用第#3組，P6-07，060EH-060FH 32bit (位置) -2147483648 ~ +2147483647
#define Traget_Speed_p_PDAT4 "0612000204" //速度模式正轉速度位址，用第#4組，P6-09
#define Traget_Speed_n_PDAT5 "0616000204" //速度模式反轉速度位址，用第#5組，P6-12
// #define Traget_Speed_0_PDAT6 "061A000204" //速度模式速度0位址，用第#6組，P6-13，061AH-061BH 32bit r/min -2147483648 ~ +2147483647
#define Position_r_CMD_PDAT7 "061E000204" //相對移動定位模式位址設定位址，用第#7組，P6-05
//速度、加速度、S曲線常數
#define ACC00 "0528000204" //加速時間位址，P5-20，0528H-0529H 16bit DEC ms 1~65500，從0加速到3000r/min所需時間
//#define ACC01 "052A000204" //加速時間位址，P5-21
//#define ACC02 "052C000204" //加速時間位址，P5-22
//#define ACC03 "052E000204" //加速時間位址，P5-23
//#define ACC04 "0530000204" //加速時間位址，P5-24
//#define ACC05 "0532000204" //加速時間位址，P5-25
//#define ACC06 "0534000204" //加速時間位址，P5-26
//#define ACC07 "0536000204" //加速時間位址，P5-27
//#define ACC08 "0538000204" //加速時間位址，P5-28
//#define ACC09 "053A000204" //加速時間位址，P5-29
//#define ACC10 "053C000204" //加速時間位址，P5-30
//#define ACC11 "053E000204" //加速時間位址，P5-31
//#define ACC12 "0540000204" //加速時間位址，P5-32
//#define ACC13 "0542000204" //加速時間位址，P5-33
//#define ACC14 "0544000204" //加速時間位址，P5-34
//#define ACC15 "0546000204" //加速時間位址，P5-35

#define POV00 "0578000204" //速度設定位址，P5-60，0578H-0579H 16bit DEC 0.1r/min 1~60000
//#define POV01 "057A000204" //速度設定位址，P5-61
//#define POV02 "057C000204" //速度設定位址，P5-62
//#define POV03 "057E000204" //速度設定位址，P5-63
//#define POV04 "0580000204" //速度設定位址，P5-64
//#define POV05 "0582000204" //速度設定位址，P5-65
//#define POV06 "0584000204" //速度設定位址，P5-66
//#define POV07 "0586000204" //速度設定位址，P5-67
//#define POV08 "0588000204" //速度設定位址，P5-68
//#define POV09 "058A000204" //速度設定位址，P5-69
//#define POV10 "058C000204" //速度設定位址，P5-70
//#define POV11 "058E000204" //速度設定位址，P5-71
//#define POV12 "0590000204" //速度設定位址，P5-72
//#define POV13 "0592000204" //速度設定位址，P5-73
//#define POV14 "0594000204" //速度設定位址，P5-74
//#define POV15 "0596000204" //速度設定位址，P5-75

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__0575946C_CDF9_417A_83AB_015C80670D41__INCLUDED_)

/* PLC相關 */
#define PLC_WORK "083CFF00" //工作啟動旗標位置
#define PLC_COMPLETE "083DFF00" //工作完成旗標位置
#define PLC_DEBUG "0834FF00" //DEBUG模式旗標位置
#define PLC_NOIN "0835FF00" //DEBUG模式旗標位置
#define PLC_SandRmode "0836FF00" //S&R模式旗標位置
#define PLC_NoInto "0835FF00" //遮段給前端機台信號旗標位置
#define PLC_Blowers "0837FF00" //鼓風機控制信號旗標位置
#define PLC_ALM2_No_BEE "0838FF00" //第二級警報單次關閉警示聲旗標位置
#define PLC_ALM1_No_BEE "0839FF00" //第一級警報關閉警示聲旗標位置
#define PLC_EVER_ALM1_No_BEE "0A03FF00" //開機後第一級警報關閉警示聲旗標位置
#define PLC_NOSleep "083EFF00" //不休眠模式旗標位置
#define PLC_EVER_NOSleep "0A02FF00" //開機後不休眠模式旗標位置
#define PLC_Manual "083FFF00" //手動模式旗標位置
#define PLC_Illumination "0840FF00" //光源啟動位置，正光
#define PLC_Illumination2 "0848FF00" //光源啟動位置，側光
#define PLC_TEST "0841FF00" //出板後拿走板子即模擬後端基台信號模式旗標位置
#define PLC_Queue "0842FF00" //單進單出模式旗標位置
#define PLC_Reverse "0843FF00" //機台反向模式旗標位置
#define PLC_EVER_Reverse "0A00FF00" //開機後機台反向旗標位置
#define PLC_NG "0844FF00" //NG信號旗標位置
#define PLC_byPASS "0845FF00" //把後段機台信號傳給前段旗標位置
#define PLC_EVER_byPASS "0A01FF00" //開機後把後段機台信號傳給前段旗標位置
#define PLC_NoWait "0846FF00" //不等待後段機台信號旗標位置
#define PLC_Status "084C002004" //機台狀態旗標位置
#define PLC_ALM "0864002004" //PLC錯誤警告旗標位置
#define PLC_PC_ALM_LV1 "0865FF00" //PC發動一級警報位置
#define PLC_PC_ALM_LV2 "0866FF00" //PC發動二級警報位置
#define PLC_ALM "0864002004" //PLC錯誤警告旗標位置
#define PLC_Manual_OUTPUT "0888002004" //手動輸出點旗標位置
#define PLC_IO_OUTPUT "0824001002" //IO輸出點狀態旗標位置
#define PLC_IO_INPUT "0800002004" //IO輸入點狀態旗標位置
#define PLC_Working_Cycle "1000000102" //前一塊板子作業經過時間位置

#define PLC_Conveyor_Width_VAR "11A5000102" //輸送帶寬度設定
#define PLC_Conveyor_Width_ManualVAR "10E5000204" //第一輸送帶吋動移動距離設定
#define PLC_Conveyor_Width_Auto_ADJ_All "083BFF00" //輸送帶自動調寬窄準備指令
#define PLC_Conveyor_Width_Auto_ADJ_Start "0862FF00" //輸送帶自動調寬窄準備後開始指令
#define PLC_Conveyor_Width_Auto_ADJ "08CEFF00" //第一輸送帶自動調寬窄
#define PLC_Conveyor_Width_CW_ADJ "08B5FF00" //第一輸送帶手動正轉
#define PLC_Conveyor_Width_CCW_ADJ "08B8FF00" //第一輸送帶手動反轉
#define PLC_Conveyor_Width_Auto_Correction "11AB000204" //第一輸送帶微調距離
#define PLC_Conveyor_Width_Speed "11B7000204"	//第一輸送帶轉速設定
#define PLC_Conveyor_Width_CCW_Mode "08C80010"	//第一輸送帶倒退模式(讀取調寬窄馬達狀態用的)
#define PLC_Conveyor_Change_Speed "08C80020"//輸送帶變更速度

#define PLC_Conveyor_Speed "11C3000204"	//輸送帶轉速設定
#define PLC_Conveyor_Move_Locate "11C9000204"	//輸送從感應到走到定位點需要的距離(50pp/一圈)
