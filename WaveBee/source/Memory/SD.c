///*
// * SD.c
// *
// *  Created on: Feb 19, 2018
// *      Author: ericksong
// */
//
//#include "SD.h"
//
//
//AT_NONCACHEABLE_SECTION(static FATFS g_fileSystem); /* File system object */
//AT_NONCACHEABLE_SECTION(static FIL g_fileObject);   /* File object */
//AT_NONCACHEABLE_SECTION(static BYTE work[_MAX_SS]);
//volatile uint32_t fullBlock = 0;
//volatile uint32_t emptyBlock = 4;
//extern sd_card_t g_sd;
//static const sdmmchost_detect_card_t s_sdCardDetect = {
//    .cdType = kSDMMCHOST_DetectCardByGpioCD,
//    .cdTimeOut_ms = (~0U),
//};
//
//
//status_t sdcardWaitCardInsert(void)
//{
//    /* Save host information. */
//    g_sd.host.base = SD_HOST_BASEADDR;
//    g_sd.host.sourceClock_Hz = SD_HOST_CLK_FREQ;
//    /* card detect type */
//    g_sd.usrParam.cd = &s_sdCardDetect;
//    /* SD host init function */
//    if (SD_HostInit(&g_sd) != kStatus_Success)
//    {
//        PRINTF("\r\nSD host init fail\r\n");
//        return kStatus_Fail;
//    }
//    /* power off card */
//    SD_PowerOffCard(g_sd.host.base, g_sd.usrParam.pwr);
//    /* wait card insert */
//    if (SD_WaitCardDetectStatus(SD_HOST_BASEADDR, &s_sdCardDetect, true) == kStatus_Success)
//    {
//        PRINTF("\r\nCard inserted.\r\n");
//        /* power on the card */
//        SD_PowerOnCard(g_sd.host.base, g_sd.usrParam.pwr);
//    }
//    else
//    {
//        PRINTF("\r\nCard detect fail.\r\n");
//        return kStatus_Fail;
//    }
//
//    return kStatus_Success;
//}
//
//
//status_t Init_SD(void){
//
//    FRESULT error;
//
//	const TCHAR driverNumberBuffer[3U] = {SDDISK + '0', ':', '/'};
//
//	PRINTF("\r\nPlease insert a card into board.\r\n");
//
//	if (sdcardWaitCardInsert() != kStatus_Success)
//	{
//		return -1;
//	}
//
//	if (f_mount(&g_fileSystem, driverNumberBuffer, 0U))
//	{
//		PRINTF("Mount volume failed.\r\n");
//		return -1;
//	}
//
//	error = f_chdrive((char const *)&driverNumberBuffer[0U]);
//	if (error)
//	{
//		PRINTF("Change drive failed.\r\n");
//		return -1;
//	}
//
//	PRINTF("\r\nMake file system......The time may be long if the card capacity is big.\r\n");
//	if (f_mkfs(driverNumberBuffer, FM_ANY, 0U, work, sizeof work))
//	{
//		PRINTF("Make file system failed.\r\n");
//		return -1;
//	}
//
//	PRINTF("\r\nCreate directory......\r\n");
//	error = f_mkdir(_T("/record"));
//	if (error)
//	{
//		if (error == FR_EXIST)
//		{
//			PRINTF("Directory exists.\r\n");
//		}
//		else
//		{
//			PRINTF("Make directory failed.\r\n");
//			return -1;
//		}
//	}
//
//	PRINTF("\n\rPlease choose the option :\n\r");
//}
//
//void WriteToCard(void){
//
//}
//
//void ReadFromSD(void){
//
//}
