/*
 *  ReactOS winfile
 *
 *  dialogs.h
 *
 *  Copyright (C) 2002  Robert Dickenson <robd@reactos.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __DIALOGS_H__
#define __DIALOGS_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "resource.h"

struct ExecuteDialog {
	TCHAR	cmd[MAX_PATH];
	int		cmdshow;
};

struct MoveFileDialog {
	TCHAR	cmd[MAX_PATH];
	int		cmdshow;
};

struct PropertiesDialog {
	TCHAR	cmd[MAX_PATH];
	int		cmdshow;
    Entry*  pEntry;
};


BOOL CALLBACK ExecuteDialogWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK ViewFileTypeWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK OptionsConfirmationWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK MoveFileWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK PropertiesDlgProc(HWND, UINT, WPARAM, LPARAM);


#ifdef __cplusplus
};
#endif

#endif // __DIALOGS_H__
