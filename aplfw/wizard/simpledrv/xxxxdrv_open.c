/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_close.c
 * @brief %jp{$OBJNAME_JP$ クローズ}%en{$OBJNAME_EN$  close}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/** オープン */
HANDLE XxxxDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_XXXXDRV	*self;
	HANDLE		hFile;
	
	/* upper cast */
	self = (C_XXXXDRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = FileObj_Create(&self->DrvObj, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		/* ここでデバイスを初期化 */
	}
	
	return hFile;
}


/* end of file */
