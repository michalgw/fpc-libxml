(*
 * Summary: implementation of the Relax-NG validation
 * Description: implementation of the Relax-NG validation
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 *)


{$IFDEF LIBXML_SCHEMAS_ENABLED}

{$IFDEF POINTER}
  xmlRelaxNGPtr = ^xmlRelaxNG;
  xmlRelaxNGParserCtxtPtr = ^xmlRelaxNGParserCtxt;
  xmlRelaxNGValidCtxtPtr = ^xmlRelaxNGValidCtxt;
{$ENDIF}

{$IFDEF TYPE}
  xmlRelaxNG = record end;

(**
 * A schemas validation context
 *)
  xmlRelaxNGValidityErrorFunc = procedure(ctx: pointer; msg: PAnsiChar); cdecl; varargs;
  xmlRelaxNGValidityWarningFunc = procedure(ctx: pointer; msg: PAnsiChar); cdecl; varargs;

  xmlRelaxNGParserCtxt = record end;

  xmlRelaxNGValidCtxt = record end;

(*
 * xmlRelaxNGValidErr:
 *
 * List of possible Relax NG validation errors
 *)
  xmlRelaxNGValidErr = (
    XML_RELAXNG_OK = 0,
    XML_RELAXNG_ERR_MEMORY,
    XML_RELAXNG_ERR_TYPE,
    XML_RELAXNG_ERR_TYPEVAL,
    XML_RELAXNG_ERR_DUPID,
    XML_RELAXNG_ERR_TYPECMP,
    XML_RELAXNG_ERR_NOSTATE,
    XML_RELAXNG_ERR_NODEFINE,
    XML_RELAXNG_ERR_LISTEXTRA,
    XML_RELAXNG_ERR_LISTEMPTY,
    XML_RELAXNG_ERR_INTERNODATA,
    XML_RELAXNG_ERR_INTERSEQ,
    XML_RELAXNG_ERR_INTEREXTRA,
    XML_RELAXNG_ERR_ELEMNAME,
    XML_RELAXNG_ERR_ATTRNAME,
    XML_RELAXNG_ERR_ELEMNONS,
    XML_RELAXNG_ERR_ATTRNONS,
    XML_RELAXNG_ERR_ELEMWRONGNS,
    XML_RELAXNG_ERR_ATTRWRONGNS,
    XML_RELAXNG_ERR_ELEMEXTRANS,
    XML_RELAXNG_ERR_ATTREXTRANS,
    XML_RELAXNG_ERR_ELEMNOTEMPTY,
    XML_RELAXNG_ERR_NOELEM,
    XML_RELAXNG_ERR_NOTELEM,
    XML_RELAXNG_ERR_ATTRVALID,
    XML_RELAXNG_ERR_CONTENTVALID,
    XML_RELAXNG_ERR_EXTRACONTENT,
    XML_RELAXNG_ERR_INVALIDATTR,
    XML_RELAXNG_ERR_DATAELEM,
    XML_RELAXNG_ERR_VALELEM,
    XML_RELAXNG_ERR_LISTELEM,
    XML_RELAXNG_ERR_DATATYPE,
    XML_RELAXNG_ERR_VALUE,
    XML_RELAXNG_ERR_LIST,
    XML_RELAXNG_ERR_NOGRAMMAR,
    XML_RELAXNG_ERR_EXTRADATA,
    XML_RELAXNG_ERR_LACKDATA,
    XML_RELAXNG_ERR_INTERNAL,
    XML_RELAXNG_ERR_ELEMWRONG,
    XML_RELAXNG_ERR_TEXTWRONG
  );

(*
 * xmlRelaxNGParserFlags:
 *
 * List of possible Relax NG Parser flags
 *)
  xmlRelaxNGParserFlag = (
    XML_RELAXNGP_NONE = 0,
    XML_RELAXNGP_FREE_DOC = 1,
    XML_RELAXNGP_CRNG = 2
  );

{$ENDIF}

{$IFDEF FUNCTION}
function xmlRelaxNGInitTypes: cint; EXTDECL; external xml2lib;
function xmlRelaxNGCleanupTypes: cint; EXTDECL; external xml2lib;

(*
 * Interfaces for parsing.
 *)
function xmlRelaxNGNewParserCtxt(URL: PAnsiChar): xmlRelaxNGParserCtxtPtr; EXTDECL; external xml2lib;
function xmlRelaxNGNewMemParserCtxt(buffer: PAnsiChar; size: cint): xmlRelaxNGParserCtxtPtr; EXTDECL; external xml2lib;
function xmlRelaxNGNewDocParserCtxt(doc: xmlDocPtr): xmlRelaxNGParserCtxtPtr; EXTDECL; external xml2lib;
function xmlRelaxParserSetFlag(ctxt: xmlRelaxNGParserCtxtPtr; flag: cint; doc: xmlDocPtr): cint; EXTDECL; external xml2lib;
procedure xmlRelaxNGFreeParserCtxt(ctxt: xmlRelaxNGParserCtxtPtr); EXTDECL; external xml2lib;
procedure xmlRelaxNGSetParserErrors(ctxt: xmlRelaxNGParserCtxtPtr; err: xmlRelaxNGValidityErrorFunc; warn: xmlRelaxNGValidityWarningFunc; ctx: pointer); EXTDECL; external xml2lib;
function xmlRelaxNGGetParserErrors(ctxt: xmlRelaxNGParserCtxtPtr; var err: xmlRelaxNGValidityErrorFunc; var warn: xmlRelaxNGValidityWarningFunc; var ctx: pointer): cint; EXTDECL; external xml2lib;
procedure xmlRelaxNGSetParserStructuredErrors(ctxt: xmlRelaxNGParserCtxtPtr; serror: xmlStructuredErrorFunc; ctx: pointer); EXTDECL; external xml2lib;
function xmlRelaxNGParse(ctxt: xmlRelaxNGParserCtxtPtr): xmlRelaxNGPtr; EXTDECL; external xml2lib;
procedure xmlRelaxNGFree(schema: xmlRelaxNGPtr); EXTDECL; external xml2lib;
{$IFDEF LIBXML_OUTPUT_ENABLED}
procedure xmlRelaxNGDump(output: PFILE; schema: xmlRelaxNGPtr); EXTDECL; external xml2lib;
procedure xmlRelaxNGDumpTree(output: PFILE; schema: xmlRelaxNGPtr); EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_OUTPUT_ENABLED *)

(*
 * Interfaces for validating
 *)
procedure xmlRelaxNGSetValidErrors(ctxt: xmlRelaxNGValidCtxtPtr; err: xmlRelaxNGValidityErrorFunc; warn: xmlRelaxNGValidityWarningFunc; ctx: pointer); EXTDECL; external xml2lib;
function xmlRelaxNGGetValidErrors(ctxt: xmlRelaxNGValidCtxtPtr; var err: xmlRelaxNGValidityErrorFunc; var warn: xmlRelaxNGValidityWarningFunc; var ctx: pointer): cint; EXTDECL; external xml2lib;
procedure xmlRelaxNGSetValidStructuredErrors(ctxt: xmlRelaxNGValidCtxtPtr; serror: xmlStructuredErrorFunc; ctx: pointer); EXTDECL; external xml2lib;
function xmlRelaxNGNewValidCtxt(schema: xmlRelaxNGPtr): xmlRelaxNGValidCtxtPtr; EXTDECL; external xml2lib;
procedure xmlRelaxNGFreeValidCtxt(ctxt: xmlRelaxNGValidCtxtPtr); EXTDECL; external xml2lib;
function xmlRelaxNGValidateDoc(ctxt: xmlRelaxNGValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL; external xml2lib;

(*
 * Interfaces for progressive validation when possible
 *)
function xmlRelaxNGValidatePushElement(ctxt: xmlRelaxNGValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL; external xml2lib;
function xmlRelaxNGValidatePushCData(ctxt: xmlRelaxNGValidCtxtPtr; data: xmlCharPtr; len: cint): cint; EXTDECL; external xml2lib;
function xmlRelaxNGValidatePopElement(ctxt: xmlRelaxNGValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL; external xml2lib;
function xmlRelaxNGValidateFullElement(ctxt: xmlRelaxNGValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL; external xml2lib;
{$ENDIF}

{$IFDEF FUNCTIONVAR}
  xmlRelaxNGInitTypes: function: cint; EXTDECL;
  xmlRelaxNGCleanupTypes: function: cint; EXTDECL;

(*
 * Interfaces for parsing.
 *)
  xmlRelaxNGNewParserCtxt: function(URL: PAnsiChar): xmlRelaxNGParserCtxtPtr; EXTDECL;
  xmlRelaxNGNewMemParserCtxt: function(buffer: PAnsiChar; size: cint): xmlRelaxNGParserCtxtPtr; EXTDECL;
  xmlRelaxNGNewDocParserCtxt: function(doc: xmlDocPtr): xmlRelaxNGParserCtxtPtr; EXTDECL;
  xmlRelaxParserSetFlag: function(ctxt: xmlRelaxNGParserCtxtPtr; flag: cint; doc: xmlDocPtr): cint; EXTDECL;
  xmlRelaxNGFreeParserCtxt: procedure(ctxt: xmlRelaxNGParserCtxtPtr); EXTDECL;
  xmlRelaxNGSetParserErrors: procedure(ctxt: xmlRelaxNGParserCtxtPtr; err: xmlRelaxNGValidityErrorFunc; warn: xmlRelaxNGValidityWarningFunc; ctx: pointer); EXTDECL;
  xmlRelaxNGGetParserErrors: function(ctxt: xmlRelaxNGParserCtxtPtr; var err: xmlRelaxNGValidityErrorFunc; var warn: xmlRelaxNGValidityWarningFunc; var ctx: pointer): cint; EXTDECL;
  xmlRelaxNGSetParserStructuredErrors: procedure(ctxt: xmlRelaxNGParserCtxtPtr; serror: xmlStructuredErrorFunc; ctx: pointer); EXTDECL;
  xmlRelaxNGParse: function(ctxt: xmlRelaxNGParserCtxtPtr): xmlRelaxNGPtr; EXTDECL;
  xmlRelaxNGFree: procedure(schema: xmlRelaxNGPtr); EXTDECL;
{$IFDEF LIBXML_OUTPUT_ENABLED}
  xmlRelaxNGDump: procedure(output: PFILE; schema: xmlRelaxNGPtr); EXTDECL;
  xmlRelaxNGDumpTree: procedure(output: PFILE; schema: xmlRelaxNGPtr); EXTDECL;
{$ENDIF} (* LIBXML_OUTPUT_ENABLED *)

(*
 * Interfaces for validating
 *)
  xmlRelaxNGSetValidErrors: procedure(ctxt: xmlRelaxNGValidCtxtPtr; err: xmlRelaxNGValidityErrorFunc; warn: xmlRelaxNGValidityWarningFunc; ctx: pointer); EXTDECL;
  xmlRelaxNGGetValidErrors: function(ctxt: xmlRelaxNGValidCtxtPtr; var err: xmlRelaxNGValidityErrorFunc; var warn: xmlRelaxNGValidityWarningFunc; var ctx: pointer): cint; EXTDECL;
  xmlRelaxNGSetValidStructuredErrors: procedure(ctxt: xmlRelaxNGValidCtxtPtr; serror: xmlStructuredErrorFunc; ctx: pointer); EXTDECL;
  xmlRelaxNGNewValidCtxt: function(schema: xmlRelaxNGPtr): xmlRelaxNGValidCtxtPtr; EXTDECL;
  xmlRelaxNGFreeValidCtxt: procedure(ctxt: xmlRelaxNGValidCtxtPtr); EXTDECL;
  xmlRelaxNGValidateDoc: function(ctxt: xmlRelaxNGValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL;

(*
 * Interfaces for progressive validation when possible
 *)
  xmlRelaxNGValidatePushElement: function(ctxt: xmlRelaxNGValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL;
  xmlRelaxNGValidatePushCData: function(ctxt: xmlRelaxNGValidCtxtPtr; data: xmlCharPtr; len: cint): cint; EXTDECL;
  xmlRelaxNGValidatePopElement: function(ctxt: xmlRelaxNGValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL;
  xmlRelaxNGValidateFullElement: function(ctxt: xmlRelaxNGValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL;
{$ENDIF}
{$ENDIF} (* LIBXML_SCHEMAS_ENABLED *)

