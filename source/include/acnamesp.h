
/******************************************************************************
 *
 * Name: acnamesp.h - Namespace subcomponent prototypes and defines
 *
 *****************************************************************************/

/******************************************************************************
 *
 * 1. Copyright Notice
 *
 * Some or all of this work - Copyright (c) 1999, Intel Corp.  All rights
 * reserved.
 *
 * 2. License
 *
 * 2.1. This is your license from Intel Corp. under its intellectual property
 * rights.  You may have additional license terms from the party that provided
 * you this software, covering your right to use that party's intellectual
 * property rights.
 *
 * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a
 * copy of the source code appearing in this file ("Covered Code") an
 * irrevocable, perpetual, worldwide license under Intel's copyrights in the
 * base code distributed originally by Intel ("Original Intel Code") to copy,
 * make derivatives, distribute, use and display any portion of the Covered
 * Code in any form, with the right to sublicense such rights; and
 *
 * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent
 * license (with the right to sublicense), under only those claims of Intel
 * patents that are infringed by the Original Intel Code, to make, use, sell,
 * offer to sell, and import the Covered Code and derivative works thereof
 * solely to the minimum extent necessary to exercise the above copyright
 * license, and in no event shall the patent license extend to any additions
 * to or modifications of the Original Intel Code.  No other license or right
 * is granted directly or by implication, estoppel or otherwise;
 *
 * The above copyright and patent license is granted only if the following
 * conditions are met:
 *
 * 3. Conditions
 *
 * 3.1. Redistribution of Source with Rights to Further Distribute Source.
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification with rights to further distribute source must include
 * the above Copyright Notice, the above License, this list of Conditions,
 * and the following Disclaimer and Export Compliance provision.  In addition,
 * Licensee must cause all Covered Code to which Licensee contributes to
 * contain a file documenting the changes Licensee made to create that Covered
 * Code and the date of any change.  Licensee must include in that file the
 * documentation of any changes made by any predecessor Licensee.  Licensee
 * must include a prominent statement that the modification is derived,
 * directly or indirectly, from Original Intel Code.
 *
 * 3.2. Redistribution of Source with no Rights to Further Distribute Source.
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification without rights to further distribute source must
 * include the following Disclaimer and Export Compliance provision in the
 * documentation and/or other materials provided with distribution.  In
 * addition, Licensee may not authorize further sublicense of source of any
 * portion of the Covered Code, and must include terms to the effect that the
 * license from Licensee to its licensee is limited to the intellectual
 * property embodied in the software Licensee provides to its licensee, and
 * not to intellectual property embodied in modifications its licensee may
 * make.
 *
 * 3.3. Redistribution of Executable. Redistribution in executable form of any
 * substantial portion of the Covered Code or modification must reproduce the
 * above Copyright Notice, and the following Disclaimer and Export Compliance
 * provision in the documentation and/or other materials provided with the
 * distribution.
 *
 * 3.4. Intel retains all right, title, and interest in and to the Original
 * Intel Code.
 *
 * 3.5. Neither the name Intel nor any other trademark owned or controlled by
 * Intel shall be used in advertising or otherwise to promote the sale, use or
 * other dealings in products derived from or relating to the Covered Code
 * without prior written authorization from Intel.
 *
 * 4. Disclaimer and Export Compliance
 *
 * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED
 * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE
 * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,
 * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY
 * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES
 * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR
 * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,
 * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY
 * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL
 * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS
 * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY
 * LIMITED REMEDY.
 *
 * 4.3. Licensee shall not export, either directly or indirectly, any of this
 * software or system incorporating such software without first obtaining any
 * required license or other approval from the U. S. Department of Commerce or
 * any other agency or department of the United States Government.  In the
 * event Licensee exports any such software from the United States or
 * re-exports any such software from a foreign destination, Licensee shall
 * ensure that the distribution and export/re-export of the software is in
 * compliance with all laws, regulations, orders, or other restrictions of the
 * U.S. Export Administration Regulations. Licensee agrees that neither it nor
 * any of its subsidiaries will export/re-export any technical data, process,
 * software, or service, directly or indirectly, to any country for which the
 * United States government or any agency thereof requires an export license,
 * other governmental approval, or letter of assurance, without first obtaining
 * such license, approval or letter.
 *
 *****************************************************************************/

#ifndef __ACNAMESP_H__
#define __ACNAMESP_H__


/* To search the entire name space, pass this as SearchBase */

#define NS_ALL                  ((ACPI_HANDLE)0)

/*
 * Elements of AcpiNsProperties are bit significant
 * and should be one-to-one with values of ACPI_OBJECT_TYPE
 */
#define NSP_NORMAL              0
#define NSP_NEWSCOPE            1   /* a definition of this type opens a name scope */
#define NSP_LOCAL               2   /* suppress search of enclosing scopes */


/* Definitions of the predefined namespace names  */

#define ACPI_UNKNOWN_NAME       (UINT32) 0x3F3F3F3F     /* Unknown name is  "????" */
#define ACPI_ROOT_NAME          (UINT32) 0x2F202020     /* Root name is     "/   " */
#define ACPI_SYS_BUS_NAME       (UINT32) 0x5F53425F     /* Sys bus name is  "_SB_" */

#define NS_ROOT_PATH            "/"
#define NS_SYSTEM_BUS           "_SB_"


/* Flags for AcpiNsLookup, AcpiNsSearchAndEnter */

#define NS_NO_UPSEARCH          0
#define NS_SEARCH_PARENT        0x01
#define NS_DONT_OPEN_SCOPE      0x02
#define NS_NO_PEER_SEARCH       0x04

#define NS_WALK_UNLOCK          TRUE
#define NS_WALK_NO_UNLOCK       FALSE


ACPI_STATUS
AcpiNsWalkNamespace (
    OBJECT_TYPE_INTERNAL    Type,
    ACPI_HANDLE             StartObject,
    UINT32                  MaxDepth,
    BOOLEAN                 UnlockBeforeCallback,
    WALK_CALLBACK           UserFunction,
    void                    *Context,
    void                    **ReturnValue);


ACPI_NAMED_OBJECT*
AcpiNsGetNextObject (
    OBJECT_TYPE_INTERNAL    Type,
    ACPI_NAMED_OBJECT       *Parent,
    ACPI_NAMED_OBJECT       *Child);


ACPI_STATUS
AcpiNsDeleteNamespaceByOwner (
    UINT16                  TableId);

void
AcpiNsFreeTableEntry (
    ACPI_NAMED_OBJECT       *Entry);


/* Namespace loading - nsload */

ACPI_STATUS
AcpiNsParseTable (
    ACPI_TABLE_DESC         *TableDesc,
    ACPI_NAME_TABLE         *Scope);

ACPI_STATUS
AcpiNsLoadTable (
    ACPI_TABLE_DESC         *TableDesc,
    ACPI_NAMED_OBJECT       *Entry);

ACPI_STATUS
AcpiNsLoadTableByType (
    ACPI_TABLE_TYPE         TableType);


/*
 * Top-level namespace access - nsaccess
 */


ACPI_STATUS
AcpiNsRootInitialize (
    void);

ACPI_STATUS
AcpiNsLookup (
    ACPI_GENERIC_STATE      *ScopeInfo,
    NATIVE_CHAR             *Name,
    OBJECT_TYPE_INTERNAL    Type,
    OPERATING_MODE          InterpreterMode,
    UINT32                  Flags,
    ACPI_WALK_STATE         *WalkState,
    ACPI_NAMED_OBJECT       **RetEntry);


/*
 * Table allocation/deallocation - nsalloc
 */

ACPI_NAME_TABLE *
AcpiNsAllocateNameTable (
    UINT32                  NumEntries);

ACPI_STATUS
AcpiNsDeleteNamespaceSubtree (
    ACPI_NAMED_OBJECT       *ParentHandle);

void
AcpiNsDetachObject (
    ACPI_HANDLE             Object);

void
AcpiNsDeleteNameTable (
    ACPI_NAME_TABLE         *NameTable);


/*
 * Namespace modification - nsmodify
 */

ACPI_STATUS
AcpiNsUnloadNamespace (
    ACPI_HANDLE             Handle);

ACPI_STATUS
AcpiNsDeleteSubtree (
    ACPI_HANDLE             StartHandle);


/*
 * Namespace dump/print utilities - nsdump
 */

void
AcpiNsDumpTables (
    ACPI_HANDLE             SearchBase,
    UINT32                  MaxDepth);

void
AcpiNsDumpEntry (
    ACPI_HANDLE             Handle,
    UINT32                  DebugLevel);

ACPI_STATUS
AcpiNsDumpPathname (
    ACPI_HANDLE             Handle,
    NATIVE_CHAR             *Msg,
    UINT32                  Level,
    UINT32                  Component);

void
AcpiNsDumpRootDevices (
    void);

void
AcpiNsDumpObjects (
    OBJECT_TYPE_INTERNAL    Type,
    UINT32                  MaxDepth,
    UINT32                  OwnderId,
    ACPI_HANDLE             StartHandle);


/*
 * Namespace evaluation functions - nseval
 */

ACPI_STATUS
AcpiNsEvaluateByHandle (
    ACPI_NAMED_OBJECT       *ObjectNte,
    ACPI_OBJECT_INTERNAL    **Params,
    ACPI_OBJECT_INTERNAL    **ReturnObject);

ACPI_STATUS
AcpiNsEvaluateByName (
    NATIVE_CHAR             *Pathname,
    ACPI_OBJECT_INTERNAL    **Params,
    ACPI_OBJECT_INTERNAL    **ReturnObject);

ACPI_STATUS
AcpiNsEvaluateRelative (
    ACPI_NAMED_OBJECT       *ObjectNte,
    NATIVE_CHAR             *Pathname,
    ACPI_OBJECT_INTERNAL    **Params,
    ACPI_OBJECT_INTERNAL    **ReturnObject);

ACPI_STATUS
AcpiNsExecuteControlMethod (
    ACPI_NAMED_OBJECT       *MethodEntry,
    ACPI_OBJECT_INTERNAL    **Params,
    ACPI_OBJECT_INTERNAL    **ReturnObjDesc);

ACPI_STATUS
AcpiNsGetObjectValue (
    ACPI_NAMED_OBJECT       *ObjectEntry,
    ACPI_OBJECT_INTERNAL    **ReturnObjDesc);


/*
 * Parent/Child/Peer utility functions - nsfamily
 */

ACPI_NAME
AcpiNsFindParentName (
    ACPI_NAMED_OBJECT       *EntryToSearch);

BOOLEAN
AcpiNsExistDownstreamSibling (
    ACPI_NAMED_OBJECT       *ThisEntry);


/*
 * Scope manipulation - nsscope
 */

UINT32
AcpiNsOpensScope (
    OBJECT_TYPE_INTERNAL    Type);

NATIVE_CHAR *
AcpiNsGetTablePathname (
    ACPI_NAME_TABLE         *Scope);

NATIVE_CHAR *
AcpiNsNameOfCurrentScope (
    ACPI_WALK_STATE         *WalkState);

ACPI_STATUS
AcpiNsHandleToPathname (
    ACPI_HANDLE             ObjHandle,
    UINT32                  *BufSize,
    NATIVE_CHAR             *UserBuffer);

BOOLEAN
AcpiNsPatternMatch (
    ACPI_NAMED_OBJECT       *ObjEntry,
    NATIVE_CHAR             *SearchFor);

ACPI_STATUS
AcpiNsNameCompare (
    ACPI_HANDLE             ObjHandle,
    UINT32                  Level,
    void                    *Context,
    void                    **ReturnValue);

ACPI_STATUS
AcpiNsGetNamedObject (
    NATIVE_CHAR             *Pathname,
    ACPI_NAME_TABLE         *InScope,
    ACPI_NAMED_OBJECT       **OutNte);

/*
 * Object management for NTEs - nsobject
 */

ACPI_STATUS
AcpiNsAttachObject (
    ACPI_HANDLE             ObjHandle,
    ACPI_HANDLE             Value,
    OBJECT_TYPE_INTERNAL    Type);


void *
AcpiNsCompareValue (
    ACPI_HANDLE             ObjHandle,
    UINT32                  Level,
    void                    *ObjDesc);


/*
 * Namespace searching and entry - nssearch
 */

ACPI_STATUS
AcpiNsSearchAndEnter (
    UINT32                  EntryName,
    ACPI_WALK_STATE         *WalkState,
    ACPI_NAME_TABLE         *NameTable,
    OPERATING_MODE          InterpreterMode,
    OBJECT_TYPE_INTERNAL    Type,
    UINT32                  Flags,
    ACPI_NAMED_OBJECT       **RetEntry);

void
AcpiNsInitializeTable (
    ACPI_NAME_TABLE         *NewTable,
    ACPI_NAME_TABLE         *ParentScope,
    ACPI_NAMED_OBJECT       *ParentEntry);

ACPI_STATUS
AcpiNsSearchNameTable (
    UINT32                  EntryName,
    ACPI_NAME_TABLE         *NameTable,
    OBJECT_TYPE_INTERNAL    Type,
    ACPI_NAMED_OBJECT       **RetEntry,
    NS_SEARCH_DATA          *RetInfo);


/*
 * Utility functions - nsutils
 */

BOOLEAN
AcpiNsValidRootPrefix (
    NATIVE_CHAR             Prefix);

BOOLEAN
AcpiNsValidPathSeparator (
    NATIVE_CHAR             Sep);

OBJECT_TYPE_INTERNAL
AcpiNsGetType (
    ACPI_HANDLE             ObjHandle);

void *
AcpiNsGetAttachedObject (
    ACPI_HANDLE             ObjHandle);

UINT32
AcpiNsLocal (
    OBJECT_TYPE_INTERNAL    Type);

ACPI_STATUS
AcpiNsInternalizeName (
    NATIVE_CHAR             *DottedName,
    NATIVE_CHAR             **ConvertedName);

ACPI_STATUS
AcpiNsExternalizeName (
    UINT32                  InternalNameLength,
    NATIVE_CHAR             *InternalName,
    UINT32                  *ConvertedNameLength,
    NATIVE_CHAR             **ConvertedName);

ACPI_NAMED_OBJECT*
AcpiNsConvertHandleToEntry (
    ACPI_HANDLE             Handle);

ACPI_HANDLE
AcpiNsConvertEntryToHandle(
    ACPI_NAMED_OBJECT*Nte);

void
AcpiNsTerminate (
    void);

ACPI_NAMED_OBJECT *
AcpiNsGetParentEntry (
    ACPI_NAMED_OBJECT       *ThisEntry);


ACPI_NAMED_OBJECT *
AcpiNsGetNextValidEntry (
    ACPI_NAMED_OBJECT       *ThisEntry);


#endif /* __ACNAMESP_H__ */
