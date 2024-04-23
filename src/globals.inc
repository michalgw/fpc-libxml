(*
 * Summary: interface for all global variables of the library
 * Description: all the global variables and thread handling for
 *              those variables is handled by this module.
 *
 * The bottom of this file is automatically generated by build_glob.py
 * based on the description file global.data
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Gary Pennington <Gary.Pennington@uk.sun.com>, Daniel Veillard
 *)

{$IFDEF POINTER}
  xmlGlobalStatePtr = ^xmlGlobalState;
  xmlRegisterNodeFuncPtr = ^xmlRegisterNodeFunc;
  xmlDeregisterNodeFuncPtr = ^xmlDeregisterNodeFunc;
  xmlParserInputBufferCreateFilenameFuncPtr = ^xmlParserInputBufferCreateFilenameFunc;
  xmlOutputBufferCreateFilenameFuncPtr = ^xmlOutputBufferCreateFilenameFunc;
{$ENDIF}

{$IFDEF FUNCTION}
procedure xmlInitGlobals; EXTDECL; external xml2lib;
procedure xmlCleanupGlobals; EXTDECL; external xml2lib;
{$ENDIF}

{$IFDEF FUNCTIONVAR}
  xmlInitGlobals: procedure; EXTDECL;
  xmlCleanupGlobals: procedure; EXTDECL;
{$ENDIF}

{$IFDEF TYPE}
  xmlParserInputBufferCreateFilenameFunc = function(URI: PAnsiChar; enc: xmlCharEncoding): xmlParserInputBufferPtr; EXTDECL;
  xmlOutputBufferCreateFilenameFunc = function(URI: PAnsiChar; encoder: xmlCharEncodingHandlerPtr; compression: cint): xmlOutputBufferPtr; EXTDECL;
{$ENDIF}

{$IFDEF FUNCTION}
function xmlParserInputBufferCreateFilenameDefault(func: xmlParserInputBufferCreateFilenameFunc): xmlParserInputBufferCreateFilenameFunc; EXTDECL; external xml2lib;
function xmlOutputBufferCreateFilenameDefault(func: xmlOutputBufferCreateFilenameFunc): xmlOutputBufferCreateFilenameFunc; EXTDECL; external xml2lib;
{$ENDIF}

{$IFDEF FUNCTIONVAR}
  xmlParserInputBufferCreateFilenameDefault: function(func: xmlParserInputBufferCreateFilenameFunc): xmlParserInputBufferCreateFilenameFunc; EXTDECL;
  xmlOutputBufferCreateFilenameDefault: function(func: xmlOutputBufferCreateFilenameFunc): xmlOutputBufferCreateFilenameFunc; EXTDECL;
{$ENDIF}

(*
 * Externally global symbols which need to be protected for backwards
 * compatibility support.
 *)

{$IFDEF TYPE}
  xmlRegisterNodeFunc = procedure(node: xmlNodePtr); EXTDECL;
  xmlDeregisterNodeFunc = procedure(node: xmlNodePtr); EXTDECL;

  xmlGlobalState = record
    xmlParserVersion                        : PAnsiChar;

    xmlDefaultSAXLocator                    : xmlSAXLocator;
    xmlDefaultSAXHandler                    : xmlSAXHandlerV1;
    docbDefaultSAXHandler                   : xmlSAXHandlerV1;
    htmlDefaultSAXHandler                   : xmlSAXHandlerV1;

    xmlFree                                 : xmlFreeFunc;
    xmlMalloc                               : xmlMallocFunc;
    xmlMemStrdup                            : xmlStrdupFunc;
    xmlRealloc                              : xmlReallocFunc;

    xmlGenericError                         : xmlGenericErrorFunc;
    xmlStructuredError                      : xmlStructuredErrorFunc;
    xmlGenericErrorContext                  : pointer;

    oldXMLWDcompatibility                   : cint;

    xmlBufferAllocScheme                    : xmlBufferAllocationScheme;
    xmlDefaultBufferSize                    : cint;

    xmlSubstituteEntitiesDefaultValue       : cint;
    xmlDoValidityCheckingDefaultValue       : cint;
    xmlGetWarningsDefaultValue              : cint;
    xmlKeepBlanksDefaultValue               : cint;
    xmlLineNumbersDefaultValue              : cint;
    xmlLoadExtDtdDefaultValue               : cint;
    xmlParserDebugEntities                  : cint;
    xmlPedanticParserDefaultValue           : cint;

    xmlSaveNoEmptyTags                      : cint;
    xmlIndentTreeOutput                     : cint;
    xmlTreeIndentString                     : PAnsiChar;

    xmlRegisterNodeDefaultValue             : xmlRegisterNodeFunc;
    xmlDeregisterNodeDefaultValue           : xmlDeregisterNodeFunc;

    xmlMallocAtomic                         : xmlMallocFunc;
    xmlLastError                            : xmlError;

    xmlParserInputBufferCreateFilenameValue : xmlParserInputBufferCreateFilenameFunc;
    xmlOutputBufferCreateFilenameValue      : xmlOutputBufferCreateFilenameFunc;

    xmlStructuredErrorContext               : pointer;
  end;
{$ENDIF}

{$IFDEF FUNCTION}
procedure xmlInitializeGlobalState(gs: xmlGlobalStatePtr); EXTDECL; external xml2lib;
procedure xmlThrDefSetGenericErrorFunc(ctx: pointer; handler: xmlGenericErrorFunc); EXTDECL; external xml2lib;
procedure xmlThrDefSetStructuredErrorFunc(ctx: pointer; handler: xmlStructuredErrorFunc); EXTDECL; external xml2lib;

function xmlRegisterNodeDefault(func: xmlRegisterNodeFunc): xmlRegisterNodeFunc; EXTDECL; external xml2lib;
function xmlThrDefRegisterNodeDefault(func: xmlRegisterNodeFunc): xmlRegisterNodeFunc; EXTDECL; external xml2lib;
function xmlDeregisterNodeDefault(func: xmlRegisterNodeFunc): xmlDeregisterNodeFunc; EXTDECL; external xml2lib;
function xmlThrDefDeregisterNodeDefault(func: xmlRegisterNodeFunc): xmlDeregisterNodeFunc; EXTDECL; external xml2lib;

function xmlThrDefOutputBufferCreateFilenameDefault(func: xmlOutputBufferCreateFilenameFunc): xmlOutputBufferCreateFilenameFunc; EXTDECL; external xml2lib;
function xmlThrDefParserInputBufferCreateFilenameDefault(func: xmlParserInputBufferCreateFilenameFunc): xmlParserInputBufferCreateFilenameFunc; EXTDECL; external xml2lib;

(** DOC_DISABLE *)
(*
 * In general the memory allocation entry points are not kept
 * thread specific but this can be overridden by LIBXML_THREAD_ALLOC_ENABLED
 *    - xmlMalloc
 *    - xmlMallocAtomic
 *    - xmlRealloc
 *    - xmlMemStrdup
 *    - xmlFree
 *)

{$IFDEF LIBXML_DOCB_ENABLED}
function __docbDefaultSAXHandler: xmlSAXHandlerV1Ptr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE docbDefaultSAXHandler := __docbDefaultSAXHandler()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  docbDefaultSAXHandler: xmlSAXHandlerV1; cvar; external;
{$ENDIF}
{$ENDIF}
{$ENDIF}

{$IFDEF LIBXML_HTML_ENABLED}
function __htmlDefaultSAXHandler: xmlSAXHandlerV1Ptr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE htmlDefaultSAXHandler := __htmlDefaultSAXHandler()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  htmlDefaultSAXHandler: xmlSAXHandlerV1; cvar; external;
{$ENDIF}
{$ENDIF}
{$ENDIF}

function __xmlLastError: xmlErrorPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlLastError := __xmlLastError()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlLastError: xmlError; cvar; external;
{$ENDIF}
{$ENDIF}

(*
 * Everything starting from the line below is
 * Automatically generated by build_glob.py.
 * Do not modify the previous line.
 *)

function __oldXMLWDcompatibility: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE oldXMLWDcompatibility := __oldXMLWDcompatibility()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  oldXMLWDcompatibility: cint; cvar; external;
  {$ENDIF}
{$ENDIF}

function __xmlBufferAllocScheme: xmlBufferAllocationSchemePtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlBufferAllocScheme := __xmlBufferAllocScheme()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlBufferAllocScheme: xmlBufferAllocationScheme; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefBufferAllocScheme(v: xmlBufferAllocationScheme): xmlBufferAllocationScheme; EXTDECL; external xml2lib;

function __xmlDefaultBufferSize: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDefaultBufferSize := __xmlDefaultBufferSize()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlDefaultBufferSize: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefDefaultBufferSize(v: cint): cint; EXTDECL; external xml2lib;

function __xmlDefaultSAXHandler: xmlSAXHandlerV1Ptr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDefaultSAXHandler := __xmlDefaultSAXHandler()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlDefaultSAXHandler: xmlSAXHandlerV1; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlDefaultSAXLocator: xmlSAXLocatorPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDefaultSAXLocator := __xmlDefaultSAXLocator()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlDefaultSAXLocator: xmlSAXLocator; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlDoValidityCheckingDefaultValue: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDoValidityCheckingDefaultValue := __xmlDoValidityCheckingDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlDoValidityCheckingDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefDoValidityCheckingDefaultValue(v: cint): cint; EXTDECL; external xml2lib;

function __xmlGenericError: xmlGenericErrorFuncPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlGenericError := __xmlGenericError()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlGenericError: xmlGenericErrorFunc; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlStructuredError: xmlStructuredErrorFuncPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlStructuredError := __xmlStructuredError()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlStructuredError: xmlStructuredErrorFunc; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlGenericErrorContext: ppointer; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlGenericErrorContext := __xmlGenericErrorContext()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlGenericErrorContext: pointer; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlGetWarningsDefaultValue: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlGetWarningsDefaultValue := __xmlGetWarningsDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlGetWarningsDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefGetWarningsDefaultValue(v: cint): cint; EXTDECL; external xml2lib;

function __xmlIndentTreeOutput: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlIndentTreeOutput := __xmlIndentTreeOutput()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlIndentTreeOutput: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefIndentTreeOutput(v: cint): cint; EXTDECL; external xml2lib;

function __xmlTreeIndentString: PPAnsiChar; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlTreeIndentString := __xmlTreeIndentString()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlTreeIndentString: PAnsiChar; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefTreeIndentString(v: PAnsiChar): PAnsiChar; EXTDECL; external xml2lib;

function __xmlKeepBlanksDefaultValue: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlKeepBlanksDefaultValue := __xmlKeepBlanksDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlKeepBlanksDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefKeepBlanksDefaultValue(v: cint): cint; EXTDECL; external xml2lib;

function __xmlLineNumbersDefaultValue: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlLineNumbersDefaultValue := __xmlLineNumbersDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlLineNumbersDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefLineNumbersDefaultValue(v: cint): cint; EXTDECL; external xml2lib;

function __xmlLoadExtDtdDefaultValue: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlLoadExtDtdDefaultValue := __xmlLoadExtDtdDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlLoadExtDtdDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefLoadExtDtdDefaultValue(v: cint): cint; EXTDECL; external xml2lib;

function __xmlParserDebugEntities: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlParserDebugEntities := __xmlParserDebugEntities()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlParserDebugEntities: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefParserDebugEntities(v: cint): cint; EXTDECL; external xml2lib;

function __xmlParserVersion: PPAnsiChar; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlParserVersion := __xmlParserVersion()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlParserVersion: PAnsiChar; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlPedanticParserDefaultValue: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlPedanticParserDefaultValue := __xmlPedanticParserDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlPedanticParserDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefPedanticParserDefaultValue(v: cint): cint; EXTDECL; external xml2lib;

function __xmlSaveNoEmptyTags: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlSaveNoEmptyTags := __xmlSaveNoEmptyTags()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlSaveNoEmptyTags: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefSaveNoEmptyTags(v: cint): cint; EXTDECL; external xml2lib;

function __xmlSubstituteEntitiesDefaultValue: pcint; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlSubstituteEntitiesDefaultValue := __xmlSubstituteEntitiesDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlSubstituteEntitiesDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
function xmlThrDefSubstituteEntitiesDefaultValue(v: cint): cint; EXTDECL; external xml2lib;

function __xmlRegisterNodeDefaultValue: xmlRegisterNodeFuncPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlRegisterNodeDefaultValue := __xmlRegisterNodeDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlRegisterNodeDefaultValue: xmlRegisterNodeFunc; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlDeregisterNodeDefaultValue: xmlDeregisterNodeFuncPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDeregisterNodeDefaultValue := __xmlDeregisterNodeDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlDeregisterNodeDefaultValue: xmlDeregisterNodeFunc; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlParserInputBufferCreateFilenameValue: xmlParserInputBufferCreateFilenameFuncPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlParserInputBufferCreateFilenameValue := __xmlParserInputBufferCreateFilenameValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlParserInputBufferCreateFilenameValue: xmlParserInputBufferCreateFilenameFunc; cvar; external;
{$ENDIF}
{$ENDIF}

function __xmlOutputBufferCreateFilenameValue: xmlOutputBufferCreateFilenameFuncPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlOutputBufferCreateFilenameValue := __xmlOutputBufferCreateFilenameValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
var
  xmlOutputBufferCreateFilenameValue: xmlOutputBufferCreateFilenameFunc; cvar; external;
{$ENDIF}
{$ENDIF}

{$ENDIF}

{$IFDEF FUNCTIONVAR}
  xmlInitializeGlobalState: procedure(gs: xmlGlobalStatePtr); EXTDECL;
  xmlThrDefSetGenericErrorFunc: procedure(ctx: pointer; handler: xmlGenericErrorFunc); EXTDECL;
  xmlThrDefSetStructuredErrorFunc: procedure(ctx: pointer; handler: xmlStructuredErrorFunc); EXTDECL;

  xmlRegisterNodeDefault: function(func: xmlRegisterNodeFunc): xmlRegisterNodeFunc; EXTDECL;
  xmlThrDefRegisterNodeDefault: function(func: xmlRegisterNodeFunc): xmlRegisterNodeFunc; EXTDECL;
  xmlDeregisterNodeDefault: function(func: xmlRegisterNodeFunc): xmlDeregisterNodeFunc; EXTDECL;
  xmlThrDefDeregisterNodeDefault: function(func: xmlRegisterNodeFunc): xmlDeregisterNodeFunc; EXTDECL;

  xmlThrDefOutputBufferCreateFilenameDefault: function(func: xmlOutputBufferCreateFilenameFunc): xmlOutputBufferCreateFilenameFunc; EXTDECL;
  xmlThrDefParserInputBufferCreateFilenameDefault: function(func: xmlParserInputBufferCreateFilenameFunc): xmlParserInputBufferCreateFilenameFunc; EXTDECL;

(** DOC_DISABLE *)
(*
 * In general the memory allocation entry points are not kept
 * thread specific but this can be overridden by LIBXML_THREAD_ALLOC_ENABLED
 *    - xmlMalloc
 *    - xmlMallocAtomic
 *    - xmlRealloc
 *    - xmlMemStrdup
 *    - xmlFree
 *)

{$IFDEF LIBXML_DOCB_ENABLED}
  __docbDefaultSAXHandler: function: xmlSAXHandlerV1Ptr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE docbDefaultSAXHandler := __docbDefaultSAXHandler()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  docbDefaultSAXHandler: xmlSAXHandlerV1; cvar; external;
{$ENDIF}
{$ENDIF}
{$ENDIF}

{$IFDEF LIBXML_HTML_ENABLED}
  __htmlDefaultSAXHandler: function: xmlSAXHandlerV1Ptr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE htmlDefaultSAXHandler := __htmlDefaultSAXHandler()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  htmlDefaultSAXHandler: xmlSAXHandlerV1; cvar; external;
{$ENDIF}
{$ENDIF}
{$ENDIF}

  __xmlLastError: function: xmlErrorPtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlLastError := __xmlLastError()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlLastError: xmlError; cvar; external;
{$ENDIF}
{$ENDIF}

(*
 * Everything starting from the line below is
 * Automatically generated by build_glob.py.
 * Do not modify the previous line.
 *)

  __oldXMLWDcompatibility: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE oldXMLWDcompatibility := __oldXMLWDcompatibility()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  oldXMLWDcompatibility: cint; cvar; external;
  {$ENDIF}
{$ENDIF}

  __xmlBufferAllocScheme: function: xmlBufferAllocationSchemePtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlBufferAllocScheme := __xmlBufferAllocScheme()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlBufferAllocScheme: xmlBufferAllocationScheme; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefBufferAllocScheme: function(v: xmlBufferAllocationScheme): xmlBufferAllocationScheme; EXTDECL;

  __xmlDefaultBufferSize: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDefaultBufferSize := __xmlDefaultBufferSize()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlDefaultBufferSize: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefDefaultBufferSize: function(v: cint): cint; EXTDECL;

  __xmlDefaultSAXHandler: function: xmlSAXHandlerV1Ptr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDefaultSAXHandler := __xmlDefaultSAXHandler()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlDefaultSAXHandler: xmlSAXHandlerV1; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlDefaultSAXLocator: function: xmlSAXLocatorPtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDefaultSAXLocator := __xmlDefaultSAXLocator()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlDefaultSAXLocator: xmlSAXLocator; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlDoValidityCheckingDefaultValue: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDoValidityCheckingDefaultValue := __xmlDoValidityCheckingDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlDoValidityCheckingDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefDoValidityCheckingDefaultValue: function(v: cint): cint; EXTDECL;

  __xmlGenericError: function: xmlGenericErrorFuncPtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlGenericError := __xmlGenericError()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlGenericError: xmlGenericErrorFunc; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlStructuredError: function: xmlStructuredErrorFuncPtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlStructuredError := __xmlStructuredError()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlStructuredError: xmlStructuredErrorFunc; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlGenericErrorContext: function: ppointer; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlGenericErrorContext := __xmlGenericErrorContext()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlGenericErrorContext: pointer; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlGetWarningsDefaultValue: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlGetWarningsDefaultValue := __xmlGetWarningsDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlGetWarningsDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefGetWarningsDefaultValue: function(v: cint): cint; EXTDECL;

  __xmlIndentTreeOutput: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlIndentTreeOutput := __xmlIndentTreeOutput()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlIndentTreeOutput: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefIndentTreeOutput: function(v: cint): cint; EXTDECL;

  __xmlTreeIndentString: function: PPAnsiChar; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlTreeIndentString := __xmlTreeIndentString()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlTreeIndentString: PAnsiChar; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefTreeIndentString: function(v: PAnsiChar): PAnsiChar; EXTDECL;

  __xmlKeepBlanksDefaultValue: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlKeepBlanksDefaultValue := __xmlKeepBlanksDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlKeepBlanksDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefKeepBlanksDefaultValue: function(v: cint): cint; EXTDECL;

  __xmlLineNumbersDefaultValue: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlLineNumbersDefaultValue := __xmlLineNumbersDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlLineNumbersDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefLineNumbersDefaultValue: function(v: cint): cint; EXTDECL;

  __xmlLoadExtDtdDefaultValue: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlLoadExtDtdDefaultValue := __xmlLoadExtDtdDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlLoadExtDtdDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefLoadExtDtdDefaultValue: function(v: cint): cint; EXTDECL;

  __xmlParserDebugEntities: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlParserDebugEntities := __xmlParserDebugEntities()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlParserDebugEntities: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefParserDebugEntities: function(v: cint): cint; EXTDECL;

  __xmlParserVersion: function: PPAnsiChar; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlParserVersion := __xmlParserVersion()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlParserVersion: PAnsiChar; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlPedanticParserDefaultValue: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlPedanticParserDefaultValue := __xmlPedanticParserDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlPedanticParserDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefPedanticParserDefaultValue: function(v: cint): cint; EXTDECL;

  __xmlSaveNoEmptyTags: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlSaveNoEmptyTags := __xmlSaveNoEmptyTags()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlSaveNoEmptyTags: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefSaveNoEmptyTags: function(v: cint): cint; EXTDECL;

  __xmlSubstituteEntitiesDefaultValue: function: pcint; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlSubstituteEntitiesDefaultValue := __xmlSubstituteEntitiesDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlSubstituteEntitiesDefaultValue: cint; cvar; external;
{$ENDIF}
{$ENDIF}
  xmlThrDefSubstituteEntitiesDefaultValue: function(v: cint): cint; EXTDECL;

  __xmlRegisterNodeDefaultValue: function: xmlRegisterNodeFuncPtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlRegisterNodeDefaultValue := __xmlRegisterNodeDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlRegisterNodeDefaultValue: xmlRegisterNodeFunc; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlDeregisterNodeDefaultValue: function: xmlDeregisterNodeFuncPtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlDeregisterNodeDefaultValue := __xmlDeregisterNodeDefaultValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlDeregisterNodeDefaultValue: xmlDeregisterNodeFunc; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlParserInputBufferCreateFilenameValue: function: xmlParserInputBufferCreateFilenameFuncPtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlParserInputBufferCreateFilenameValue := __xmlParserInputBufferCreateFilenameValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlParserInputBufferCreateFilenameValue: xmlParserInputBufferCreateFilenameFunc; cvar; external;
{$ENDIF}
{$ENDIF}

  __xmlOutputBufferCreateFilenameValue: function: xmlOutputBufferCreateFilenameFuncPtr; EXTDECL;
{$IFDEF LIBXML_THREAD_ENABLED}
{$DEFINE xmlOutputBufferCreateFilenameValue := __xmlOutputBufferCreateFilenameValue()^ }
{$ELSE}
{$IFNDEF NO_EXTERNAL_VARS}
  xmlOutputBufferCreateFilenameValue: xmlOutputBufferCreateFilenameFunc; cvar; external;
{$ENDIF}
{$ENDIF}

{$ENDIF}

{$IFDEF EXTVAR}
{$IFDEF LIBXML_THREAD_ALLOC_ENABLED}
{$IFDEF LIBXML_THREAD_ENABLED}
function __xmlMalloc: xmlMallocFuncPtr; EXTDECL;
{$DEFINE xmlMalloc := __xmlMalloc()^ }
{$ELSE}
var
  xmlMalloc: xmlMallocFunc; {$IFNDEF NO_EXTERNAL_VARS}cvar; external;{$ENDIF}
{$ENDIF}

{$IFDEF LIBXML_THREAD_ENABLED}
function __xmlMallocAtomic: xmlMallocFuncPtr; EXTDECL;
#define xmlMallocAtomic ( *(__xmlMallocAtomic()))
{$ELSE}
var
  xmlMallocAtomic: xmlMallocFunc; {$IFNDEF NO_EXTERNAL_VARS}cvar; external;{$ENDIF}
{$ENDIF}

{$IFDEF LIBXML_THREAD_ENABLED}
function __xmlRealloc: xmlReallocFuncPtr; EXTDECL;
#define xmlRealloc ( *(__xmlRealloc()))
{$ELSE}
var
  xmlRealloc: xmlReallocFunc; {$IFNDEF NO_EXTERNAL_VARS}cvar; external;{$ENDIF}
{$ENDIF}

{$IFDEF LIBXML_THREAD_ENABLED}
function __xmlFree: xmlFreeFuncPtr; EXTDECL;
#define xmlFree ( *(__xmlFree()))
{$ELSE}
var
  xmlFree: xmlFreeFunc; {$IFNDEF NO_EXTERNAL_VARS}cvar; external;{$ENDIF}
{$ENDIF}

{$IFDEF LIBXML_THREAD_ENABLED}
function __xmlMemStrdup: xmlStrdupFuncPtr; EXTDECL;
#define xmlMemStrdup ( *(__xmlMemStrdup()))
{$ELSE}
var
  xmlMemStrdup: xmlStrdupFunc; {$IFNDEF NO_EXTERNAL_VARS}cvar; external;{$ENDIF}
{$ENDIF}

{$ELSE} (* !LIBXML_THREAD_ALLOC_ENABLED *)
{$IFDEF NO_EXTERNAL_VARS}
var
  varxmlMalloc: PxmlMallocFunc;
  varxmlMallocAtomic: PxmlMallocFunc;
  varxmlRealloc: PxmlReallocFunc;
  varxmlFree: PxmlFreeFunc;
  varxmlMemStrdup: PxmlStrdupFunc;

function GetxmlMalloc: xmlMallocFunc; inline;
procedure SetxmlMalloc(AValue: xmlMallocFunc); inline;
function GetxmlMallocAtomic: xmlMallocFunc; inline;
procedure SetxmlMallocAtomic(AValue: xmlMallocFunc); inline;
function GetxmlRealloc: xmlReallocFunc; inline;
procedure SetxmlRealloc(AValue: xmlReallocFunc); inline;
function GetxmlFree: xmlFreeFunc; inline;
procedure SetxmlFree(AValue: xmlFreeFunc); inline;
function GetxmlMemStrdup: xmlStrdupFunc; inline;
procedure SetxmlMemStrdup(AValue: xmlStrdupFunc); inline;

property xmlMalloc: xmlMallocFunc read GetxmlMalloc write SetxmlMalloc;
property xmlMallocAtomic: xmlMallocFunc read GetxmlMallocAtomic write SetxmlMallocAtomic;
property xmlRealloc: xmlReallocFunc read GetxmlRealloc write SetxmlRealloc;
property xmlFree: xmlFreeFunc read GetxmlFree write SetxmlFree;
property xmlMemStrdup: xmlStrdupFunc read GetxmlMemStrdup write SetxmlMemStrdup;

{$ELSE}
var
  xmlMalloc: xmlMallocFunc; cvar; external;
  xmlMallocAtomic: xmlMallocFunc; cvar; external;
  xmlRealloc: xmlReallocFunc; cvar; external;
  xmlFree: xmlFreeFunc; cvar; external;
  xmlMemStrdup: xmlStrdupFunc; cvar; external;
{$ENDIF}
{$ENDIF} (* LIBXML_THREAD_ALLOC_ENABLED *)
{$ENDIF}